/*
 * EXTI_Interface.h
 *
 *  Created on: Jun 11, 2023
 *      Author: ADMIN
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

#include "../../Std Libraries/STD_TYPES.h"
#include "EXTI_Registers.h"

#define EXTI_RISING_EDGE  			0
#define EXTI_FALLING_EDGE 			1
#define EXTI_ON_CHANGE			 	2

typedef struct{
	u8 port;
	u8 lineNum;
	u8 triggerType;
}EXTI_Config_t;

void EXTI_voidHardwareInterruptEnable(EXTI_Config_t *config);

void EXTI_voidHardwareEventEnable(EXTI_Config_t *config);
void EXTI_voidSoftwareInterruptMask(u8 lineNum);
void EXTI_voidSoftwareEventMask(u8 lineNum);

void EXTI_voidSetCallBackFunction(u8 lineNum, void(*ptr)(void));

#endif /* EXTI_EXTI_INTERFACE_H_ */
