//
// Created by guan on 2025/5/20.
//
#include "app_oled.h"

#include <stdio.h>
// #include <stdlib.h>

#include "app_music.h"
#include "app_sprintf.h"
#include "app_system.h"
#include "app_task.h"
#include "bsp_adc.h"
#include "cmsis_os2.h"
#include "MPU6050.h"
#include "tim.h"
#include "OLED/oled.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

char text[50] = {0};
uint8_t count = 0;

app_pro *pro_date = NULL;

void clean_page(){
    static uint8_t lst_page = 128;
    if(lst_page != pro_date->page){
        OLED_FullyClear();
        osDelay(10);
        if(pro_date->page < 4)
            OLED_ShowStr(15, 0, (uint8_t*)"Test Project", 2);
    }
    lst_page = pro_date->page;
}

void page_1(){
    d_Sprintf(text, "freq:%dHz    ", pro_date->freq, 0,0,0);
    OLED_ShowStr(25, 20, (uint8_t*)text, 1);
    f_Sprintf(text, "duty:%f%%    ", pro_date->duty, 0,0,0);
    OLED_ShowStr(25, 35, (uint8_t*)text, 1);
    d_Sprintf(text, "level %d,%d,%d,%d    ", pro_date->key->k_count[0],pro_date->key->k_count[1],pro_date->key->k_count[2],pro_date->key->k_count[3]);
    OLED_ShowStr(25, 50, (uint8_t*)text, 1);
}

void page_2(){
    f_Sprintf(text, "pitch:%f    ", pro_date->imu_date.pitch, 0,0,0);
    OLED_ShowStr(25, 20, (uint8_t*)text, 1);
    f_Sprintf(text, "roll :%f    ", pro_date->imu_date.roll, 0,0,0);
    OLED_ShowStr(25, 35, (uint8_t*)text, 1);
    f_Sprintf(text, "yaw  :%f    ", pro_date->imu_date.yaw,0,0,0);
    OLED_ShowStr(25, 50, (uint8_t*)text, 1);
}

void page_3(){
    f_Sprintf(text, "V1:%fV V2:%fV   ", pro_date->vbus->value1, pro_date->vbus->value2,0,0);
    OLED_ShowStr(12, 20, (uint8_t*)text, 1);
    f_Sprintf(text, "V3:%fV V4:%fV    ", pro_date->vbus->value3, pro_date->vbus->value4,0,0);
    OLED_ShowStr(12, 35, (uint8_t*)text, 1);
    d_Sprintf(text, "count:%d    ", count,0,0,0);
    OLED_ShowStr(35, 50, (uint8_t*)text, 1);
}

void page_4(){
    if(pro_date->u1_f != 0){
        f_Sprintf(text, "u1_data:%f    ", pro_date->u1_f, 0,0,0);
        OLED_ShowStr(25, 20, (uint8_t*)text, 1);
    }else OLED_ShowStr(25, 20, (uint8_t*)"u1_data:No Data    ", 1);
    if(pro_date->u2_f != 0){
        f_Sprintf(text, "u2_data:%f    ", pro_date->u2_f, 0,0,0);
        OLED_ShowStr(25, 40, (uint8_t*)text, 1);
    }else OLED_ShowStr(25, 40, (uint8_t*)"u2_data:No Data    ", 1);
}

void app_oled_task(void *argument)
{
    while(!app_sys_ready())
        osDelay(10);

    pro_date = get_app_date();
    for(;;)
    {
        clean_page();
        if(pro_date->page < 4)
        {
            if(++count == 100){
                count = 0;
            }
            switch (pro_date->page){
            case 0:{
                    page_1();
                    break;
            }case 1:{
                    page_2();
                    break;
            }case 2:{
                    page_3();
                    break;
            }case 3:{
                    page_4();
                    break;
            }default:{
                    pro_date->page = 0;
                    break;
                }
            }
        }else{
            OLED_ShowStr(37, 16, (uint8_t*)"YOU WIN~", 2);
            OLED_VerticalShift();
        }
        osDelay(1);
    }
}
