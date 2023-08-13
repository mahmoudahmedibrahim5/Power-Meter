/*
 * USART_Interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef USART_USART_INTERFACE_H_
#define USART_USART_INTERFACE_H_

#include "../../Std Libraries/stm32f401xx.h"
#include "../GPIO/GPIO_Interface.h"
#include "USART_Config.h"
#include "USART_Registers.h"

void USART_init(st_USART_RegDef_t* USARTn, USART_Config_t* config);
void USART_configurePins(st_USART_RegDef_t* USARTn, uint8_t mode);
void USART_sendData(st_USART_RegDef_t* USARTn, uint8_t data);
void USART_receiveData(st_USART_RegDef_t* USARTn, uint8_t* data);

#endif /* USART_USART_INTERFACE_H_ */
