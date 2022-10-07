/*
 * led.c
 *
 *  Created on: Oct 7, 2022
 *      Author: kccistc
 */

#include "led.h"

void Led_GetInstance(Led *led, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	led->GPIOX = GPIOx;
	led->GPIO_Pin = GPIO_Pin;
}


void Led_On(Led *led)
{
	HAL_GPIO_WritePin(led->GPIOX, led->GPIO_Pin, GPIO_PIN_SET);
}

void Led_Off(Led *led)
{
	HAL_GPIO_WritePin(led->GPIOX, led->GPIO_Pin, GPIO_PIN_RESET);
}

void Led_Toggle(Led *led)
{
	HAL_GPIO_TogglePin(led->GPIOX, led->GPIO_Pin);
}
