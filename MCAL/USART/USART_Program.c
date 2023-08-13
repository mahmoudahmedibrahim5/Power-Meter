/*
 * USART_Program.c
 *
 *  Created on: Jun 17, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "USART_Interface.h"

void USART_init(st_USART_RegDef_t* USARTn, USART_Config_t* config){
	// Enable Clock
	if(USARTn == USART1)
		RCC_peripheralEn(USART1_EN);
	else if(USARTn == USART2)
		RCC_peripheralEn(USART2_EN);
	else if(USARTn == USART6)
		RCC_peripheralEn(USART6_EN);
	// Configure the pins
	USART_configurePins(USARTn, config->mode);
	// Enable USART
	USARTn->CR1 |= (1<<13);

	if(config->mode == SYNCHRONOUS){
		// Enable CK pin
		USARTn->CR2 |= (1<<11);
	}
	else if(config->mode == HALF_DUPLEX){
		// Select Half-Duplex mode
		USARTn->CR3 |= (1<<3);
	}
	else{
		// Disable CK pin
		USARTn->CR2 &= ~(1<<11);
	}

	// Define word length
	switch(config->dataSize){
	case 0:
		USARTn->CR1 &= ~(1<<12);
		break;
	case 1:
		USARTn->CR1 |= (1<<12);
		break;
	}

	// Configure Parity bit
	switch(config->parityType){
		case 0:
			USARTn->CR1 |= (1<<10); // Enable Parity
			USARTn->CR1 &= ~(1<<9);	// Configure it to Even Parity
			break;
		case 1:
			USARTn->CR1 |= (1<<10); // Enable Parity
			USARTn->CR1 |= (1<<9);  // Configure it to Odd Parity
			break;
		case 2:
			USARTn->CR1 &= ~(1<<10);// Disable Parity
			break;
	}

	// Set the number of stop bits
	USARTn->CR2 &= ~(11<<12);
	USARTn->CR2 |= (config->stopBits<<12);

	if(config->overSampling == OVERSAMPLING8){
		USARTn->CR1 |= (1<<15);
	}
	else{
		USARTn->CR1 &= ~(1<<15);
	}

	/*		Setting  the BaudRate
	 **************************************
	 * This part could have been calculated but this would take time and space
	 * So, I preferred to write manually only the famous used BaudRates instead of calculating
	 * If you want to add more BaudRates check the table in page 521 (Section 19.3.4 Fractional baud rate generation) in Reference Manual.
	 * Here is the equation for the calculation:
	 * float realValue = (F_CPU)/(8*(2-config->overSampling) * config->baudrate);
	 * */
	if(config->baudrate == 9600){
		if(config->overSampling == OVERSAMPLING16)
			USARTn->BRR |= 0x683;
		else
			USARTn->BRR |= 0xD06;
	}
	else if(config->baudrate == 115200){
		if(config->overSampling == OVERSAMPLING16)
			USARTn->BRR |= 0x8B;
		else
			USARTn->BRR |= 0x116;
	}

	// Send Idle frame to start transmission (Transmitter Enable)
	if(config->transmission == TX_ONLY)
		USARTn->CR1 |= (1<<3);
	else if(config->transmission == RX_ONLY)
		USARTn->CR1 |= (1<<2);
	else if(config->transmission == TX_AND_RX){
		USARTn->CR1 |= (1<<3);
		USARTn->CR1 |= (1<<2);
	}
}

void USART_configurePins(st_USART_RegDef_t* USARTn, uint8_t mode){
	GPIO_Config_t USARTConfig;
	USARTConfig.mode = ALT_FN;
	USARTConfig.outType = PUSH_PULL;
	USARTConfig.pupdState = NO_PUPD;
	USARTConfig.speed = HIGH_SPEED;

	if(USARTn == USART1){
		USARTConfig.AltFuncMode = AF7;
		GPIO_initPin(PORTA, 9, &USARTConfig);	// TX
		GPIO_initPin(PORTA, 10, &USARTConfig);	// RX
		if(mode == SYNCHRONOUS)
			GPIO_initPin(PORTA, 8, &USARTConfig); 	// CK
		if(mode == HARDWARE_FLOW_CONTROL){
			GPIO_initPin(PORTA, 11, &USARTConfig);	// CTS
			GPIO_initPin(PORTA, 12, &USARTConfig);	// RTS
		}
	}
	else if(USARTn == USART2){
		USARTConfig.AltFuncMode = AF7;
		GPIO_initPin(PORTA, 2, &USARTConfig);	// TX
		GPIO_initPin(PORTA, 3, &USARTConfig);	// RX
		if(mode == SYNCHRONOUS)
			GPIO_initPin(PORTA, 4, &USARTConfig);	// CK
		if(mode == HARDWARE_FLOW_CONTROL){
			GPIO_initPin(PORTA, 0, &USARTConfig); 	// CTS
			GPIO_initPin(PORTA, 1, &USARTConfig);	// RTS
		}
	}
	else if(USARTn == USART6){
		USARTConfig.AltFuncMode = AF8;
		GPIO_initPin(PORTA, 11, &USARTConfig);	// TX
		GPIO_initPin(PORTA, 12, &USARTConfig);	// RX
	}
}

void USART_sendData(st_USART_RegDef_t* USARTn, uint8_t data){
	while(!(USARTn->SR & (1<<7)));
	USARTn->DR = data;
}

void USART_receiveData(st_USART_RegDef_t* USARTn, uint8_t* data){
	while(!(USARTn->SR & (1<<5)));
	*data = USARTn->DR;
}
