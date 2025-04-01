/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include "bsp/esp-bsp.h"
#include "gui_guider.h"
#include "custom.h"
#include "message.h"

static const char *TAG = "message";

/**
 * @typedef cmd_set_handler_t
 * @brief Function pointer type for handling command set operations.
 * @param arg Pointer to arguments required by the handler.
 */
typedef void (*cmd_set_handler_t)(void *arg);

/**
 * @typedef screen_type_handler
 * @brief Function pointer type for handling screen type operations.
 * @param lang Boolean indicating the language setting (e.g., true for one language, false for another).
 */
typedef void (*screen_type_handler)(bool lang);

/**
 * @struct screen_type_mapping_t
 * @brief Structure for mapping screen types to their respective handlers.
 *
 * @var screen_type_mapping_t::screen_type
 * Screen type identifier (e.g., type of screen being handled).
 *
 * @var screen_type_mapping_t::screen_number
 * Screen number identifier (e.g., specific screen instance).
 *
 * @var screen_type_mapping_t::handler
 * Function pointer to the handler for the specified screen type.
 */
typedef struct {
    uint8_t screen_type;
    uint8_t screen_number;
    screen_type_handler handler;
} screen_type_mapping_t;

static cmd_set_handler_t cmd_set_reset_handler = NULL;
static cmd_set_handler_t cmd_set_bl_handler = NULL;
static cmd_set_handler_t cmd_set_list_handler = NULL;
static cmd_set_handler_t cmd_set_menu_handler = NULL;
static cmd_set_handler_t cmd_set_screen_handler = NULL;
static cmd_set_handler_t cmd_set_notif_handler = NULL;
static cmd_set_handler_t cmd_set_config_handler = NULL;
static cmd_set_handler_t cmd_set_error_handler = NULL;
static cmd_set_handler_t cmd_set_apps_handler = NULL;
static cmd_set_handler_t cmd_set_bellapps_handler = NULL;

extern lv_obj_t *cont_main_loop;
extern lv_obj_t *cont_bellapps;

const char *lang_pick(const char *en_text, const char *fr_text, bool lang)
{
    return lang ? fr_text : en_text;
}

void register_cmd_set_reset_handler(cmd_set_handler_t handler)
{
    cmd_set_reset_handler = handler;
}

void register_cmd_set_bl_handler(cmd_set_handler_t handler)
{
    cmd_set_bl_handler = handler;
}

void register_cmd_set_list_handler(cmd_set_handler_t handler)
{
    cmd_set_list_handler = handler;
}

void register_cmd_set_menu_handler(cmd_set_handler_t handler)
{
    cmd_set_menu_handler = handler;
}

void register_cmd_set_screen_handler(cmd_set_handler_t handler)
{
    cmd_set_screen_handler = handler;
}

void register_cmd_set_notif_handler(cmd_set_handler_t handler)
{
    cmd_set_notif_handler = handler;
}

void register_cmd_set_config_handler(cmd_set_handler_t handler)
{
    cmd_set_config_handler = handler;
}

void register_cmd_set_error_handler(cmd_set_handler_t handler)
{
    cmd_set_error_handler = handler;
}

void register_cmd_set_apps_handler(cmd_set_handler_t handler)
{
    cmd_set_apps_handler = handler;
}

void register_cmd_set_bellapps_handler(cmd_set_handler_t handler)
{
    cmd_set_bellapps_handler = handler;
}

void cmd_set_reset(void *arg)
{
    ESP_LOGI(TAG, "CMD_SET_RESET");
    esp_restart();
}

void cmd_set_bl(void *arg)
{
    cmd_set_bl_t *cmd = (cmd_set_bl_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_BL, state:%d, intensity:%d", cmd->state, cmd->intensity);
}

void cmd_set_list(void *arg)
{
    cmd_set_list_t *cmd = (void *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_LIST, frame:%d, lang:%d, menu list msb:%02X, menu list lsb:%02X",
             cmd->frame_num, cmd->lang, cmd->menu_list_msb, cmd->menu_list_lsb);
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_main_loop);

    uint16_t menu_mask = 0;
    menu_mask |= cmd->menu_list_msb;
    menu_mask <<= 8;
    menu_mask |= cmd->menu_list_lsb;
    ESP_LOGI(TAG, "menu_mask: %04X", menu_mask);
    add_main_loop_items(cont_main_loop, menu_mask, cmd->lang);

    bsp_display_unlock();
}

uint8_t get_bit_pos(uint16_t mask, uint8_t frame_num)
{
    uint8_t valid_cn = 0;
    for (uint8_t i = 0; i < 16; i++) {
        if ((i == frame_num) && (mask & (1 << i))) {
            return valid_cn;
        }

        if (mask & (1 << i)) {
            valid_cn++;
        }
    }
    return 0xFF;
}

void cmd_set_menu(void *arg)
{
    static int prev_menu_num = 0;
    cmd_set_menu_t *cmd = (cmd_set_menu_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_MENU, frame:%d, lang:%d, menu num:%d", cmd->frame_num, cmd->lang, cmd->menu_num);
    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_main_loop);

    add_main_loop_items(cont_main_loop, main_loop_cfg.loop_mask, cmd->lang);

    uint8_t count = lv_obj_get_child_count(cont_main_loop);
    int extra_items = 3;
    int total_items = (count - 6);

    ESP_LOGI(TAG, "Total items: %d, prev_menu_num:%d", total_items, prev_menu_num);
    ESP_LOGW(TAG, "Send menu:%d, index:%d", cmd->menu_num, get_bit_pos(main_loop_cfg.loop_mask, cmd->menu_num));

    if (cmd->menu_num && (cmd->menu_num <= MAX_MAIN_LOOP_ITEMS)) {
        uint8_t send_num = get_bit_pos(main_loop_cfg.loop_mask, cmd->menu_num);

        if (prev_menu_num == (total_items - 1) && (send_num == 0 || send_num == 1)) {
            send_num += total_items + extra_items;
        } else if (prev_menu_num == 0 && (send_num == (total_items - 2) || send_num == (total_items - 1))) {
            send_num -= total_items - extra_items;
        } else if (send_num < count) {
            prev_menu_num = send_num;
            send_num += extra_items;
        }

        if (send_num < count) {
            ESP_LOGI(TAG, "Send menu %d", send_num);
            lv_obj_scroll_to_view(lv_obj_get_child(cont_main_loop, send_num), LV_ANIM_ON);
        } else {
            ESP_LOGW(TAG, "Invalid menu number %d", cmd->menu_num);
        }
    } else {
        ESP_LOGW(TAG, "Invalid menu number %d", cmd->menu_num);
    }

    bsp_display_unlock();
}

void cmd_set_screen(void *arg)
{
    cmd_set_screen_t *cmd = (cmd_set_screen_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_SCREEN, frame:%d, lang:%d, screen type:%d, screen num:%d",
             cmd->frame_num, cmd->lang, cmd->scren_type, cmd->scren_num);

    process_screen(cmd->scren_type, cmd->scren_num, cmd->lang);
}

void cmd_set_notif(void *arg)
{
    cmd_set_notif_t *cmd = (cmd_set_notif_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_NOTIF, frame:%d, lang:%d, notif type:%d, menu_indication:%d, title:%.*s",
             cmd->frame_num, cmd->lang, cmd->notif_type, cmd->menu_indication, cmd->title_len, cmd->title);

    for (uint8_t i = 0; i < cmd->var_count; i++) {
        ESP_LOGI(TAG, "Variable %d(%d): %.*s", i, cmd->vars[i].len, cmd->vars[i].len, cmd->vars[i].text);
    }

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_notif);
    lv_label_set_text(guider_ui.screen_notif_label_title, cmd->title);
    lv_label_set_text(guider_ui.screen_notif_label_var1_tex, cmd->vars[0].text);

    if (cmd->notif_type == 1) {
        lv_image_set_src(guider_ui.screen_notif_img_notif_type, &_error_RGB565A8_29x35);
    } else if (cmd->notif_type == 0) {
        lv_image_set_src(guider_ui.screen_notif_img_notif_type, &_icon_ok_RGB565A8_29x35);
    }

    if (cmd->menu_indication == 1) {
        lv_obj_clear_flag(guider_ui.screen_notif_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
    } else if (cmd->menu_indication == 0) {
        lv_obj_add_flag(guider_ui.screen_notif_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
    }

    if (cmd->var_count > 1) {
        lv_obj_clear_flag(guider_ui.screen_notif_cont_labels, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(guider_ui.screen_notif_label_var2_tex, cmd->vars[1].text);
        lv_label_set_text(guider_ui.screen_notif_label_var3_tex, cmd->vars[2].text);
        lv_label_set_text(guider_ui.screen_notif_label_var4_tex, cmd->vars[3].text);
    } else {
        lv_obj_add_flag(guider_ui.screen_notif_cont_labels, LV_OBJ_FLAG_HIDDEN);
    }

    bsp_display_unlock();
}

void cmd_set_config(void *arg)
{
    cmd_set_config_t *cmd = (cmd_set_config_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_CONFIG, frame:%d, lang:%d, config type:%d, menu_indication:%d, title:%.*s, url:%.*s",
             cmd->frame_num, cmd->lang, cmd->config_type, cmd->menu_indication, cmd->title_len, cmd->title, cmd->url_len, cmd->url);

    for (uint8_t i = 0; i < cmd->var_count; i++) {
        ESP_LOGI(TAG, "Variable %d(%d): %.*s", i, cmd->vars[i].len, cmd->vars[i].len, cmd->vars[i].text);
    }

    bsp_display_lock(0);

    switch (cmd->config_type) {
    case CONFIG_TYPE_WIFI_NETWORK:
        lv_screen_load(guider_ui.screen_network);
        lv_label_set_text(guider_ui.screen_network_label_title, cmd->title);
        lv_label_set_text(guider_ui.screen_network_label_var1_tex, cmd->vars[0].text);
        lv_label_set_text(guider_ui.screen_network_label_var2_tex, cmd->vars[1].text);
        lv_qrcode_update(guider_ui.screen_network_qrcode_url, cmd->url, 20);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_network_btn_back, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_network_btn_back, LV_OBJ_FLAG_HIDDEN);
        }

        break;
    case CONFIG_TYPE_DATA_CLIENT_PAIRING:
        lv_screen_load(guider_ui.screen_wpsd_2);
        lv_label_set_text(guider_ui.screen_wpsd_2_label_title, cmd->title);
        lv_label_set_text(guider_ui.screen_wpsd_2_label_var1_tex, cmd->vars[0].text);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_wpsd_2_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_wpsd_2_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case CONFIG_TYPE_SPEED_TEST:
        lv_screen_load(guider_ui.screen_speedtest);
        lv_label_set_text(guider_ui.screen_speedtest_label_title, cmd->title);
        lv_label_set_text_fmt(guider_ui.screen_speedtest_label_var1_tex, "%s Mbps", cmd->vars[0].text);
        lv_label_set_text_fmt(guider_ui.screen_speedtest_label_var2_tex, "%s Mbps", cmd->vars[1].text);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_speedtest_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_speedtest_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case CONFIG_TYPE_MODEM_PASSWORD:
        lv_screen_load(guider_ui.screen_mm_1);
        lv_label_set_text(guider_ui.screen_mm_1_label_title, cmd->title);
        lv_label_set_text(guider_ui.screen_mm_1_label_var1_tex, cmd->vars[0].text);
        lv_qrcode_update(guider_ui.screen_mm_1_qrcode_passwd, cmd->url, 20);

        if (cmd->menu_indication == 1) {
            lv_obj_clear_flag(guider_ui.screen_mm_1_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
        } else if (cmd->menu_indication == 0) {
            lv_obj_add_flag(guider_ui.screen_mm_1_btn_back_indication, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    default:
        ESP_LOGW(TAG, "Unknown config type");
        break;
    }

    bsp_display_unlock();
}

void cmd_set_error(void *arg)
{
    cmd_set_error_t *cmd = (cmd_set_error_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_ERROR, frame:%d, lang:%d, error num:%d, error:%s, url:%s",
             cmd->frame_num, cmd->lang, cmd->error_num, cmd->label, cmd->url);

    for (uint8_t i = 0; i < cmd->var_count; i++) {
        ESP_LOGI(TAG, "Variable %d(%d): %.*s", i, cmd->vars[i].len, cmd->vars[i].len, cmd->vars[i].text);
    }

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_error);

    lv_label_set_text_fmt(guider_ui.screen_error_label_err_num, "Error %02d - %s\n\n", cmd->error_num, cmd->label);
    lv_label_set_text(guider_ui.screen_error_label_var1_tex, cmd->vars[0].text);
    lv_label_set_text(guider_ui.screen_error_label_var2_tex, cmd->vars[1].text);
    lv_qrcode_update(guider_ui.screen_error_qrcode_url, cmd->url, 20);

    bsp_display_unlock();
}

void cmd_set_apps(void *arg)
{
    cmd_set_apps_t *cmd = (cmd_set_apps_t *)arg;
    if (NULL == cmd) {
        return;
    }
    ESP_LOGI(TAG, "CMD_SET_APPS, frame:%d, lang:%d, screen num:%d, url len:%d, url:%.*s",
             cmd->frame_num, cmd->lang, cmd->screen_num, cmd->url_len, cmd->url_len, cmd->url);

    for (uint8_t i = 0; i < cmd->var_count; i++) {
        ESP_LOGI(TAG, "Variable %d(%d): %.*s", i, cmd->vars[i].len, cmd->vars[i].len, cmd->vars[i].text);
    }

    bsp_display_lock(0);

    lv_screen_load(guider_ui.screen_app_detail);
    // lv_label_set_text(guider_ui.screen_app_detail_btn_back_indication,
    //                   lang_pick("Back to apps", "Retour aux applications", cmd->lang));
    lv_label_set_text(guider_ui.screen_app_detail_label_title,
                      lang_pick("Bell Apps\n\n\n", "Applications Bell\n\n\n", cmd->lang));

    switch (cmd->screen_num) {
    case 1:
        lv_image_set_src(guider_ui.screen_app_detail_img_app_icon, &_icon_app_RGB565A8_109x71);
        lv_label_set_text(guider_ui.screen_app_detail_label_app_name,
                          lang_pick("Wi-Fi App\n", "Application Wi-Fi\n", cmd->lang));
        break;
    case 2:
        lv_image_set_src(guider_ui.screen_app_detail_img_app_icon, &_icon_app_RGB565A8_109x71);
        lv_label_set_text(guider_ui.screen_app_detail_label_app_name,
                          lang_pick("Fibe TV app\n", "Application Fibe TV\n", cmd->lang));
        break;
    case 3:
        lv_image_set_src(guider_ui.screen_app_detail_img_app_icon, &_icon_app_RGB565A8_109x71);
        lv_label_set_text(guider_ui.screen_app_detail_label_app_name,
                          lang_pick("Virtual repair tool\n", "Outil de réparation virtuelle\n", cmd->lang));
        break;
    default:
        ESP_LOGW(TAG, "Unknown screen number");
        break;
    }
    lv_label_set_text(guider_ui.screen_app_detail_label_var1_tex, cmd->vars[0].text);
    lv_label_set_text(guider_ui.screen_app_detail_label_var2_tex, cmd->vars[1].text);
    lv_qrcode_update(guider_ui.screen_app_detail_qrcode_url, cmd->url, 20);

    bsp_display_unlock();
}

void cmd_set_bellapps(void *arg)
{
    cmd_set_bellapps_t *cmd = (cmd_set_bellapps_t *)arg;
    if (NULL == cmd) {
        return;
    }
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

esp_err_t message_parse_cmd(uint8_t *data, size_t len, uint8_t *req_cmd, uint8_t *ack_num)
{
    if (len < 1) {
        ESP_LOGW(TAG, "Invalid command");
        return ESP_FAIL;
    }

    *req_cmd = 0;  // Initialize req_cmd to 0
    *ack_num = 0;  // Initialize ack_num to 0

    switch (data[CMD_TYPE_INDEX]) {
    // SYNCHRONIZATION
    case CMD_HELLO:
        ESP_LOGI(TAG, "CMD_HELLO");
        *req_cmd = CMD_HELLO;
        break;
    case CMD_GET_FW_VERSION:
        ESP_LOGI(TAG, "CMD_GET_FW_VERSION");
        *req_cmd = CMD_GET_FW_VERSION;
        break;
    case CMD_SET_RESET:
        if (cmd_set_reset_handler) {
            cmd_set_reset_handler(NULL);
        } else {
            ESP_LOGW(TAG, "CMD_SET_RESET handler not registered");
        }
        break;
    case CMD_SET_IMAGE:
        ESP_LOGI(TAG, "CMD_SET_IMAGE");
        break;
    case CMD_SEND_IMAGE:
        ESP_LOGI(TAG, "CMD_SEND_IMAGE");
        break;
    case CMD_SET_BACKLIGHT:
        if (cmd_set_bl_handler && len == 3) {
            cmd_set_bl_t cmd;
            cmd.state = data[BL_STATE_INDEX];
            cmd.intensity = data[BL_INTENSITY_INDEX];

            cmd_set_bl_handler(&cmd);
        } else {
            ESP_LOGW(TAG, "CMD_SET_BL handler not registered or invalid data length");
        }
        break;
    // COMMAND with acknowledgement
    case CMD_SET_LIST:
        if (cmd_set_list_handler && len == 5) {
            cmd_set_list_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[LIST_LANG_INDEX];
            cmd.menu_list_msb = data[LIST_MENUS_MSB_INDEX];
            cmd.menu_list_lsb = data[LIST_MENUS_LSB_INDEX];

            cmd_set_list_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_LIST handler not registered or invalid data length");
        }
        break;
    case CMD_SET_MENU:
        if (cmd_set_menu_handler && len == 4) {
            cmd_set_menu_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[MENU_LANG_INDEX];
            cmd.menu_num = data[MENU_NUM_INDEX];

            cmd_set_menu_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_MENU handler not registered or invalid data length");
        }
        break;
    case CMD_SET_SCREEN:
        if (cmd_set_screen_handler && len == 5) {
            cmd_set_screen_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[SCREEN_LANG_INDEX];
            cmd.scren_type = data[SCREEN_TYPE_INDEX];
            cmd.scren_num = data[SCREEN_NUM_INDEX];

            cmd_set_screen_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_SCREEN handler not registered or invalid data length");
        }
        break;
    case CMD_SET_NOTIF:
        if (cmd_set_notif_handler && len >= 4) {
            cmd_set_notif_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[NOTIF_LANG_INDEX];
            cmd.notif_type = data[NOTIF_TYPE_INDEX];
            cmd.menu_indication = data[NOTIF_MENU_INDEX];

            cmd.title_len = data[NOTIF_TITLE_LEN_IDX];
            if (cmd.title_len > 0 && NOTIF_TITLE_IDX + cmd.title_len <= len) {
                cmd.title = (const char *)&data[NOTIF_TITLE_IDX];
            } else {
                cmd.title = NULL;
                cmd.title_len = 0;
            }

            uint8_t offset = NOTIF_TITLE_IDX + cmd.title_len;
            cmd.var_count = 0;

            for (uint8_t i = 0; i < 4 && offset < len; i++) {
                cmd.vars[i].len = data[offset];
                if (offset + 1 + cmd.vars[i].len <= len) {
                    cmd.vars[i].text = (const char *)&data[offset + 1];
                    offset += 1 + cmd.vars[i].len;
                    cmd.var_count++;
                } else {
                    cmd.vars[i].len = 0;
                    cmd.vars[i].text = NULL;
                    break;
                }
            }

            cmd_set_notif_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_NOTIF handler not registered or invalid data length");
        }
        break;
    case CMD_SET_CONFIG:
        if (cmd_set_config_handler && len >= 6) {
            cmd_set_config_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[CONFIG_LANG_INDEX];
            cmd.config_type = data[CONFIG_TYPE_INDEX];
            cmd.menu_indication = data[CONFIG_MENU_INDEX];
            cmd.title_len = data[CONFIG_TITLE_LEN_IDX];
            cmd.title = (const char *) &data[CONFIG_TITLE_IDX];

            uint8_t url_len_idx = CONFIG_TITLE_IDX + cmd.title_len;
            cmd.url_len = data[url_len_idx];
            cmd.url = (const char *) &data[url_len_idx + 1];

            uint8_t offset = url_len_idx + 1 + cmd.url_len;
            cmd.var_count = 0;

            for (uint8_t i = 0; i < 4 && offset < len; i++) {
                cmd.vars[i].len = data[offset];
                if (offset + 1 + cmd.vars[i].len <= len) {
                    cmd.vars[i].text = (const char *)&data[offset + 1];
                    offset += 1 + cmd.vars[i].len;
                    cmd.var_count++;
                } else {
                    cmd.vars[i].len = 0;
                    cmd.vars[i].text = NULL;
                    break;
                }
            }
            cmd_set_config_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_CONFIG handler not registered or invalid data length");
        }
        break;
    case CMD_SET_ERROR:
        if (cmd_set_error_handler && len >= 8) {
            cmd_set_error_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[ERROR_LANG_INDEX];
            cmd.error_num = data[ERROR_NUM_INDEX];
            cmd.error_len = data[ERROR_LEN_INDEX];
            cmd.label = (const char *) &data[ERROR_LABEL_INDEX];

            uint8_t url_len_idx = ERROR_LABEL_INDEX + cmd.error_len;
            cmd.url_len = data[url_len_idx];
            cmd.url = (const char *) &data[url_len_idx + 1];

            uint8_t offset = url_len_idx + 1 + cmd.url_len;
            cmd.var_count = 0;

            for (uint8_t i = 0; i < 4 && offset < len; i++) {
                cmd.vars[i].len = data[offset];
                if (offset + 1 + cmd.vars[i].len <= len) {
                    cmd.vars[i].text = (const char *)&data[offset + 1];
                    offset += 1 + cmd.vars[i].len;
                    cmd.var_count++;
                } else {
                    cmd.vars[i].len = 0;
                    cmd.vars[i].text = NULL;
                    break;
                }
            }

            cmd_set_error_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_ERROR invalid data length");
        }
        break;
    case CMD_SET_BELLAPPS:
        if (cmd_set_bellapps_handler && len == 4) {
            cmd_set_bellapps_t cmd;
            cmd.frame_num = data[FRAME_INDEX];
            cmd.lang = data[BELLAPPS_LANG_INDEX];
            cmd.menu_num = data[BELLAPPS_MENU_INDEX];

            cmd_set_bellapps_handler(&cmd);
            *ack_num = cmd.frame_num;
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
            cmd.url_len = data[APPS_LABEL_LEN_INDEX];
            cmd.url = (const char *) &data[APPS_LABEL_LEN_INDEX + 1];

            uint8_t offset = APPS_LABEL_LEN_INDEX + 1 + cmd.url_len;
            cmd.var_count = 0;

            for (uint8_t i = 0; i < 4 && offset < len; i++) {
                cmd.vars[i].len = data[offset];
                if (offset + 1 + cmd.vars[i].len <= len) {
                    cmd.vars[i].text = (const char *)&data[offset + 1];
                    offset += 1 + cmd.vars[i].len;
                    cmd.var_count++;
                } else {
                    cmd.vars[i].len = 0;
                    cmd.vars[i].text = NULL;
                    break;
                }
            }

            cmd_set_apps_handler(&cmd);
            *ack_num = cmd.frame_num;
        } else {
            ESP_LOGW(TAG, "CMD_SET_APPS invalid data length");
        }
        break;
    case CMD_GET_STATUS:
        if (len == 1) {
            ESP_LOGI(TAG, "CMD_GET_STATUS");
            *req_cmd = CMD_GET_STATUS;
        } else {
            ESP_LOGW(TAG, "CMD_GET_STATUS invalid data length");
        }
        break;
    default:
        ESP_LOGW(TAG, "Unknown command:%02X", data[0]);
        return ESP_FAIL;
    }

    return ESP_OK;
}

void message_register_handle()
{
    register_cmd_set_reset_handler(cmd_set_reset);
    register_cmd_set_bl_handler(cmd_set_bl);
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
    lv_label_set_text(guider_ui.screen_restart_label_title,
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
    lv_label_set_text(guider_ui.screen_restart_label_title,
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
    lv_label_set_text(guider_ui.screen_restart_label_title,
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
    lv_label_set_text(guider_ui.screen_speedtest_label_var1_tex, "-- Mbps\n");
    lv_label_set_text(guider_ui.screen_speedtest_label_var2_tex, "-- Mbps");

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
    lv_label_set_text(guider_ui.screen_restart_label_title,
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
