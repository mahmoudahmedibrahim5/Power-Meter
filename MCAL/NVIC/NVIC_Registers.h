/*
 * NVIC_Registers.h
 *
 *  Created on: Feb 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef NVIC_NVIC_REGISTERS_H_
#define NVIC_NVIC_REGISTERS_H_

#define NVIC_BASE_ADDR					0xE000E000

typedef struct{
	uint32_t r1[64];
	volatile uint32_t ISER[8];
	uint32_t r2[24];
	volatile uint32_t ICER[8];
	uint32_t r3[24];
	volatile uint32_t ISPR[8];
	uint32_t r4[24];
	volatile uint32_t ICPR[8];
	uint32_t r5[24];
	volatile uint32_t IABR[8];
	uint32_t r6[56];
	volatile uint8_t IPR[240];
	uint32_t r7[580];
	volatile uint32_t STIR;
}st_NVIC_RegDef_t;

#define NVIC	((st_NVIC_RegDef_t *)NVIC_BASE_ADDR)

#endif /* NVIC_NVIC_REGISTERS_H_ */
