//
// Created by fish on 2024/12/13.
//

#include "bsp_buzzer.h"

#include "bsp_tim.h"
#include "cmsis_os2.h"

void bsp_buzzer_init() {
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}

void bsp_buzzer_alarm(double freq, double blank) {
    bsp_tim_config(&htim3, freq);
    bsp_tim_set_blank(&htim3, TIM_CHANNEL_4, blank);
}

void bsp_buzzer_quiet() {
    bsp_tim_set_blank(&htim3, TIM_CHANNEL_4, 0);
}

void bsp_buzzer_flash(double freq, double blank, uint32_t duration) {
    bsp_buzzer_alarm(freq, blank);
    osDelay(duration);
    bsp_buzzer_quiet();
}