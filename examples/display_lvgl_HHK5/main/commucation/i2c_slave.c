#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "driver/i2c_master.h"
#include "driver/i2c_slave.h"
#include "driver/gpio.h"

#include "esp_err.h"
#include "esp_log.h"

#include "bsp/esp-bsp.h"
#include "gui_guider.h"
#include "message.h"

// I2C Slave Configuration
#define I2C_SLAVE_SCL_IO        4    /*!< GPIO number for I2C slave clock */
#define I2C_SLAVE_SDA_IO        0    /*!< GPIO number for I2C slave data */
#define I2C_SLAVE_INT_IO        18   /*!< GPIO number for I2C slave interrupt */
#define ESP_SLAVE_ADDR          0x30 /*!< ESP_I2C slave address, you can set any 7bit value */
#define TEST_I2C_PORT           0
#define DATA_LENGTH             100

const char *TAG = "i2c_slave";

typedef struct {
    uint8_t command_data;
    i2c_slave_dev_handle_t handle;
} i2c_slave_context_t;

static QueueHandle_t event_queue;
static uint8_t *temp_data;
static size_t temp_len = 0;

static i2c_slave_context_t context;
typedef enum {
    I2C_SLAVE_EVT_RX,
    I2C_SLAVE_EVT_TX
} i2c_slave_event_t;

void disp_buf(uint8_t *buf, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x ", buf[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

static bool i2c_slave_request_cb(i2c_slave_dev_handle_t i2c_slave, const i2c_slave_request_event_data_t *evt_data, void *arg)
{
    BaseType_t xTaskWoken;
    i2c_slave_event_t evt = I2C_SLAVE_EVT_TX;
    xQueueSendFromISR(event_queue, &evt, &xTaskWoken);
    return xTaskWoken;
}

static bool i2c_slave_receive_cb(i2c_slave_dev_handle_t i2c_slave, const i2c_slave_rx_done_event_data_t *evt_data, void *arg)
{
    BaseType_t xTaskWoken = pdFALSE;
    i2c_slave_event_t evt = I2C_SLAVE_EVT_RX;

    if (evt_data->length <= DATA_LENGTH) {
        memcpy(temp_data, evt_data->buffer, evt_data->length);
        temp_len = evt_data->length;
        xQueueSendFromISR(event_queue, &evt, &xTaskWoken);
    } else {
        ESP_LOGW(TAG, "Received data length exceeds buffer size");
    }

    return xTaskWoken == pdTRUE;
}

void i2c_slave_read_task(void *arg)
{
    i2c_slave_event_t evt;
    uint8_t read_red = 0;
    uint8_t cmd_data[10];
    uint8_t cmd_len = 0;
    uint32_t total_written = 0;

    while (1) {
        if (xQueueReceive(event_queue, &evt, portMAX_DELAY) == pdTRUE) {
            if (evt == I2C_SLAVE_EVT_RX) {
                disp_buf(temp_data, temp_len);
                read_red = temp_data[0];
                message_parse_cmd(temp_data, temp_len);
            } else if (evt == I2C_SLAVE_EVT_TX) {
                switch (context.command_data) {
                case CMD_HELLO:
                    cmd_data[0] = 0x01;
                    cmd_len = 1;
                    break;
                case CMD_GET_FW_VERSION:
                    cmd_data[0] = 0x01;
                    cmd_data[1] = 0x02;
                    cmd_len = 2;
                    break;
                default:
                    ESP_LOGI(TAG, "Unknown command");
                    break;
                }
                i2c_slave_write(context.handle, cmd_data, cmd_len, &total_written, 1000);
                ESP_LOGI(TAG, "I2C_SLAVE_EVT_TX, reg:%02X, %d", cmd_len, total_written);
            }
        }
    }
}

void i2c_slave_start(void)
{
    event_queue = xQueueCreate(2, sizeof(i2c_slave_event_t));
    assert(event_queue);
    temp_data = malloc(DATA_LENGTH);
    assert(temp_data);

    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << I2C_SLAVE_INT_IO);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    gpio_set_level(I2C_SLAVE_INT_IO, 1);

    i2c_slave_config_t i2c_slv_config = {
        .i2c_port = TEST_I2C_PORT,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .scl_io_num = I2C_SLAVE_SCL_IO,
        .sda_io_num = I2C_SLAVE_SDA_IO,
        .slave_addr = ESP_SLAVE_ADDR,
        .send_buf_depth = DATA_LENGTH,
        .receive_buf_depth = DATA_LENGTH,
        .flags.enable_internal_pullup = true,
    };

    i2c_new_slave_device(&i2c_slv_config, &context.handle);

    i2c_slave_event_callbacks_t cbs = {
        .on_receive = i2c_slave_receive_cb,
        .on_request = i2c_slave_request_cb,
    };

    i2c_slave_register_event_callbacks(context.handle, &cbs, NULL);

    message_register_handle();

    xTaskCreate(i2c_slave_read_task, "i2c_slave_read_task", 1024 * 4, NULL, 5, NULL);
}
