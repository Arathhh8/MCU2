/*
 * main_app.c
 *
 *  Created on: May 27, 2024
 *      Author: arath
 */


#include"stm32f1xx_hal.h"
#include "main_app.h"
#include <string.h>

void SystemClock_Config(void);
void UART2_Init(void);
void Error_handler(void);
uint8_t convert_to_capital(uint8_t data);

UART_HandleTypeDef huart2;

char *user_data = "The application is running\r\n";

int main(void){

	HAL_Init();
	SystemClock_Config();
	UART2_Init(); // high level peripheral initialization

	uint16_t len_of_data = strlen(user_data);

	HAL_UART_Transmit(&huart2, (uint8_t*)user_data, len_of_data, HAL_MAX_DELAY);

	uint8_t recvd_data;

	HAL_UART_Receive_IT(&huart2, &recvd_data, 1);

	while(1);

	return 0;
}

void SystemClock_Config(void)
{
	  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	  /** Initializes the RCC Oscillators according to the specified parameters
	  * in the RCC_OscInitTypeDef structure.
	  */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
	    //Error_Handler();
	  }

	  /** Initializes the CPU, AHB and APB buses clocks
	  */
	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	  {
	    //Error_Handler();
	  }
}


void UART2_Init(void){
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 9600;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	//huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if( HAL_UART_Init(&huart2) != HAL_OK ){
		// There is a problem
		Error_handler();
	}

}

uint8_t convert_to_capital(uint8_t data){

	if(data >= 'a' && data <= 'z'){
		data = data - ('a' - 'A');
	}

	return data;
}

void Error_handler(void){

	while(1);
}


