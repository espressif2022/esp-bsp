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



void setup_scr_screen_title(lv_ui *ui)
{
    //Write codes screen_title
    ui->screen_title = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_title, 960, 376);
    lv_obj_set_scrollbar_mode(ui->screen_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_title_cont_title
    ui->screen_title_cont_title = lv_obj_create(ui->screen_title);
    lv_obj_set_pos(ui->screen_title_cont_title, 0, 0);
    lv_obj_set_size(ui->screen_title_cont_title, 960, 120);
    lv_obj_set_scrollbar_mode(ui->screen_title_cont_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_title_cont_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_title_cont_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_title_cont_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_title_cont_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_title_cont_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_title_label_title
    ui->screen_title_label_title = lv_label_create(ui->screen_title_cont_title);
    lv_obj_set_pos(ui->screen_title_label_title, 30, 52);
    lv_obj_set_size(ui->screen_title_label_title, 510, 43);
    lv_label_set_text(ui->screen_title_label_title, "Bell Apps\n\n\n");
    lv_label_set_long_mode(ui->screen_title_label_title, LV_LABEL_LONG_WRAP);

    //Write style for screen_title_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_title_label_title, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_title_label_title, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_title_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_title_label_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_title_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_title_line_splite
    ui->screen_title_line_splite = lv_line_create(ui->screen_title_cont_title);
    lv_obj_set_pos(ui->screen_title_line_splite, 37, 112);
    lv_obj_set_size(ui->screen_title_line_splite, 864, 5);
    static lv_point_precise_t screen_title_line_splite[] = {{0, 0},{900, 0}};
    lv_line_set_points(ui->screen_title_line_splite, screen_title_line_splite, 2);

    //Write style for screen_title_line_splite, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->screen_title_line_splite, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_title_line_splite, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_title_line_splite, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_title_line_splite, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_title_btn_back_indication
    ui->screen_title_btn_back_indication = lv_button_create(ui->screen_title_cont_title);
    lv_obj_set_pos(ui->screen_title_btn_back_indication, 686, 45);
    lv_obj_set_size(ui->screen_title_btn_back_indication, 218, 45);
    ui->screen_title_btn_back_indication_label = lv_label_create(ui->screen_title_btn_back_indication);
    lv_label_set_text(ui->screen_title_btn_back_indication_label, "Back to apps");
    lv_label_set_long_mode(ui->screen_title_btn_back_indication_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_title_btn_back_indication_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_title_btn_back_indication, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_title_btn_back_indication_label, LV_PCT(100));

    //Write style for screen_title_btn_back_indication, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_title_btn_back_indication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_title_btn_back_indication, lv_color_hex(0x004D8F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_title_btn_back_indication, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_title_btn_back_indication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_title_btn_back_indication, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_title_btn_back_indication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_title_btn_back_indication, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_title_btn_back_indication, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_title_btn_back_indication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_title_btn_back_indication, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_title_cont_bell
    ui->screen_title_cont_bell = lv_obj_create(ui->screen_title);
    lv_obj_set_pos(ui->screen_title_cont_bell, 0, 0);
    lv_obj_set_size(ui->screen_title_cont_bell, 960, 113);
    lv_obj_set_scrollbar_mode(ui->screen_title_cont_bell, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_title_cont_bell, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_title_cont_bell, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_title_cont_bell, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_title_cont_bell, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_title_cont_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_title_label_bell
    ui->screen_title_label_bell = lv_label_create(ui->screen_title_cont_bell);
    lv_obj_set_pos(ui->screen_title_label_bell, 37, 34);
    lv_obj_set_size(ui->screen_title_label_bell, 103, 43);
    lv_label_set_text(ui->screen_title_label_bell, "Bell");
    lv_label_set_long_mode(ui->screen_title_label_bell, LV_LABEL_LONG_WRAP);

    //Write style for screen_title_label_bell, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_title_label_bell, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_title_label_bell, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_title_label_bell, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_title_label_bell, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_title_label_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_title.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_title);

}
