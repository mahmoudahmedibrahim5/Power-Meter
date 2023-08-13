/*
 * LED.h
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 *
 *      since I am usually use the same configuration for LEDs
 *      I decided to write this driver so I don't need to write this
 *      configuration every time I use LED and it also make the main code more readable
 *
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include "../../Std Libraries/stm32f401xx.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"

typedef struct LED{
	uint8_t port;
	uint8_t pin;
}LED_t;

void LED_init(LED_t* led);
void LED_turnON(LED_t* led);
void LED_turnOFF(LED_t* led);
void LED_toggle(LED_t* led);
uint8_t LED_read(LED_t* led);

#endif /* LED_LED_H_ */
