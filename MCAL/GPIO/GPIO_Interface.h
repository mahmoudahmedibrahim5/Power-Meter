/*
 * GPIO_Interface.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "../RCC/RCC_Interface.h"
#include "../../Std Libraries/stm32f401xx.h"
#include "GPIO_Registers.h"
#include "GPIO_Config.h"

#define LOW  0
#define HIGH 1

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH=7
}EN_Port_t;

void GPIO_initPort(EN_Port_t port, GPIO_Config_t* mode);
void GPIO_initPin(EN_Port_t port, uint8_t pinNum, GPIO_Config_t* mode);

void GPIO_setPinValue(EN_Port_t port, uint8_t pinNum, uint8_t val);
void GPIO_setPortValue(EN_Port_t port, uint16_t val);
void GPIO_togglePin(EN_Port_t port, uint8_t pinNum);
void GPIO_togglePort(EN_Port_t port);

uint8_t GPIO_readPin(EN_Port_t port, uint8_t pinNum);
uint16_t GPIO_readPort(EN_Port_t port);

#endif /* GPIO_GPIO_INTERFACE_H_ */
