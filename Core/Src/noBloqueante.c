/*
 * noBloqueante.c
 *
 *  Created on: Aug 24, 2024
 *      Author: ---
 */

#include "stm32f1xx.h"

volatile uint32_t msTicks = 0;

void SysTick_Handler(void) {
    msTicks++;
}

void delay_ms_non_blocking(uint32_t delay) {
    uint32_t currentTicks = msTicks;
    while ((msTicks - currentTicks) < delay) {
        // Aquí el código es no bloqueante, podrías ejecutar otras tareas
    }
}

int main(void) {
    HAL_Init();
    SysTick_Config(SystemCoreClock / 1000);  // Configura SysTick para que interrumpa cada 1ms

    __HAL_RCC_GPIOC_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    while (1) {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        delay_ms_non_blocking(1000);  // Espera no bloqueante de 1 segundo
    }
}

