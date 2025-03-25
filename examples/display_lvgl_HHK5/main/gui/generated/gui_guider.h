/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *screen_main_loop;
	bool screen_main_loop_del;
	lv_obj_t *screen_main_loop_label_1;
	lv_obj_t *screen_main_loop_btn_1;
	lv_obj_t *screen_main_loop_btn_1_label;
	lv_obj_t *screen_bu0;
	bool screen_bu0_del;
	lv_obj_t *screen_bu0_label_welcome;
	lv_obj_t *screen_bu0_btn_1;
	lv_obj_t *screen_bu0_btn_1_label;
	lv_obj_t *screen_bu1;
	bool screen_bu1_del;
	lv_obj_t *screen_bu1_label_loading;
	lv_obj_t *screen_bu1_img_1;
	lv_obj_t *screen_bu1_btn_1;
	lv_obj_t *screen_bu1_btn_1_label;
	lv_obj_t *screen_bu2;
	bool screen_bu2_del;
	lv_obj_t *screen_bu2_label_brand;
	lv_obj_t *screen_bu2_btn_1;
	lv_obj_t *screen_bu2_btn_1_label;
	lv_obj_t *screen_bu3;
	bool screen_bu3_del;
	lv_obj_t *screen_bu3_label_title_1;
	lv_obj_t *screen_bu3_label_title_2;
	lv_obj_t *screen_bu3_bar_step1;
	lv_obj_t *screen_bu3_bar_step2;
	lv_obj_t *screen_bu3_bar_step3;
	lv_obj_t *screen_bu3_btn_1;
	lv_obj_t *screen_bu3_btn_1_label;
	lv_obj_t *screen_STB1;
	bool screen_STB1_del;
	lv_obj_t *screen_STB1_label_connect_to;
	lv_obj_t *screen_STB1_label_time;
	lv_obj_t *screen_STB1_cont_1;
	lv_obj_t *screen_STB1_label_1;
	lv_obj_t *screen_STB1_line_1;
	lv_obj_t *screen_STB1_btn_3;
	lv_obj_t *screen_STB1_btn_3_label;
	lv_obj_t *screen_STB1_btn_2;
	lv_obj_t *screen_STB1_btn_2_label;
	lv_obj_t *screen_notif;
	bool screen_notif_del;
	lv_obj_t *screen_notif_cont_notify;
	lv_obj_t *screen_notif_label_notify_info;
	lv_obj_t *screen_notif_img_notif_type;
	lv_obj_t *screen_notif_cont_title;
	lv_obj_t *screen_notif_label_1;
	lv_obj_t *screen_notif_line_2;
	lv_obj_t *screen_notif_btn_3;
	lv_obj_t *screen_notif_btn_3_label;
	lv_obj_t *screen_notif_btn_2;
	lv_obj_t *screen_notif_btn_2_label;
	lv_obj_t *screen_notif_img_1;
	lv_obj_t *screen_network;
	bool screen_network_del;
	lv_obj_t *screen_network_label_ssid_title;
	lv_obj_t *screen_network_cont_title;
	lv_obj_t *screen_network_label_title;
	lv_obj_t *screen_network_line_2;
	lv_obj_t *screen_network_btn_back;
	lv_obj_t *screen_network_btn_back_label;
	lv_obj_t *screen_network_btn_1;
	lv_obj_t *screen_network_btn_1_label;
	lv_obj_t *screen_network_label_ssid;
	lv_obj_t *screen_network_label_passwd_title;
	lv_obj_t *screen_network_label_passwd;
	lv_obj_t *screen_network_label_qrcode;
	lv_obj_t *screen_network_qrcode_wifi;
	lv_obj_t *screen_speedtest;
	bool screen_speedtest_del;
	lv_obj_t *screen_speedtest_label_ssid_title;
	lv_obj_t *screen_speedtest_label_down_spd;
	lv_obj_t *screen_speedtest_label_passwd_title;
	lv_obj_t *screen_speedtest_label_up_spd;
	lv_obj_t *screen_speedtest_img_speed_test;
	lv_obj_t *screen_speedtest_cont_title;
	lv_obj_t *screen_speedtest_label_1;
	lv_obj_t *screen_speedtest_line_4;
	lv_obj_t *screen_speedtest_btn_3;
	lv_obj_t *screen_speedtest_btn_3_label;
	lv_obj_t *screen_speedtest_btn_2;
	lv_obj_t *screen_speedtest_btn_2_label;
	lv_obj_t *screen_mm_1;
	bool screen_mm_1_del;
	lv_obj_t *screen_mm_1_label_passwd_title;
	lv_obj_t *screen_mm_1_label_passwd;
	lv_obj_t *screen_mm_1_label_scan;
	lv_obj_t *screen_mm_1_qrcode_passwd;
	lv_obj_t *screen_mm_1_cont_title;
	lv_obj_t *screen_mm_1_label_1;
	lv_obj_t *screen_mm_1_line_4;
	lv_obj_t *screen_mm_1_btn_3;
	lv_obj_t *screen_mm_1_btn_3_label;
	lv_obj_t *screen_mm_1_btn_2;
	lv_obj_t *screen_mm_1_btn_2_label;
	lv_obj_t *screen_error;
	bool screen_error_del;
	lv_obj_t *screen_error_label_info_2;
	lv_obj_t *screen_error_cont_title;
	lv_obj_t *screen_error_label_brand;
	lv_obj_t *screen_error_btn_1;
	lv_obj_t *screen_error_btn_1_label;
	lv_obj_t *screen_error_label_info_3;
	lv_obj_t *screen_error_qrcode_error;
	lv_obj_t *screen_error_cont_1;
	lv_obj_t *screen_error_label_info_1;
	lv_obj_t *screen_error_img_1;
	lv_obj_t *screen_apps;
	bool screen_apps_del;
	lv_obj_t *screen_apps_cont_1;
	lv_obj_t *screen_apps_label_1;
	lv_obj_t *screen_apps_line_1;
	lv_obj_t *screen_apps_btn_3;
	lv_obj_t *screen_apps_btn_3_label;
	lv_obj_t *screen_apps_btn_2;
	lv_obj_t *screen_apps_btn_2_label;
	lv_obj_t *screen_select;
	bool screen_select_del;
	lv_obj_t *screen_select_cont_1;
	lv_obj_t *screen_select_label_2;
	lv_obj_t *screen_select_line_2;
	lv_obj_t *screen_select_btn_5;
	lv_obj_t *screen_select_btn_5_label;
	lv_obj_t *screen_select_btn_4;
	lv_obj_t *screen_select_btn_4_label;
	lv_obj_t *screen_select_label_3;
	lv_obj_t *screen_select_btn_6;
	lv_obj_t *screen_select_btn_6_label;
	lv_obj_t *screen_select_btn_7;
	lv_obj_t *screen_select_btn_7_label;
	lv_obj_t *screen_restart;
	bool screen_restart_del;
	lv_obj_t *screen_restart_label_loading;
	lv_obj_t *screen_restart_cont_1;
	lv_obj_t *screen_restart_label_1;
	lv_obj_t *screen_restart_line_1;
	lv_obj_t *screen_restart_btn_1;
	lv_obj_t *screen_restart_btn_1_label;
	lv_obj_t *screen_null;
	bool screen_null_del;
	lv_obj_t *screen_null_cont_1;
	lv_obj_t *screen_null_label_2;
	lv_obj_t *screen_null_line_2;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_main_loop(lv_ui *ui);
void setup_scr_screen_bu0(lv_ui *ui);
void setup_scr_screen_bu1(lv_ui *ui);
void setup_scr_screen_bu2(lv_ui *ui);
void setup_scr_screen_bu3(lv_ui *ui);
void setup_scr_screen_STB1(lv_ui *ui);
void setup_scr_screen_notif(lv_ui *ui);
void setup_scr_screen_network(lv_ui *ui);
void setup_scr_screen_speedtest(lv_ui *ui);
void setup_scr_screen_mm_1(lv_ui *ui);
void setup_scr_screen_error(lv_ui *ui);
void setup_scr_screen_apps(lv_ui *ui);
void setup_scr_screen_select(lv_ui *ui);
void setup_scr_screen_restart(lv_ui *ui);
void setup_scr_screen_null(lv_ui *ui);
LV_IMAGE_DECLARE(_arc_RGB565A8_100x100);
LV_IMAGE_DECLARE(_error_RGB565A8_29x35);
LV_IMAGE_DECLARE(_icon_ok_RGB565A8_29x35);
LV_IMAGE_DECLARE(_speed_test_RGB565A8_145x140);
LV_IMAGE_DECLARE(_error_RGB565A8_31x40);

LV_FONT_DECLARE(lv_font_montserratMedium_40)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_70)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_montserratMedium_35)
LV_FONT_DECLARE(lv_font_montserratMedium_20)


#ifdef __cplusplus
}
#endif
#endif
