/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_network(lv_ui *ui)
{
    //Write codes screen_network
    ui->screen_network = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_network, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_network, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_network, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_network, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_network, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_network, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_network_label_ssid_title
    ui->screen_network_label_ssid_title = lv_label_create(ui->screen_network);
    lv_obj_set_pos(ui->screen_network_label_ssid_title, 49, 138);
    lv_obj_set_size(ui->screen_network_label_ssid_title, 291, 43);
    lv_label_set_text(ui->screen_network_label_ssid_title, "Network [SSID]:\n\n");
    lv_label_set_long_mode(ui->screen_network_label_ssid_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_network_label_ssid_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_network_label_ssid_title, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_network_label_ssid_title, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_network_label_ssid_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_network_label_ssid_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_network_label_ssid_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_network_label_var1_tex
    ui->screen_network_label_var1_tex = lv_label_create(ui->screen_network);
    lv_obj_set_pos(ui->screen_network_label_var1_tex, 49, 184);
    lv_obj_set_size(ui->screen_network_label_var1_tex, 422, 43);
    lv_label_set_text(ui->screen_network_label_var1_tex, "[SSID]\n");
    lv_label_set_long_mode(ui->screen_network_label_var1_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_network_label_var1_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_network_label_var1_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_network_label_var1_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_network_label_var1_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_network_label_var1_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_network_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_network_label_passwd_title
    ui->screen_network_label_passwd_title = lv_label_create(ui->screen_network);
    lv_obj_set_pos(ui->screen_network_label_passwd_title, 49, 236);
    lv_obj_set_size(ui->screen_network_label_passwd_title, 205, 43);
    lv_label_set_text(ui->screen_network_label_passwd_title, "Passwords:\n\n\n");
    lv_label_set_long_mode(ui->screen_network_label_passwd_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_network_label_passwd_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_network_label_passwd_title, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_network_label_passwd_title, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_network_label_passwd_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_network_label_passwd_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_network_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_network_label_var2_tex
    ui->screen_network_label_var2_tex = lv_label_create(ui->screen_network);
    lv_obj_set_pos(ui->screen_network_label_var2_tex, 49, 282);
    lv_obj_set_size(ui->screen_network_label_var2_tex, 436, 43);
    lv_label_set_text(ui->screen_network_label_var2_tex, "[password]\n");
    lv_label_set_long_mode(ui->screen_network_label_var2_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_network_label_var2_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_network_label_var2_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_network_label_var2_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_network_label_var2_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_network_label_var2_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_network_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_network_label_tips
    ui->screen_network_label_tips = lv_label_create(ui->screen_network);
    lv_obj_set_pos(ui->screen_network_label_tips, 529, 255);
    lv_obj_set_size(ui->screen_network_label_tips, 190, 60);
    lv_label_set_text(ui->screen_network_label_tips, "Scan to connect wifi");
    lv_label_set_long_mode(ui->screen_network_label_tips, LV_LABEL_LONG_WRAP);

    //Write style for screen_network_label_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_network_label_tips, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_network_label_tips, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_network_label_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_network_label_tips, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_network_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_network_qrcode_url
    ui->screen_network_qrcode_url = lv_qrcode_create(ui->screen_network);
    lv_obj_set_pos(ui->screen_network_qrcode_url, 754, 138);
    lv_obj_set_size(ui->screen_network_qrcode_url, 172, 172);
    lv_qrcode_set_size(ui->screen_network_qrcode_url, 172);
    lv_qrcode_set_dark_color(ui->screen_network_qrcode_url, lv_color_hex(0x2C3224));
    lv_qrcode_set_light_color(ui->screen_network_qrcode_url, lv_color_hex(0xffffff));
    const char * screen_network_qrcode_url_data = "https://www.nxp.com/";
    lv_qrcode_update(ui->screen_network_qrcode_url, screen_network_qrcode_url_data, 20);

    //The custom code of screen_network.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_network);

    //Init events for screen.
    events_init_screen_network(ui);
}
