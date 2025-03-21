/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
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

static const char *items[] = {
    "Service status",
    "Wi-Fi password",
    "Connect Fibe TV receiver",
    "Connect Wi-Fi device (WPS)",
    "Modem management",
    "Test internet speed",
    "Bell Apps",
    "Restart the modem",
    "Switch to English",
    "Close"
};

static lv_obj_t * mask_upper_layer;
static lv_obj_t * mask_down_layer;

static void scroll_event_cb(lv_event_t * e)
{
    lv_obj_t * cont = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    static int16_t focus_index = 0;

    if (code == LV_EVENT_SCROLL) {
        lv_area_t cont_a;
        lv_obj_get_coords(cont, &cont_a);
        int32_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

        uint32_t i;
        uint32_t child_cnt = lv_obj_get_child_count(cont);
        for (i = 0; i < child_cnt; i++) {
            lv_obj_t * child = lv_obj_get_child(cont, i);
            lv_area_t child_a;
            lv_obj_get_coords(child, &child_a);

            int32_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;

            int32_t diff_y = child_y_center - cont_y_center;
            diff_y = LV_ABS(diff_y);

            lv_opa_t opa = lv_map(diff_y, 0, lv_obj_get_height(cont) / 2, LV_OPA_COVER, LV_OPA_TRANSP);
            printf("[%d], diff_y: %d, pos:[%03d,%03d]\n", i, diff_y, child_a.y1, child_a.y2);
            // lv_obj_set_style_opa(child, opa, 0);

            lv_color_t color = lv_color_mix(lv_color_black(), lv_color_hex(0x004D8F), lv_map(diff_y, 0, lv_obj_get_height(cont) / 2, 0, 255));
            lv_obj_set_style_bg_color(child, color, 0);

            if (diff_y == 0) {
                focus_index = i;
            }
        }
    } else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        printf("LV_EVENT_DRAW_MAIN_BEGIN:%d\n", focus_index);

        lv_obj_t * child;
        lv_area_t child_focus, child_prev, child_next;

        child = lv_obj_get_child(cont, focus_index - 1);
        if (child) {
            lv_obj_get_coords(child, &child_prev);
            printf("child_prev,%p:[%03d,%03d]\n", child_prev, child_prev.y1, child_prev.y2);
        }

        child = lv_obj_get_child(cont, focus_index);
        lv_obj_get_coords(child, &child_focus);
        if (child) {
            printf("child_focus,%p:[%03d,%03d]\n", child_focus, child_focus.y1, child_focus.y2);
        }

        child = lv_obj_get_child(cont, focus_index + 1);
        if (child) {
            lv_obj_get_coords(child, &child_next);
            printf("child_next,%p:[%03d,%03d]\n", child_next, child_next.y1, child_next.y2);
        }

    } else if (code == LV_EVENT_DRAW_POST_END) {
        printf("LV_EVENT_DRAW_POST_END:%d\n", focus_index);
    }
}

void lv_create_mask(void)
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

/**
 * Translate the object as they scroll
 */
void lv_main_loop_loading(void)
{
    /*Create a container with COLUMN flex direction*/
    lv_obj_t * cont_col = lv_obj_create(lv_screen_active());
    lv_obj_set_size(cont_col, lv_pct(100), 262);
    lv_obj_align(cont_col, LV_ALIGN_TOP_MID, 0, 70);
    lv_obj_set_scroll_snap_y(cont_col, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(cont_col, scroll_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_opa(cont_col, LV_OPA_TRANSP, 0); // Set container background to transparent
    lv_obj_set_style_border_width(cont_col, 0, 0); // Remove border
    lv_obj_set_style_radius(cont_col, 0, 0); // Set corners to right angles

    uint32_t i;
    for (i = 0; i < 10; i++) {
        lv_obj_t * obj;
        lv_obj_t * label;

        /*Add items to the column*/
        obj = lv_button_create(cont_col);
        lv_obj_set_size(obj, lv_pct(90), 80);
        lv_obj_set_style_border_width(obj, 0, 0); // Remove border
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x004D8F), 0); // Set button background color to blue

        lv_obj_t * icon = lv_label_create(obj);
        lv_label_set_text(icon, LV_SYMBOL_DIRECTORY); // Set icon to directory symbol
        lv_obj_align(icon, LV_ALIGN_LEFT_MID, 10, 0); // Align icon to the left middle of the button with some padding
        lv_obj_set_style_text_color(icon, lv_color_hex(0xFFFFFF), 0); // Set icon color to white

        label = lv_label_create(obj);
        lv_label_set_text(label, items[i]);
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 40, 0); // Align label to the left middle of the button with some padding after the icon
        lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), 0); // Set label text color to white
        // lv_obj_set_style_text_font(label, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    }
    lv_obj_scroll_to_view(lv_obj_get_child(cont_col, 0), LV_ANIM_OFF);
    lv_create_mask();

    /*Update the buttons position manually for first*/
    lv_obj_send_event(cont_col, LV_EVENT_SCROLL, NULL);
}

static void arc_anim_cb(void * obj, int32_t v)
{
    lv_arc_set_value((lv_obj_t *)obj, v);
}

void create_arc_2()
{
    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_style_t style;
    lv_style_init(&style);
    lv_style_set_arc_width(&style, 6);
    // lv_style_set_arc_image_src(&style, &_arc_RGB565A8_100x100);

    lv_obj_add_style(arc, &style, 0);

    lv_obj_align(arc, LV_ALIGN_CENTER, 0, 50);
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

void lv_example_arc_loading(void)
{
    /*Create an Arc*/
    lv_obj_t * arc = lv_arc_create(lv_screen_active());

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

    lv_obj_add_style(arc, &style, LV_PART_INDICATOR);

    lv_obj_align(arc, LV_ALIGN_TOP_LEFT, 78, 158);
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

    // create_arc_2();
}

void lv_bu_loading(void)
{
    // lv_obj_t * label = lv_label_create(lv_screen_active());
    // lv_label_set_text(label, "Loading...");
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    printf("Loading...\n");

    lv_example_arc_loading();
}

void lv_apps_loading(void)
{
    const char *items[] = {
        "Wi-Fi App",
        "Fibe TV app",
        "Virtual repair tool",
    };

    /*Create a container with COLUMN flex direction*/
    lv_obj_t * cont_col = lv_obj_create(lv_screen_active());
    lv_obj_set_size(cont_col, 900, 220);
    lv_obj_align(cont_col, LV_ALIGN_TOP_MID, 0, 145);
    lv_obj_set_scroll_snap_y(cont_col, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);
    // lv_obj_add_event_cb(cont_col, scroll_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_opa(cont_col, LV_OPA_TRANSP, 0); // Set container background to transparent
    lv_obj_set_style_border_width(cont_col, 0, 0); // Remove border
    lv_obj_set_style_radius(cont_col, 0, 0); // Set corners to right angles

    uint32_t i;
    for (i = 0; i < 3; i++) {
        lv_obj_t * obj;
        lv_obj_t * label;

        /*Add items to the column*/
        obj = lv_button_create(cont_col);
        lv_obj_set_size(obj, 800, 80);
        lv_obj_set_style_border_width(obj, 0, 0); // Remove border
        // lv_obj_set_style_radius(obj, 0, 0); // Set corners to right angles
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), 0); // Set button background color to blue

        lv_obj_t * icon = lv_label_create(obj);
        lv_label_set_text(icon, LV_SYMBOL_DIRECTORY); // Set icon to directory symbol
        lv_obj_align(icon, LV_ALIGN_LEFT_MID, 10, 0); // Align icon to the left middle of the button with some padding
        lv_obj_set_style_text_color(icon, lv_color_hex(0x004D8F), 0); // Set icon color to white

        label = lv_label_create(obj);
        lv_label_set_text(label, items[i]);
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 40, 0); // Align label to the left middle of the button with some padding after the icon
        lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF), 0); // Set label text color to white
        // lv_obj_set_style_text_font(label, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    }
    lv_obj_scroll_to_view(lv_obj_get_child(cont_col, 1), LV_ANIM_OFF);

    /*Update the buttons position manually for first*/
    lv_obj_send_event(cont_col, LV_EVENT_SCROLL, NULL);
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}
