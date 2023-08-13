/*
 * BT.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef BT_MODULE_BT_H_
#define BT_MODULE_BT_H_

#include "../../Std Libraries/stm32f401xx.h"
#include "../../MCAL/USART/USART_Interface.h"

typedef struct{
	st_USART_RegDef_t* USARTn;
	uint32_t baudrate;
}BT_t;

void BT_init(BT_t* bt);
void BT_sendData(BT_t* bt, uint8_t* buffer, uint32_t len);
void BT_receiveData(BT_t* bt, uint8_t* buffer, uint32_t len);

#endif /* BT_MODULE_BT_H_ */
