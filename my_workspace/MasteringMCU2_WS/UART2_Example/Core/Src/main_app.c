/*
 * main_app.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */


#include"stm32f1xx_hal.h"
#include "main_app.h"

void SystemClockConfig(void);

int main(void){

	HAL_Init();
	SystemClockConfig();

	return 0;
}

void SystemClockConfig(void){


}
