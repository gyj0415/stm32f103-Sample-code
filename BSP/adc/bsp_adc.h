//
// Created by guan on 2025/5/20.
//

#ifndef BSP_ADC_H
#define BSP_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
#include "adc.h"

typedef struct {
    float value1;
    float value2;
    float value3;
    float value4;
    uint16_t vbus_raw[4];
}adc_date;

void bsp_adc_init();
void bsp_adc_average(void);
adc_date *get_adc_d();

#ifdef __cplusplus
}
#endif

#endif //BSP_ADC_H
