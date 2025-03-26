#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include "bsp/esp-bsp.h"
#include "gui_guider.h"
#include "custom.h"
#include "message.h"

static const char *TAG = "message";

typedef void (*cmd_set_list_handler_t)(cmd_set_list_t *cmd);
typedef void (*cmd_set_menu_handler_t)(cmd_set_menu_t *cmd);
typedef void (*cmd_set_screen_handler_t)(cmd_set_screen_t *cmd);
typedef void (*cmd_set_notif_handler_t)(cmd_set_notif_t *cmd);
typedef void (*cmd_set_config_handler_t)(cmd_set_config_t *cmd);
typedef void (*cmd_set_error_handler_t)(cmd_set_error_t *cmd);
typedef void (*cmd_set_apps_handler_t)(cmd_set_apps_t *cmd);
typedef void (*cmd_set_bellapps_handler_t)(cmd_set_bellapps_t *cmd);

typedef void (*screen_type_handler)(bool lang);

typedef struct {
    uint8_t screen_type;
    uint8_t screen_number;
    screen_type_handler handler;
} screen_type_mapping_t;

static cmd_set_list_handler_t cmd_set_list_handler = NULL;
static cmd_set_menu_handler_t cmd_set_menu_handler = NULL;
static cmd_set_screen_handler_t cmd_set_screen_handler = NULL;
static cmd_set_notif_handler_t cmd_set_notif_handler = NULL;
static cmd_set_config_handler_t cmd_set_config_handler = NULL;
static cmd_set_error_handler_t cmd_set_error_handler = NULL;
static cmd_set_apps_handler_t cmd_set_apps_handler = NULL;
static cmd_set_bellapps_handler_t cmd_set_bellapps_handler = NULL;

extern lv_obj_t * cont_main_loop;
extern lv_obj_t * cont_bellapps;

const char *lang_pick(const char *en_text, const char *fr_text, bool lang)
{
    return lang ? fr_text : en_text;
}

void register_cmd_set_list_handler(cmd_set_list_handler_t handler)
{
    cmd_set_list_handler = handler;
}

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

void cmd_set_list(cmd_set_list_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_LIST, frame:%d, lang:%d, menu list msb:%0X, menu list lsb:%0X",
             cmd->frame_num, cmd->lang, cmd->menu_list_msb, cmd->menu_list_lsb);
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_main_loop);

    uint16_t menu_list = 0;
    menu_list |= cmd->menu_list_msb;
    menu_list <<= 8;
    menu_list |= cmd->menu_list_lsb;
    uint8_t count = lv_obj_get_child_count(cont_main_loop);

    for (int i = 0; i < 16; i++) {
        if ((i < count + 1) && (i != 0)) {

            lv_obj_t *child_btn = lv_obj_get_child(cont_main_loop, i - 1);
            lv_obj_t *child_label = lv_obj_get_child(child_btn, 1);
            if (menu_list & (1 << i)) {
                ESP_LOGI(TAG, "Show menu %d, %s", i, lv_label_get_text(child_label));
                lv_obj_clear_flag(child_btn, LV_OBJ_FLAG_HIDDEN);
                if (cmd->lang == LANG_ENGLISH) {
                    lv_label_set_text(child_label, items_main_loop[i][0]);
                } else {
                    lv_label_set_text(child_label, items_main_loop[i][1]);
                }
            } else {
                ESP_LOGI(TAG, "Hide menu %d, %s", i, lv_label_get_text(child_label));
                lv_obj_add_flag(child_btn, LV_OBJ_FLAG_HIDDEN);
            }
        }
    }

    lv_obj_scroll_to_view(lv_obj_get_child(cont_main_loop, 0), LV_ANIM_OFF);

    bsp_display_unlock();
}

void cmd_set_menu(cmd_set_menu_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_MENU, frame:%d, lang:%d, menu num:%d", cmd->frame_num, cmd->lang, cmd->menu_num);
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_main_loop);
    lv_obj_scroll_to_view(lv_obj_get_child(cont_main_loop, cmd->menu_num), LV_ANIM_ON);

    bsp_display_unlock();
}

void cmd_set_screen(cmd_set_screen_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_SCREEN, frame:%d, lang:%d, screen type:%d, screen num:%d",
             cmd->frame_num, cmd->lang, cmd->scren_type, cmd->scren_num);

    process_screen(cmd->scren_type, cmd->scren_num, cmd->lang);
}

void cmd_set_notif(cmd_set_notif_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_NOTIF, frame:%d, notif type:%d, menu:%d, title:%.*s, text:%.*s",
             cmd->frame_num, cmd->notif_type, cmd->menu_indication, cmd->title_len, cmd->title, cmd->text_len, cmd->text);

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_notif);
    lv_label_set_text(guider_ui.screen_notif_label_1, cmd->title);
    lv_label_set_text(guider_ui.screen_notif_label_notify_info, cmd->text);
    if (cmd->notif_type == 1) {
        lv_image_set_src(guider_ui.screen_notif_img_notif_type, &_error_RGB565A8_29x35);
    } else if (cmd->notif_type == 0) {
        lv_image_set_src(guider_ui.screen_notif_img_notif_type, &_icon_ok_RGB565A8_29x35);
    }

    if (cmd->menu_indication == 1) {
        lv_obj_clear_flag(guider_ui.screen_notif_btn_3, LV_OBJ_FLAG_HIDDEN);
    } else if (cmd->menu_indication == 0) {
        lv_obj_add_flag(guider_ui.screen_notif_btn_3, LV_OBJ_FLAG_HIDDEN);
    }

    bsp_display_unlock();
}

void cmd_set_config(cmd_set_config_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_CONFIG, frame:%d, config type:%d, menu:%d, title:%.*s, text:%.*s, url:%.*s",
             cmd->frame_num, cmd->config_type, cmd->menu_indication, cmd->title_len, cmd->title, cmd->text_len, cmd->text, cmd->url_len, cmd->url);

    bsp_display_lock(0);

    switch (cmd->config_type) {
    case CONFIG_TYPE_WIFI_NETWORK:
        lv_screen_load(guider_ui.screen_network);
        lv_label_set_text(guider_ui.screen_network_label_title, cmd->title);
        lv_label_set_text(guider_ui.screen_network_label_ssid, cmd->text);
        // lv_label_set_text(guider_ui.screen_network_label_passwd, cmd->title);
        lv_qrcode_update(guider_ui.screen_network_qrcode_wifi, cmd->url, 20);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_network_btn_back, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_network_btn_back, LV_OBJ_FLAG_HIDDEN);
        }

        break;
    case CONFIG_TYPE_DATA_CLIENT_PAIRING:
        lv_screen_load(guider_ui.screen_wpsd_2);
        lv_label_set_text(guider_ui.screen_wpsd_2_label_2, cmd->title);
        lv_label_set_text(guider_ui.screen_wpsd_2_label_device_name, cmd->text);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_wpsd_2_btn_5, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_wpsd_2_btn_5, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case CONFIG_TYPE_SPEED_TEST:
        lv_screen_load(guider_ui.screen_speedtest);
        lv_label_set_text(guider_ui.screen_speedtest_label_1, cmd->title);
        lv_label_set_text(guider_ui.screen_speedtest_label_down_spd, cmd->text);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_speedtest_btn_3, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_speedtest_btn_3, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case CONFIG_TYPE_MODEM_PASSWORD:
        lv_screen_load(guider_ui.screen_mm_1);
        lv_label_set_text(guider_ui.screen_mm_1_label_1, cmd->title);
        lv_label_set_text(guider_ui.screen_mm_1_label_passwd, cmd->text);
        lv_qrcode_update(guider_ui.screen_mm_1_qrcode_passwd, cmd->url, 20);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_mm_1_btn_3, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_mm_1_btn_3, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    default:
        ESP_LOGW(TAG, "Unknown config type");
        break;
    }

    bsp_display_unlock();
}

void cmd_set_error(cmd_set_error_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_ERROR, frame:%d, error num:%d, error len:%d, label:%s, text:%s, url:%s",
             cmd->frame_num, cmd->error_num, cmd->error_len, cmd->label, cmd->text, cmd->url);

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_error);
    lv_label_set_text_fmt(guider_ui.screen_error_label_info_1, "Error %02d - %s\n\n", cmd->error_num, cmd->label);
    lv_label_set_text(guider_ui.screen_error_label_info_2, cmd->text);
    lv_qrcode_update(guider_ui.screen_error_qrcode_error, cmd->url, 20);

    bsp_display_unlock();
}

void cmd_set_apps(cmd_set_apps_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_APPS, frame:%d, lang:%d, screen num:%d, text len:%d, text:%.*s, url len:%d, url:%.*s",
             cmd->frame_num, cmd->lang, cmd->screen_num, cmd->text_len, cmd->text_len, cmd->text, cmd->url_len, cmd->url_len, cmd->url);

    bsp_display_lock(0);

    lv_label_set_text(guider_ui.screen_app_detail_btn_back_label,
                      lang_pick("Back to apps", "Retour aux applications", cmd->lang));
    lv_label_set_text(guider_ui.screen_app_detail_label_3,
                      lang_pick("Bell Apps\n\n\n", "Applications Bell\n\n\n", cmd->lang));

    switch (cmd->screen_num) {
    case 1:
        lv_image_set_src(guider_ui.screen_app_detail_img_2, &_icon_app_RGB565A8_109x71);
        lv_label_set_text(guider_ui.screen_app_detail_label_passwd,
                          lang_pick("Wi-Fi App\n", "Application Wi-Fi\n", cmd->lang));
        break;
    case 2:
        lv_image_set_src(guider_ui.screen_app_detail_img_2, &_icon_app_RGB565A8_109x71);
        lv_label_set_text(guider_ui.screen_app_detail_label_passwd,
                          lang_pick("Fibe TV app\n", "Application Fibe TV\n", cmd->lang));
        break;
    case 3:
        lv_image_set_src(guider_ui.screen_app_detail_img_2, &_icon_app_RGB565A8_109x71);
        lv_label_set_text(guider_ui.screen_app_detail_label_passwd,
                          lang_pick("Virtual repair tool\n", "Outil de réparation virtuelle\n", cmd->lang));
        break;
    default:
        ESP_LOGW(TAG, "Unknown screen number");
        break;
    }
    lv_screen_load(guider_ui.screen_app_detail);
    lv_label_set_text(guider_ui.screen_app_detail_label_passwd_title, cmd->text);
    lv_qrcode_update(guider_ui.screen_app_detail_qrcode_wifi, cmd->url, 20);

    bsp_display_unlock();
}

void cmd_set_bellapps(cmd_set_bellapps_t *cmd)
{
    ESP_LOGI(TAG, "CMD_SET_BELLAPPS, frame:%d, lang:%d, menu num:%d", cmd->frame_num, cmd->lang, cmd->menu_num);
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_apps);

    uint8_t count = lv_obj_get_child_count(cont_bellapps);
    for (int i = 0; i < count; i++) {
        lv_obj_t *child_btn = lv_obj_get_child(cont_bellapps, i);
        lv_obj_t *child_label = lv_obj_get_child(child_btn, 1);
        if (cmd->lang == LANG_ENGLISH) {
            lv_label_set_text(child_label, items_bell_apps[i][0]);
        } else {
            lv_label_set_text(child_label, items_bell_apps[i][1]);
        }
    }
    lv_obj_scroll_to_view(lv_obj_get_child(cont_bellapps, cmd->menu_num), LV_ANIM_ON);

    bsp_display_unlock();
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
        if (cmd_set_menu_handler && len >= 4) {
            cmd_set_list_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[LIST_LANG_INDEX];
            cmd.menu_list_msb = data[LIST_MENUS_MSB_INDEX];
            cmd.menu_list_lsb = data[LIST_MENUS_LSB_INDEX];
            cmd_set_list_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_LIST handler not registered or invalid data length");
        }
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
            cmd.menu_indication = data[NOTIF_MENU_INDEX];
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
            cmd.menu_indication = data[CONFIG_MENU_INDEX];
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
    register_cmd_set_list_handler(cmd_set_list);
    register_cmd_set_menu_handler(cmd_set_menu);
    register_cmd_set_screen_handler(cmd_set_screen);
    register_cmd_set_notif_handler(cmd_set_notif);
    register_cmd_set_config_handler(cmd_set_config);
    register_cmd_set_error_handler(cmd_set_error);
    register_cmd_set_apps_handler(cmd_set_apps);
    register_cmd_set_bellapps_handler(cmd_set_bellapps);
}

void handle_bu_welcome(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_welcome");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu0);
    bsp_display_unlock();
}

void handle_bu_loading(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_loading");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu1);
    bsp_display_unlock();
}

void handle_bu_bell(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_bell");
    bsp_display_lock(0);
    lv_screen_load(guider_ui.screen_bu2);
    bsp_display_unlock();
}

void handle_bu_connect_1(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_step1");

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_bu3);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step1, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step2, 0, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step3, 0, LV_ANIM_OFF);
    lv_label_set_text(guider_ui.screen_bu3_label_title_2,
                      lang_pick("Connecting to network\n\n",
                                "Connexion au réseau\n\n", lang));

    bsp_display_unlock();
}

void handle_bu_authenticating_2(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_step2");

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_bu3);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step1, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step2, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step3, 0, LV_ANIM_OFF);
    lv_label_set_text(guider_ui.screen_bu3_label_title_2,
                      lang_pick("Authenticating\n\n",
                                "Authentification\n\n", lang));

    bsp_display_unlock();
}

void handle_bu_configuring_3(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_step3");

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_bu3);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step1, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step2, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step3, 100, LV_ANIM_OFF);
    lv_label_set_text(guider_ui.screen_bu3_label_title_2,
                      lang_pick("Configuring services\n\n",
                                "Configuration des services\n\n", lang));

    bsp_display_unlock();
}

void handle_bu_authenticating_3(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_auth_step3");

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_bu3);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step1, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step2, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step3, 100, LV_ANIM_OFF);
    lv_label_set_text(guider_ui.screen_bu3_label_title_2,
                      lang_pick("Authenticating\n\n",
                                "Authentification\n\n", lang));

    bsp_display_unlock();
}

void handle_bu_configuring_services_3(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_config_step3");

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_bu3);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step1, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step2, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step3, 100, LV_ANIM_OFF);
    lv_label_set_text(guider_ui.screen_bu3_label_title_2,
                      lang_pick("Configuring services\n",
                                "Configuration des services\n", lang));

    bsp_display_unlock();
}

void handle_bu_configuring_wifi_3(bool lang)
{
    ESP_LOGI(TAG, "screen_num_bu_connecting_wifi_step3");

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_bu3);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step1, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step2, 100, LV_ANIM_OFF);
    lv_bar_set_value(guider_ui.screen_bu3_bar_step3, 100, LV_ANIM_OFF);
    lv_label_set_text(guider_ui.screen_bu3_label_title_2,
                      lang_pick("Configuring Wi-Fi\n",
                                "Configuration du Wi-Fi\n", lang));

    bsp_display_unlock();
}

void handle_fu_upgrading(bool lang)
{
    ESP_LOGI(TAG, "fu_upgrading");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_restart);
    lv_label_set_text(guider_ui.screen_restart_label_1,
                      lang_pick("Firmware Upgrade\n\n",
                                "Mise à niveau du firmware\n\n", lang));
    lv_label_set_text(guider_ui.screen_restart_label_loading,
                      lang_pick("Firmware upgrading\n\n",
                                "Mise à niveau du firmware\n\n", lang));

    bsp_display_unlock();
}

void handle_fu_restart(bool lang)
{
    ESP_LOGI(TAG, "fu_restart");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_restart);
    lv_label_set_text(guider_ui.screen_restart_label_1,
                      lang_pick("Firmware Upgrade\n\n",
                                "Mise à niveau du firmware\n\n", lang));
    lv_label_set_text(guider_ui.screen_restart_label_loading,
                      lang_pick("Modem will now restart\n\n",
                                "Le modem va maintenant redémarrer\n\n", lang));

    bsp_display_unlock();
}

void handle_stb_pairing(bool lang)
{
    ESP_LOGI(TAG, "stb_pairing");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_STB1);
    lv_label_set_text(guider_ui.screen_STB1_label_connect_to,
                      lang_pick("Connect a Fibe TV wireless receiver\n\n",
                                "Connectez un récepteur sans fil Fibe TV\n\n", lang));
    lv_label_set_text(guider_ui.screen_STB1_label_1,
                      lang_pick("Connect Fibe TV receiver",
                                "Connectez le récepteur Fibe TV", lang));
    lv_label_set_text(guider_ui.screen_STB1_btn_3_label,
                      lang_pick("Press Ok to cancel",
                                "Appuyez sur OK pour annuler", lang));

    bsp_display_unlock();
}

void handle_wpsd_pairing(bool lang)
{
    ESP_LOGI(TAG, "wpsd_pairing");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_STB1);
    lv_label_set_text(guider_ui.screen_STB1_label_connect_to,
                      lang_pick("Connect a Wi-Fi device using WPS\n\n",
                                "Connectez un appareil Wi-Fi en utilisant WPS\n\n", lang));
    lv_label_set_text(guider_ui.screen_STB1_label_1,
                      lang_pick("Connect Wi-Fi device (WPS)",
                                "Connectez l'appareil Wi-Fi (WPS)", lang));
    lv_label_set_text(guider_ui.screen_STB1_btn_3_label,
                      lang_pick("Press Ok to cancel",
                                "Appuyez sur OK pour annuler", lang));

    bsp_display_unlock();
}

void handle_factory_reset_select(bool lang)
{
    ESP_LOGI(TAG, "factory_reset_select");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_select);
    lv_label_set_text(guider_ui.screen_select_label_2,
                      lang_pick("Reset to factory default\n\n",
                                "Réinitialiser aux paramètres d'usine\n\n", lang));
    lv_label_set_text(guider_ui.screen_select_label_3,
                      lang_pick("Reset modem to factory default?\n\n",
                                "Réinitialiser le modem aux paramètres d'usine?\n\n", lang));
    lv_label_set_text(guider_ui.screen_select_btn_6_label,
                      lang_pick("No, keep my settings",
                                "Non, garder mes paramètres", lang));
    lv_label_set_text(guider_ui.screen_select_btn_7_label,
                      lang_pick("Yes, reset my settings",
                                "Oui, réinitialiser mes paramètres", lang));

    bsp_display_unlock();
}

void handle_factory_reset_confirm(bool lang)
{
    ESP_LOGI(TAG, "factory_reset_confirm");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_select);
    lv_label_set_text(guider_ui.screen_select_label_2,
                      lang_pick("Reset to factory default\n\n",
                                "Réinitialiser aux paramètres d'usine\n\n", lang));
    lv_label_set_text(guider_ui.screen_select_label_3,
                      lang_pick("Are you sure? All settings will be reset.\n\n",
                                "Êtes-vous sûr? Tous les paramètres seront réinitialisés.\n\n", lang));
    lv_label_set_text(guider_ui.screen_select_btn_6_label,
                      lang_pick("No, cancel",
                                "Non, annuler", lang));
    lv_label_set_text(guider_ui.screen_select_btn_7_label,
                      lang_pick("Yes, continue",
                                "Oui, continuer", lang));

    bsp_display_unlock();
}

void handle_factory_reset_restart(bool lang)
{
    ESP_LOGI(TAG, "factory_reset_restart");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_restart);
    lv_label_set_text(guider_ui.screen_restart_label_1,
                      lang_pick("Reset to factory default\n\n",
                                "Réinitialiser aux paramètres d'usine\n\n", lang));
    lv_label_set_text(guider_ui.screen_restart_label_loading,
                      lang_pick("Resetting modem to factory default.\nYour modem will now restart\n",
                                "Réinitialisation du modem aux paramètres d'usine.\nVotre modem va maintenant redémarrer\n", lang));

    bsp_display_unlock();
}

void handle_speed_test(bool lang)
{
    ESP_LOGI(TAG, "speed_test");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_speedtest);

    bsp_display_unlock();
}

void handle_restart_modem_confirm(bool lang)
{
    ESP_LOGI(TAG, "restart_modem_confirm");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_select);
    lv_label_set_text(guider_ui.screen_select_label_2,
                      lang_pick("Restart the modem\n\n",
                                "Redémarrer le modem\n\n", lang));
    lv_label_set_text(guider_ui.screen_select_label_3,
                      lang_pick("Do you want to restart the modem?\n\n",
                                "Voulez-vous redémarrer le modem?\n\n", lang));
    lv_label_set_text(guider_ui.screen_select_btn_6_label,
                      lang_pick("No",
                                "Non", lang));
    lv_label_set_text(guider_ui.screen_select_btn_7_label,
                      lang_pick("Yes",
                                "Oui", lang));

    bsp_display_unlock();
}

void handle_restart_modem_restart(bool lang)
{
    ESP_LOGI(TAG, "restart_modem_restart");
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_restart);
    lv_label_set_text(guider_ui.screen_restart_label_1,
                      lang_pick("Restart the modem\n\n",
                                "Redémarrer le modem\n\n", lang));
    lv_label_set_text(guider_ui.screen_restart_label_loading,
                      lang_pick("Modem will now restart\n\n",
                                "Le modem va maintenant redémarrer\n\n", lang));

    bsp_display_unlock();
}

static const screen_type_mapping_t cmd_set_screen_map[] = {
    // SCREEN_TYPE_BOOT
    { SCREEN_TYPE_BOOT, 0x00, handle_bu_welcome },
    { SCREEN_TYPE_BOOT, 0x01, handle_bu_loading },
    { SCREEN_TYPE_BOOT, 0x02, handle_bu_bell },
    { SCREEN_TYPE_BOOT, 0x03, handle_bu_connect_1 },
    { SCREEN_TYPE_BOOT, 0x04, handle_bu_authenticating_2 },
    { SCREEN_TYPE_BOOT, 0x05, handle_bu_configuring_3 },
    { SCREEN_TYPE_BOOT, 0x07, handle_bu_authenticating_3 },
    { SCREEN_TYPE_BOOT, 0x08, handle_bu_configuring_services_3 },
    { SCREEN_TYPE_BOOT, 0x11, handle_bu_configuring_wifi_3 },

    // SCREEN_TYPE_FIRMWARE_UPGRADE
    { SCREEN_TYPE_FIRMWARE_UPGRADE, 0x01, handle_fu_upgrading },
    { SCREEN_TYPE_FIRMWARE_UPGRADE, 0x02, handle_fu_restart },

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

void process_screen(uint8_t type, uint8_t number, bool lang)
{
    size_t map_size = sizeof(cmd_set_screen_map) / sizeof(screen_type_mapping_t);
    for (size_t i = 0; i < map_size; i++) {
        if (cmd_set_screen_map[i].screen_type == type && cmd_set_screen_map[i].screen_number == number) {
            if (cmd_set_screen_map[i].handler) {
                cmd_set_screen_map[i].handler(lang);
                return;
            }
        }
    }
    printf("No handler found for type: 0x%02X, number: 0x%02X\n", type, number);
}