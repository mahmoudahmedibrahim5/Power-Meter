/*
 * Button.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 */

#include "Button_Interface.h"

void Button_voidInit(Button_t* btn){
	GPIO_Config_t Button_config;
	Button_config.mode = GPIO_INPUT;
	Button_config.speed = GPIO_LOW_SPEED;
	Button_config.pupdState = GPIO_PULL_UP;
	GPIO_voidInitPin(btn->port, btn->pin, &Button_config);
}

u8 Button_u8Read(Button_t* btn){
	return GPIO_u8ReadPin(btn->port, btn->pin);
}

void Button_voidSetInterrupt(Button_t* btn, u8 triggerType, void (*ptr)(void)){
	if(btn->pin < 5)
		NVIC_voidEnableIRQ(btn->pin + NVIC_IRQ_EXTI0);
	else if(btn->pin < 10)
		NVIC_voidEnableIRQ(NVIC_IRQ_EXTI9_5);
	else if(btn->pin < 16)
		NVIC_voidEnableIRQ(NVIC_IRQ_EXTI15_10);

	EXTI_Config_t button = {btn->port, btn->pin, triggerType};
	EXTI_voidHardwareInterruptEnable(&button);
	EXTI_voidSetCallBackFunction(btn->pin, ptr);
}
