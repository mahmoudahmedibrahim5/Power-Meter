/*
 * KEYPAD.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"

#define NO_KEY_PRESSED 10

typedef struct{
	EN_Port_t port;
	uint8_t pins[8]; // pins in order from left to right
}KeyPad_t;

uint8_t KEYPAD_read(KeyPad_t* KeyPad);

#endif /* KEYPAD_H_ */

