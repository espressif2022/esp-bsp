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



void setup_scr_screen_restart(lv_ui *ui)
{
    //Write codes screen_restart
    ui->screen_restart = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_restart, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_restart, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_restart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_restart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_restart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_restart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_restart_label_loading
    ui->screen_restart_label_loading = lv_label_create(ui->screen_restart);
    lv_obj_set_pos(ui->screen_restart_label_loading, 162, 228);
    lv_obj_set_size(ui->screen_restart_label_loading, 593, 71);
    lv_label_set_text(ui->screen_restart_label_loading, "Resetting modem to factory default.\nYour modem will now restart");
    lv_label_set_long_mode(ui->screen_restart_label_loading, LV_LABEL_LONG_WRAP);

    //Write style for screen_restart_label_loading, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_restart_label_loading, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_restart_label_loading, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_restart_label_loading, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_restart_label_loading, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_restart.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_restart);

    //Init events for screen.
    events_init_screen_restart(ui);
}
