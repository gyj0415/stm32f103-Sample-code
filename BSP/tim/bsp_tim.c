//
// Created by fish on 2024/12/13.
//

#include "bsp_tim.h"

#include "bsp_def.h"
#include "math.h"

#define RCC_CLOCK_FREQ_MHZ 72

void bsp_tim_set(TIM_HandleTypeDef *h, uint16_t period, uint16_t prescaler) {
    HAL_TIM_Base_DeInit(h);
    h->Init.Period = period;
    h->Init.Prescaler = prescaler;
    HAL_TIM_Base_Init(h);
}

// usage: bsp_tim_config(&htim1, 1000);
void bsp_tim_config(TIM_HandleTypeDef *h, double p) {
    double t = 1e6 / p, k = 1, period_limit = h->Instance == TIM2 ? (1ll << 32) : (1ll << 16);
    t *= RCC_CLOCK_FREQ_MHZ;
    k = ceil(t / period_limit);
    bsp_tim_set(h, (uint16_t) (t / k) - 1, (uint16_t) k - 1);
}

// 0 <= blank <= 1
// usage: bsp_tim_set_blank(&htim1, TIM_CHANNEL_1, 0.5);
void bsp_tim_set_blank(TIM_HandleTypeDef *h, uint32_t channel, double blank) {
    BSP_ASSERT(0 <= blank && blank <= 1);
    __HAL_TIM_SetCompare(h, channel, (uint32_t) ((h->Init.Period + 1) * blank));
}

void bsp_tim_pwm_enable(TIM_HandleTypeDef *h, uint32_t channel)
{
    HAL_TIM_PWM_Start(h, channel);
}

void bsp_tim_pwm_disable(TIM_HandleTypeDef *h, uint32_t channel)
{
    HAL_TIM_PWM_Stop(h, channel);
}
