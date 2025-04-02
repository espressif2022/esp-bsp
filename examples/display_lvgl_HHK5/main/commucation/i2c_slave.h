/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#ifndef I2C_SLAVE_H
#define I2C_SLAVE_H

#include <esp_err.h>
#include <driver/i2c.h>

void i2c_slave_start(void);

void i2c_send_test_cmd(uint8_t *cmd, uint16_t len);

#endif // I2C_SLAVE_H
