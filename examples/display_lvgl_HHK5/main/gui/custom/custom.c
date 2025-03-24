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
            // printf("[%d], diff_y: %d, pos:[%03d,%03d]\n", i, diff_y, child_a.y1, child_a.y2);
            // lv_obj_set_style_opa(child, opa, 0);

            lv_color_t color = lv_color_mix(lv_color_black(), lv_color_hex(0x004D8F), lv_map(diff_y, 0, lv_obj_get_height(cont) / 2, 0, 255));
            lv_obj_set_style_bg_color(child, color, 0);

            if (diff_y == 0) {
                focus_index = i;
            }
        }
    } else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        // printf("LV_EVENT_DRAW_MAIN_BEGIN:%d\n", focus_index);

        lv_obj_t * child;
        lv_area_t child_focus, child_prev, child_next;

        child = lv_obj_get_child(cont, focus_index - 1);
        if (child) {
            lv_obj_get_coords(child, &child_prev);
            // printf("child_prev,%p:[%03d,%03d]\n", child_prev, child_prev.y1, child_prev.y2);
        }

        child = lv_obj_get_child(cont, focus_index);
        lv_obj_get_coords(child, &child_focus);
        if (child) {
            // printf("child_focus,%p:[%03d,%03d]\n", child_focus, child_focus.y1, child_focus.y2);
        }

        child = lv_obj_get_child(cont, focus_index + 1);
        if (child) {
            lv_obj_get_coords(child, &child_next);
            // printf("child_next,%p:[%03d,%03d]\n", child_next, child_next.y1, child_next.y2);
        }

    } else if (code == LV_EVENT_DRAW_POST_END) {
        // printf("LV_EVENT_DRAW_POST_END:%d\n", focus_index);
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
lv_obj_t * cont_col;
void lv_main_loop_loading(void)
{
    /*Create a container with COLUMN flex direction*/
    cont_col = lv_obj_create(lv_screen_active());
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

#define ITEM_CNT 5

lv_draw_buf_t* pSpinMask = NULL;
lv_timer_t* tim = NULL;

volatile lv_area_t sw_area = {0};

uint8_t buf_SpinMask[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 132, 140, 138, 135, 132, 129, 126, 123, 120, 117, 114, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 135, 147, 147, 142, 140, 138, 135, 132, 129, 126, 123, 120, 117, 114, 108, 96, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 153, 153, 148, 147, 146, 142, 139, 135, 132, 129, 126, 123, 119, 116, 113, 111, 108, 102, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 157, 157, 153, 151, 148, 146, 139, 135, 132, 129, 126, 123, 119, 116, 113, 113, 109, 107, 104, 102, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 161, 161, 157, 157, 153, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 109, 104, 102, 102, 98, 0, 0, 0, 0,
    0, 0, 0, 165, 165, 162, 162, 157, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92, 102, 102, 98, 98, 94, 0, 0, 0,
    0, 0, 165, 168, 166, 166, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 98, 94, 94, 90, 0, 0,
    0, 153, 172, 170, 168, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93, 93, 90, 90, 76, 0,
    0, 172, 174, 173, 173, 148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 89, 87, 85, 83, 0,
    162, 178, 177, 177, 173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 85, 83, 83, 73,
    178, 181, 180, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 82, 78, 77,
    181, 184, 183, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 75, 78, 77, 74,
    184, 187, 186, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 75, 74, 71,
    187, 190, 189, 186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69, 72, 71, 68,
    190, 193, 193, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 69, 68, 65,
    193, 196, 196, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 65, 65, 62,
    196, 199, 199, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59, 62, 62, 59,
    199, 201, 202, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 59, 59, 56,
    201, 204, 205, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 56, 56, 53,
    204, 205, 209, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 53, 53, 51,
    191, 211, 211, 212, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 50, 50, 51, 44,
    0, 211, 212, 215, 216, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 46, 46, 47, 44, 0,
    0, 193, 217, 217, 221, 221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 40, 43, 44, 37, 0,
    0, 0, 217, 221, 221, 225, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 38, 38, 40, 38, 0, 0,
    0, 0, 0, 221, 225, 225, 230, 230, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 30, 34, 34, 38, 38, 0, 0, 0,
    0, 0, 0, 0, 225, 229, 230, 232, 237, 237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 25, 30, 30, 34, 34, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 229, 232, 234, 237, 241, 241, 244, 247, 250, 253, 0, 5, 8, 13, 18, 21, 23, 26, 30, 30, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 229, 236, 238, 241, 244, 247, 250, 253, 253, 253, 253, 11, 14, 18, 19, 21, 26, 26, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 207, 236, 242, 245, 247, 250, 253, 253, 253, 7, 10, 13, 17, 17, 19, 20, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 242, 245, 247, 250, 253, 253, 5, 7, 10, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static void arc_anim_start_cb(lv_timer_t* tim)  // 渐变加载回调
{
    uint8_t* p_arr = buf_SpinMask;
    lv_obj_t* table = lv_timer_get_user_data(tim);

    for (int i = 0; i < 900; ++i)
        if (p_arr[i]) {
            p_arr[i] += 10;
            if (!p_arr[i]) {
                p_arr[i] = 1;
            }
        }
    //lv_obj_invalidate(table);     //多个
    lv_obj_invalidate_area(table, &sw_area);    // 刷新对应的区域，在只有一个环形渐变加载器时时可以正常使用的
    // lv_log("_2");                               // 如果需要同时多个加载器一起转，可以将上面的单个区域变量，换成数组，存储多个区域，并使能刷新
}

static void draw_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    // lv_draw_dsc_base_t * base_dsc = (lv_draw_dsc_base_t *)(draw_task->draw_dsc);
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task);

    /*If the cells are drawn...*/
    if (base_dsc->part == LV_PART_ITEMS && lv_draw_task_get_type(draw_task) == LV_DRAW_TASK_TYPE_FILL) {
        /*Draw the background*/
        bool chk = lv_table_has_cell_ctrl(obj, base_dsc->id1, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
        if (chk) {
            sw_area.x1 = 0;     sw_area.x2 = 29;
            sw_area.y1 = 0;     sw_area.y2 = 29;

            lv_area_t draw_task_area;
            lv_draw_task_get_area(draw_task, &draw_task_area);

            lv_area_align(&draw_task_area, &sw_area, LV_ALIGN_RIGHT_MID, -15, 0);      // 绘图区域定位

            lv_layer_t* new_layer = lv_draw_layer_create(base_dsc->layer, LV_COLOR_FORMAT_L8, &sw_area);        // 创建一个新层
            new_layer->draw_buf = lv_draw_buf_create(30, 30, LV_COLOR_FORMAT_L8, LV_DRAW_BUF_STRIDE(30, LV_COLOR_FORMAT_L8));// 给新层一个draw_buf，默认为空，
            lv_memzero(new_layer->draw_buf->data, new_layer->draw_buf->data_size);  // 内存清0，不清0会导致图像有异常

            lv_draw_arc_dsc_t arc_dsc;
            lv_draw_arc_dsc_init(&arc_dsc);
            arc_dsc.radius = 15;
            arc_dsc.width = 3;
            arc_dsc.color = lv_color_white();
            arc_dsc.rounded = false;
            arc_dsc.start_angle = 0;
            arc_dsc.end_angle = 360;
            arc_dsc.center.x = sw_area.x1 + 15;
            arc_dsc.center.y = sw_area.y1 + 15;
            lv_draw_arc(base_dsc->layer, &arc_dsc);       // 画一个圆环

            lv_draw_image_dsc_t layer_draw_dsc;
            lv_draw_image_dsc_init(&layer_draw_dsc);

            layer_draw_dsc.pivot.x = arc_dsc.center.x;
            layer_draw_dsc.pivot.y = arc_dsc.center.y;
            layer_draw_dsc.opa = LV_OPA_100;
            layer_draw_dsc.rotation = 0;
            layer_draw_dsc.antialias = 0;
            layer_draw_dsc.blend_mode = LV_BLEND_MODE_NORMAL;
            // const lv_image_dsc_t * bitmap_mask_src;
            layer_draw_dsc.bitmap_mask_src = (const lv_image_dsc_t *)pSpinMask;
            layer_draw_dsc.image_area = sw_area;
            layer_draw_dsc.src = new_layer;
            lv_draw_layer(base_dsc->layer, &layer_draw_dsc, &sw_area);      // 画bitmap透明度

            // lv_log("1_");
        } else {
            // lv_log("0_");
        }
    }
}

static void change_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    uint32_t col;
    uint32_t row;
    lv_table_get_selected_cell(obj, &row, &col);
    bool chk = lv_table_has_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
    if (chk) {
        lv_table_clear_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
        lv_timer_pause(tim);        //启动定时器
    } else {
        lv_table_add_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
        lv_timer_resume(tim);       // 挂起定时器
    }
}

/**
 * A very light-weighted list created from table
 */
// .data = buf ##name,
// .unaligned data = buf ##name,
void create_arc_2()
{
    // 给bitmap透明度数组创建描述符
    static lv_draw_buf_t SpinMask = { \
                                      .header = { \
                                                  .magic = LV_IMAGE_HEADER_MAGIC, \
                                                  .cf = (LV_COLOR_FORMAT_L8), \
                                                  .flags = LV_IMAGE_FLAGS_MODIFIABLE, \
                                                  .w = (30), \
                                                  .h = (30), \
                                                  .stride = LV_DRAW_BUF_STRIDE(30, LV_COLOR_FORMAT_L8), \
                                                  .reserved_2 = 0, \
                                                }, \
                                      .data_size = sizeof(buf_SpinMask), \
                                      .data = buf_SpinMask, \
                                      .unaligned_data = buf_SpinMask, \
                                    };
    LV_DRAW_BUF_INIT_STATIC(SpinMask);
    pSpinMask = &SpinMask;

    // 下面英文注释的都是没有修改的
    /*Measure memory usage*/
    lv_mem_monitor_t mon1;
    lv_mem_monitor(&mon1);

    uint32_t t = lv_tick_get();

    lv_obj_t* table = lv_table_create(lv_screen_active());

    /*Set a smaller height to the table. It'll make it scrollable*/
    lv_obj_set_size(table, LV_SIZE_CONTENT, 200);

    lv_table_set_column_width(table, 0, 150);
    lv_table_set_row_count(table, ITEM_CNT); /*Not required but avoids a lot of memory reallocation lv_table_set_set_value*/
    lv_table_set_column_count(table, 1);

    /* Set table background color to black */
    lv_obj_set_style_bg_color(table, lv_color_hex(0x000000), 0);

    /*Don't make the cell pressed, we will draw something different in the event*/
    lv_obj_remove_style(table, NULL, LV_PART_ITEMS | LV_STATE_PRESSED);

    uint32_t i;
    for (i = 0; i < ITEM_CNT; i++) {
        lv_table_set_cell_value_fmt(table, i, 0, "Item %"LV_PRIu32, i + 1);
    }

    lv_obj_align(table, LV_ALIGN_CENTER, 0, -20);

    /*Add an event callback to to apply some custom drawing*/
    lv_obj_add_event_cb(table, draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_event_cb(table, change_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_flag(table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    lv_mem_monitor_t mon2;
    lv_mem_monitor(&mon2);

    size_t mem_used = mon1.free_size - mon2.free_size;

    uint32_t elaps = lv_tick_elaps(t);

    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text_fmt(label, "%"LV_PRIu32" items were created in %"LV_PRIu32" ms\n"
                          "using %zu bytes of memory",
                          (uint32_t)ITEM_CNT, elaps, mem_used);

    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -10);

    // 创建定时器，用定时器去周期回调，这个就不是英文注释了
    tim = lv_timer_create(arc_anim_start_cb, 50, (void*)table);
    lv_timer_pause(tim);

}

void lv_example_arc_loading(void)
{
    // create_arc_2();
    // return;

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

    // lv_obj_add_style(arc, &style, LV_PART_INDICATOR);

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
    lv_obj_set_size(cont_col, lv_pct(100), 220);
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
        lv_obj_set_size(obj, lv_pct(90), 80);
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
