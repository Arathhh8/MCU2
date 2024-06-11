/*
 * it.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */

#include "main_app.h"


extern UART_HandleTypeDef huart2;

void SysTick_Handler (void){

	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void){

	HAL_UART_IRQHandler(&huart2);
}
