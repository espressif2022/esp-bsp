/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

const char *items_main_loop[MAX_MAIN_LOOP_ITEMS][2] = {
    {"Service status", "État du service"},
    {"Wi-Fi password", "Mot de passe Wi-Fi"},
    {"Connect Fibe TV receiver", "Connecter un récepteur Télé Fibe"},
    {"Connect Wi-Fi device (WPS)", "Connecter un appareil Wi-Fi (WPS)"},
    {"Modem management", "Configuration du modem"},
    {"Test internet speed", "Vérification de la vitesse"},
    {"Bell Apps", "Applications Bell"},
    {"Restart the modem", "Redémarrer le modem"},
    {"Passer au français", "Switch to English"},
    {"Close", "Fermer"}
};

const char *items_bell_apps[MAX_BELL_APPS_ITEMS][2] = {
    {"Wi-Fi App", "Application Wi-Fi"},
    {"Fibe TV app", "Application Fibe TV"},
    {"Virtual repair tool", "Outil de réparation virtuel"},
};

static lv_obj_t *mask_upper_layer;
static lv_obj_t *mask_down_layer;

lv_obj_t *cont_main_loop;
lv_obj_t *cont_bellapps;

main_loop_cfg_t main_loop_cfg;

/* Function to calculate the total content height of the container */
static int32_t get_content_height(lv_obj_t *cont)
{
    int32_t h = 0;
    int32_t pad_row = lv_obj_get_style_pad_row(cont, LV_PART_MAIN);
    int32_t total = (int32_t)lv_obj_get_child_count(cont);

    for (int i = 0; i < total; i++) {
        h += lv_obj_get_height(lv_obj_get_child(cont, i));
        if (i < total - 1) {
            h += pad_row;
        }
    }
    return h + lv_obj_get_style_pad_top(cont, LV_PART_MAIN)
           + lv_obj_get_style_pad_bottom(cont, LV_PART_MAIN);
}

static void main_loop_infinite_event_cb(lv_event_t *e)
{
    lv_obj_t *cont = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // static bool is_adjusting = false;

    if (code == LV_EVENT_SCROLL) {
        lv_area_t cont_a;
        lv_obj_get_coords(cont, &cont_a);
        int32_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

        uint32_t child_cnt = lv_obj_get_child_count(cont);
        for (int i = 0; i < child_cnt; i++) {
            lv_obj_t *child = lv_obj_get_child(cont, i);
            lv_area_t child_a;
            lv_obj_get_coords(child, &child_a);

            int32_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;
            int32_t diff_y = child_y_center - cont_y_center;
            diff_y = LV_ABS(diff_y);

            // lv_opa_t opa = lv_map(diff_y, 0, lv_obj_get_height(cont) / 2, LV_OPA_COVER, LV_OPA_TRANSP);
            // printf("[%d], diff_y: %d, pos:[%03d,%03d]\n", i, diff_y, child_a.y1, child_a.y2);

            lv_color_t color = lv_color_mix(lv_color_black(), lv_color_hex(0x004D8F), lv_map(diff_y, 0, lv_obj_get_height(cont) / 2, 0, 255));
            lv_obj_set_style_bg_color(child, color, 0);

        }
    } else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
    } else if (code == LV_EVENT_DRAW_POST_END) {
    } else if (code == LV_EVENT_SCROLL_BEGIN) {
        int32_t scroll_y = lv_obj_get_scroll_y(cont);
        // printf("start, scroll_y:%d\r\n", scroll_y);
    } else if (code == LV_EVENT_SCROLL_END) {
        int32_t scroll_y = lv_obj_get_scroll_y(cont);
        // int32_t cont_h = lv_obj_get_height(cont);
        // int32_t content_h = get_content_height(cont);
        int32_t child_cnt = lv_obj_get_child_count(cont);

        // printf("scroll_y: %d, content_h: %d, cont_h: %d, left:%d, cnt:%d\n", scroll_y, content_h, cont_h, content_h - cont_h, child_cnt);

        if (scroll_y == (-75 + 90 * 1)) { //jump
            lv_obj_scroll_to_y(cont, -75 + 90 * (child_cnt - 6 + 1), LV_ANIM_OFF);
            printf("end:1, scroll_y:%d -> %d\r\n", scroll_y, -75 + 90 * (child_cnt - 6 + 1));
        } else if (scroll_y == (-75 + 90 * (child_cnt - 2))) { //jump
            lv_obj_scroll_to_y(cont, -75 + 90 * 4, LV_ANIM_OFF);
            printf("end:2 , scroll_y:%d -> %d\r\n", scroll_y, -75 + 90 * 4);
        }
    }
}

void create_main_loop_mask(void)
{
    static const lv_color_t mask_colors[2] = {
        LV_COLOR_MAKE(0x00, 0x00, 0x00),
        LV_COLOR_MAKE(0x00, 0x00, 0x00)
    };

    static lv_opa_t mask_opacity_upper[2] = {
        LV_OPA_COVER,
        LV_OPA_30
    };

    static lv_opa_t mask_opacity_down[2] = {
        LV_OPA_30,
        LV_OPA_COVER
    };

    static lv_style_t mask_style_upper;
    static lv_style_t mask_style_down;
    static lv_grad_dsc_t mask_gradient_upper;
    static lv_grad_dsc_t mask_gradient_down;

    lv_style_init(&mask_style_upper);
    lv_style_init(&mask_style_down);

    lv_gradient_init_stops(&mask_gradient_upper, mask_colors, mask_opacity_upper, NULL, 2);
    lv_gradient_init_stops(&mask_gradient_down, mask_colors, mask_opacity_down, NULL, 2);

    lv_grad_linear_init(&mask_gradient_upper, lv_pct(50), lv_pct(0), lv_pct(50), lv_pct(100), LV_GRAD_EXTEND_PAD);
    lv_grad_linear_init(&mask_gradient_down, lv_pct(50), lv_pct(0), lv_pct(50), lv_pct(100), LV_GRAD_EXTEND_PAD);

    lv_style_set_bg_grad(&mask_style_upper, &mask_gradient_upper);
    lv_style_set_bg_grad(&mask_style_down, &mask_gradient_down);

    mask_upper_layer = lv_obj_create(lv_screen_active());
    lv_obj_align(mask_upper_layer, LV_ALIGN_TOP_MID, 0, 70);
    lv_obj_set_size(mask_upper_layer, lv_pct(100), 85);
    lv_obj_set_style_bg_opa(mask_upper_layer, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(mask_upper_layer, 0, 0);
    lv_obj_add_style(mask_upper_layer, &mask_style_upper, 0);

    mask_down_layer = lv_obj_create(lv_screen_active());
    lv_obj_align(mask_down_layer, LV_ALIGN_TOP_MID, 0, 252);
    lv_obj_set_size(mask_down_layer, lv_pct(100), 85);
    lv_obj_set_style_bg_opa(mask_down_layer, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(mask_down_layer, 0, 0);
    lv_obj_add_style(mask_down_layer, &mask_style_down, 0);
}

lv_obj_t *create_main_loop_item(lv_obj_t *parent, const char *text)
{
    lv_obj_t *btn = lv_button_create(parent);
    lv_obj_set_size(btn, lv_pct(90), 80);
    lv_obj_set_style_border_width(btn, 0, 0);
    lv_obj_set_style_bg_color(btn, lv_color_hex(0x004D8F), 0);

    lv_obj_t *icon = lv_label_create(btn);
    lv_label_set_text(icon, LV_SYMBOL_DIRECTORY);
    lv_obj_align(icon, LV_ALIGN_LEFT_MID, 10, 0);
    lv_obj_set_style_text_color(icon, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, &lv_font_montserratMedium_25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 40, 0);
    lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), 0);

    return btn;
}

// [7 8 9] 0 1 2 3 4 5 6 7 8 9 [0 1 2]
void add_main_loop_items(lv_obj_t *parent, uint16_t mask, uint8_t lang)
{
    uint16_t mask_tmp = mask;
    mask_tmp = mask >> 1;

    if ((mask == main_loop_cfg.loop_mask) && (lang == main_loop_cfg.lang)) {
        printf("add_main_loop_items: same, mask:%04X(%04X), lang:%d(%d)\n", mask, main_loop_cfg.loop_mask, lang, main_loop_cfg.lang);
        return;
    } else {
        clear_main_loop_items(parent);
    }

    for (uint32_t i = 0; i < MAX_MAIN_LOOP_ITEMS; i++) {
        if (mask_tmp & (1 << i)) {
            create_main_loop_item(parent, items_main_loop[i][lang]);
        }
    }
    uint8_t count = lv_obj_get_child_count(parent);

    for (int i = 0; i < 6; i++) {
        lv_obj_t *copy_obj = (i < 3) ? lv_obj_get_child(parent, i) : lv_obj_get_child(parent, count - 3 + (i % 3));
        lv_obj_t *copy_label = lv_obj_get_child(copy_obj, 1);
        create_main_loop_item(parent, lv_label_get_text(copy_label));
    }
    for (int i = 0; i < 3; i++) {
        lv_obj_t *last_child = lv_obj_get_child(parent, lv_obj_get_child_count(parent) - 1);
        lv_obj_move_to_index(last_child, 0);
    }
    main_loop_cfg.loop_mask = mask;
    main_loop_cfg.lang = lang;
    printf("add_main_loop_items: %d, mask:%04X, lang:%d\n", count, mask, lang);

    lv_obj_scroll_to_view(lv_obj_get_child(parent, 3), LV_ANIM_OFF);
}

void clear_main_loop_items(lv_obj_t *parent)
{
    while (lv_obj_get_child_count(parent) > 0) {
        lv_obj_t *child_btn = lv_obj_get_child(parent, 0);
        lv_obj_del(child_btn);
    }
}

static void arc_anim_cb(void *obj, int32_t v)
{
    lv_arc_set_value((lv_obj_t *)obj, v);
}

void create_arc_loading(uint16_t pos_x, uint16_t pos_y)
{
    /*Create an Arc*/
    lv_obj_t *arc = lv_arc_create(lv_screen_active());

    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_MAIN);   /*Be sure the knob is not displayed*/
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_remove_flag(arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
    lv_obj_set_style_arc_color(arc, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);

    /* Set the gradient color for the arc */
    lv_style_t style;
    lv_style_init(&style);
    lv_style_set_arc_width(&style, 6);

    static lv_grad_dsc_t grad;
    lv_color_t colors[] = {lv_color_hex(0x000000), lv_color_hex(0xFFFFFF)};
    lv_opa_t opacities[] = {LV_OPA_COVER, LV_OPA_COVER};
    lv_gradient_init_stops(&grad, colors, opacities, NULL, 2);
    lv_grad_linear_init(&grad, lv_pct(50), lv_pct(0), lv_pct(50), lv_pct(100), LV_GRAD_EXTEND_PAD);
    // lv_grad_conical_init(&grad, LV_GRAD_CENTER, LV_GRAD_CENTER, 45, 125, LV_GRAD_EXTEND_REFLECT);
    lv_style_set_bg_grad(&style, &grad);

    // lv_obj_add_style(arc, &style, LV_PART_INDICATOR);

    lv_obj_align(arc, LV_ALIGN_TOP_LEFT, pos_x, pos_y);
    lv_obj_set_size(arc, 80, 80);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc);
    lv_anim_set_exec_cb(&a, arc_anim_cb);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);    /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);
}

void lv_main_loop_loading(void)
{
    printf("Loading main loop...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_bell, lv_screen_active());

    cont_main_loop = lv_obj_create(lv_screen_active());
    lv_obj_set_size(cont_main_loop, lv_pct(100), 262);
    lv_obj_align(cont_main_loop, LV_ALIGN_TOP_MID, 0, 70);
    lv_obj_set_scroll_snap_y(cont_main_loop, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_flex_flow(cont_main_loop, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(cont_main_loop, main_loop_infinite_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_opa(cont_main_loop, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(cont_main_loop, 0, 0);
    lv_obj_set_style_radius(cont_main_loop, 0, 0);
    lv_obj_add_flag(cont_main_loop, LV_OBJ_FLAG_SCROLL_ONE);

    add_main_loop_items(cont_main_loop, 0x07FE, 0);
    create_main_loop_mask();

    /*Update the buttons position manually for first*/
    lv_obj_send_event(cont_main_loop, LV_EVENT_SCROLL, NULL);
}

void lv_bu_loading(void)
{
    printf("Loading bu...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());

    create_arc_loading(78, 158);
}

void lv_restart_loading()
{
    printf("Loading restart...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());

    create_arc_loading(46, 216);
}

void lv_apps_loading(void)
{
    printf("Loading bellapps...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());

    cont_bellapps = lv_obj_create(lv_screen_active());
    lv_obj_set_size(cont_bellapps, lv_pct(100), 262);
    lv_obj_align(cont_bellapps, LV_ALIGN_TOP_MID, 0, 150);
    lv_obj_set_scroll_snap_y(cont_bellapps, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_flex_flow(cont_bellapps, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_bg_opa(cont_bellapps, LV_OPA_TRANSP, 0); // Set container background to transparent
    lv_obj_set_style_border_width(cont_bellapps, 0, 0); // Remove border
    lv_obj_set_style_radius(cont_bellapps, 0, 0); // Set corners to right angles
    lv_obj_add_flag(cont_bellapps, LV_OBJ_FLAG_SCROLL_ONE);

    for (uint32_t i = 0; i < MAX_BELL_APPS_ITEMS; i++) {
        lv_obj_t *obj;
        lv_obj_t *label;

        /*Add items_bell_apps to the column*/
        obj = lv_button_create(cont_bellapps);
        lv_obj_set_size(obj, lv_pct(90), 80);
        lv_obj_set_style_border_width(obj, 0, 0); // Remove border
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), 0); // Set button background color to blue

        lv_obj_t *icon = lv_label_create(obj);
        lv_label_set_text(icon, LV_SYMBOL_DIRECTORY); // Set icon to directory symbol
        lv_obj_align(icon, LV_ALIGN_LEFT_MID, 10, 0); // Align icon to the left middle of the button with some padding
        lv_obj_set_style_text_color(icon, lv_color_hex(0x004D8F), 0); // Set icon color to white

        label = lv_label_create(obj);
        lv_label_set_text(label, items_bell_apps[i][0]);
        lv_obj_set_style_text_font(label, &lv_font_montserratMedium_25, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 40, 0); // Align label to the left middle of the button with some padding after the icon
        lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), 0); // Set label text color to white
    }
    lv_obj_scroll_to_view(lv_obj_get_child(cont_bellapps, 1), LV_ANIM_OFF);

    /*Update the buttons position manually for first*/
    lv_obj_send_event(cont_bellapps, LV_EVENT_SCROLL, NULL);
}

void lv_wpsd_loading(void)
{
    printf("Loading wpsd...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());

}
void lv_app_detail_loading(void)
{
    printf("Loading app detail:%p...\n", guider_ui.screen_title_cont_title);
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());
}
void lv_select_loading(void)
{
    printf("Loading select...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());
}
void lv_error_loading(void)
{
    printf("Loading error...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_bell, lv_screen_active());
}
void lv_mm_loading(void)
{
    printf("Loading mm...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());
}
void lv_speed_test_loading(void)
{
    printf("Loading speed test...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());
}
void lv_network_loading(void)
{
    printf("Loading network...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());
}
void lv_notif_loading(void)
{
    printf("Loading notif...\n");
    lv_obj_set_parent(guider_ui.screen_title_cont_title, lv_screen_active());
    lv_obj_set_parent(guider_ui.screen_title_cont_bell, lv_screen_active());
}

void custom_init(lv_ui *ui)
{
    printf("custom_init\r\n");
    setup_scr_screen_title(ui);

    setup_scr_screen_app_detail(ui);
    setup_scr_screen_apps(ui);
    setup_scr_screen_bu0(ui);
    setup_scr_screen_bu1(ui);
    setup_scr_screen_bu2(ui);
    setup_scr_screen_bu3(ui);
    setup_scr_screen_error(ui);
    setup_scr_screen_main_loop(ui);
    setup_scr_screen_mm_1(ui);
    setup_scr_screen_network(ui);
    setup_scr_screen_notif(ui);
    setup_scr_screen_restart(ui);
    setup_scr_screen_STB1(ui);
    setup_scr_screen_select(ui);
    setup_scr_screen_speedtest(ui);
    setup_scr_screen_wpsd_2(ui);

    lv_screen_load(guider_ui.screen_main_loop);
    // lv_screen_load(guider_ui.screen_apps);
}
