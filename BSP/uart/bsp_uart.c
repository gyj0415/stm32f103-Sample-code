//
// Created by fish on 2024/9/2.
//

#include "bsp_uart.h"
#include "bsp_def.h"
#include "string.h"

static uint8_t uart_tx_buf[UART_BUFFER_SIZE];
static uint8_t uart_rx_buf[UART_ENUM_SIZE][UART_BUFFER_SIZE];
static UART_HandleTypeDef *handle[UART_ENUM_SIZE] = { NULL };
static void (*callback[UART_ENUM_SIZE])(bsp_uart_e e, uint8_t *s, uint16_t l);

void bsp_uart_init(bsp_uart_e e, UART_HandleTypeDef *h) {
    BSP_ASSERT(handle[e] == NULL);
    if(e != E_UART_CDC) handle[e] = h;
}

void bsp_uart_set_callback(bsp_uart_e e, void (*f)(bsp_uart_e e, uint8_t *s, uint16_t l)) {
    BSP_ASSERT(callback[e] == NULL);
    BSP_ASSERT(e == E_UART_CDC || handle[e]);
    callback[e] = f;
    if(e != E_UART_CDC) {
        HAL_UARTEx_ReceiveToIdle_DMA(handle[e], uart_rx_buf[e], UART_BUFFER_SIZE);
        __HAL_DMA_DISABLE_IT(handle[e]->hdmarx, DMA_IT_HT);
    }
}

void bsp_uart_send(bsp_uart_e e, uint8_t *s, uint16_t l) {
    BSP_ASSERT(handle[e]);
    HAL_UART_Transmit(handle[e], s, l, HAL_MAX_DELAY);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *h, uint16_t l) {
    for(int i = 0; i < UART_ENUM_SIZE; i++) {
        if(h == handle[i]) {
            if(callback[i] != NULL) callback[i](i, uart_rx_buf[i], l);
            memset(uart_rx_buf[i], 0, sizeof(uint8_t) * l);
            HAL_UARTEx_ReceiveToIdle_DMA(h, uart_rx_buf[i], UART_BUFFER_SIZE);
            __HAL_DMA_DISABLE_IT(h->hdmarx, DMA_IT_HT);
        }
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *h) {
    for(int i = 0; i < UART_ENUM_SIZE; i++) {
        if(handle[i] == NULL) continue;
        if(h == handle[i]) {
            HAL_UARTEx_ReceiveToIdle_DMA(h, uart_rx_buf[i], UART_BUFFER_SIZE);
            __HAL_DMA_DISABLE_IT(h->hdmarx, DMA_IT_HT);
            break;
        }
    }
}

void usb_cdc_callback(uint8_t *s, uint16_t l) {
    if(callback[E_UART_CDC] != NULL) callback[E_UART_CDC](E_UART_CDC, s, l);
}