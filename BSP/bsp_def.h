//
// Created by fish on 2024/9/2.
//

#pragma once

#include "app_msg.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdint.h"
#include "bsp_uart.h"
#include "cmsis_os2.h"
#include "bsp_led.h"
#include "bsp_sys.h"

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((unused)) static void bsp_assert_err(const char* file, uint32_t line) {
    UNUSED(file); UNUSED(line);
    // // 开启 rtos 调度锁，强行停止其他任务，便于调试。
    vTaskSuspendAll();
    bsp_led_set(255, 0, 0);
    float error_t = 9999.0;
    size_t i = sizeof(error_t) / sizeof(float);
    app_msg_vofa_send(E_UART_DEBUG, &error_t, i);
    // bsp_uart_printf(E_UART_DEBUG, "[Err] BSP Assert error at %s:%lu\r\n", file, line);
    while(1) __NOP();
}

#define BSP_ASSERT(arg) if(!(arg)) bsp_assert_err(__FILE__, __LINE__);

#ifdef __cplusplus
}
#endif
