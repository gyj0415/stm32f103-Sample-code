//
// Created by guan on 2025/5/20.
//
#include "app_msg.h"
#include <stdint.h>
#include <string.h>
#include "bsp_def.h"

/*
 *  Vofa+ Justfloat
 */

float ch[APP_MSG_VOFA_CHANNEL_LIMIT];
uint8_t vofa_tail[4] = {0x00, 0x00, 0x80, 0x7f};

void app_msg_vofa_send(bsp_uart_e e, float f[], size_t size) {
    BSP_ASSERT(0 < size && size <= APP_MSG_VOFA_CHANNEL_LIMIT);
    uint8_t p = 0;
    for (size_t i = 0; i < size; i++) {
        ch[p++] = (float)f[i];
    }
    bsp_uart_send(e, (uint8_t *)(&ch), size * sizeof(float));
    bsp_uart_send(e, vofa_tail, sizeof(vofa_tail));
}
