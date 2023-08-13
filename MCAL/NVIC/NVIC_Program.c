/*
 * NVIC_Program.c
 *
 *  Created on: Feb 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "NVIC_Interface.h"

void NVIC_enableIRQ(uint8_t IRQn)
{
	// To know which register we will use, ex: ISER0, ISER1, ...
	uint8_t index = IRQn/32;
	NVIC->ISER[index] |= (uint32_t)(1<<(IRQn%32));
}

void NVIC_disableIRQ(uint8_t IRQn)
{
	// To know which register we will use, ex: ICER0, ICER1, ...
	uint8_t index = IRQn/32;
	NVIC->ICER[index] |= (uint32_t)(1<<(IRQn%32));
}


void NVIC_setPendingIRQ(uint8_t IRQn)
{
	// To know which register we will use, ex: ISPR0, ISPR1, ...
	uint8_t index = IRQn/32;
	NVIC->ISPR[index] |= (uint32_t)(1<<(IRQn%32));
}

void NVIC_clearPendingIRQ(uint8_t IRQn)
{
	// To know which register we will use, ex: ICPR0, ICPR1, ...
	uint8_t index = IRQn/32;
	NVIC->ICPR[index] |= (uint32_t)(1<<(IRQn%32));
}


void NVIC_setPriority(uint8_t IRQn, uint8_t priority)
{
	NVIC->IPR[IRQn] = (priority<<4);
}

uint8_t NVIC_getPriority(uint8_t IRQn)
{
	return (NVIC->IPR[IRQn]>>4);
}
