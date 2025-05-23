//
// Created by guan on 2025/5/20.
//
#include "app_system.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "app_servo.h"
#include "bsp_buzzer.h"
#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_time.h"
#include "cmsis_os2.h"
#include "i2c.h"
#include "MPU6050.h"
#include "OLED/oled.h"
#include "tim.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define KEY1 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)

bool k_state[4] = {false};
//0 raw, 1 s, 2 l, 3 dou
app_key key_date;

void Key_Scan(){
    static uint8_t key = 0;
    static uint16_t k_timestamp = 0, kd_timestamp = 0;
    static bool k_d_t = false, k_s_t = false, k_d = false;
    bool ReadDate = KEY1;
    k_state[0] = !ReadDate;
    if(k_d_t){
        if(++kd_timestamp > 20){
            if(k_s_t) k_state[1] ^= 1, k_s_t = false;
            k_d_t = false;
            kd_timestamp = 0;
        }
    }
    switch(key){
    case 0:{
            if(!ReadDate) key++;
            else key = 0;
            break;
    }case 1:{
            if(!ReadDate){
                if(k_d_t && kd_timestamp <= 20) k_d = true, k_s_t = false;
                else k_d = false;
                key++;
            }else key = 0;
            break;
    }case 2:{
            k_timestamp++;
            if(ReadDate){
                if(!k_d){
                    if(k_timestamp > 100) k_state[2] ^= 1;
                    else k_s_t = true;
                }else k_state[3] ^= 1;
                key = k_timestamp = 0;
                k_d_t = true;
            }
            break;
    }default: break;
    }
}

void key_state(){
    static bool l_s[4];
    key_date.k_state[0] = k_state[0];
    for(uint8_t i=1; i<4; i++){
        if(l_s[i] != k_state[i]) key_date.k_state[i] = true, key_date.k_count[i]++;
        else key_date.k_state[i] = false;
    }
    l_s[1] = k_state[1], l_s[2] = k_state[2], l_s[3] = k_state[3];
}

app_key *get_key_s(){
    return &key_date;
}

bool app_sys_ready(){
    return get_imu_flag();
}

void app_sys_init(){
    OLED_Init();
    MPU6050_init(&hi2c1);
    app_servo_init(&htim4, 50, TIM_CHANNEL_3);
    app_servo_init(&htim4, 50, TIM_CHANNEL_4);
}

void app_sys_task(void *argument){
    bsp_tim_config(&htim3, 2976);
    bsp_buzzer_flash(2976, 0.02, 250);
    bsp_led_set(0, 0, 255);
    app_sys_init();
    while(!app_sys_ready())
        osDelay(10);
    if(app_sys_ready()) {
        bsp_buzzer_flash(2976, 0.02, 125);
        osDelay(10);
        bsp_buzzer_flash(2976, 0.02, 125);
    }
    int8_t r = 0, g = 0, b = 0;
    uint8_t s_c = 0;
    for(;;){
        Key_Scan();
        key_state();
        if(++s_c >= 100){
            s_c = 0;
            // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
        }
        bsp_led_set(ABS(r), ABS(g), ABS(b));
        if(++r > 100) r = -100;
        if(++g > 100) g = -100;
        if(++b > 100) b = -100;
        osDelay(10);
    }
}

