//
// Created by guan on 2025/5/20.
//

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

#include "app_system.h"
#include "bsp_adc.h"
#include "bsp_uart.h"
#include "MPU6050.h"

typedef struct{
    uint8_t page;

    app_key *key;
    adc_date *vbus;
    MPU6050 imu_date;

    float u1_f, u2_f;
    float duty;
    uint32_t freq;
}app_pro;

app_pro *get_app_date();

#ifdef __cplusplus
}
#endif
