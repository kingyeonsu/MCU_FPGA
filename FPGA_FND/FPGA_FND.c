/*
 * FPGA_FND.c
 *
 *  Created on: Oct 7, 2022
 *      Author: kccistc
 */

#include "FPGA_FND.h"

int gNumber=0;

void FPGA_FND_SetNumber(int number)
{
	gNumber = number;
}

void FPGA_FND_DisplayFNDNumber()
{
	FPGA_FND_SetFNDNumber(gNumber);
}

void FPGA_FND_SetFNDNumber(int number)
{
	static int position=0;
	position = (position + 1) % 4;

	switch (position)
	{
	case 0:
		FPGA_FND_SetValue(number%10);
	  break;
	case 1:
		FPGA_FND_SetValue(number/10%10);
	  break;
	case 2:
		FPGA_FND_SetValue(number/100%10);
	  break;
	case 3:
		FPGA_FND_SetValue(number/1000%10);
	  break;
	}
	FPGA_FND_SetDigitPosition(position);
}

void FPGA_FND_SetDigitPosition(int position)
{
	if (position >= 4) return;

	int pinState=0;

	GPIO_TypeDef* gpio[2] = {GPIOB, GPIOB};
	int gpio_pin[2] = {GPIO_PIN_4, GPIO_PIN_5};

	for (int i=0; i < 2; i++)
	{
		pinState = (position & (1<<i)) ? 1 : 0;
		HAL_GPIO_WritePin(gpio[i], gpio_pin[i], pinState);
	}
}

void FPGA_FND_SetValue(int number)
{
	if (number >= 10) return;

	int pinState=0;

	GPIO_TypeDef* gpio[4] = {GPIOC, GPIOC, GPIOB, GPIOC};
	int gpio_pin[4] = {GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_8, GPIO_PIN_9};

	for (int i=0; i < 4; i++)
	{
		pinState = (number & (1<<i)) ? 1 : 0;
		HAL_GPIO_WritePin(gpio[i], gpio_pin[i], pinState);
	}
}
