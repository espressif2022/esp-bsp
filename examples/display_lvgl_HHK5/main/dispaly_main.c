/*
 * SPDX-FileCopyrightText: 2021-2025 Espressif Systems (Shanghai) CO LTD
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

typedef struct {
    uint8_t screen_type;
    uint8_t screen_number;
} screen_set_mapping_t;

lv_ui guider_ui;

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

void send_cmd_set_list_0x20(uint8_t lang)
{
    uint8_t list_test_text_1[] = {
        0x20,
        0xFF, 0x00,
        0x06, 0xFE //Delete one
    };
    list_test_text_1[2] = lang % 2;
    i2c_send_test_cmd(list_test_text_1, sizeof(list_test_text_1));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    list_test_text_1[2] = lang % 2;
    list_test_text_1[3] = 0x07;//Full screen
    i2c_send_test_cmd(list_test_text_1, sizeof(list_test_text_1));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));
}

void send_cmd_set_menu_0x21(uint8_t lang)
{
    uint8_t menu_test_text_1[] = {
        0x21,
        0xFF, 0x01, 0x01
    };
    menu_test_text_1[2] = lang % 2;

    //1->10->1->10->1->10->1->10->1->10
    for (int i = 0; i < 10; i++) {
        menu_test_text_1[3] = i % 10 + 1;
        i2c_send_test_cmd(menu_test_text_1, sizeof(menu_test_text_1));
        vTaskDelay(pdMS_TO_TICKS(1000 * 1));
    }
}

void send_cmd_set_screen_0x30(uint8_t lang)
{
    const screen_set_mapping_t cmd_set_screen_map[] = {
        { SCREEN_TYPE_BOOT, 0x00 },
        { SCREEN_TYPE_BOOT, 0x01 },
        { SCREEN_TYPE_BOOT, 0x02 },
        { SCREEN_TYPE_BOOT, 0x03 },
        { SCREEN_TYPE_BOOT, 0x04 },
        { SCREEN_TYPE_BOOT, 0x05 },
        { SCREEN_TYPE_BOOT, 0x07 },
        { SCREEN_TYPE_BOOT, 0x08 },
        { SCREEN_TYPE_BOOT, 0x11 },

        { SCREEN_TYPE_FIRMWARE_UPGRADE, 0x01 },
        { SCREEN_TYPE_FIRMWARE_UPGRADE, 0x02 },

        { SCREEN_TYPE_WIRELESS_STB_PAIRING, 0x01 },

        { SCREEN_TYPE_DATA_CLIENT_PAIRING, 0x01 },

        { SCREEN_TYPE_FACTORY_RESET, 0x01 },
        { SCREEN_TYPE_FACTORY_RESET, 0x02 },
        { SCREEN_TYPE_FACTORY_RESET, 0x03 },

        { SCREEN_TYPE_SPEED_TEST, 0x01 },

        { SCREEN_TYPE_RESTART_MODEM, 0x01 },
        { SCREEN_TYPE_RESTART_MODEM, 0x02 },
    };

    for (size_t i = 0; i < sizeof(cmd_set_screen_map) / sizeof(cmd_set_screen_map[0]); i++) {
        uint8_t screen_set_text[] = {
            0x30,
            0xFF, lang % 2,
            cmd_set_screen_map[i].screen_type,
            cmd_set_screen_map[i].screen_number
        };

        printf("Testing Screen Type: 0x%02X, Screen Number: 0x%02X\n",
               cmd_set_screen_map[i].screen_type, cmd_set_screen_map[i].screen_number);
        i2c_send_test_cmd(screen_set_text, sizeof(screen_set_text));
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void send_cmd_set_notif_0x40(uint8_t lang)
{
    uint8_t notif_v4_text[] = {
        0x40,
        0xFF, 0x01,
        0x01,//notif type
        0x00,//menu indication
        0x05, 0x42, 0x55, 0x2D, 0x36, 0x00,//"BU-6"
        0x01, 0x00,//var1 null
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x32, 0x00,//var1 "error line 2"
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x33, 0x00,//var1 "error line 3"
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x34, 0x00,//var1 "error line 4"

    };
    notif_v4_text[2] = lang % 2;
    i2c_send_test_cmd(notif_v4_text, sizeof(notif_v4_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    uint8_t notif_v1_text[] = {
        0x40,
        0xFF, 0x01,
        0x01,//notif type
        0x00,//menu indication
        0x05, 0x46, 0x55, 0x2D, 0x33, 0x00,//"FU-3"
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x31, 0x00,//var1 "error line 1"
    };
    notif_v1_text[2] = lang % 2;
    i2c_send_test_cmd(notif_v1_text, sizeof(notif_v1_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    uint8_t notif_v2_text[] = {
        0x40,
        0xFF, 0x01,
        0x00,//notif type
        0x01,//menu indication
        0x06, 0x53, 0x54, 0x42, 0x2D, 0x32, 0x00,//"STB-2"
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x31, 0x00,//var1 "error line 1"
    };
    notif_v2_text[2] = lang % 2;
    i2c_send_test_cmd(notif_v2_text, sizeof(notif_v2_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));
}

void send_cmd_set_config_0x41(uint8_t lang)
{
    uint8_t config_wifi_text[] = {
        0x41,
        0xFF, 0x01,
        0x01,//config type
        0x01,//menu indication
        0x12, 0x59, 0x6F, 0x75, 0x72, 0x20, 0x57, 0x69, 0x46, 0x69, 0x20, 0x6E, 0x65,
        0x74, 0x77, 0x6F, 0x72, 0x6B, 0x00,//"Your WiFi network"
        0x03, 0x6F, 0x6B, 0x00,//url
        0x0A, 0x74, 0x65, 0x73, 0x74, 0x20, 0x73, 0x73, 0x69, 0x64, 0x00,//"test ssid"
        0x0C, 0x74, 0x65, 0x73, 0x74, 0x20, 0x70, 0x61, 0x73, 0x73, 0x77, 0x64, 0x00,//"test passwd"
        0x06, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x00,
        0x03, 0x31, 0x32, 0x33, 0x00
    };
    config_wifi_text[2] = lang % 2;
    i2c_send_test_cmd(config_wifi_text, sizeof(config_wifi_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    uint8_t client_pairing_text[] = {
        0x41,
        0xFF, 0x01,
        0x02,//config type
        0x00,//menu indication
        0x1B, 0x43, 0x6F, 0x6E, 0x6E, 0x65, 0x63, 0x74, 0x20, 0x57, 0x69, 0x2D, 0x46,
        0x69, 0x20, 0x64, 0x65, 0x76, 0x69, 0x63, 0x65, 0x20, 0x28, 0x57, 0x50, 0x53, 0x29, 0x00,//"Connect Wi-Fi device (WPS)"
        0x03, 0x6F, 0x6B, 0x00,//url
        0x03, 0x45, 0x53, 0x50, 0x00,//"ESP"
        0x05, 0x61, 0x62, 0x63, 0x64, 0x00,
        0x06, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x00,
        0x03, 0x31, 0x32, 0x33, 0x00
    };
    client_pairing_text[2] = lang % 2;
    i2c_send_test_cmd(client_pairing_text, sizeof(client_pairing_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    uint8_t speed_test_text[] = {
        0x41,
        0xFF, 0x01,
        0x03, //config type
        0x01, //menu indication
        0x0B, 0x53, 0x70, 0x65, 0x65, 0x64, 0x20, 0x54, 0x65, 0x73, 0x74, 0x00,//"Speed Test"
        0x03, 0x6F, 0x6B, 0x00, //url ok
        0x03, 0x35, 0x36, 0x00,//"56"
        0x03, 0x39, 0x36, 0x00,//"96"
        0x06, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x00,
        0x03, 0x31, 0x32, 0x33, 0x00
    };
    speed_test_text[2] = lang % 2;
    i2c_send_test_cmd(speed_test_text, sizeof(speed_test_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    uint8_t modem_password_text[] = {
        0x41,
        0xFF, 0x01,
        0x04,//config type
        0x00,//menu indication
        0x14, 0x4D, 0x6F, 0x64, 0x65, 0x6D, 0x20, 0x50, 0x61, 0x73, 0x73, 0x77,
        0x6F, 0x72, 0x64, 0x20, 0x4D, 0x4D, 0x2D, 0x31, 0x00,//"Modem Password MM-1"
        0x03, 0x6F, 0x6B, 0x00,//url
        0x0C, 0x74, 0x65, 0x73, 0x74, 0x20, 0x70, 0x61, 0x73, 0x73, 0x77, 0x64, 0x00,//"test passwd"
        0x05, 0x61, 0x62, 0x63, 0x64, 0x00,
        0x06, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x00,
        0x03, 0x31, 0x32, 0x33, 0x00
    };
    modem_password_text[2] = lang % 2;
    i2c_send_test_cmd(modem_password_text, sizeof(modem_password_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));
}

void send_cmd_set_error_0x42(uint8_t lang)
{
    uint8_t error_text_var4[] = {
        0x42,
        0xFF, 0x01,
        0xFE,//error num
        0x10, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x20, 0x74, 0x65, 0x73, 0x74, 0x00,//Err label "Error name test"
        0x03, 0x6F, 0x6B, 0x00,//url
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x31, 0x00,//var1 "error line 1"
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x32, 0x00,//var2 "error line 2"
        0x06, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x00,
        0x03, 0x31, 0x32, 0x33, 0x00
    };
    error_text_var4[2] = lang % 2;
    i2c_send_test_cmd(error_text_var4, sizeof(error_text_var4));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    uint8_t error_text_var0[] = {
        0x42,
        0xFF, 0x01,
        0xFE,//error num
        0x10, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x20, 0x74, 0x65, 0x73, 0x74, 0x00,//Err label "Error name test"
        0x01, 0x00,//url null
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x31, 0x00,//var1 "error line 1"
        0x0D, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x32, 0x00,//var2 "error line 2"
    };
    error_text_var0[2] = lang % 2;
    i2c_send_test_cmd(error_text_var0, sizeof(error_text_var0));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));
}

void send_cmd_set_apps_0x50(uint8_t lang)
{
    uint8_t app_slider_text[] = {
        0x50,
        0xFF, 0x01,
        0x01,
    };
    app_slider_text[2] = lang % 2;

    for (int i = 0; i < 6; i++) {
        app_slider_text[3] = i % 3 + 1;
        i2c_send_test_cmd(app_slider_text, sizeof(app_slider_text));
        vTaskDelay(pdMS_TO_TICKS(1000 * 1));
    }
}

void send_cmd_set_apps_0x51(uint8_t lang)
{
    uint8_t wifi_app_text[] = {
        0x51,
        0xFF, 0x01,
        0x01, //screen num
        0x06, 0x54, 0x69, 0x74, 0x6C, 0x65, 0x00,//url
        0x12, 0x64, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x31, 0x00,//"description line1"
        0x12, 0x64, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x32, 0x00,//"description line2"
        0x05, 0x61, 0x62, 0x63, 0x64, 0x00,
        0x06, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x00,
    };
    wifi_app_text[2] = lang % 2;

    wifi_app_text[3] = 0x01;//wifi app
    i2c_send_test_cmd(wifi_app_text, sizeof(wifi_app_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    wifi_app_text[3] = 0x02;//Fibe TV app
    i2c_send_test_cmd(wifi_app_text, sizeof(wifi_app_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

    wifi_app_text[3] = 0x03;//Virtual repair tool
    i2c_send_test_cmd(wifi_app_text, sizeof(wifi_app_text));
    vTaskDelay(pdMS_TO_TICKS(1000 * 2));

}

void app_main(void)
{
    i2c_slave_start();

    bsp_display_start();
    bsp_display_backlight_on();

    ESP_LOGI(TAG, "Display LVGL demo");
    bsp_display_lock(0);

    setup_ui(&guider_ui);
    custom_init(&guider_ui);

    bsp_display_unlock();

    uint8_t lang = 0;
    while (1) {
        // send_cmd_set_list_0x20(lang);
        // send_cmd_set_menu_0x21(lang);
        // send_cmd_set_screen_0x30(lang);
        // send_cmd_set_notif_0x40(lang);
        // send_cmd_set_config_0x41(lang);
        // send_cmd_set_error_0x42(lang);
        send_cmd_set_apps_0x50(lang);
        // send_cmd_set_apps_0x51(lang);
        lang++;
    }
}
