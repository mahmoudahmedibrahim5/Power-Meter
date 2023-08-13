/*
 * RCC_Interface.h
 *
 *  Created on: Feb 8, 2023
 *      Author: MAhmoud Ahmed Ibrahim
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_

#include "../../Std Libraries/stm32f401xx.h"
#include "RCC_Registers.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void RCC_init();

void RCC_peripheralEn(EN_peripheral_t per);
void RCC_peripheralDis(EN_peripheral_t per);

void RCC_peripheralLowPowerEn(EN_peripheral_t per);
void RCC_peripheralLowPowerDis(EN_peripheral_t per);

void RCC_peripheralReset(EN_peripheral_t per);

#endif /* RCC_RCC_INTERFACE_H_ */
