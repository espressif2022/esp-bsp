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

    //Write codes screen_wpsd_2_label_connnect
    ui->screen_wpsd_2_label_connnect = lv_label_create(ui->screen_wpsd_2);
    lv_obj_set_pos(ui->screen_wpsd_2_label_connnect, 38, 166);
    lv_obj_set_size(ui->screen_wpsd_2_label_connnect, 330, 51);
    lv_label_set_text(ui->screen_wpsd_2_label_connnect, "Connected:\n\n");
    lv_label_set_long_mode(ui->screen_wpsd_2_label_connnect, LV_LABEL_LONG_WRAP);

    //Write style for screen_wpsd_2_label_connnect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_label_connnect, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_label_connnect, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_label_connnect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_label_connnect, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_label_connnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wpsd_2_label_var1_tex
    ui->screen_wpsd_2_label_var1_tex = lv_label_create(ui->screen_wpsd_2);
    lv_obj_set_pos(ui->screen_wpsd_2_label_var1_tex, 38, 228);
    lv_obj_set_size(ui->screen_wpsd_2_label_var1_tex, 422, 43);
    lv_label_set_text(ui->screen_wpsd_2_label_var1_tex, "[Device name]\n");
    lv_label_set_long_mode(ui->screen_wpsd_2_label_var1_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_wpsd_2_label_var1_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wpsd_2_label_var1_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wpsd_2_label_var1_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wpsd_2_label_var1_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wpsd_2_label_var1_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wpsd_2_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_wpsd_2.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_wpsd_2);

    //Init events for screen.
    events_init_screen_wpsd_2(ui);
}
