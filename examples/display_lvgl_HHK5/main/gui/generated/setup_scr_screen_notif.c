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



void setup_scr_screen_notif(lv_ui *ui)
{
    //Write codes screen_notif
    ui->screen_notif = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_notif, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_notif, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_notif, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_notif, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_cont_notify
    ui->screen_notif_cont_notify = lv_obj_create(ui->screen_notif);
    lv_obj_set_pos(ui->screen_notif_cont_notify, 2, 178);
    lv_obj_set_size(ui->screen_notif_cont_notify, 960, 60);
    lv_obj_set_scrollbar_mode(ui->screen_notif_cont_notify, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_notif_cont_notify, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_cont_notify, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_cont_notify, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_cont_notify, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_cont_notify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_label_var1_tex
    ui->screen_notif_label_var1_tex = lv_label_create(ui->screen_notif_cont_notify);
    lv_obj_set_pos(ui->screen_notif_label_var1_tex, 80, 17);
    lv_obj_set_size(ui->screen_notif_label_var1_tex, 677, 43);
    lv_label_set_text(ui->screen_notif_label_var1_tex, "Services configured: Internet, TV and Home Phone\n\n");
    lv_label_set_long_mode(ui->screen_notif_label_var1_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_var1_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_var1_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_var1_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_var1_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_var1_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_img_notif_type
    ui->screen_notif_img_notif_type = lv_image_create(ui->screen_notif_cont_notify);
    lv_obj_set_pos(ui->screen_notif_img_notif_type, 30, 11);
    lv_obj_set_size(ui->screen_notif_img_notif_type, 29, 35);
    lv_obj_add_flag(ui->screen_notif_img_notif_type, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_notif_img_notif_type, &_error_RGB565A8_29x35);
    lv_image_set_pivot(ui->screen_notif_img_notif_type, 50,50);
    lv_image_set_rotation(ui->screen_notif_img_notif_type, 0);

    //Write style for screen_notif_img_notif_type, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_notif_img_notif_type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_notif_img_notif_type, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_img_back
    ui->screen_notif_img_back = lv_image_create(ui->screen_notif);
    lv_obj_set_pos(ui->screen_notif_img_back, 30, 126);
    lv_obj_set_size(ui->screen_notif_img_back, 29, 35);
    lv_obj_add_flag(ui->screen_notif_img_back, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_notif_img_back, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_notif_img_back, &_icon_ok_RGB565A8_29x35);
    lv_image_set_pivot(ui->screen_notif_img_back, 50,50);
    lv_image_set_rotation(ui->screen_notif_img_back, 0);

    //Write style for screen_notif_img_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_notif_img_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_notif_img_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_cont_labels
    ui->screen_notif_cont_labels = lv_obj_create(ui->screen_notif);
    lv_obj_set_pos(ui->screen_notif_cont_labels, 40, 225);
    lv_obj_set_size(ui->screen_notif_cont_labels, 784, 135);
    lv_obj_set_scrollbar_mode(ui->screen_notif_cont_labels, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_notif_cont_labels, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_notif_cont_labels, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_cont_labels, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_label_var4_tex
    ui->screen_notif_label_var4_tex = lv_label_create(ui->screen_notif_cont_labels);
    lv_obj_set_pos(ui->screen_notif_label_var4_tex, 15, 102);
    lv_obj_set_size(ui->screen_notif_label_var4_tex, 677, 43);
    lv_label_set_text(ui->screen_notif_label_var4_tex, "error message, error message, error message\n");
    lv_label_set_long_mode(ui->screen_notif_label_var4_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_var4_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_var4_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_var4_tex, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_var4_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_var4_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_var4_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_label_var3_tex
    ui->screen_notif_label_var3_tex = lv_label_create(ui->screen_notif_cont_labels);
    lv_obj_set_pos(ui->screen_notif_label_var3_tex, 15, 58);
    lv_obj_set_size(ui->screen_notif_label_var3_tex, 677, 43);
    lv_label_set_text(ui->screen_notif_label_var3_tex, "error message, error message, error message, \n\n");
    lv_label_set_long_mode(ui->screen_notif_label_var3_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_var3_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_var3_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_var3_tex, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_var3_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_var3_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_var3_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_label_var2_tex
    ui->screen_notif_label_var2_tex = lv_label_create(ui->screen_notif_cont_labels);
    lv_obj_set_pos(ui->screen_notif_label_var2_tex, 22, 17);
    lv_obj_set_size(ui->screen_notif_label_var2_tex, 677, 43);
    lv_label_set_text(ui->screen_notif_label_var2_tex, "[Typicaly two lines of error message,\n\n");
    lv_label_set_long_mode(ui->screen_notif_label_var2_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_var2_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_var2_tex, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_var2_tex, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_var2_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_var2_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_cont_bell
    ui->screen_notif_cont_bell = lv_obj_create(ui->screen_notif);
    lv_obj_set_pos(ui->screen_notif_cont_bell, 2, -1);
    lv_obj_set_size(ui->screen_notif_cont_bell, 960, 113);
    lv_obj_set_scrollbar_mode(ui->screen_notif_cont_bell, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_notif_cont_bell, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_notif_cont_bell, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_cont_bell, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_cont_bell, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_cont_bell, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_label_bell
    ui->screen_notif_label_bell = lv_label_create(ui->screen_notif_cont_bell);
    lv_obj_set_pos(ui->screen_notif_label_bell, 37, 34);
    lv_obj_set_size(ui->screen_notif_label_bell, 103, 43);
    lv_label_set_text(ui->screen_notif_label_bell, "Bell");
    lv_label_set_long_mode(ui->screen_notif_label_bell, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_bell, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_bell, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_bell, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_bell, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_bell, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_btn_next
    ui->screen_notif_btn_next = lv_button_create(ui->screen_notif_cont_bell);
    lv_obj_set_pos(ui->screen_notif_btn_next, 425, 10);
    lv_obj_set_size(ui->screen_notif_btn_next, 100, 50);
    ui->screen_notif_btn_next_label = lv_label_create(ui->screen_notif_btn_next);
    lv_label_set_text(ui->screen_notif_btn_next_label, "next");
    lv_label_set_long_mode(ui->screen_notif_btn_next_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_notif_btn_next_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_notif_btn_next, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_notif_btn_next_label, LV_PCT(100));

    //Write style for screen_notif_btn_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_notif_btn_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_btn_next, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_btn_next, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_notif_btn_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_btn_next, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_btn_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_btn_next, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_btn_next, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_btn_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_btn_next, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_cont_title
    ui->screen_notif_cont_title = lv_obj_create(ui->screen_notif);
    lv_obj_set_pos(ui->screen_notif_cont_title, 0, 0);
    lv_obj_set_size(ui->screen_notif_cont_title, 960, 120);
    lv_obj_set_scrollbar_mode(ui->screen_notif_cont_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_notif_cont_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_cont_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_cont_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_cont_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_label_title
    ui->screen_notif_label_title = lv_label_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_label_title, 30, 50);
    lv_obj_set_size(ui->screen_notif_label_title, 510, 43);
    lv_label_set_text(ui->screen_notif_label_title, "Services status\n\n\n");
    lv_label_set_long_mode(ui->screen_notif_label_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_title, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_title, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_line_2
    ui->screen_notif_line_2 = lv_line_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_line_2, 37, 112);
    lv_obj_set_size(ui->screen_notif_line_2, 864, 5);
    static lv_point_precise_t screen_notif_line_2[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_notif_line_2, screen_notif_line_2, 2);

    //Write style for screen_notif_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_notif_line_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_notif_line_2, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_notif_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_notif_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_btn_back_indication
    ui->screen_notif_btn_back_indication = lv_button_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_btn_back_indication, 688, 45);
    lv_obj_set_size(ui->screen_notif_btn_back_indication, 218, 45);
    ui->screen_notif_btn_back_indication_label = lv_label_create(ui->screen_notif_btn_back_indication);
    lv_label_set_text(ui->screen_notif_btn_back_indication_label, "Back to menu");
    lv_label_set_long_mode(ui->screen_notif_btn_back_indication_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_notif_btn_back_indication_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_notif_btn_back_indication, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_notif_btn_back_indication_label, LV_PCT(100));

    //Write style for screen_notif_btn_back_indication, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_notif_btn_back_indication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_btn_back_indication, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_btn_back_indication, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_notif_btn_back_indication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_btn_back_indication, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_btn_back_indication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_btn_back_indication, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_btn_back_indication, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_btn_back_indication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_btn_back_indication, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_btn_2
    ui->screen_notif_btn_2 = lv_button_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_btn_2, 425, 9);
    lv_obj_set_size(ui->screen_notif_btn_2, 100, 50);
    ui->screen_notif_btn_2_label = lv_label_create(ui->screen_notif_btn_2);
    lv_label_set_text(ui->screen_notif_btn_2_label, "next");
    lv_label_set_long_mode(ui->screen_notif_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_notif_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_notif_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_notif_btn_2_label, LV_PCT(100));

    //Write style for screen_notif_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_notif_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_notif_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_notif.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_notif);

    //Init events for screen.
    events_init_screen_notif(ui);
}
