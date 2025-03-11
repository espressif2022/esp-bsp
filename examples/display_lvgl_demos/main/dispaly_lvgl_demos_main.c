/*
 * SPDX-FileCopyrightText: 2021-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "lv_demos.h"
#include "bsp/esp-bsp.h"

static char *TAG = "app_main";

#define LOG_MEM_INFO    (1)

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "esp_timer.h"
#include "esp_log.h"

#include "esp_lv_fs.h"
#include "mmap_generate_spiffs_assets.h"

extern const uint8_t output_1_start[] asm("_binary_output_1_wav_start");
extern const uint8_t output_1_end[]   asm("_binary_output_1_wav_end");

extern const uint8_t output_2_start[] asm("_binary_output_2_wav_start");
extern const uint8_t output_2_end[]   asm("_binary_output_2_wav_end");

static int64_t last_time = 0;
static lv_font_t *my_font;
static lv_obj_t *main_label;

static void timer_callback(TimerHandle_t xTimer)
{
    int64_t current_time = esp_timer_get_time();
    if (last_time != 0) {
        // printf("Time difference: %lld ms\r\n", (current_time - last_time) / 1000);
    }
    static int i = 0;
    bsp_display_lock(0);
    // lv_label_set_text(main_label, "T");
#if 0
    char test[2] = {i % 26 + 'A', 0};
    lv_label_set_text(main_label, test);
#else
    char test[4];
    if (i % 2 == 0) {
        test[0] = rand() % 26 + 'A'; // Random English letter
        test[1] = 0;
    } else {
        uint16_t unicode = 0x4E00 + (rand() % (0x9FA5 - 0x4E00 + 1)); // Random Chinese character
        // Manually encode to UTF-8
        test[0] = 0xE0 | ((unicode >> 12) & 0x0F);
        test[1] = 0x80 | ((unicode >> 6) & 0x3F);
        test[2] = 0x80 | (unicode & 0x3F);
        test[3] = 0;
    }
    printf("label:%s\r\n", test);
    lv_label_set_text(main_label, test);
#endif
    bsp_display_unlock();
    i++;
    last_time = current_time;
}

void init_mmap_filesystem()
{
    mmap_assets_handle_t asset_handle;
    static esp_lv_fs_handle_t fs_drive_a_handle;

    const mmap_assets_config_t config = {
        .partition_label = "factory",
        .max_files = MMAP_SPIFFS_ASSETS_FILES,
        .checksum = MMAP_SPIFFS_ASSETS_CHECKSUM,
        .start_offset = MMAP_SPIFFS_ASSETS_OFFSET,
        .flags = {
            .mmap_enable = true,
            .app_bin_check = false,
            .full_check = true,
            .metadata_check = true,
        },
    };
    mmap_assets_new(&config, &asset_handle);

    const fs_cfg_t fs_drive_cfg = {
        .fs_letter = 'A',
        .fs_assets = asset_handle,
        .fs_nums = MMAP_SPIFFS_ASSETS_FILES
    };
    esp_lv_fs_desc_init(&fs_drive_cfg, &fs_drive_a_handle);

    int stored_files = mmap_assets_get_stored_files(asset_handle);
    ESP_LOGI(TAG, "offfset:0x%X, stored_files:%d", MMAP_SPIFFS_ASSETS_OFFSET, stored_files);

    for (int i = 0; i < stored_files; i++) {
        const char *name = mmap_assets_get_name(asset_handle, i);
        int size = mmap_assets_get_size(asset_handle, i);
        ESP_LOGI(TAG, "name:%s, size:%d", name, size);
    }

    // my_font = lv_font_load("A:font_20.bin"); /*!< pingfang_20.bin */
    my_font = lv_font_load("A:font_20_all.bin"); /*!< pingfang_20.bin */

    assert(my_font != NULL);
}

void app_main(void)
{

    /* Initialize display and LVGL */
    bsp_display_start();
    init_mmap_filesystem();

#if CONFIG_BSP_DISPLAY_LVGL_AVOID_TEAR
    ESP_LOGI(TAG, "Avoid lcd tearing effect");
#if CONFIG_BSP_DISPLAY_LVGL_FULL_REFRESH
    ESP_LOGI(TAG, "LVGL full-refresh");
#elif CONFIG_BSP_DISPLAY_LVGL_DIRECT_MODE
    ESP_LOGI(TAG, "LVGL direct-mode");
#endif
#endif

    /* Set display brightness to 100% */
    bsp_display_backlight_on();

    ESP_LOGI(TAG, "Display LVGL demo");
    bsp_display_lock(0);
    // lv_demo_widgets();      /* A widgets example */
    // lv_demo_music();        /* A modern, smartphone-like music player demo. */
    // lv_demo_stress();       /* A stress test for LVGL. */
    // lv_demo_benchmark();    /* A demo to measure the performance of LVGL or to compare different settings. */

    /*Create the main label*/
    main_label = lv_label_create(lv_scr_act());
    lv_obj_remove_style_all(main_label);
    lv_obj_set_style_text_color(main_label, lv_color_hex(0xFF0000), 0);
    lv_obj_set_style_text_font(main_label, my_font, 0);
    lv_obj_align(main_label, LV_ALIGN_CENTER, 0, 0);

    // lv_label_set_text(main_label, "mmap 单分区测试 全字体 徐新");
    lv_label_set_text(main_label, "T");

    bsp_display_unlock();
    /* Create a FreeRTOS timer */
    TimerHandle_t timer = xTimerCreate("MyTimer", pdMS_TO_TICKS(30 * 20), pdTRUE, (void *)0, timer_callback);

    if (timer == NULL) {
        ESP_LOGE(TAG, "Failed to create timer");
    } else {
        if (xTimerStart(timer, 0) != pdPASS) {
            ESP_LOGE(TAG, "Failed to start timer");
        }
    }

#if LOG_MEM_INFO
    static char buffer[128];    /* Make sure buffer is enough for `sprintf` */
    while (1) {
    // if (1) {
        sprintf(buffer, "   Biggest /     Free /    Total\n"
                "\t  SRAM : [%8d K / %8d K / %8d K]\n"
                "\t PSRAM : [%8d K / %8d K / %8d K]",
                heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL) / 1024,
                heap_caps_get_free_size(MALLOC_CAP_INTERNAL) / 1024,
                heap_caps_get_total_size(MALLOC_CAP_INTERNAL) / 1024,
                heap_caps_get_largest_free_block(MALLOC_CAP_SPIRAM) / 1024,
                heap_caps_get_free_size(MALLOC_CAP_SPIRAM) / 1024,
                heap_caps_get_total_size(MALLOC_CAP_SPIRAM) / 1024);
        ESP_LOGI("MEM", "%s", buffer);

        vTaskDelay(pdMS_TO_TICKS(1000 * 10));
    }
#endif
}
