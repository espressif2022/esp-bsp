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



void setup_scr_screen_bu3(lv_ui *ui)
{
    //Write codes screen_bu3
    ui->screen_bu3 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_bu3, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_bu3, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_bu3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_bu3_label_title_1
    ui->screen_bu3_label_title_1 = lv_label_create(ui->screen_bu3);
    lv_obj_set_pos(ui->screen_bu3_label_title_1, 67, 194);
    lv_obj_set_size(ui->screen_bu3_label_title_1, 384, 65);
    lv_label_set_text(ui->screen_bu3_label_title_1, "Connecting to Bell\n\n");
    lv_label_set_long_mode(ui->screen_bu3_label_title_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_bu3_label_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_bu3_label_title_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_bu3_label_title_1, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_bu3_label_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_bu3_label_title_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bu3_label_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_bu3_label_title_2
    ui->screen_bu3_label_title_2 = lv_label_create(ui->screen_bu3);
    lv_obj_set_pos(ui->screen_bu3_label_title_2, 67, 250);
    lv_obj_set_size(ui->screen_bu3_label_title_2, 273, 32);
    lv_label_set_text(ui->screen_bu3_label_title_2, "Configuring services\n\n");
    lv_label_set_long_mode(ui->screen_bu3_label_title_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_bu3_label_title_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_bu3_label_title_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_bu3_label_title_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_bu3_label_title_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_bu3_label_title_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bu3_label_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_bu3_bar_step1
    ui->screen_bu3_bar_step1 = lv_bar_create(ui->screen_bu3);
    lv_obj_set_pos(ui->screen_bu3_bar_step1, 67, 305);
    lv_obj_set_size(ui->screen_bu3_bar_step1, 216, 14);
    lv_obj_set_style_anim_duration(ui->screen_bu3_bar_step1, 1000, 0);
    lv_bar_set_mode(ui->screen_bu3_bar_step1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_bu3_bar_step1, 0, 100);
    lv_bar_set_value(ui->screen_bu3_bar_step1, 100, LV_ANIM_OFF);

    //Write style for screen_bu3_bar_step1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3_bar_step1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3_bar_step1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3_bar_step1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_bar_step1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bu3_bar_step1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_bu3_bar_step1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3_bar_step1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3_bar_step1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3_bar_step1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_bar_step1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_bu3_bar_step2
    ui->screen_bu3_bar_step2 = lv_bar_create(ui->screen_bu3);
    lv_obj_set_pos(ui->screen_bu3_bar_step2, 291, 305);
    lv_obj_set_size(ui->screen_bu3_bar_step2, 216, 14);
    lv_obj_set_style_anim_duration(ui->screen_bu3_bar_step2, 1000, 0);
    lv_bar_set_mode(ui->screen_bu3_bar_step2, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_bu3_bar_step2, 0, 100);
    lv_bar_set_value(ui->screen_bu3_bar_step2, 100, LV_ANIM_OFF);

    //Write style for screen_bu3_bar_step2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3_bar_step2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3_bar_step2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3_bar_step2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_bar_step2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bu3_bar_step2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_bu3_bar_step2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3_bar_step2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3_bar_step2, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3_bar_step2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_bar_step2, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_bu3_bar_step3
    ui->screen_bu3_bar_step3 = lv_bar_create(ui->screen_bu3);
    lv_obj_set_pos(ui->screen_bu3_bar_step3, 513, 305);
    lv_obj_set_size(ui->screen_bu3_bar_step3, 217, 14);
    lv_obj_set_style_anim_duration(ui->screen_bu3_bar_step3, 1000, 0);
    lv_bar_set_mode(ui->screen_bu3_bar_step3, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_bu3_bar_step3, 0, 100);
    lv_bar_set_value(ui->screen_bu3_bar_step3, 50, LV_ANIM_OFF);

    //Write style for screen_bu3_bar_step3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3_bar_step3, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3_bar_step3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3_bar_step3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_bar_step3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bu3_bar_step3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_bu3_bar_step3, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bu3_bar_step3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bu3_bar_step3, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bu3_bar_step3, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bu3_bar_step3, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //The custom code of screen_bu3.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_bu3);

}
