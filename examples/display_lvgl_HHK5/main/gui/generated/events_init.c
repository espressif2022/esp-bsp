/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern void lv_main_loop_loading(void);
void lv_bu_loading(void);
void lv_apps_loading(void);
void lv_restart_loading(void);

static void screen_main_loop_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_main_loop_loading();
        break;
    }
    default:
        break;
    }
}

static void screen_main_loop_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_bu0, guider_ui.screen_bu0_del, &guider_ui.screen_main_loop_del, setup_scr_screen_bu0, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_main_loop (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_main_loop, screen_main_loop_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_main_loop_btn_1, screen_main_loop_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_bu0_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_bu1, guider_ui.screen_bu1_del, &guider_ui.screen_bu0_del, setup_scr_screen_bu1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_bu0 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_bu0_btn_1, screen_bu0_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_bu1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_bu_loading();
        break;
    }
    default:
        break;
    }
}

static void screen_bu1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_bu2, guider_ui.screen_bu2_del, &guider_ui.screen_bu1_del, setup_scr_screen_bu2, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_bu1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_bu1, screen_bu1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_bu1_btn_1, screen_bu1_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_bu2_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_bu3, guider_ui.screen_bu3_del, &guider_ui.screen_bu2_del, setup_scr_screen_bu3, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_bu2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_bu2_btn_1, screen_bu2_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_bu3_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_STB1, guider_ui.screen_STB1_del, &guider_ui.screen_bu3_del, setup_scr_screen_STB1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_bu3 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_bu3_btn_1, screen_bu3_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_STB1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_notif, guider_ui.screen_notif_del, &guider_ui.screen_STB1_del, setup_scr_screen_notif, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_STB1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_STB1_btn_2, screen_STB1_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_notif_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_network, guider_ui.screen_network_del, &guider_ui.screen_notif_del, setup_scr_screen_network, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_notif (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_notif_btn_2, screen_notif_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_network_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_speedtest, guider_ui.screen_speedtest_del, &guider_ui.screen_network_del, setup_scr_screen_speedtest, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_network (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_network_btn_1, screen_network_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_speedtest_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_mm_1, guider_ui.screen_mm_1_del, &guider_ui.screen_speedtest_del, setup_scr_screen_mm_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_speedtest (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_speedtest_btn_2, screen_speedtest_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_mm_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_error, guider_ui.screen_error_del, &guider_ui.screen_mm_1_del, setup_scr_screen_error, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_mm_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_mm_1_btn_2, screen_mm_1_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_error_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_apps, guider_ui.screen_apps_del, &guider_ui.screen_error_del, setup_scr_screen_apps, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_error (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_error_btn_1, screen_error_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_apps_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_apps_loading();
        break;
    }
    default:
        break;
    }
}

static void screen_apps_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_select, guider_ui.screen_select_del, &guider_ui.screen_apps_del, setup_scr_screen_select, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_apps (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_apps, screen_apps_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_apps_btn_2, screen_apps_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_select_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_restart, guider_ui.screen_restart_del, &guider_ui.screen_select_del, setup_scr_screen_restart, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_select (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_select_btn_4, screen_select_btn_4_event_handler, LV_EVENT_ALL, ui);
}

static void screen_restart_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_restart_loading();
        break;
    }
    default:
        break;
    }
}

static void screen_restart_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_loop, guider_ui.screen_main_loop_del, &guider_ui.screen_restart_del, setup_scr_screen_main_loop, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_restart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_restart, screen_restart_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_restart_btn_1, screen_restart_btn_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
