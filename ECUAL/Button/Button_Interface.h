/*
 * Button.h
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 *
 *      since I am usually use the same configuration for Buttons
 *      I decided to write this driver so I don't need to write this
 *      configuration every time I use Button and it also make the main code more readable
 */

#ifndef BUTTON_BUTTON_H_
#define BUTTON_BUTTON_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/NVIC/NVIC_Interface.h"
#include "../../MCAL/SYSCFG/SYSCFG_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"

typedef struct{
	EN_Port_t port;
	u8 pin;
}Button_t;

void Button_voidInit(Button_t* btn);
u8 Button_u8Read(Button_t* btn);

/* If you use interrupt,
 * you should call EXTI_clearFlag(lineNum) at the ISR
 * It Clear the interrupt flag, line Number = pin Number
 * */
void Button_voidSetInterrupt(Button_t* btn, u8 triggerType, void (*ptr)(void));

#endif /* BUTTON_BUTTON_H_ */
