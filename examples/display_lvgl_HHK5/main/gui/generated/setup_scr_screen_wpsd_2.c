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



void setup_scr_screen_wpsd_2(lv_ui *ui)
{
    //Write codes screen_wpsd_2
    ui->screen_wpsd_2 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_wpsd_2, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_wpsd_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_wpsd_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wpsd_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wpsd_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_label_title
    ui->screen_wpsd_2_label_title = lv_label_create(ui->screen_wpsd_2);
    lv_obj_set_pos(ui->screen_wpsd_2_label_title, 38, 166);
    lv_obj_set_size(ui->screen_wpsd_2_label_title, 330, 51);
    lv_label_set_text(ui->screen_wpsd_2_label_title, "Connected:\n\n");
    lv_label_set_long_mode(ui->screen_wpsd_2_label_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_wpsd_2_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_label_title, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_label_title, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_label_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_label_device_name
    ui->screen_wpsd_2_label_device_name = lv_label_create(ui->screen_wpsd_2);
    lv_obj_set_pos(ui->screen_wpsd_2_label_device_name, 38, 228);
    lv_obj_set_size(ui->screen_wpsd_2_label_device_name, 422, 43);
    lv_label_set_text(ui->screen_wpsd_2_label_device_name, "[Device name]\n");
    lv_label_set_long_mode(ui->screen_wpsd_2_label_device_name, LV_LABEL_LONG_WRAP);

    //Write style for screen_wpsd_2_label_device_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_label_device_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_label_device_name, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_label_device_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_label_device_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_label_device_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_cont_title
    ui->screen_wpsd_2_cont_title = lv_obj_create(ui->screen_wpsd_2);
    lv_obj_set_pos(ui->screen_wpsd_2_cont_title, 0, 1);
    lv_obj_set_size(ui->screen_wpsd_2_cont_title, 960, 120);
    lv_obj_set_scrollbar_mode(ui->screen_wpsd_2_cont_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_wpsd_2_cont_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_cont_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wpsd_2_cont_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wpsd_2_cont_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_label_2
    ui->screen_wpsd_2_label_2 = lv_label_create(ui->screen_wpsd_2_cont_title);
    lv_obj_set_pos(ui->screen_wpsd_2_label_2, 30, 52);
    lv_obj_set_size(ui->screen_wpsd_2_label_2, 602, 55);
    lv_label_set_text(ui->screen_wpsd_2_label_2, "Connenct Wi-Fi device (WPS)\n\n\n");
    lv_label_set_long_mode(ui->screen_wpsd_2_label_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_wpsd_2_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_label_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_label_2, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_line_5
    ui->screen_wpsd_2_line_5 = lv_line_create(ui->screen_wpsd_2_cont_title);
    lv_obj_set_pos(ui->screen_wpsd_2_line_5, 37, 112);
    lv_obj_set_size(ui->screen_wpsd_2_line_5, 864, 5);
    static lv_point_precise_t screen_wpsd_2_line_5[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_wpsd_2_line_5, screen_wpsd_2_line_5, 2);

    //Write style for screen_wpsd_2_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_wpsd_2_line_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_wpsd_2_line_5, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_wpsd_2_line_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_wpsd_2_line_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_btn_5
    ui->screen_wpsd_2_btn_5 = lv_button_create(ui->screen_wpsd_2_cont_title);
    lv_obj_set_pos(ui->screen_wpsd_2_btn_5, 688, 45);
    lv_obj_set_size(ui->screen_wpsd_2_btn_5, 218, 45);
    ui->screen_wpsd_2_btn_5_label = lv_label_create(ui->screen_wpsd_2_btn_5);
    lv_label_set_text(ui->screen_wpsd_2_btn_5_label, "Press ok to cancel");
    lv_label_set_long_mode(ui->screen_wpsd_2_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_wpsd_2_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_wpsd_2_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_wpsd_2_btn_5_label, LV_PCT(100));

    //Write style for screen_wpsd_2_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wpsd_2_btn_5, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wpsd_2_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wpsd_2_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_btn_5, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_btn_4
    ui->screen_wpsd_2_btn_4 = lv_button_create(ui->screen_wpsd_2_cont_title);
    lv_obj_set_pos(ui->screen_wpsd_2_btn_4, 425, 10);
    lv_obj_set_size(ui->screen_wpsd_2_btn_4, 100, 50);
    ui->screen_wpsd_2_btn_4_label = lv_label_create(ui->screen_wpsd_2_btn_4);
    lv_label_set_text(ui->screen_wpsd_2_btn_4_label, "next");
    lv_label_set_long_mode(ui->screen_wpsd_2_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_wpsd_2_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_wpsd_2_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_wpsd_2_btn_4_label, LV_PCT(100));

    //Write style for screen_wpsd_2_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wpsd_2_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wpsd_2_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wpsd_2_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_wpsd_2.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_wpsd_2);

    //Init events for screen.
    events_init_screen_wpsd_2(ui);
}
