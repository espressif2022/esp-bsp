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

#include "gui_guider.h"
#include "custom.h"
#include "i2c_slave.h"
#include "message.h"

void mem_monitor()
{
    static char buffer[256];    /* Make sure buffer is enough for `sprintf` */
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
}

lv_ui guider_ui;

void app_main(void)
{
    i2c_slave_start();

    /* Initialize display and LVGL */
    bsp_display_start();

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

    // lv_main_loop_loading();

    setup_ui(&guider_ui);
    custom_init(&guider_ui);

    bsp_display_unlock();

#if LOG_MEM_INFO
    // while (1) {
    if (1) {
        mem_monitor();
        // vTaskDelay(pdMS_TO_TICKS(1000 * 10));
    }
#endif

    return;
    // process_screen(SCREEN_TYPE_BOOT, 0x00, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x01, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x02, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x03, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x04, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x05, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x07, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x08, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    // process_screen(SCREEN_TYPE_BOOT, 0x11, LANG_ENGLISH);
    // vTaskDelay(pdMS_TO_TICKS(1000 * 5));

    process_screen(SCREEN_TYPE_FIRMWARE_UPGRADE, 0x1, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    process_screen(SCREEN_TYPE_FIRMWARE_UPGRADE, 0x12, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));

    process_screen(SCREEN_TYPE_WIRELESS_STB_PAIRING, 0x01, LANG_FRENCH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));

    process_screen(SCREEN_TYPE_DATA_CLIENT_PAIRING, 0x01, LANG_FRENCH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));

    process_screen(SCREEN_TYPE_FACTORY_RESET, 0x01, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    process_screen(SCREEN_TYPE_FACTORY_RESET, 0x02, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    process_screen(SCREEN_TYPE_FACTORY_RESET, 0x03, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));

    process_screen(SCREEN_TYPE_SPEED_TEST, 0x01, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));

    process_screen(SCREEN_TYPE_RESTART_MODEM, 0x01, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));
    process_screen(SCREEN_TYPE_RESTART_MODEM, 0x02, LANG_ENGLISH);
    vTaskDelay(pdMS_TO_TICKS(1000 * 5));
}
