/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "bsp/esp-bsp.h"
#include "thorvg_capi.h"

static const char *TAG = "THORVG";

#define OFFSET              100
#define LOTTIE_SIZE_HOR     300
#define LOTTIE_SIZE_VER     300

static uint16_t argb888_to_rgb565(uint32_t argb888)
{
    uint8_t r = (argb888 >> 16) & 0xFF;
    uint8_t g = (argb888 >> 8) & 0xFF;
    uint8_t b = argb888 & 0xFF;

    uint16_t r_565 = (r >> 3) << 11;
    uint16_t g_565 = (g >> 2) << 5;
    uint16_t b_565 = b >> 3;

    return r_565 | g_565 | b_565;
}

static void convert_argb888_to_rgb565(const uint32_t *argb888_array, uint16_t *rgb565_array, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        rgb565_array[i] = argb888_to_rgb565(argb888_array[i]);
    }
}

void example_thorvg_shape(void *arg)
{
    bsp_lcd_handles_t *lcd_panels = (bsp_lcd_handles_t *) arg;
    assert(lcd_panels);

    uint32_t *lottile_cavas_888 = NULL;
    uint16_t *lottile_cavas_565 = NULL;

    lottile_cavas_888 = heap_caps_malloc(LOTTIE_SIZE_HOR * LOTTIE_SIZE_VER * sizeof(uint32_t), MALLOC_CAP_SPIRAM);
    assert(lottile_cavas_888);

    lottile_cavas_565 = heap_caps_malloc(LOTTIE_SIZE_HOR * LOTTIE_SIZE_VER * sizeof(uint16_t), MALLOC_CAP_SPIRAM);
    assert(lottile_cavas_565);

    assert(tvg_engine_init(TVG_ENGINE_SW, 0) == TVG_RESULT_SUCCESS);

    Tvg_Canvas *canvas = tvg_swcanvas_create();
    assert(canvas);

    assert(tvg_swcanvas_set_target(canvas, lottile_cavas_888, LOTTIE_SIZE_HOR, LOTTIE_SIZE_HOR, LOTTIE_SIZE_VER, TVG_COLORSPACE_ARGB8888) == TVG_RESULT_SUCCESS);

    Tvg_Paint *paint = tvg_shape_new();
    assert(paint);

    assert(tvg_shape_append_rect(paint, 0, 0, 100, 100, 0, 0) == TVG_RESULT_SUCCESS);
    assert(tvg_shape_set_fill_color(paint, 255, 0, 0, 255) == TVG_RESULT_SUCCESS);

    assert(tvg_canvas_push(canvas, paint) == TVG_RESULT_SUCCESS);

    assert(tvg_canvas_draw(canvas) == TVG_RESULT_SUCCESS);
    assert(tvg_canvas_sync(canvas) == TVG_RESULT_SUCCESS);

    convert_argb888_to_rgb565(lottile_cavas_888, lottile_cavas_565, LOTTIE_SIZE_HOR * LOTTIE_SIZE_VER);
    esp_lcd_panel_draw_bitmap(lcd_panels->panel, OFFSET + 0, OFFSET + 0, OFFSET + LOTTIE_SIZE_HOR, OFFSET + LOTTIE_SIZE_VER, lottile_cavas_565);

    assert(tvg_canvas_destroy(canvas) == TVG_RESULT_SUCCESS);

    assert(tvg_engine_term(TVG_ENGINE_SW) == TVG_RESULT_SUCCESS);

    if (lottile_cavas_888) {
        free(lottile_cavas_888);
    }

    if (lottile_cavas_565) {
        free(lottile_cavas_565);
    }

    vTaskDelete(NULL);
}

void example_thorvg_lottie(void *arg)
{
    bsp_lcd_handles_t *lcd_panels = (bsp_lcd_handles_t *) arg;
    assert(lcd_panels);

    uint32_t *lottile_cavas_888 = NULL;
    uint16_t *lottile_cavas_565 = NULL;

    lottile_cavas_888 = heap_caps_malloc(LOTTIE_SIZE_HOR * LOTTIE_SIZE_VER * sizeof(uint32_t), MALLOC_CAP_SPIRAM);
    assert(lottile_cavas_888);

    lottile_cavas_565 = heap_caps_malloc(LOTTIE_SIZE_HOR * LOTTIE_SIZE_VER * sizeof(uint16_t), MALLOC_CAP_SPIRAM);
    assert(lottile_cavas_565);

    assert(tvg_engine_init(TVG_ENGINE_SW, 0) == TVG_RESULT_SUCCESS);

    char *src = "/spiffs/lolo_walk.json";

    Tvg_Animation *animation = tvg_animation_new();
    assert(animation);

    Tvg_Paint *picture = tvg_animation_get_picture(animation);
    assert(picture);

    assert(tvg_picture_load(picture, src) == TVG_RESULT_SUCCESS);

    assert(tvg_picture_set_size(picture, LOTTIE_SIZE_HOR, LOTTIE_SIZE_VER) == TVG_RESULT_SUCCESS);

    Tvg_Canvas *canvas = tvg_swcanvas_create();
    assert(canvas);

    assert(tvg_swcanvas_set_target(canvas, lottile_cavas_888, LOTTIE_SIZE_HOR, LOTTIE_SIZE_HOR, LOTTIE_SIZE_VER, TVG_COLORSPACE_ARGB8888) == TVG_RESULT_SUCCESS);
    assert(tvg_canvas_push(canvas, picture) == TVG_RESULT_SUCCESS);

    float f_total;
    float f = 0;
    assert(tvg_animation_get_total_frame(animation, &f_total) == TVG_RESULT_SUCCESS);
    assert(f_total != 0.0f);

    while (f < f_total) {
        assert(tvg_animation_get_frame(animation, &f) == TVG_RESULT_SUCCESS);
        f++;
        if (f >= f_total) {
            f = 0;
        }
        ESP_LOGD(TAG, "set %f / %f", f, f_total);

        assert(tvg_animation_set_frame(animation, f) == TVG_RESULT_SUCCESS);
        assert(tvg_canvas_update(canvas) == TVG_RESULT_SUCCESS);

        assert(tvg_canvas_draw(canvas) == TVG_RESULT_SUCCESS);
        assert(tvg_canvas_sync(canvas) == TVG_RESULT_SUCCESS);

        convert_argb888_to_rgb565(lottile_cavas_888, lottile_cavas_565, LOTTIE_SIZE_HOR * LOTTIE_SIZE_VER);
        esp_lcd_panel_draw_bitmap(lcd_panels->panel, OFFSET + 0, OFFSET + 0, OFFSET + LOTTIE_SIZE_HOR, OFFSET + LOTTIE_SIZE_VER, lottile_cavas_565);

        vTaskDelay(pdMS_TO_TICKS(1));
    }

    assert(tvg_animation_del(animation) == TVG_RESULT_SUCCESS);

    assert(tvg_canvas_destroy(canvas) == TVG_RESULT_SUCCESS);

    assert(tvg_engine_term(TVG_ENGINE_SW) == TVG_RESULT_SUCCESS);

    if (lottile_cavas_888) {
        free(lottile_cavas_888);
    }

    if (lottile_cavas_565) {
        free(lottile_cavas_565);
    }

    vTaskDelete(NULL);
}
