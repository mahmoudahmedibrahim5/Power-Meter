/*
 * TIMERS_Interface.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef TIMERS_TIMERS_INTERFACE_H_
#define TIMERS_TIMERS_INTERFACE_H_

#include "../../Std Libraries/stm32f401xx.h"
#include "../../Std Libraries/DataTypes.h"
#include "../RCC/RCC_Interface.h"
#include "../GPIO/GPIO_Interface.h"
#include "TIMERS_Registers.h"
#include "TIMERS_Config.h"

void TIMERS_init(st_TIM_RegDef_t* TIMx);

void TIMERS_startTimer(st_TIM_RegDef_t* TIMx);
void TIMERS_stopTimer(st_TIM_RegDef_t* TIMx);

void TIMERS_delaySec(uint32_t s);
void TIMERS_delayMilliSec(uint32_t ms);
void TIMERS_delayMicroSec(uint32_t us);

#endif /* TIMERS_TIMERS_INTERFACE_H_ */
