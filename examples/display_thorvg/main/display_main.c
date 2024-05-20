/*
 * SPDX-FileCopyrightText: 2022-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"
#include "bsp/esp-bsp.h"

#include "thorvg_demo_ui.h"

static const char *TAG = "EXAMPLE";

static bsp_lcd_handles_t lcd_panels;

void app_main(void)
{
    bsp_spiffs_mount();

    /* Initialize display */
    bsp_display_new_with_handles(NULL, &lcd_panels);

    bsp_display_backlight_on();

    BaseType_t res = xTaskCreate(example_thorvg_lottie, "LVGL task", 50 * 1024, (void *)&lcd_panels, 5, NULL);
    if (res != pdPASS) {
        ESP_LOGE(TAG, "Create LVGL task fail!");
    }
}
