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
    lv_obj_set_pos(ui->screen_notif_cont_notify, 0, 178);
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

    //Write codes screen_notif_label_notify_info
    ui->screen_notif_label_notify_info = lv_label_create(ui->screen_notif_cont_notify);
    lv_obj_set_pos(ui->screen_notif_label_notify_info, 88, 17);
    lv_obj_set_size(ui->screen_notif_label_notify_info, 552, 43);
    lv_label_set_text(ui->screen_notif_label_notify_info, "Services configured: Internet, TV and Home Phone\n\n");
    lv_label_set_long_mode(ui->screen_notif_label_notify_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_notify_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_notify_info, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_notify_info, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_notify_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_notify_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_notify_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_img_notif_type
    ui->screen_notif_img_notif_type = lv_image_create(ui->screen_notif_cont_notify);
    lv_obj_set_pos(ui->screen_notif_img_notif_type, 31, 13);
    lv_obj_set_size(ui->screen_notif_img_notif_type, 29, 35);
    lv_obj_add_flag(ui->screen_notif_img_notif_type, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_notif_img_notif_type, &_error_RGB565A8_29x35);
    lv_image_set_pivot(ui->screen_notif_img_notif_type, 50,50);
    lv_image_set_rotation(ui->screen_notif_img_notif_type, 0);

    //Write style for screen_notif_img_notif_type, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_notif_img_notif_type, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_notif_img_notif_type, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

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

    //Write codes screen_notif_label_1
    ui->screen_notif_label_1 = lv_label_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_label_1, 30, 52);
    lv_obj_set_size(ui->screen_notif_label_1, 372, 43);
    lv_label_set_text(ui->screen_notif_label_1, "Services status\n\n\n");
    lv_label_set_long_mode(ui->screen_notif_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_notif_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_label_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_label_1, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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

    //Write codes screen_notif_btn_3
    ui->screen_notif_btn_3 = lv_button_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_btn_3, 688, 45);
    lv_obj_set_size(ui->screen_notif_btn_3, 218, 45);
    ui->screen_notif_btn_3_label = lv_label_create(ui->screen_notif_btn_3);
    lv_label_set_text(ui->screen_notif_btn_3_label, "Back to menu");
    lv_label_set_long_mode(ui->screen_notif_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_notif_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_notif_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_notif_btn_3_label, LV_PCT(100));

    //Write style for screen_notif_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_notif_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_notif_btn_3, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_notif_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_notif_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_notif_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_notif_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_notif_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_notif_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_notif_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_notif_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_notif_btn_2
    ui->screen_notif_btn_2 = lv_button_create(ui->screen_notif_cont_title);
    lv_obj_set_pos(ui->screen_notif_btn_2, 425, 10);
    lv_obj_set_size(ui->screen_notif_btn_2, 100, 50);
    ui->screen_notif_btn_2_label = lv_label_create(ui->screen_notif_btn_2);
    lv_label_set_text(ui->screen_notif_btn_2_label, "Test");
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
