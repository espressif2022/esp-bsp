/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#ifndef MESSAG_H
#define MESSAG_H

#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"

// Synchronization Commands
#define CMD_HELLO               0x00
#define CMD_GET_FW_VERSION      0x01
#define CMD_SET_RESET           0x02
#define CMD_SET_IMAGE           0x03
#define CMD_SEND_IMAGE          0x04 // To be developed further
#define CMD_GET_STATUS          0x60

// Backlight Command
#define CMD_SET_BACKLIGHT       0x10

// Command Types
#define CMD_SET_LIST            0x20
#define CMD_SET_MENU            0x21
#define CMD_SET_SCREEN          0x30
#define CMD_SET_NOTIF           0x40
#define CMD_SET_CONFIG          0x41
#define CMD_SET_ERROR           0x42
#define CMD_SET_BELLAPPS        0x50
#define CMD_SET_APPS            0x51

// Cmd_Set_Menu 0x21
// 0x30 0x20 Frame Num Language Menu Num
#define CMD_SERVICE_STATUS      0x01
#define CMD_WIFI_PASSWORD       0x02
#define CMD_CONNECT_FIBE_TV     0x03
#define CMD_CONNECT_WIFI_DEVICE 0x04
#define CMD_MODEM_MANAGEMENT    0x05
#define CMD_TEST_INTERNET_SPEED 0x06
#define CMD_BELL_APPS           0x07
#define CMD_RESTART_MODEM       0x08
#define CMD_SWITCH_LANGUAGE     0x09
#define CMD_CLOSE               0x0A

// Cmd_Set_Screen 0x30
// 0x30 0x30 Frame Num Language Screen Type Screen Number
#define SCREEN_TYPE_BOOT                    0x00
#define SCREEN_TYPE_FIRMWARE_UPGRADE        0x01
#define SCREEN_TYPE_WIRELESS_STB_PAIRING    0x02
#define SCREEN_TYPE_DATA_CLIENT_PAIRING     0x03
#define SCREEN_TYPE_FACTORY_RESET           0x04
#define SCREEN_TYPE_SPEED_TEST              0x05
#define SCREEN_TYPE_RESTART_MODEM           0x06

// Cmd_Set_Config 0x41
// 0x30 0x41 Frame NumConfig TypeMenu Title LengthTitle Text LengthText URL LengthURL
#define CONFIG_TYPE_WIFI_NETWORK            0x01 // BU-12
#define CONFIG_TYPE_DATA_CLIENT_PAIRING     0x02 // WPSD-2
#define CONFIG_TYPE_SPEED_TEST              0x03 // ST-2
#define CONFIG_TYPE_MODEM_PASSWORD          0x04 // MM-1

// Cmd_Set_BellApps 0x50
// 0x30 0x50 Frame Num Language Menu Num
#define SCREEN_NUM_APPS_WIFI_APP                   0x01
#define SCREEN_NUM_APPS_FIBE_TV_APP                0x02
#define SCREEN_NUM_APPS_VIRTUAL_REPAIR_TOOL        0x03


#define LANG_ENGLISH            0x00
#define LANG_FRENCH             0x01

/**
 * The following part is offset.
 */
// Command Data Indices
#define CMD_TYPE_INDEX          0
#define FRAME_INDEX             1

// Cmd_Set_Backlight 0x10
#define BL_STATE_INDEX          1
#define BL_INTENSITY_INDEX      2

// Cmd_Set_List 0x20
#define LIST_LANG_INDEX         2
#define LIST_MENUS_MSB_INDEX    3
#define LIST_MENUS_LSB_INDEX    4

// Cmd_Set_Menu 0x21
#define MENU_LANG_INDEX         2
#define MENU_NUM_INDEX          3

// Cmd_Set_Screen 0x30
#define SCREEN_LANG_INDEX       2
#define SCREEN_TYPE_INDEX       3
#define SCREEN_NUM_INDEX        4

//Cmd_Set_Notif 0x40
#define NOTIF_LANG_INDEX        2
#define NOTIF_TYPE_INDEX        3
#define NOTIF_MENU_INDEX        4
#define NOTIF_TITLE_LEN_IDX     5
#define NOTIF_TITLE_IDX         6

//Cmd_Set_Config 0x41
#define CONFIG_LANG_INDEX       2
#define CONFIG_TYPE_INDEX       3
#define CONFIG_MENU_INDEX       4
#define CONFIG_TITLE_LEN_IDX    5
#define CONFIG_TITLE_IDX        6

//Cmd_Set_Error 0x42
#define ERROR_LANG_INDEX        2
#define ERROR_NUM_INDEX         3
#define ERROR_LEN_INDEX         4
#define ERROR_LABEL_INDEX       5

// Cmd_Set_BellApps 0x50
#define BELLAPPS_LANG_INDEX     2
#define BELLAPPS_MENU_INDEX     3

// Cmd_Set_Apps 0x51
#define APPS_LANG_INDEX         2
#define APPS_SCREEN_INDEX       3
#define APPS_LABEL_LEN_INDEX    4
#define APPS_LABEL_INDEX        5

typedef struct {
    uint8_t state;
    uint8_t intensity;
} cmd_set_bl_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    union {
        struct {
            uint8_t menu_list_lsb;
            uint8_t menu_list_msb;
        };
        struct {
            uint8_t no : 1;
            uint8_t mn1 : 1;
            uint8_t mn2 : 1;
            uint8_t mn3 : 1;
            uint8_t mn4 : 1;
            uint8_t mn5 : 1;
            uint8_t mn6 : 1;
            uint8_t mn7 : 1;
            uint8_t mn8 : 1;
            uint8_t mn9 : 1;
            uint8_t mn10 : 1;
            uint8_t reserved : 5;
        };
    };
} cmd_set_list_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t menu_num;
} cmd_set_menu_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t scren_type;
    uint8_t scren_num;
} cmd_set_screen_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t notif_type;
    uint8_t menu_indication;
    uint8_t title_len;
    const char *title;

    uint8_t var_count;
    struct {
        uint8_t len;
        const char *text;
    } vars[4];
} cmd_set_notif_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t config_type;
    uint8_t menu_indication;
    uint8_t title_len;
    const char *title;
    uint8_t url_len;
    const char *url;

    uint8_t var_count;
    struct {
        uint8_t len;
        const char *text;
    } vars[4];
} cmd_set_config_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t error_num;
    uint8_t error_len;
    const char *label;
    uint8_t url_len;
    const char *url;

    uint8_t var_count;
    struct {
        uint8_t len;
        const char *text;
    } vars[4];
} cmd_set_error_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t screen_num;
    uint8_t text_len;
    const char *text;
    uint8_t url_len;
    const char *url;
} cmd_set_apps_t;

typedef struct {
    uint8_t frame_num;
    uint8_t lang;
    uint8_t menu_num;
} cmd_set_bellapps_t;

esp_err_t message_parse_cmd(uint8_t *data, size_t len, uint8_t *req_cmd, uint8_t *ack_num);

void message_register_handle();

void process_screen(uint8_t type, uint8_t number, bool lang);

#endif // MESSAG_H
