/*
 * it.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */

#include "main_app.h"


void SysTick_Handler (void){

	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

