/*
 * msp.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */

#include "main_app.h"
#include<stdio.h>
#include<string.h>

void HAL_MspInit(void)
{
  // Here we will do low level processor specific initis

	// 1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // this is actually no required because this config is by default

	// 2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; // enable usage fault, memory fault and bus fault system exeptions

	// 3. Configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

	// to delete

}


void HAL_UART_MspInit(UART_HandleTypeDef *huart){

	GPIO_InitTypeDef gpio_uart;
	// here we are going to do the low level inits. of the USART2 peripheral

	// 1. enable the clock for the USART2 peripheral as well as for GPIOA peripheral
	//__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	// 2. Do the pin muxing configurations
	gpio_uart.Pin = GPIO_PIN_2; // UART2_TX
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio_uart);

	gpio_uart.Pin = GPIO_PIN_3;	// UART_RX
	HAL_GPIO_Init(GPIOA, &gpio_uart);



	// 3. Enable the IRQ and set up the priority (NVIC settings)
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}
