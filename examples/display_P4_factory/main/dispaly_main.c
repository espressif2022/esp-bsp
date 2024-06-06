/*
 * SPDX-FileCopyrightText: 2021-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include "esp_log.h"
#include "bsp/esp-bsp.h"
#include "app_disp_fs.h"

static char *TAG = "app_main";

void app_main(void)
{
    /* Initialize and mount SPIFFS */
    bsp_spiffs_mount();

    /* Initialize I2C (for touch and audio) */
    bsp_i2c_init();

    /* Initialize display and LVGL */
    bsp_display_start();

    /* Set default display brightness */
    // bsp_display_brightness_set(APP_DISP_DEFAULT_BRIGHTNESS);
    bsp_display_backlight_off();

    /* Add and show LVGL objects on display */
    app_disp_lvgl_show();

    /* Initialize SPI flash file system and show list of files on display */
    app_disp_fs_init();

    /* Initialize audio */
    app_audio_init();

    ESP_LOGI(TAG, "Example initialization done.");

}
