/*
 * EXTI_Program.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "EXTI_Interface.h"

void EXTI_voidHardwareInterruptEnable(EXTI_Config_t *config)
{
	// Enable Interrupt mask
	EXTI->IMR |= (1<<(config->lineNum));

	// Choose the trigger mode
	if((config->triggerType) == EXTI_RISING_EDGE){
		// Enable Rising Edge trigger
		EXTI->RTSR |= (1<<(config->lineNum));
		EXTI->FTSR &= ~(1<<(config->lineNum));
	}
	if((config->triggerType) == EXTI_FALLING_EDGE){
		// Enable Falling Edge trigger
		EXTI->FTSR |= (1<<(config->lineNum));
		EXTI->RTSR &= ~(1<<(config->lineNum));
	}
	if((config->triggerType) == EXTI_ON_CHANGE){
		// Enable Rising Edge trigger
		EXTI->RTSR |= (1<<(config->lineNum));
		// Enable Falling Edge trigger
		EXTI->FTSR |= (1<<(config->lineNum));
	}
}

void EXTI_voidHardwareEventEnable(EXTI_Config_t *config)
{
	EXTI->EMR |= (1<<(config->lineNum));

	// Choose the trigger mode
	if((config->triggerType) == EXTI_RISING_EDGE){
		// Enable Rising Edge trigger
		EXTI->RTSR |= (1<<(config->lineNum));
		EXTI->FTSR &= ~(1<<(config->lineNum));
	}
	if((config->triggerType) == EXTI_FALLING_EDGE){
		// Enable Falling Edge trigger
		EXTI->FTSR |= (1<<(config->lineNum));
		EXTI->RTSR &= ~(1<<(config->lineNum));
	}
	if((config->triggerType) == EXTI_ON_CHANGE){
		// Enable Rising Edge trigger
		EXTI->RTSR |= (1<<(config->lineNum));
		// Enable Falling Edge trigger
		EXTI->FTSR |= (1<<(config->lineNum));
	}
}

void EXTI_voidSoftwareInterruptMask(u8 lineNum)
{
	EXTI->IMR |=(1<<lineNum);
	EXTI->SWIER |=(1<<lineNum);
}

void EXTI_voidSoftwareEventMask(u8 lineNum)
{
	EXTI->EMR |=(1<<lineNum);
	EXTI->SWIER |=(1<<lineNum);
}

void (*EXTI_CallBack_line[16])(void);

void EXTI_voidSetCallBackFunction(u8 lineNum, void(*ptr)(void))
{
	EXTI_CallBack_line[lineNum] = ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack_line[0]();
	EXTI->PR |= (1<<0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_CallBack_line[1]();
	EXTI->PR |= (1<<1);
}

void EXTI2_IRQHandler(void)
{
	EXTI_CallBack_line[2]();
	EXTI->PR |= (1<<2);
}

void EXTI3_IRQHandler(void)
{
	EXTI_CallBack_line[3]();
	EXTI->PR |= (1<<3);
}

void EXTI4_IRQHandler(void)
{
	EXTI_CallBack_line[4]();
	EXTI->PR |= (1<<4);
}

void EXTI9_5_IRQHandler(void)
{
	u32 tempReg = EXTI->PR;
	u8 i=5;
	for(i=5; i<10; i++)
		if((tempReg>>i)&1)
			break;
	EXTI_CallBack_line[i]();
	EXTI->PR |= (1<<i);
}

void EXTI15_10_IRQHandler(void)
{
	u32 tempReg = EXTI->PR;
	u8 i=10;
	for(i=10; i<16; i++)
		if((tempReg>>i)&1)
			break;
	EXTI_CallBack_line[i]();
	EXTI->PR |= (1<<i);
}
