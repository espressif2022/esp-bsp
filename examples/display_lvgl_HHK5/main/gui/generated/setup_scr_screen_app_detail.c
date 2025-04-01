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



void setup_scr_screen_app_detail(lv_ui *ui)
{
    //Write codes screen_app_detail
    ui->screen_app_detail = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_app_detail, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_app_detail, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_app_detail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_app_detail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_app_detail, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_app_detail, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_app_detail_label_var1_tex
    ui->screen_app_detail_label_var1_tex = lv_label_create(ui->screen_app_detail);
    lv_obj_set_pos(ui->screen_app_detail_label_var1_tex, 234, 268);
    lv_obj_set_size(ui->screen_app_detail_label_var1_tex, 589, 45);
    lv_label_set_text(ui->screen_app_detail_label_var1_tex, "[Description of the App, Description of \n\n\n");
    lv_label_set_long_mode(ui->screen_app_detail_label_var1_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_app_detail_label_var1_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_app_detail_label_var1_tex, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_app_detail_label_var1_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_app_detail_label_var1_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_app_detail_label_var1_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_app_detail_label_var1_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_app_detail_label_app_name
    ui->screen_app_detail_label_app_name = lv_label_create(ui->screen_app_detail);
    lv_obj_set_pos(ui->screen_app_detail_label_app_name, 234, 219);
    lv_obj_set_size(ui->screen_app_detail_label_app_name, 436, 43);
    lv_label_set_text(ui->screen_app_detail_label_app_name, "Wi-Fi App\n");
    lv_label_set_long_mode(ui->screen_app_detail_label_app_name, LV_LABEL_LONG_WRAP);

    //Write style for screen_app_detail_label_app_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_app_detail_label_app_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_app_detail_label_app_name, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_app_detail_label_app_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_app_detail_label_app_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_app_detail_label_app_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_app_detail_qrcode_url
    ui->screen_app_detail_qrcode_url = lv_qrcode_create(ui->screen_app_detail);
    lv_obj_set_pos(ui->screen_app_detail_qrcode_url, 28, 156);
    lv_obj_set_size(ui->screen_app_detail_qrcode_url, 182, 182);
    lv_qrcode_set_size(ui->screen_app_detail_qrcode_url, 182);
    lv_qrcode_set_dark_color(ui->screen_app_detail_qrcode_url, lv_color_hex(0x2C3224));
    lv_qrcode_set_light_color(ui->screen_app_detail_qrcode_url, lv_color_hex(0xffffff));
    const char * screen_app_detail_qrcode_url_data = "https://www.nxp.com/";
    lv_qrcode_update(ui->screen_app_detail_qrcode_url, screen_app_detail_qrcode_url_data, 20);

    //Write codes screen_app_detail_img_app_icon
    ui->screen_app_detail_img_app_icon = lv_image_create(ui->screen_app_detail);
    lv_obj_set_pos(ui->screen_app_detail_img_app_icon, 213, 139);
    lv_obj_set_size(ui->screen_app_detail_img_app_icon, 109, 71);
    lv_obj_add_flag(ui->screen_app_detail_img_app_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_app_detail_img_app_icon, &_icon_app_RGB565A8_109x71);
    lv_image_set_pivot(ui->screen_app_detail_img_app_icon, 50,50);
    lv_image_set_rotation(ui->screen_app_detail_img_app_icon, 0);

    //Write style for screen_app_detail_img_app_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_app_detail_img_app_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_app_detail_img_app_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_app_detail_label_var2_tex
    ui->screen_app_detail_label_var2_tex = lv_label_create(ui->screen_app_detail);
    lv_obj_set_pos(ui->screen_app_detail_label_var2_tex, 234, 306);
    lv_obj_set_size(ui->screen_app_detail_label_var2_tex, 589, 45);
    lv_label_set_text(ui->screen_app_detail_label_var2_tex, "the App,Description of the App]\n\n\n");
    lv_label_set_long_mode(ui->screen_app_detail_label_var2_tex, LV_LABEL_LONG_WRAP);

    //Write style for screen_app_detail_label_var2_tex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_app_detail_label_var2_tex, lv_color_hex(0x4d4949), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_app_detail_label_var2_tex, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_app_detail_label_var2_tex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_app_detail_label_var2_tex, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_app_detail_label_var2_tex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_app_detail.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_app_detail);

    //Init events for screen.
    events_init_screen_app_detail(ui);
}
