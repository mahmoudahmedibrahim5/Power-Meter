/*
 * Button.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 */

#include "Button.h"

void Button_init(Button_t* btn){
	GPIO_Config_t Button_config;
	Button_config.mode = IN;
	Button_config.speed = LOW_SPEED;
	Button_config.pupdState = PULL_UP;
	GPIO_initPin(btn->port, btn->pin, &Button_config);
}

uint8_t Button_read(Button_t* btn){
	return GPIO_readPin(btn->port, btn->pin);
}

/*void Button_setInterrupt(Button_t* btn, uint8_t triggerType){
	if(btn->pin < 5)
		NVIC_enableIRQ(btn->pin + NVIC_IRQ_EXTI0);
	else if(btn->pin < 10)
		NVIC_enableIRQ(NVIC_IRQ_EXTI9_5);
	else if(btn->pin < 16)
		NVIC_enableIRQ(NVIC_IRQ_EXTI15_10);

	EXTI_Config_t button = {btn->port, btn->pin, triggerType};
	EXTI_hardwareInterruptMask(&button);
}*/
