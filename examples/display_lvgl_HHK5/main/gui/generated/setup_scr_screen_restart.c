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
    lv_obj_set_pos(ui->screen_restart_label_loading, 164, 247);
    lv_obj_set_size(ui->screen_restart_label_loading, 442, 43);
    lv_label_set_text(ui->screen_restart_label_loading, "Modem will now restart\n\n");
    lv_label_set_long_mode(ui->screen_restart_label_loading, LV_LABEL_LONG_WRAP);

    //Write style for screen_restart_label_loading, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_restart_label_loading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_restart_label_loading, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_restart_label_loading, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes screen_restart_img_1
    ui->screen_restart_img_1 = lv_image_create(ui->screen_restart);
    lv_obj_set_pos(ui->screen_restart_img_1, 46, 216);
    lv_obj_set_size(ui->screen_restart_img_1, 100, 100);
    lv_obj_add_flag(ui->screen_restart_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_restart_img_1, &_arc_RGB565A8_100x100);
    lv_image_set_pivot(ui->screen_restart_img_1, 50,50);
    lv_image_set_rotation(ui->screen_restart_img_1, 0);

    //Write style for screen_restart_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_restart_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_restart_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_restart_cont_1
    ui->screen_restart_cont_1 = lv_obj_create(ui->screen_restart);
    lv_obj_set_pos(ui->screen_restart_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_restart_cont_1, 960, 120);
    lv_obj_set_scrollbar_mode(ui->screen_restart_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_restart_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_restart_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_restart_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_restart_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_restart_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_restart_label_1
    ui->screen_restart_label_1 = lv_label_create(ui->screen_restart_cont_1);
    lv_obj_set_pos(ui->screen_restart_label_1, 29, 52);
    lv_obj_set_size(ui->screen_restart_label_1, 372, 43);
    lv_label_set_text(ui->screen_restart_label_1, "Restart the modem\n\n");
    lv_label_set_long_mode(ui->screen_restart_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_restart_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_restart_label_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_restart_label_1, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_restart_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_restart_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_restart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_restart_line_1
    ui->screen_restart_line_1 = lv_line_create(ui->screen_restart_cont_1);
    lv_obj_set_pos(ui->screen_restart_line_1, 37, 112);
    lv_obj_set_size(ui->screen_restart_line_1, 866, 5);
    static lv_point_precise_t screen_restart_line_1[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_restart_line_1, screen_restart_line_1, 2);

    //Write style for screen_restart_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_restart_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_restart_line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_restart_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_restart_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_restart_btn_1
    ui->screen_restart_btn_1 = lv_button_create(ui->screen_restart_cont_1);
    lv_obj_set_pos(ui->screen_restart_btn_1, 425, 10);
    lv_obj_set_size(ui->screen_restart_btn_1, 100, 50);
    ui->screen_restart_btn_1_label = lv_label_create(ui->screen_restart_btn_1);
    lv_label_set_text(ui->screen_restart_btn_1_label, "Test");
    lv_label_set_long_mode(ui->screen_restart_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_restart_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_restart_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_restart_btn_1_label, LV_PCT(100));

    //Write style for screen_restart_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_restart_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_restart_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_restart_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_restart_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_restart_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_restart_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_restart_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_restart_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_restart_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_restart_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_restart.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_restart);

    //Init events for screen.
    events_init_screen_restart(ui);
}
