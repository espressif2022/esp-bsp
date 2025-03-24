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



void setup_scr_screen_error(lv_ui *ui)
{
    //Write codes screen_error
    ui->screen_error = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_error, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_error, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_error, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_error, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_error, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_error, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_info_2
    ui->screen_error_label_info_2 = lv_label_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_label_info_2, 44, 182);
    lv_obj_set_size(ui->screen_error_label_info_2, 436, 83);
    lv_label_set_text(ui->screen_error_label_info_2, "[Typicaly two lines of error message, error\nmessage, error message.]\n\n");
    lv_label_set_long_mode(ui->screen_error_label_info_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_info_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_info_2, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_info_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_info_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_info_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_info_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_cont_title
    ui->screen_error_cont_title = lv_obj_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_cont_title, 2, 0);
    lv_obj_set_size(ui->screen_error_cont_title, 960, 113);
    lv_obj_set_scrollbar_mode(ui->screen_error_cont_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_error_cont_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_cont_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_error_cont_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_error_cont_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_brand
    ui->screen_error_label_brand = lv_label_create(ui->screen_error_cont_title);
    lv_obj_set_pos(ui->screen_error_label_brand, 40, 32);
    lv_obj_set_size(ui->screen_error_label_brand, 103, 43);
    lv_label_set_text(ui->screen_error_label_brand, "Bell");
    lv_label_set_long_mode(ui->screen_error_label_brand, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_brand, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_brand, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_brand, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_brand, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_brand, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_brand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_btn_1
    ui->screen_error_btn_1 = lv_button_create(ui->screen_error_cont_title);
    lv_obj_set_pos(ui->screen_error_btn_1, 425, 10);
    lv_obj_set_size(ui->screen_error_btn_1, 100, 50);
    ui->screen_error_btn_1_label = lv_label_create(ui->screen_error_btn_1);
    lv_label_set_text(ui->screen_error_btn_1_label, "Test");
    lv_label_set_long_mode(ui->screen_error_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_error_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_error_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_error_btn_1_label, LV_PCT(100));

    //Write style for screen_error_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_error_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_error_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_error_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_error_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_info_3
    ui->screen_error_label_info_3 = lv_label_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_label_info_3, 40, 300);
    lv_obj_set_size(ui->screen_error_label_info_3, 607, 50);
    lv_label_set_text(ui->screen_error_label_info_3, "Use the Bell virtual repair tool to help resolve your issue");
    lv_label_set_long_mode(ui->screen_error_label_info_3, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_info_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_info_3, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_info_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_info_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_info_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_info_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_qrcode_error
    ui->screen_error_qrcode_error = lv_qrcode_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_qrcode_error, 740, 153);
    lv_obj_set_size(ui->screen_error_qrcode_error, 172, 172);
    lv_qrcode_set_size(ui->screen_error_qrcode_error, 172);
    lv_qrcode_set_dark_color(ui->screen_error_qrcode_error, lv_color_hex(0x2C3224));
    lv_qrcode_set_light_color(ui->screen_error_qrcode_error, lv_color_hex(0xffffff));
    const char * screen_error_qrcode_error_data = "https://www.nxp.com/";
    lv_qrcode_update(ui->screen_error_qrcode_error, screen_error_qrcode_error_data, 20);

    //Write codes screen_error_cont_1
    ui->screen_error_cont_1 = lv_obj_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_cont_1, 7, 93);
    lv_obj_set_size(ui->screen_error_cont_1, 960, 39);
    lv_obj_set_scrollbar_mode(ui->screen_error_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_error_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_error_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_error_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_info_1
    ui->screen_error_label_info_1 = lv_label_create(ui->screen_error_cont_1);
    lv_obj_set_pos(ui->screen_error_label_info_1, 77, 16);
    lv_obj_set_size(ui->screen_error_label_info_1, 552, 43);
    lv_label_set_text(ui->screen_error_label_info_1, "Error ### - Error name\n\n");
    lv_label_set_long_mode(ui->screen_error_label_info_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_info_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_info_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_info_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_info_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_info_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_info_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_img_1
    ui->screen_error_img_1 = lv_image_create(ui->screen_error_cont_1);
    lv_obj_set_pos(ui->screen_error_img_1, 31, 10);
    lv_obj_set_size(ui->screen_error_img_1, 31, 40);
    lv_obj_add_flag(ui->screen_error_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_error_img_1, &_error_RGB565A8_31x40);
    lv_image_set_pivot(ui->screen_error_img_1, 50,50);
    lv_image_set_rotation(ui->screen_error_img_1, 0);

    //Write style for screen_error_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_error_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_error_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_error.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_error);

    //Init events for screen.
    events_init_screen_error(ui);
}
