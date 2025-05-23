//
// Created by guan on 2025/5/22.
//
#include "app_servo.h"

#include <stdbool.h>

#include "bsp_tim.h"
#include "stm32f1xx_hal_tim.h"
#include "tim.h"

void app_servo_init(TIM_HandleTypeDef *h, double freq, uint32_t channel) {
    bsp_tim_config(h, freq);
    bsp_tim_pwm_enable(h, channel);
}

void servo_open(TIM_HandleTypeDef *h, uint32_t channel) {
    bsp_tim_set_blank(h, channel, 0.125);
}

void servo_close(TIM_HandleTypeDef *h, uint32_t channel) {
    bsp_tim_set_blank(h, channel, 0.025);
}

void servo_change(TIM_HandleTypeDef *h, uint32_t channel, uint8_t angle) {
    bsp_tim_set_blank(h, channel, ((angle * 2.0 / 180 + 0.5) / 20));
}