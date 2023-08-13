/*
 * TIMERS_Program.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "TIMERS_Interface.h"

void TIMERS_init(st_TIM_RegDef_t* TIMx)
{
	if(TIMx == TIM2)
		RCC_peripheralEn(TIM2_EN);
	else if(TIMx == TIM3)
		RCC_peripheralEn(TIM3_EN);
	else if(TIMx == TIM4)
		RCC_peripheralEn(TIM4_EN);
	else if(TIMx == TIM5)
		RCC_peripheralEn(TIM5_EN);
}

void TIMERS_startTimer(st_TIM_RegDef_t* TIMx)
{
	TIMx->CR1 |= (1<<TIMERS_BIT_CEN);
}

void TIMERS_stopTimer(st_TIM_RegDef_t* TIMx)
{
	TIMx->CR1 &= ~(1<<TIMERS_BIT_CEN);
}


void TIMERS_delaySec(uint32_t s)
{
	// Enable UEV (Update event)
	TIMERS_DELAY_TIMER->CR1 &= ~(1<<TIMERS_BIT_UDIS);

	// Set counting as up
	TIMERS_DELAY_TIMER->CR1 &= ~(1<<TIMERS_BIT_DIR);

	// Set Prescaler
	TIMERS_DELAY_TIMER->PSC = 15999;	// Periodic Time = 1 ms

	// Auto-Reload Register
	TIMERS_DELAY_TIMER->ARR = 1000;

	// Start The Timer
	TIMERS_startTimer(TIMERS_DELAY_TIMER);

	for(uint32_t i=0; i<s; i++){
		while(!(TIMERS_DELAY_TIMER->SR & (1<<0)));
		// Clear The Update Flag
		TIMERS_DELAY_TIMER->SR &= ~(1<<0);
	}

	// Stop The Timer
	TIMERS_stopTimer(TIMERS_DELAY_TIMER);
}

void TIMERS_delayMilliSec(uint32_t ms)
{
	// Enable UEV (Update event)
	TIMERS_DELAY_TIMER->CR1 &= ~(1<<TIMERS_BIT_UDIS);

	// Set counting as up
	TIMERS_DELAY_TIMER->CR1 &= (1<<TIMERS_BIT_DIR);

	// Set Prescaler
	TIMERS_DELAY_TIMER->PSC = 15;	// Periodic Time = 1 us

	// Auto-Reload Register
	TIMERS_DELAY_TIMER->ARR = 1000;

	// Start The Timer
	TIMERS_startTimer(TIMERS_DELAY_TIMER);

	for(uint32_t i=0; i<ms; i++){
		while(!(TIMERS_DELAY_TIMER->SR & (1<<0)));
		// Clear The Update Flag
		TIMERS_DELAY_TIMER->SR &= ~(1<<0);
	}

	// Stop The Timer
	TIMERS_stopTimer(TIMERS_DELAY_TIMER);
}

void TIMERS_delayMicroSec(uint32_t us)
{

}



void TIMERS_writePWM(uint8_t dutyCycle)
{

}
