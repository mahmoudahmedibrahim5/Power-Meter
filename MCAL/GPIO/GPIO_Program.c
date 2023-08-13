/*
 * GPIO_Program.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */


#include "GPIO_Interface.h"

void GPIO_initPort(EN_Port_t port, GPIO_Config_t* mode)
{
	st_GPIO_RegDef_t *GPIOn;
	switch(port)
	{
	case PORTA:
			RCC_peripheralEn(GPIOA_EN);
			GPIOn = GPIOA;
			break;
	case PORTB:
			RCC_peripheralEn(GPIOB_EN);
			GPIOn = GPIOB;
			break;
	case PORTC:
			RCC_peripheralEn(GPIOC_EN);
			GPIOn = GPIOC;
			break;
	case PORTD:
			RCC_peripheralEn(GPIOD_EN);
			GPIOn = GPIOD;
			break;
	case PORTE:
			RCC_peripheralEn(GPIOE_EN);
			GPIOn = GPIOE;
			break;
	case PORTH:
			RCC_peripheralEn(GPIOH_EN);
			GPIOn = GPIOH;
			break;
	default:
			// error (will be edited later)
			break;
	}
	for(uint8_t i=0; i<16; i++)
	{
		// Configure the mode
		GPIOn->MODER  &= ~(0x3<<((2*i)));
		GPIOn->MODER  |= (mode->mode << (2*i));

		// Configure output type in case mode is output
		if(mode->mode == OUT || mode->mode == ALT_FN){
		GPIOn->OTYPER  &= ~(1<<(i));
		GPIOn->OTYPER  |= (mode->outType << i);
		}

		// Configure speed
		GPIOn->OSPEEDR &= ~(0x3<<((2*i)));
		GPIOn->OSPEEDR |= (mode->speed << (2*i));

		// Configure pull up and pull down resistors in case mode is input or open drain output
		GPIOn->PUPDR &= ~(0x3<<((2*i)));
		GPIOn->PUPDR |= (mode->pupdState << (2*i));

		// Configure Alternate function
		if(mode->mode == ALT_FN){
			if(mode->AltFuncMode<8)
				GPIOn->AFRL |= (mode->AltFuncMode << (4*i));
			else
				GPIOn->AFRH |= ((mode->AltFuncMode-8) << (4*i));
		}
	}
}
void GPIO_initPin(EN_Port_t port, uint8_t pinNum, GPIO_Config_t* mode)
{
		st_GPIO_RegDef_t *GPIOn;
		switch(port)
		{
		case PORTA:
				RCC_peripheralEn(GPIOA_EN);
				GPIOn = GPIOA;
				break;
		case PORTB:
				RCC_peripheralEn(GPIOB_EN);
				GPIOn = GPIOB;
				break;
		case PORTC:
				RCC_peripheralEn(GPIOC_EN);
				GPIOn = GPIOC;
				break;
		case PORTD:
				RCC_peripheralEn(GPIOD_EN);
				GPIOn = GPIOD;
				break;
		case PORTE:
				RCC_peripheralEn(GPIOE_EN);
				GPIOn = GPIOE;
				break;
		case PORTH:
				RCC_peripheralEn(GPIOH_EN);
				GPIOn = GPIOH;
				break;
		default:
				// error (will be edited later)
				break;
		}

		// Configure the mode
		GPIOn->MODER  &= ~(0x3<<((2*pinNum)));
		GPIOn->MODER  |= (mode->mode << (2*pinNum));

		// Configure output type in case mode is output
		if(mode->mode == OUT || mode->mode == ALT_FN){
		GPIOn->OTYPER  &= ~(1<<(pinNum));
		GPIOn->OTYPER  |= (mode->outType << pinNum);
		}

		// Configure speed
		GPIOn->OSPEEDR &= ~(0x3<<((2*pinNum)));
		GPIOn->OSPEEDR |= (mode->speed << (2*pinNum));

		// Configure pull up and pull down resistors in case mode is input or open drain output
		GPIOn->PUPDR &= ~(0x3<<((2*pinNum)));
		GPIOn->PUPDR |= (mode->pupdState << (2*pinNum));

		// Configure Alternate function
		if(mode->mode == ALT_FN){
			if(pinNum<8)
				GPIOn->AFRL |= (mode->AltFuncMode << (4*pinNum));
			else
				GPIOn->AFRH |= ((mode->AltFuncMode) << (4*(pinNum-8)));
		}
}

void GPIO_setPinValue(EN_Port_t port, uint8_t pinNum, uint8_t val)
{
	st_GPIO_RegDef_t *GPIOn;
		switch(port)
		{
		case PORTA:
				GPIOn = GPIOA;
				break;
		case PORTB:
				GPIOn = GPIOB;
				break;
		case PORTC:
				GPIOn = GPIOC;
				break;
		case PORTD:
				GPIOn = GPIOD;
				break;
		case PORTE:
				GPIOn = GPIOE;
				break;
		case PORTH:
				GPIOn = GPIOH;
				break;
		default:
				// error
				break;
		}
	if(val == HIGH)
	{
		GPIOn->ODR |= (1<<pinNum);
	}
	else
	{
		GPIOn->ODR &= ~(1<<pinNum);
	}
}
void GPIO_setPortValue(EN_Port_t port, uint16_t val)
{
	st_GPIO_RegDef_t *GPIOn;
		switch(port)
		{
		case PORTA:
				GPIOn = GPIOA;
				break;
		case PORTB:
				GPIOn = GPIOB;
				break;
		case PORTC:
				GPIOn = GPIOC;
				break;
		case PORTD:
				GPIOn = GPIOD;
				break;
		case PORTE:
				GPIOn = GPIOE;
				break;
		case PORTH:
				GPIOn = GPIOH;
				break;
		default:
				// error
				break;
		}

		GPIOn->ODR = val;
}

void GPIO_togglePin(EN_Port_t port, uint8_t pinNum)
{
	st_GPIO_RegDef_t *GPIOn;
		switch(port)
		{
		case PORTA:
				GPIOn = GPIOA;
				break;
		case PORTB:
				GPIOn = GPIOB;
				break;
		case PORTC:
				GPIOn = GPIOC;
				break;
		case PORTD:
				GPIOn = GPIOD;
				break;
		case PORTE:
				GPIOn = GPIOE;
				break;
		case PORTH:
				GPIOn = GPIOH;
				break;
		default:
				// error
				break;
		}
	GPIOn->ODR ^= (1<<pinNum);
}
void GPIO_togglePort(EN_Port_t port)
{
	st_GPIO_RegDef_t *GPIOn;
		switch(port)
		{
		case PORTA:
				GPIOn = GPIOA;
				break;
		case PORTB:
				GPIOn = GPIOB;
				break;
		case PORTC:
				GPIOn = GPIOC;
				break;
		case PORTD:
				GPIOn = GPIOD;
				break;
		case PORTE:
				GPIOn = GPIOE;
				break;
		case PORTH:
				GPIOn = GPIOH;
				break;
		default:
				// error
				break;
		}
	GPIOn->ODR ^= 0xFFFF;
}

uint8_t GPIO_readPin(EN_Port_t port, uint8_t pinNum)
{
	st_GPIO_RegDef_t *GPIOn;
			switch(port)
			{
			case PORTA:
					GPIOn = GPIOA;
					break;
			case PORTB:
					GPIOn = GPIOB;
					break;
			case PORTC:
					GPIOn = GPIOC;
					break;
			case PORTD:
					GPIOn = GPIOD;
					break;
			case PORTE:
					GPIOn = GPIOE;
					break;
			case PORTH:
					GPIOn = GPIOH;
					break;
			default:
					// error
					break;
			}
	return (uint8_t)((GPIOn->IDR & (1<<pinNum))>>pinNum);
}
uint16_t GPIO_readPort(EN_Port_t port)
{
	st_GPIO_RegDef_t *GPIOn;
				switch(port)
				{
				case PORTA:
						GPIOn = GPIOA;
						break;
				case PORTB:
						GPIOn = GPIOB;
						break;
				case PORTC:
						GPIOn = GPIOC;
						break;
				case PORTD:
						GPIOn = GPIOD;
						break;
				case PORTE:
						GPIOn = GPIOE;
						break;
				case PORTH:
						GPIOn = GPIOH;
						break;
				default:
						// error
						break;
				}
	return (uint16_t)(GPIOn->IDR);
}
