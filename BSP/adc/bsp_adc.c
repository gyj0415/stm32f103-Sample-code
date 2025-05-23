//
// Created by fish on 2024/10/6.
//

#include "bsp_adc.h"

#include "adc.h"
#include "bsp_tim.h"

#include "stdint.h"

/*
 *  bsp_adc
 *  读 vbus 电压用
 *  TODO: 精度待验证
 */

static uint16_t val[4];
static uint16_t val_avg[4][8];
adc_date bsp_adc_date;

void bsp_adc_init(){
    HAL_ADCEx_Calibration_Start(&hadc1);//adc校准
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)val, 4);
}

void bsp_adc_average(void){
    static uint8_t p = 0;
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)val, 4);
    if(++p > 8) p = 0;
    for(uint8_t i=0; i<4 ;i++){
        val_avg[i][p] = val[i];
        bsp_adc_date.vbus_raw[i] = val[i];
    }
    for(uint8_t j=0; j<8; j++){
        bsp_adc_date.value1 += 1.0 * val_avg[0][j];
        bsp_adc_date.value2 += 1.0 * val_avg[1][j];
        bsp_adc_date.value3 += 1.0 * val_avg[2][j];
        bsp_adc_date.value4 += 1.0 * val_avg[3][j];
    }
    bsp_adc_date.value1 *= 3.3 / 4095 / 8;
    bsp_adc_date.value2 *= 3.3 / 4095 / 8;
    bsp_adc_date.value3 *= 3.3 / 4095 / 8;
    bsp_adc_date.value4 *= 3.3 / 4095 / 8;
}

adc_date *get_adc_d(){
    return &bsp_adc_date;
}
