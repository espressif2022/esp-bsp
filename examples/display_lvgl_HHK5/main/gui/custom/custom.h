/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

#define MAX_MAIN_LOOP_ITEMS 10
#define MAX_BELL_APPS_ITEMS 3

typedef struct {
    uint16_t loop_mask;
    uint8_t lang;
} main_loop_cfg_t;

extern const char *items_main_loop[][2];

extern const char *items_bell_apps[][2];

extern main_loop_cfg_t main_loop_cfg;

void custom_init(lv_ui *ui);

void add_main_loop_items(lv_obj_t *parent, uint16_t mask, uint8_t lang);

void clear_main_loop_items(lv_obj_t *parent);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
