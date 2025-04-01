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
extern void lv_notif_loading(void);
extern void lv_network_loading(void);
extern void lv_speed_test_loading(void);
extern void lv_mm_loading(void);
extern void lv_error_loading(void);
extern void lv_apps_loading(void);
extern void lv_select_loading(void);
extern void lv_restart_loading(void);
extern void lv_wpsd_loading(void);
extern void lv_app_detail_loading(void);

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

void events_init_screen_main_loop (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_main_loop, screen_main_loop_event_handler, LV_EVENT_ALL, ui);
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

void events_init_screen_bu1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_bu1, screen_bu1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_STB1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {

        break;
    }
    default:
        break;
    }
}

void events_init_screen_STB1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_STB1, screen_STB1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_notif_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_notif_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_notif (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_notif, screen_notif_event_handler, LV_EVENT_ALL, ui);
}

static void screen_network_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_network_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_network (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_network, screen_network_event_handler, LV_EVENT_ALL, ui);
}

static void screen_speedtest_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_speed_test_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_speedtest (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_speedtest, screen_speedtest_event_handler, LV_EVENT_ALL, ui);
}

static void screen_mm_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_mm_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_mm_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_mm_1, screen_mm_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_error_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_error_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_error (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_error, screen_error_event_handler, LV_EVENT_ALL, ui);
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

void events_init_screen_apps (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_apps, screen_apps_event_handler, LV_EVENT_ALL, ui);
}

static void screen_select_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_select_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_select (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_select, screen_select_event_handler, LV_EVENT_ALL, ui);
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

void events_init_screen_restart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_restart, screen_restart_event_handler, LV_EVENT_ALL, ui);
}

static void screen_wpsd_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_wpsd_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_wpsd_2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_wpsd_2, screen_wpsd_2_event_handler, LV_EVENT_ALL, ui);
}

static void screen_app_detail_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_app_detail_loading();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_app_detail (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_app_detail, screen_app_detail_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
