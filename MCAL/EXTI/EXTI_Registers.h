/*
 * EXTI_Registers.h
 *
 *  Created on: Jun 11, 2023
 *      Author: ADMIN
 */

#ifndef EXTI_EXTI_REGISTERS_H_
#define EXTI_EXTI_REGISTERS_H_

#define EXTI_BASE_ADDR					0x40013C00

typedef volatile struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}st_EXTI_RegDef_t;

#define EXTI	((st_EXTI_RegDef_t *) EXTI_BASE_ADDR)

#endif /* EXTI_EXTI_REGISTERS_H_ */
