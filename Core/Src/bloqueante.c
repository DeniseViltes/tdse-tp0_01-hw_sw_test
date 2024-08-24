/*
 * bloqueante.c
 *
 *  Created on: Aug 24, 2024
 *      Author: Chat gpt
 */

#include "stm32f1xx.h"

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 8000; i++) {
        __NOP();  // NOP = No Operation, solo desperdicia ciclos de CPU
    }
}

int main(void) {
    HAL_Init();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    while (1) {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        delay_ms(1000);  // Espera bloqueante de 1 segundo
    }
}

