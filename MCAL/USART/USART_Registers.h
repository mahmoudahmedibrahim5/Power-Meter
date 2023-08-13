/*
 * USART_Registers.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef USART_USART_REGISTERS_H_
#define USART_USART_REGISTERS_H_

typedef struct{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}st_USART_RegDef_t;

#define USART1		((st_USART_RegDef_t*)USART1_BASE_ADDR)
#define USART2		((st_USART_RegDef_t*)USART2_BASE_ADDR)
#define USART6		((st_USART_RegDef_t*)USART6_BASE_ADDR)

#endif /* USART_USART_REGISTERS_H_ */
