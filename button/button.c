/*
 * button.c
 *
 *  Created on: Oct 7, 2022
 *      Author: kccistc
 */

#include "button.h"

void Button_GetInstance(Button *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	btn->GPIOX = GPIOx;
	btn->GPIO_Pin = GPIO_Pin;
	btn->prevState = RELEASED;
}

int Button_GetState(Button *btn)
{
	int curState;
	curState = HAL_GPIO_ReadPin(btn->GPIOX, btn->GPIO_Pin);
	if (curState == PUSHED && btn->prevState == RELEASED)
	{
		btn->prevState = PUSHED;
		return ACTIVE_PUSH;

	}
	else if (curState == RELEASED && btn->prevState == PUSHED)
	{
		btn->prevState = RELEASED;
		return ACTIVE_RELEASED;
	}
	return ACTIVE_NO;
}
