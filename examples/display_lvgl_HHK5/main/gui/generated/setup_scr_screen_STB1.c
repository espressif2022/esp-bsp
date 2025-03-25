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



void setup_scr_screen_STB1(lv_ui *ui)
{
    //Write codes screen_STB1
    ui->screen_STB1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_STB1, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_STB1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_STB1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_STB1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_STB1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_STB1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_label_connect_to
    ui->screen_STB1_label_connect_to = lv_label_create(ui->screen_STB1);
    lv_obj_set_pos(ui->screen_STB1_label_connect_to, 39, 270);
    lv_obj_set_size(ui->screen_STB1_label_connect_to, 497, 43);
    lv_label_set_text(ui->screen_STB1_label_connect_to, "Connect a Fibe TVwireless receiver\n\n");
    lv_label_set_long_mode(ui->screen_STB1_label_connect_to, LV_LABEL_LONG_WRAP);

    //Write style for screen_STB1_label_connect_to, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_STB1_label_connect_to, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_STB1_label_connect_to, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_STB1_label_connect_to, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_STB1_label_connect_to, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_STB1_label_connect_to, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_label_time
    ui->screen_STB1_label_time = lv_label_create(ui->screen_STB1);
    lv_obj_set_pos(ui->screen_STB1_label_time, 42, 170);
    lv_obj_set_size(ui->screen_STB1_label_time, 156, 71);
    lv_label_set_text(ui->screen_STB1_label_time, "4:58\n");
    lv_label_set_long_mode(ui->screen_STB1_label_time, LV_LABEL_LONG_WRAP);

    //Write style for screen_STB1_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_STB1_label_time, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_STB1_label_time, &lv_font_montserratMedium_70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_STB1_label_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_STB1_label_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_STB1_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_cont_1
    ui->screen_STB1_cont_1 = lv_obj_create(ui->screen_STB1);
    lv_obj_set_pos(ui->screen_STB1_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_STB1_cont_1, 960, 120);
    lv_obj_set_scrollbar_mode(ui->screen_STB1_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_STB1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_STB1_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_STB1_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_STB1_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_STB1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_label_1
    ui->screen_STB1_label_1 = lv_label_create(ui->screen_STB1_cont_1);
    lv_obj_set_pos(ui->screen_STB1_label_1, 30, 52);
    lv_obj_set_size(ui->screen_STB1_label_1, 510, 43);
    lv_label_set_text(ui->screen_STB1_label_1, "Connect Fibe TV receiver");
    lv_label_set_long_mode(ui->screen_STB1_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_STB1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_STB1_label_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_STB1_label_1, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_STB1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_STB1_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_STB1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_line_1
    ui->screen_STB1_line_1 = lv_line_create(ui->screen_STB1_cont_1);
    lv_obj_set_pos(ui->screen_STB1_line_1, 37, 112);
    lv_obj_set_size(ui->screen_STB1_line_1, 864, 5);
    static lv_point_precise_t screen_STB1_line_1[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_STB1_line_1, screen_STB1_line_1, 2);

    //Write style for screen_STB1_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_STB1_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_STB1_line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_STB1_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_STB1_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_btn_3
    ui->screen_STB1_btn_3 = lv_button_create(ui->screen_STB1_cont_1);
    lv_obj_set_pos(ui->screen_STB1_btn_3, 688, 45);
    lv_obj_set_size(ui->screen_STB1_btn_3, 218, 45);
    ui->screen_STB1_btn_3_label = lv_label_create(ui->screen_STB1_btn_3);
    lv_label_set_text(ui->screen_STB1_btn_3_label, "Press Ok to cancel");
    lv_label_set_long_mode(ui->screen_STB1_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_STB1_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_STB1_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_STB1_btn_3_label, LV_PCT(100));

    //Write style for screen_STB1_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_STB1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_STB1_btn_3, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_STB1_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_STB1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_STB1_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_STB1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_STB1_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_STB1_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_STB1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_STB1_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_STB1_btn_2
    ui->screen_STB1_btn_2 = lv_button_create(ui->screen_STB1_cont_1);
    lv_obj_set_pos(ui->screen_STB1_btn_2, 425, 10);
    lv_obj_set_size(ui->screen_STB1_btn_2, 100, 50);
    ui->screen_STB1_btn_2_label = lv_label_create(ui->screen_STB1_btn_2);
    lv_label_set_text(ui->screen_STB1_btn_2_label, "next");
    lv_label_set_long_mode(ui->screen_STB1_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_STB1_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_STB1_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_STB1_btn_2_label, LV_PCT(100));

    //Write style for screen_STB1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_STB1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_STB1_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_STB1_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_STB1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_STB1_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_STB1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_STB1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_STB1_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_STB1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_STB1_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_STB1.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_STB1);

    //Init events for screen.
    events_init_screen_STB1(ui);
}
