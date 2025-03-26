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



void setup_scr_screen_mm_1(lv_ui *ui)
{
    //Write codes screen_mm_1
    ui->screen_mm_1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_mm_1, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_mm_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_mm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mm_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mm_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mm_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_label_passwd_title
    ui->screen_mm_1_label_passwd_title = lv_label_create(ui->screen_mm_1);
    lv_obj_set_pos(ui->screen_mm_1_label_passwd_title, 248, 128);
    lv_obj_set_size(ui->screen_mm_1_label_passwd_title, 330, 51);
    lv_label_set_text(ui->screen_mm_1_label_passwd_title, "Your modem password:\n\n");
    lv_label_set_long_mode(ui->screen_mm_1_label_passwd_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_mm_1_label_passwd_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mm_1_label_passwd_title, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mm_1_label_passwd_title, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mm_1_label_passwd_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mm_1_label_passwd_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_label_passwd_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_label_passwd
    ui->screen_mm_1_label_passwd = lv_label_create(ui->screen_mm_1);
    lv_obj_set_pos(ui->screen_mm_1_label_passwd, 248, 195);
    lv_obj_set_size(ui->screen_mm_1_label_passwd, 422, 43);
    lv_label_set_text(ui->screen_mm_1_label_passwd, "[password]\n");
    lv_label_set_long_mode(ui->screen_mm_1_label_passwd, LV_LABEL_LONG_WRAP);

    //Write style for screen_mm_1_label_passwd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mm_1_label_passwd, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mm_1_label_passwd, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mm_1_label_passwd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mm_1_label_passwd, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_label_passwd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_label_scan
    ui->screen_mm_1_label_scan = lv_label_create(ui->screen_mm_1);
    lv_obj_set_pos(ui->screen_mm_1_label_scan, 248, 253);
    lv_obj_set_size(ui->screen_mm_1_label_scan, 276, 94);
    lv_label_set_text(ui->screen_mm_1_label_scan, "Scan QR code to \naccess your modem");
    lv_label_set_long_mode(ui->screen_mm_1_label_scan, LV_LABEL_LONG_WRAP);

    //Write style for screen_mm_1_label_scan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mm_1_label_scan, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mm_1_label_scan, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mm_1_label_scan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mm_1_label_scan, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_label_scan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_qrcode_passwd
    ui->screen_mm_1_qrcode_passwd = lv_qrcode_create(ui->screen_mm_1);
    lv_obj_set_pos(ui->screen_mm_1_qrcode_passwd, 38, 128);
    lv_obj_set_size(ui->screen_mm_1_qrcode_passwd, 172, 172);
    lv_qrcode_set_size(ui->screen_mm_1_qrcode_passwd, 172);
    lv_qrcode_set_dark_color(ui->screen_mm_1_qrcode_passwd, lv_color_hex(0x2C3224));
    lv_qrcode_set_light_color(ui->screen_mm_1_qrcode_passwd, lv_color_hex(0xffffff));
    const char * screen_mm_1_qrcode_passwd_data = "https://www.nxp.com/";
    lv_qrcode_update(ui->screen_mm_1_qrcode_passwd, screen_mm_1_qrcode_passwd_data, 20);

    //Write codes screen_mm_1_cont_title
    ui->screen_mm_1_cont_title = lv_obj_create(ui->screen_mm_1);
    lv_obj_set_pos(ui->screen_mm_1_cont_title, 0, 0);
    lv_obj_set_size(ui->screen_mm_1_cont_title, 960, 120);
    lv_obj_set_scrollbar_mode(ui->screen_mm_1_cont_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_mm_1_cont_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mm_1_cont_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mm_1_cont_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mm_1_cont_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_label_1
    ui->screen_mm_1_label_1 = lv_label_create(ui->screen_mm_1_cont_title);
    lv_obj_set_pos(ui->screen_mm_1_label_1, 30, 52);
    lv_obj_set_size(ui->screen_mm_1_label_1, 510, 55);
    lv_label_set_text(ui->screen_mm_1_label_1, "Modem management\n\n\n");
    lv_label_set_long_mode(ui->screen_mm_1_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_mm_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mm_1_label_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mm_1_label_1, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mm_1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mm_1_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_line_4
    ui->screen_mm_1_line_4 = lv_line_create(ui->screen_mm_1_cont_title);
    lv_obj_set_pos(ui->screen_mm_1_line_4, 37, 112);
    lv_obj_set_size(ui->screen_mm_1_line_4, 864, 5);
    static lv_point_precise_t screen_mm_1_line_4[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_mm_1_line_4, screen_mm_1_line_4, 2);

    //Write style for screen_mm_1_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_mm_1_line_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_mm_1_line_4, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_mm_1_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_mm_1_line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_btn_3
    ui->screen_mm_1_btn_3 = lv_button_create(ui->screen_mm_1_cont_title);
    lv_obj_set_pos(ui->screen_mm_1_btn_3, 688, 45);
    lv_obj_set_size(ui->screen_mm_1_btn_3, 218, 45);
    ui->screen_mm_1_btn_3_label = lv_label_create(ui->screen_mm_1_btn_3);
    lv_label_set_text(ui->screen_mm_1_btn_3_label, "Back to menu");
    lv_label_set_long_mode(ui->screen_mm_1_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_mm_1_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_mm_1_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_mm_1_btn_3_label, LV_PCT(100));

    //Write style for screen_mm_1_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mm_1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mm_1_btn_3, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mm_1_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mm_1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mm_1_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mm_1_btn_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mm_1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mm_1_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mm_1_btn_2
    ui->screen_mm_1_btn_2 = lv_button_create(ui->screen_mm_1_cont_title);
    lv_obj_set_pos(ui->screen_mm_1_btn_2, 425, 10);
    lv_obj_set_size(ui->screen_mm_1_btn_2, 100, 50);
    ui->screen_mm_1_btn_2_label = lv_label_create(ui->screen_mm_1_btn_2);
    lv_label_set_text(ui->screen_mm_1_btn_2_label, "next");
    lv_label_set_long_mode(ui->screen_mm_1_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_mm_1_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_mm_1_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_mm_1_btn_2_label, LV_PCT(100));

    //Write style for screen_mm_1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mm_1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mm_1_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mm_1_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mm_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mm_1_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mm_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mm_1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mm_1_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mm_1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mm_1_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_mm_1.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_mm_1);

    //Init events for screen.
    events_init_screen_mm_1(ui);
}
