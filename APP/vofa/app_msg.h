//
// Created by guan on 2025/5/20.
//

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bsp_uart.h"

#define APP_MSG_VOFA_CHANNEL_LIMIT 10

/*!
 * 通过 Vofa+ 的 Justfloat 协议发送调试数据
 * @param e 串口枚举类
 * @param f 待发送数据列表 (数据需为 float 或 double)
 * @param size 列表大小
 * @note app_msg_vofa_send(E_UART_DEBUG, data_array, sizeof(data_array) / sizeof(data_array[0]));
 */
void app_msg_vofa_send(bsp_uart_e e, float f[], size_t size);

struct app_msg_vofa {
    int16_t rc_l[2];
    int16_t rc_reserved;
    uint16_t reserved;
} __attribute__((packed));

#ifdef __cplusplus
}
#endif