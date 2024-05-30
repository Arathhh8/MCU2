/*
 * msp.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */

#include "stm32f1xx_hal.h"

void HAL_MspInit(void)
{
  // Here we will do low level processor specific initis

	// 1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // this is actually no required because this config is by default

	// 2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; // enable usage fault, memory fault and bus fault system exeptions

	// 3. Configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0x00, 0x00);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0x00, 0x00);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0x00, 0x00);

}