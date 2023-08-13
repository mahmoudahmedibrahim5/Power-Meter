/*
 * TIMERS_Registers.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef TIMERS_TIMERS_REGISTERS_H_
#define TIMERS_TIMERS_REGISTERS_H_

typedef struct{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SMCR;
	uint32_t DIER;
	uint32_t SR;
	uint32_t EGR;
	uint32_t CCMR1;
	uint32_t CCMR2;
	uint32_t CCER;
	uint32_t CNT; 	// Counter Register
	uint32_t PSC; 	// Prescaler Register
	uint32_t ARR; 	// Auto-Reload Register
	uint32_t r0;
	uint32_t CCR1;
	uint32_t CCR2;
	uint32_t CCR3;
	uint32_t CCR4;
	uint32_t r1;
	uint32_t DCR;
	uint32_t DMAR;
	uint32_t OR; 	// present only in TIM2 and TIM5
}st_TIM_RegDef_t;

#define TIM2	((st_TIM_RegDef_t *)TIM2_BASE_ADDR)
#define TIM3	((st_TIM_RegDef_t *)TIM3_BASE_ADDR)
#define TIM4	((st_TIM_RegDef_t *)TIM4_BASE_ADDR)
#define TIM5	((st_TIM_RegDef_t *)TIM5_BASE_ADDR)

/* CR1 Register Bits */
#define TIMERS_BIT_CEN		0
#define TIMERS_BIT_UDIS		1
#define TIMERS_BIT_URS		2
#define TIMERS_BIT_OPM		3
#define TIMERS_BIT_DIR		4
#define TIMERS_BIT_CMS		5
#define TIMERS_BIT_ARBE		7
#define TIMERS_BIT_CKD		8

#endif /* TIMERS_TIMERS_REGISTERS_H_ */
