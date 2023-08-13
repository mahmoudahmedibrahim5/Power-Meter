/*
 * KEYPAD.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "KEYPAD.h"

uint8_t key[17] = {NO_KEY_PRESSED,1,2,3,'A',4,5,6,'B',7,8,9,'C','*',0,'#','D'};
GPIO_Config_t KP_IN_config = {IN, 0, LOW_SPEED, PULL_UP, 0};
GPIO_Config_t KP_OUT_config = {OUT, PUSH_PULL, LOW_SPEED, NO_PUPD, 0};

uint8_t KEYPAD_read(KeyPad_t* KeyPad)
{
	/*
	 * row and column are two variables to identify which key is pressed
	 * row is initialized by 1 and column is initialized by zero
	 * If no keys are pressed then (((row-1)*4)+column) will be equal zero
	 * So the function will return value of NO_KEY_PRESSED
	 */
	uint8_t row = 1, column = 0;

	// To read the row
	GPIO_initPin(KeyPad->port, KeyPad->pins[0], &KP_IN_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[1], &KP_IN_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[2], &KP_IN_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[3], &KP_IN_config);

	GPIO_initPin(KeyPad->port, KeyPad->pins[4], &KP_OUT_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[5], &KP_OUT_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[6], &KP_OUT_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[7], &KP_OUT_config);

	GPIO_setPinValue(KeyPad->port, KeyPad->pins[4], LOW);
	GPIO_setPinValue(KeyPad->port, KeyPad->pins[5], LOW);
	GPIO_setPinValue(KeyPad->port, KeyPad->pins[6], LOW);
	GPIO_setPinValue(KeyPad->port, KeyPad->pins[7], LOW);

	if(GPIO_readPin(KeyPad->port, KeyPad->pins[0]) == 0) row=1;
	else if(GPIO_readPin(KeyPad->port, KeyPad->pins[1]) == 0) row=2;
	else if(GPIO_readPin(KeyPad->port, KeyPad->pins[3]) == 0) row=4;
	else if(GPIO_readPin(KeyPad->port, KeyPad->pins[2]) == 0) row=3;

	// To read column
	GPIO_initPin(KeyPad->port, KeyPad->pins[4], &KP_IN_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[5], &KP_IN_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[6], &KP_IN_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[7], &KP_IN_config);

	GPIO_initPin(KeyPad->port, KeyPad->pins[0], &KP_OUT_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[1], &KP_OUT_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[2], &KP_OUT_config);
	GPIO_initPin(KeyPad->port, KeyPad->pins[3], &KP_OUT_config);

	GPIO_setPinValue(KeyPad->port, KeyPad->pins[0], LOW);
	GPIO_setPinValue(KeyPad->port, KeyPad->pins[1], LOW);
	GPIO_setPinValue(KeyPad->port, KeyPad->pins[2], LOW);
	GPIO_setPinValue(KeyPad->port, KeyPad->pins[3], LOW);

	if(GPIO_readPin(KeyPad->port, KeyPad->pins[4]) == 0) column=1;
	else if(GPIO_readPin(KeyPad->port, KeyPad->pins[5]) == 0) column=2;
	else if(GPIO_readPin(KeyPad->port, KeyPad->pins[6]) == 0) column=3;
	else if(GPIO_readPin(KeyPad->port, KeyPad->pins[7]) == 0) column=4;

	return key[((row-1)*4)+column];
}
