//
// Created by guan on 2025/5/22.
//
#ifndef APP_SERVO_H
#define APP_SERVO_H

#include "tim.h"
#include <stdint.h>

void app_servo_init(TIM_HandleTypeDef *h, double freq, uint32_t channel);

void servo_open(TIM_HandleTypeDef *h, uint32_t channel);
void servo_close(TIM_HandleTypeDef *h, uint32_t channel);
void servo_change(TIM_HandleTypeDef *h, uint32_t channel, uint8_t angle);

#endif //APP_SERVO_H
