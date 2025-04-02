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

    //Write codes screen_error_label_tips
    ui->screen_error_label_tips = lv_label_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_label_tips, 64, 300);
    lv_obj_set_size(ui->screen_error_label_tips, 606, 50);
    lv_label_set_text(ui->screen_error_label_tips, "Use the Bell virtual repair tool to help resolve your issue");
    lv_label_set_long_mode(ui->screen_error_label_tips, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_tips, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_tips, lv_color_hex(0x9d9d9d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_tips, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_tips, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_tips, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_tips, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_qrcode_url
    ui->screen_error_qrcode_url = lv_qrcode_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_qrcode_url, 740, 153);
    lv_obj_set_size(ui->screen_error_qrcode_url, 172, 172);
    lv_qrcode_set_size(ui->screen_error_qrcode_url, 172);
    lv_qrcode_set_dark_color(ui->screen_error_qrcode_url, lv_color_hex(0x2C3224));
    lv_qrcode_set_light_color(ui->screen_error_qrcode_url, lv_color_hex(0xffffff));
    const char * screen_error_qrcode_url_data = "https://www.nxp.com/";
    lv_qrcode_update(ui->screen_error_qrcode_url, screen_error_qrcode_url_data, 20);

    //Write codes screen_error_cont_error
    ui->screen_error_cont_error = lv_obj_create(ui->screen_error);
    lv_obj_set_pos(ui->screen_error_cont_error, 2, 93);
    lv_obj_set_size(ui->screen_error_cont_error, 720, 180);
    lv_obj_set_scrollbar_mode(ui->screen_error_cont_error, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_error_cont_error, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_cont_error, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_error_cont_error, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_error_cont_error, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_cont_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_err_num
    ui->screen_error_label_err_num = lv_label_create(ui->screen_error_cont_error);
    lv_obj_set_pos(ui->screen_error_label_err_num, 64, 16);
    lv_obj_set_size(ui->screen_error_label_err_num, 552, 43);
    lv_label_set_text(ui->screen_error_label_err_num, "Error ### - Error name\n\n");
    lv_label_set_long_mode(ui->screen_error_label_err_num, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_err_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_err_num, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_err_num, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_err_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_err_num, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_err_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_img_error
    ui->screen_error_img_error = lv_image_create(ui->screen_error_cont_error);
    lv_obj_set_pos(ui->screen_error_img_error, 23, 10);
    lv_obj_set_size(ui->screen_error_img_error, 31, 40);
    lv_obj_add_flag(ui->screen_error_img_error, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_error_img_error, &_error_RGB565A8_31x40);
    lv_image_set_pivot(ui->screen_error_img_error, 50,50);
    lv_image_set_rotation(ui->screen_error_img_error, 0);

    //Write style for screen_error_img_error, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_error_img_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_error_img_error, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_var2_tex
    ui->screen_error_label_var2_tex = lv_label_create(ui->screen_error_cont_error);
    lv_obj_set_pos(ui->screen_error_label_var2_tex, 64, 122);
    lv_obj_set_size(ui->screen_error_label_var2_tex, 580, 45);
    lv_label_set_text(ui->screen_error_label_var2_tex, "message, error message.]\n\n");
    lv_label_set_long_mode(ui->screen_error_label_var2_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_var2_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_var2_tex, lv_color_hex(0x9d9d9d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_var2_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_var2_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_var2_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_error_label_var1_tex
    ui->screen_error_label_var1_tex = lv_label_create(ui->screen_error_cont_error);
    lv_obj_set_pos(ui->screen_error_label_var1_tex, 65, 70);
    lv_obj_set_size(ui->screen_error_label_var1_tex, 580, 45);
    lv_label_set_text(ui->screen_error_label_var1_tex, "[Typicaly two lines of error message, error\n\n");
    lv_label_set_long_mode(ui->screen_error_label_var1_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_error_label_var1_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_error_label_var1_tex, lv_color_hex(0x9d9d9d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_error_label_var1_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_error_label_var1_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_error_label_var1_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_error_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_error.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_error);

    //Init events for screen.
    events_init_screen_error(ui);
}
