//
// Created by fish on 2024/9/2.
//

#ifndef BSP_LED_H
#define BSP_LED_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * 初始化 LED
 */
void bsp_led_init(void);

/*!
 * 设置 LED 颜色，三通道范围均为 [0, 255]
 * @param r 红色
 * @param g 绿色
 * @param b 蓝色
 */
void bsp_led_set(uint8_t r, uint8_t g, uint8_t b);

#ifdef __cplusplus
}
#endif

#endif //BSP_LED_H
