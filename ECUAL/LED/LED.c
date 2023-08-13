/*
 * LED.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 */

#include "LED.h"

void LED_init(LED_t* led){
	GPIO_Config_t LED_config;
	LED_config.mode = OUT;
	LED_config.outType = PUSH_PULL;
	LED_config.speed = LOW_SPEED;
	LED_config.pupdState = NO_PUPD;
	GPIO_initPin(led->port, led->pin, &LED_config);
}

void LED_turnON(LED_t* led){
	GPIO_setPinValue(led->port, led->pin, HIGH);
}

void LED_turnOFF(LED_t* led){
	GPIO_setPinValue(led->port, led->pin, LOW);
}

void LED_toggle(LED_t* led){
	GPIO_togglePin(led->port, led->pin);
}

uint8_t LED_read(LED_t* led){
	return GPIO_readPin(led->port, led->pin);
}
