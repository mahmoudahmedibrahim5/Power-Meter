/*
 * SPI_Program.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "SPI_Interface.h"

static void SPI_voidConfigurePins(st_SPI_RegDef_t* SPIn, SPI_Config_t* config);

void SPI_voidInit(st_SPI_RegDef_t* SPIn, SPI_Config_t* config){
	SPI_voidConfigurePins(SPIn, config);

	// Configure data order
	if(config->dataOrder == SPI_FIRST_BIT_MSB)
		SPIn->CR1 &= ~(1<<7);
	else if(config->dataOrder == SPI_FIRST_BIT_LSB)
		SPIn->CR1 |= (1<<7);

	// Configure data size
	if(config->dataSize == SPI_DATA_LENGTH_8_BIT)
		SPIn->CR1 &= ~(1<<11);
	else if(config->dataSize == SPI_DATA_LENGTH_16_BIT)
		SPIn->CR1 |= (1<<11);

	// Set the BaudRate
	SPIn->CR1 &= ~(111<<3);
	SPIn->CR1 |= (config->baudrate<<3);

	// Configure communication half-duplex or full-duplex
	if(config->duplex == SPI_FULL_DUPLEX)
		SPIn->CR1 &= ~(1<<15);
	else if(config->duplex == SPI_HALF_DUPLEX_TX){
		SPIn->CR1 |= (1<<15);
		SPIn->CR1 |= (1<<14);
	}
	else if(config->duplex == SPI_HALF_DUPLEX_RX){
		SPIn->CR1 |= (1<<15);
		SPIn->CR1 &= ~(1<<14);
	}

	// Configure the mode
	if(config->mode == SPI_MASTER)
	{
		// Configure slave control
		if(config->slaveControl == SPI_SLAVE_CONTROL_HARDWARE){
			SPIn->CR1 &= ~(1<<9);
			SPIn->CR2 |= (1<<2); // SSOE pin high to make the SS pin output
		}
		else if(config->slaveControl == SPI_SLAVE_CONTROL_SOFTWARE)
			SPIn->CR1 |= (1<<9);

		// Set Master mode
		SPIn->CR1 |= (1<<2);
	}
	else
	{
		// Set Slave mode
		SPIn->CR1 &= ~(1<<2);
	}

	// Enable The SPI
	SPI_voidEnable(SPIn);
}

void SPI_voidEnable(st_SPI_RegDef_t* SPIn){
	// Enable SPI
	SPIn->CR1 |= (1<<6);
}

void SPI_voidDisable(st_SPI_RegDef_t* SPIn, u8 duplex){
	if(duplex == SPI_HALF_DUPLEX_TX){
		// wait until communication finished
		while(!(SPIn->SR&(1<<1)));
		while(SPIn->SR &(1<<7));
		// Disable SPI
		SPIn->CR1 &= ~(1<<6);
	}
	else if(SPI_HALF_DUPLEX_RX){
		while(!(SPIn->SR&(1<<0)));
		SPIn->CR1 &= ~(1<<6);
		while(!(SPIn->SR&(1<<0)));
	}
}

void SPI_voidSendData(st_SPI_RegDef_t* SPIn, u8 data){
	SPIn->DR = data;
	while(!(SPIn->SR&(1<<1)));
}

void SPI_voidReceiveData(st_SPI_RegDef_t* SPIn, u8* data){
	while(!(SPIn->SR&(1<<0)));
	*data = SPIn->DR;
}

void SPI_voidBiderctionalUpdate(st_SPI_RegDef_t* SPIn, SPI_Config_t* config)
{
	SPI_voidDisable(SPIn, config->duplex);
	/*if(SPIn == SPI1)
		RCC_peripheralDis(SPI1_EN);
	else
		RCC_peripheralDis(SPI2_EN);
	if(config->duplex == SPI_HALF_DUPLEX_RX)
		SPIn->CR1 |= (1<<14);
	else
		SPIn->CR1 &= ~(1<<14);

	if(SPIn == SPI1)
		RCC_peripheralEn(SPI1_EN);
	else
		RCC_peripheralEn(SPI2_EN);*/
	SPI_voidEnable(SPIn);
}

static void SPI_voidConfigurePins(st_SPI_RegDef_t* SPIn, SPI_Config_t* config)
{
	GPIO_Config_t spiConfig;
	spiConfig.mode = GPIO_ALT_FN;
	spiConfig.outType = GPIO_PUSH_PULL;
	spiConfig.pupdState = GPIO_NO_PUPD;
	spiConfig.speed = GPIO_HIGH_SPEED;

	if(SPIn == SPI1){
		spiConfig.AltFuncMode = GPIO_AF5;

		if(config->duplex == SPI_FULL_DUPLEX){
			if((config->slaveControl == SPI_SLAVE_CONTROL_HARDWARE))
				GPIO_voidInitPin(PORTA, 4, &spiConfig); // NSS
			GPIO_voidInitPin(PORTA, 5, &spiConfig); // SCK
			GPIO_voidInitPin(PORTA, 6, &spiConfig); // MISO
			GPIO_voidInitPin(PORTA, 7, &spiConfig); // MOSI
		}
		else{// Half-Duplex
			if(config->mode == SPI_MASTER){
				GPIO_voidInitPin(PORTA, 5, &spiConfig); // SCK
				GPIO_voidInitPin(PORTA, 7, &spiConfig); // MOSI
			}
			else{
				GPIO_voidInitPin(PORTA, 5, &spiConfig); // SCK
				GPIO_voidInitPin(PORTA, 6, &spiConfig); // MISO
			}
		}
	}
	else if(SPIn == SPI2){
		spiConfig.AltFuncMode = GPIO_AF5;

		if(config->duplex == SPI_FULL_DUPLEX){
			if((config->slaveControl == SPI_SLAVE_CONTROL_HARDWARE))
				GPIO_voidInitPin(PORTB, 12, &spiConfig); // NSS
			GPIO_voidInitPin(PORTB, 13, &spiConfig); // SCK
			GPIO_voidInitPin(PORTB, 14, &spiConfig); // MISO
			GPIO_voidInitPin(PORTB, 15, &spiConfig); // MOSI
		}
		else{// Half-Duplex
			if(config->mode == SPI_MASTER){
				GPIO_voidInitPin(PORTB, 13, &spiConfig); // SCK
				GPIO_voidInitPin(PORTB, 15, &spiConfig); // MOSI
			}
			else{
				GPIO_voidInitPin(PORTB, 13, &spiConfig); // SCK
				GPIO_voidInitPin(PORTB, 14, &spiConfig); // MISO
			}
		}
	}
	else if(SPIn == SPI3){
		spiConfig.AltFuncMode = GPIO_AF6;

		if(config->duplex == SPI_FULL_DUPLEX){
			if((config->slaveControl == SPI_SLAVE_CONTROL_HARDWARE))
				GPIO_voidInitPin(PORTA, 15, &spiConfig); // NSS
			GPIO_voidInitPin(PORTB, 3, &spiConfig);  // SCK
			GPIO_voidInitPin(PORTB, 4, &spiConfig);  // MISO
			GPIO_voidInitPin(PORTB, 5, &spiConfig);  // MOSI
		}
		else{// Half-Duplex
			if(config->mode == SPI_MASTER){
				GPIO_voidInitPin(PORTB, 3, &spiConfig);  // SCK
				GPIO_voidInitPin(PORTB, 5, &spiConfig);  // MOSI
			}
			else{
				GPIO_voidInitPin(PORTB, 3, &spiConfig);  // SCK
				GPIO_voidInitPin(PORTB, 4, &spiConfig);  // MISO
			}
		}
	}
}
