#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include "bsp/esp-bsp.h"
#include "gui_guider.h"
#include "message.h"

static const char *TAG = "message";

typedef void (*cmd_set_menu_handler_t)(cmd_set_menu_t *cmd);
typedef void (*cmd_set_screen_handler_t)(cmd_set_screen_t *cmd);
typedef void (*cmd_set_notif_handler_t)(cmd_set_notif_t *cmd);
typedef void (*cmd_set_config_handler_t)(cmd_set_config_t *cmd);
typedef void (*cmd_set_error_handler_t)(cmd_set_error_t *cmd);
typedef void (*cmd_set_apps_handler_t)(cmd_set_apps_t *cmd);
typedef void (*cmd_set_bellapps_handler_t)(cmd_set_bellapps_t *cmd);

static cmd_set_menu_handler_t cmd_set_menu_handler = NULL;
static cmd_set_screen_handler_t cmd_set_screen_handler = NULL;
static cmd_set_notif_handler_t cmd_set_notif_handler = NULL;
static cmd_set_config_handler_t cmd_set_config_handler = NULL;
static cmd_set_error_handler_t cmd_set_error_handler = NULL;
static cmd_set_apps_handler_t cmd_set_apps_handler = NULL;
static cmd_set_bellapps_handler_t cmd_set_bellapps_handler = NULL;

extern lv_obj_t * cont_col;

void register_cmd_set_menu_handler(cmd_set_menu_handler_t handler)
{
    cmd_set_menu_handler = handler;
}

void register_cmd_set_screen_handler(cmd_set_screen_handler_t handler)
{
    cmd_set_screen_handler = handler;
}

void register_cmd_set_notif_handler(cmd_set_notif_handler_t handler)
{
    cmd_set_notif_handler = handler;
}

void register_cmd_set_config_handler(cmd_set_config_handler_t handler)
{
    cmd_set_config_handler = handler;
}

void register_cmd_set_error_handler(cmd_set_error_handler_t handler)
{
    cmd_set_error_handler = handler;
}

void register_cmd_set_apps_handler(cmd_set_apps_handler_t handler)
{
    cmd_set_apps_handler = handler;
}

void register_cmd_set_bellapps_handler(cmd_set_bellapps_handler_t handler)
{
    cmd_set_bellapps_handler = handler;
}

void cmd_set_menu(cmd_set_menu_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_MENU, frame:%d, lang:%d, menu num:%d", cmd->frame_num, cmd->lang, cmd->menu_num);

    bsp_display_lock(0);
    lv_obj_scroll_to_view(lv_obj_get_child(cont_col, cmd->frame_num), LV_ANIM_ON);
    bsp_display_unlock();
}

void cmd_set_screen(cmd_set_screen_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_SCREEN, frame:%d, lang:%d, screen type:%d, screen num:%d",
             cmd->frame_num, cmd->lang, cmd->scren_type, cmd->scren_num);
}

void cmd_set_notif(cmd_set_notif_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_NOTIF, frame:%d, notif type:%d, menu:%d, title:%.*s, text:%.*s",
             cmd->frame_num, cmd->notif_type, cmd->menu, cmd->title_len, cmd->title, cmd->text_len, cmd->text);
}

void cmd_set_config(cmd_set_config_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_CONFIG, frame:%d, config type:%d, menu:%d, title:%.*s, text:%.*s, url:%.*s",
             cmd->frame_num, cmd->config_type, cmd->menu, cmd->title_len, cmd->title, cmd->text_len, cmd->text, cmd->url_len, cmd->url);
}

void cmd_set_error(cmd_set_error_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_ERROR, frame:%d, error num:%d, error len:%d, label:%.*s, text:%.*s, url:%.*s",
             cmd->frame_num, cmd->error_num, cmd->error_len, cmd->label, cmd->text_len, cmd->text, cmd->url_len, cmd->url);
}

void cmd_set_apps(cmd_set_apps_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_APPS, frame:%d, lang:%d, screen num:%d, text len:%d, text:%.*s, url len:%d, url:%.*s",
             cmd->frame_num, cmd->lang, cmd->screen_num, cmd->text_len, cmd->text_len, cmd->text, cmd->url_len, cmd->url_len, cmd->url);
}

void cmd_set_bellapps(cmd_set_bellapps_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_BELLAPPS, frame:%d, lang:%d, menu num:%d", cmd->frame_num, cmd->lang, cmd->menu_num);
}

void message_parse_cmd(uint8_t *data, size_t len)
{
    if (len < 1) {
        ESP_LOGW(TAG, "Invalid command");
        return;
    }

    switch (data[CMD_TYPE_INDEX]) {
    case CMD_HELLO:
        ESP_LOGI(TAG, "CMD_HELLO");
        // context.command_data = CMD_HELLO;
        break;
    case CMD_GET_FW_VERSION:
        ESP_LOGI(TAG, "CMD_GET_FW_VERSION");
        // context.command_data = CMD_GET_FW_VERSION;
        break;
    case CMD_SET_RESET:
        ESP_LOGI(TAG, "CMD_SET_RESET");
        break;
    case CMD_SET_IMAGE:
        ESP_LOGI(TAG, "CMD_SET_IMAGE");
        break;
    case CMD_SEND_IMAGE:
        ESP_LOGI(TAG, "CMD_SEND_IMAGE");
        break;
    case CMD_SET_BACKLIGHT:
        ESP_LOGI(TAG, "CMD_SET_BACKLIGHT");
        break;
    case CMD_SET_LIST:
        ESP_LOGI(TAG, "CMD_SET_LIST");
        break;
    case CMD_SET_MENU:
        if (cmd_set_menu_handler && len >= 4) {
            cmd_set_menu_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[MENU_LANG_INDEX];
            cmd.menu_num = data[MENU_NUM_INDEX];
            cmd_set_menu_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_MENU handler not registered or invalid data length");
        }
        break;
    case CMD_SET_SCREEN:
        if (cmd_set_screen_handler && len >= 4) {
            cmd_set_screen_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[SCREEN_LANG_INDEX];
            cmd.scren_type = data[SCREEN_TYPE_INDEX];
            cmd.scren_num = data[SCREEN_NUM_INDEX];
            cmd_set_screen_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_MENU handler not registered or invalid data length");
        }
        break;
    case CMD_SET_NOTIF:
        if (cmd_set_notif_handler && len) {
            cmd_set_notif_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.notif_type = data[NOTIF_TYPE_INDEX];
            cmd.menu = data[NOTIF_MENU_INDEX];
            cmd.title_len = data[NOTIF_TITLE_LEN_IDX];
            cmd.title = (const char *) &data[NOTIF_TITLE_IDX];

            uint8_t text_len_idx = NOTIF_TITLE_IDX + cmd.title_len;
            cmd.text_len = data[text_len_idx];
            cmd.text = (const char *) &data[text_len_idx + 1];

            cmd_set_notif_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_NOTIF handler not registered or invalid data length");
        }
        break;
    case CMD_SET_CONFIG:
        if (cmd_set_config_handler && len) {
            cmd_set_config_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.config_type = data[CONFIG_TYPE_INDEX];
            cmd.menu = data[CONFIG_MENU_INDEX];
            cmd.title_len = data[CONFIG_TITLE_LEN_IDX];
            cmd.title = (const char *) &data[CONFIG_TITLE_IDX];

            uint8_t text_len_idx = CONFIG_TITLE_IDX + cmd.title_len;
            cmd.text_len = data[text_len_idx];
            cmd.text = (const char *) &data[text_len_idx + 1];

            uint8_t url_len_idx = text_len_idx + 1 + cmd.text_len;
            cmd.url_len = data[url_len_idx];
            cmd.url = (const char *) &data[url_len_idx + 1];

            cmd_set_config_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_CONFIG handler not registered or invalid data length");
        }
        break;
    case CMD_SET_ERROR:
        if (cmd_set_error_handler && len >= 8) {
            cmd_set_error_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.error_num = data[ERROR_NUM_INDEX];
            cmd.error_len = data[ERROR_LEN_INDEX];
            cmd.label = (const char *) &data[ERROR_LABEL_INDEX];

            uint8_t text_len_idx = ERROR_LABEL_INDEX + cmd.error_len;
            cmd.text_len = data[text_len_idx];
            cmd.text = (const char *) &data[text_len_idx + 1];

            uint8_t url_len_idx = text_len_idx + 1 + cmd.text_len;
            cmd.url_len = data[url_len_idx];
            cmd.url = (const char *) &data[url_len_idx + 1];

            cmd_set_error_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_ERROR invalid data length");
        }
        break;
    case CMD_SET_BELLAPPS:
        if (cmd_set_bellapps_handler && len >= 4) {
            cmd_set_bellapps_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[BELLAPPS_LANG_INDEX];
            cmd.menu_num = data[BELLAPPS_MENU_INDEX];
            cmd_set_bellapps_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_BELLAPPS invalid data length");
        }
        break;
    case CMD_SET_APPS:
        if (cmd_set_apps_handler && len >= 8) {
            cmd_set_apps_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[APPS_LANG_INDEX];
            cmd.screen_num = data[APPS_SCREEN_INDEX];
            cmd.text_len = data[APPS_LABEL_LEN_INDEX];
            cmd.text = (const char *) &data[APPS_LABEL_INDEX];

            uint8_t url_len_idx = APPS_LABEL_INDEX + cmd.text_len;
            cmd.url_len = data[url_len_idx];
            cmd.url = (const char *) &data[url_len_idx + 1];

            cmd_set_apps_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_APPS invalid data length");
        }
        break;
    default:
        ESP_LOGW(TAG, "Unknown command:%02X", data[0]);
        break;
    }
}

void message_register_handle()
{
    register_cmd_set_menu_handler(cmd_set_menu);
    register_cmd_set_screen_handler(cmd_set_screen);
    register_cmd_set_notif_handler(cmd_set_notif);
    register_cmd_set_config_handler(cmd_set_config);
    register_cmd_set_error_handler(cmd_set_error);
    register_cmd_set_apps_handler(cmd_set_apps);
    register_cmd_set_bellapps_handler(cmd_set_bellapps);
}

typedef void (*ScreenHandler)(void);

void handle_welcome()
{
    ESP_LOGI(TAG, "screen_num_bu_welcome");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu0);
    bsp_display_unlock();
}
void handle_loading()
{
    ESP_LOGI(TAG, "screen_num_bu_loading");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu1);
    bsp_display_unlock();
}
void handle_bell()
{
    ESP_LOGI(TAG, "screen_num_bu_bell");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu2);
    bsp_display_unlock();
}
void handle_connecting_step1()
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_step1");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu3);
    bsp_display_unlock();
}
void handle_connecting_step2()
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_step2");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu3);
    bsp_display_unlock();
}
void handle_connecting_step3()
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_step3");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu3);
    bsp_display_unlock();
}
void handle_connecting_auth_step3()
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_auth_step3");
}
void handle_connecting_config_step3()
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_config_step3");
}
void handle_connecting_wifi_step3()
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_wifi_step3");
}

void handle_upgrading()
{
    ESP_LOGI(TAG, "screen_num_fu_upgrading");
}
void handle_restart()
{
    printf("Handling SCREEN_NUM_FU_RESTART\n");
}

void handle_stb_pairing()
{
    printf("Handling SCREEN_NUM_STB\n");
}
void handle_wpsd_pairing()
{
    printf("Handling SCREEN_NUM_WPSD\n");
}

void handle_factory_reset_select()
{
    printf("Handling SCREEN_NUM_FR_SELECT\n");
}
void handle_factory_reset_confirm()
{
    printf("Handling SCREEN_NUM_FR_CONFIRM\n");
}
void handle_factory_reset_restart()
{
    printf("Handling SCREEN_NUM_FR_RESTART\n");
}

void handle_speed_test()
{
    printf("Handling SCREEN_NUM_ST_TESTING\n");
}

void handle_restart_modem_confirm()
{
    printf("Handling SCREEN_NUM_RBM_CONFIRM\n");
}
void handle_restart_modem_restart()
{
    printf("Handling SCREEN_NUM_RGB_RESTART\n");
}

typedef struct {
    uint8_t type;
    uint8_t number;
    ScreenHandler handler;
} ScreenMapping;

ScreenMapping screen_map[] = {
    // SCREEN_TYPE_BOOT
    { SCREEN_TYPE_BOOT, 0x00, handle_welcome },
    { SCREEN_TYPE_BOOT, 0x01, handle_loading },
    { SCREEN_TYPE_BOOT, 0x02, handle_bell },
    { SCREEN_TYPE_BOOT, 0x03, handle_connecting_step1 },
    { SCREEN_TYPE_BOOT, 0x04, handle_connecting_step2 },
    { SCREEN_TYPE_BOOT, 0x05, handle_connecting_step3 },
    { SCREEN_TYPE_BOOT, 0x07, handle_connecting_auth_step3 },
    { SCREEN_TYPE_BOOT, 0x08, handle_connecting_config_step3 },
    { SCREEN_TYPE_BOOT, 0x11, handle_connecting_wifi_step3 },

    // SCREEN_TYPE_FIRMWARE_UPGRADE
    { SCREEN_TYPE_FIRMWARE_UPGRADE, 0x01, handle_upgrading },
    { SCREEN_TYPE_FIRMWARE_UPGRADE, 0x02, handle_restart },

    // SCREEN_TYPE_WIRELESS_STB_PAIRING
    { SCREEN_TYPE_WIRELESS_STB_PAIRING, 0x01, handle_stb_pairing },

    // SCREEN_TYPE_DATA_CLIENT_PAIRING
    { SCREEN_TYPE_DATA_CLIENT_PAIRING, 0x01, handle_wpsd_pairing },

    // SCREEN_TYPE_FACTORY_RESET
    { SCREEN_TYPE_FACTORY_RESET, 0x01, handle_factory_reset_select },
    { SCREEN_TYPE_FACTORY_RESET, 0x02, handle_factory_reset_confirm },
    { SCREEN_TYPE_FACTORY_RESET, 0x03, handle_factory_reset_restart },

    // SCREEN_TYPE_SPEED_TEST
    { SCREEN_TYPE_SPEED_TEST, 0x01, handle_speed_test },

    // SCREEN_TYPE_RESTART_MODEM
    { SCREEN_TYPE_RESTART_MODEM, 0x01, handle_restart_modem_confirm },
    { SCREEN_TYPE_RESTART_MODEM, 0x02, handle_restart_modem_restart },
};

void process_screen(uint8_t type, uint8_t number)
{
    size_t map_size = sizeof(screen_map) / sizeof(ScreenMapping);
    for (size_t i = 0; i < map_size; i++) {
        if (screen_map[i].type == type && screen_map[i].number == number) {
            if (screen_map[i].handler) {
                screen_map[i].handler();
                return;
            }
        }
    }
    printf("No handler found for type: 0x%02X, number: 0x%02X\n", type, number);
}