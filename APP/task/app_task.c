//
// Created by guan on 2025/5/20.
//
#include "app_task.h"

#include <stdlib.h>

#include "app_msg.h"
#include "app_servo.h"
#include "app_system.h"
#include "bsp_adc.h"
#include "bsp_def.h"
#include "MPU6050.h"

float uart2_data[4] = {114.0, 514.0, 1919.0, 810.0};
float data_to_send[3] = {1.0, 2.0, 3.0};
size_t data_size = sizeof(data_to_send) / sizeof(data_to_send[0]);

uint32_t freq = 0, val = 0;
float duty = 0, val_d = 0;

app_pro app_task_date;

bool parse_float(const char *str, float *value) {
    if (str == NULL || value == NULL) return false;

    char *end;
    float num = 0.0;
    int sign = 1; // 符号位，1表示正数，-1表示负数

    // 处理可能存在的正负号
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // 将字符串转换为浮点数
    while (*str >= '0' && *str <= '9') {
        num = num * 10.0 + (*str - '0');
        str++;
    }

    *value = sign * num;

    return true;
}

void read_imu(){
    data_to_send[0] = -app_task_date.imu_date.pitch;
    data_to_send[1] = app_task_date.imu_date.roll;
    data_to_send[2] = app_task_date.imu_date.yaw;
}

void set_target_1(bsp_uart_e e, uint8_t *s, uint16_t l) {
    float target;
    if (parse_float((const char *)s, &target))
        app_task_date.u1_f = target;
}

void set_target_2(bsp_uart_e e, uint8_t *s, uint16_t l) {
    float target;
    if (parse_float((const char *)s, &target))
        app_task_date.u2_f = target;
}

void change_page(){
    if(app_task_date.key->k_count[1] < 25){
        if(app_task_date.key->k_state[1]) app_task_date.page++;
        if(app_task_date.page > 3) app_task_date.page = 0;
    }else app_task_date.page = 4;
}

void app_task(void *argument)
{
    while(!app_sys_ready())
        osDelay(10);

    bsp_uart_set_callback(E_UART_DEBUG, set_target_1);
    bsp_uart_set_callback(E_UART_UART2, set_target_2);
    app_task_date.u1_f = app_task_date.u2_f = 0;
    app_task_date.key = get_key_s();
    app_task_date.vbus = get_adc_d();
    uint8_t angle = 0;

    for(;;){
        change_page();
        //adc 读取
        bsp_adc_average();
        //servo
        if(++angle == 181) angle = 0;
        servo_change(&htim4, TIM_CHANNEL_3, (180 - angle));
        servo_change(&htim4, TIM_CHANNEL_4, (180 - angle));
        //imu
        // MPU6050_Get_Angle_Plus(&imu_date);
        MPU6050_Get_Angle(&app_task_date.imu_date);
        read_imu();
        //uart
        app_msg_vofa_send(E_UART_DEBUG, data_to_send, data_size);
        app_msg_vofa_send(E_UART_UART2, uart2_data, 4);
        osDelay(10);
    }
}

app_pro *get_app_date(){
    return &app_task_date;
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *h){
    if(h->Instance == TIM1){
        if(h->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
            val  = HAL_TIM_ReadCapturedValue(h, TIM_CHANNEL_1) + 1;
            val_d = HAL_TIM_ReadCapturedValue(h, TIM_CHANNEL_2) + 1;
            __HAL_TIM_SetCounter(h, 0);
            app_task_date.freq = 1e6 / val;
            app_task_date.duty = (val_d / val) * 100;
            __HAL_TIM_CLEAR_IT(h, TIM_IT_CC1 | TIM_IT_CC2);
            HAL_TIM_IC_Start(h, TIM_CHANNEL_1);
            HAL_TIM_IC_Start(h, TIM_CHANNEL_2);
        }
    }
}
