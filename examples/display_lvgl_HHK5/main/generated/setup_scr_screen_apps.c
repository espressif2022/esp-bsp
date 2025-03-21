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



void setup_scr_screen_apps(lv_ui *ui)
{
    //Write codes screen_apps
    ui->screen_apps = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_apps, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_apps, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_apps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_apps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_apps, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_apps, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_apps_cont_title
    ui->screen_apps_cont_title = lv_obj_create(ui->screen_apps);
    lv_obj_set_pos(ui->screen_apps_cont_title, 0, 0);
    lv_obj_set_size(ui->screen_apps_cont_title, 960, 113);
    lv_obj_set_scrollbar_mode(ui->screen_apps_cont_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_apps_cont_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_apps_cont_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_apps_cont_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_apps_cont_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_apps_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_apps_label_title
    ui->screen_apps_label_title = lv_label_create(ui->screen_apps_cont_title);
    lv_obj_set_pos(ui->screen_apps_label_title, 30, 50);
    lv_obj_set_size(ui->screen_apps_label_title, 372, 32);
    lv_label_set_text(ui->screen_apps_label_title, "Bell Apps\n\n\n");
    lv_label_set_long_mode(ui->screen_apps_label_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_apps_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_apps_label_title, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_apps_label_title, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_apps_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_apps_label_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_apps_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_apps_line_split
    ui->screen_apps_line_split = lv_line_create(ui->screen_apps_cont_title);
    lv_obj_set_pos(ui->screen_apps_line_split, 37, 113);
    lv_obj_set_size(ui->screen_apps_line_split, 864, 5);
    static lv_point_precise_t screen_apps_line_split[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_apps_line_split, screen_apps_line_split, 2);

    //Write style for screen_apps_line_split, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_apps_line_split, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_apps_line_split, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_apps_line_split, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_apps_line_split, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_apps_btn_back
    ui->screen_apps_btn_back = lv_button_create(ui->screen_apps_cont_title);
    lv_obj_set_pos(ui->screen_apps_btn_back, 684, 50);
    lv_obj_set_size(ui->screen_apps_btn_back, 230, 26);
    ui->screen_apps_btn_back_label = lv_label_create(ui->screen_apps_btn_back);
    lv_label_set_text(ui->screen_apps_btn_back_label, "Back to menu\n");
    lv_label_set_long_mode(ui->screen_apps_btn_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_apps_btn_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_apps_btn_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_apps_btn_back_label, LV_PCT(100));

    //Write style for screen_apps_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_apps_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_apps_btn_back, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_apps_btn_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_apps_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_apps_btn_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_apps_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_apps_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_apps_btn_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_apps_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_apps_btn_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_apps.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_apps);

    //Init events for screen.
    events_init_screen_apps(ui);
}
