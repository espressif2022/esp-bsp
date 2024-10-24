/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "bsp/esp-bsp.h"
#include "lvgl.h"
#include "esp_log.h"

#include "esp_lv_fs.h"
#include "mmap_generate_images.h"

extern void example_lvgl_demo_ui(lv_obj_t *scr);

static const char *TAG = "display";

static mmap_assets_handle_t mmap_drive_handle;
static esp_lv_fs_handle_t fs_drive_handle;

esp_err_t mount_mmap_filesystem(void)
{
    esp_err_t ret;

    const mmap_assets_config_t asset_cfg = {
        .partition_label = "storage",
        .max_files = MMAP_IMAGES_FILES,
        .checksum = MMAP_IMAGES_CHECKSUM,
        .flags = {.mmap_enable = true}
    };
    ret = mmap_assets_new(&asset_cfg, &mmap_drive_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize %s", "storage");
        return ret;
    }

    fs_cfg_t fs_cfg;

    fs_cfg.fs_letter = 'A';
    fs_cfg.fs_assets = mmap_drive_handle;
    fs_cfg.fs_nums = MMAP_IMAGES_FILES;

    ret = esp_lv_fs_desc_init(&fs_cfg, &fs_drive_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize FS for %s", "storage");
        return ret;
    }

    return ESP_OK;
}
void app_main(void)
{
    bsp_display_start();
    mount_mmap_filesystem();

    ESP_LOGI("example", "Display LVGL animation");
    bsp_display_lock(0);
    lv_obj_t *scr = lv_disp_get_scr_act(NULL);
    example_lvgl_demo_ui(scr);

    bsp_display_unlock();
    bsp_display_backlight_on();
}
