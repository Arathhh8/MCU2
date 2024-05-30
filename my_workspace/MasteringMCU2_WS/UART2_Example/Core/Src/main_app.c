/*
 * main_app.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */


#include"stm32f1xx_hal.h"
#include "main_app.h"

void SystemClockConfig(void);
void UART2_Init(void);
void Error_handler(void);

UART_HandleTypeDef huart2;

int main(void){

	HAL_Init();
	SystemClockConfig();
	UART2_Init(); // high level peripheral initialization

	return 0;
}

void SystemClockConfig(void){


}


void UART2_Init(void){
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if( HAL_UART_Init(&huart2) != HAL_OK ){
		// There is a problem
		Error_handler();
	}

}

void Error_handler(void){

	while(1);
}

