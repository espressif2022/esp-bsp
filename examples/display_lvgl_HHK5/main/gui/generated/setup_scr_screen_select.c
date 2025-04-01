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



void setup_scr_screen_select(lv_ui *ui)
{
    //Write codes screen_select
    ui->screen_select = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_select, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_select, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_select, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_select, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_select, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_select, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_select_label_tips
    ui->screen_select_label_tips = lv_label_create(ui->screen_select);
    lv_obj_set_pos(ui->screen_select_label_tips, 33, 153);
    lv_obj_set_size(ui->screen_select_label_tips, 552, 43);
    lv_label_set_text(ui->screen_select_label_tips, "Do you want to restart your modem?\n\n");
    lv_label_set_long_mode(ui->screen_select_label_tips, LV_LABEL_LONG_WRAP);

    //Write style for screen_select_label_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_select_label_tips, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_select_label_tips, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_select_label_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_select_label_tips, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_select_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_select_btn_no
    ui->screen_select_btn_no = lv_button_create(ui->screen_select);
    lv_obj_set_pos(ui->screen_select_btn_no, 33, 208);
    lv_obj_set_size(ui->screen_select_btn_no, 866, 60);
    ui->screen_select_btn_no_label = lv_label_create(ui->screen_select_btn_no);
    lv_label_set_text(ui->screen_select_btn_no_label, "No, just go back to menu");
    lv_label_set_long_mode(ui->screen_select_btn_no_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_select_btn_no_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_select_btn_no, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_select_btn_no_label, LV_PCT(100));

    //Write style for screen_select_btn_no, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_select_btn_no, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_select_btn_no, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_select_btn_no, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_select_btn_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_select_btn_no, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_select_btn_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_select_btn_no, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_select_btn_no, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_select_btn_no, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_select_btn_no, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_select_btn_yes
    ui->screen_select_btn_yes = lv_button_create(ui->screen_select);
    lv_obj_set_pos(ui->screen_select_btn_yes, 33, 279);
    lv_obj_set_size(ui->screen_select_btn_yes, 866, 60);
    ui->screen_select_btn_yes_label = lv_label_create(ui->screen_select_btn_yes);
    lv_label_set_text(ui->screen_select_btn_yes_label, "Yes, restart my modem");
    lv_label_set_long_mode(ui->screen_select_btn_yes_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_select_btn_yes_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_select_btn_yes, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_select_btn_yes_label, LV_PCT(100));

    //Write style for screen_select_btn_yes, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_select_btn_yes, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_select_btn_yes, lv_color_hex(0x35383a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_select_btn_yes, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_select_btn_yes, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_select_btn_yes, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_select_btn_yes, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_select_btn_yes, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_select_btn_yes, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_select_btn_yes, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_select_btn_yes, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_select.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_select);

    //Init events for screen.
    events_init_screen_select(ui);
}
