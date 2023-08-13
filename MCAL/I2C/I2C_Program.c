/*
 * I2C_Program.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "I2C_Interface.h"

void I2C_init(st_I2C_RegDef_t* I2Cn, I2C_Config_t* config){
	if(I2Cn == I2C1)
		RCC_peripheralEn(I2C1_EN);
	else if(I2Cn == I2C2)
		RCC_peripheralEn(I2C2_EN);
	else if(I2Cn == I2C3)
		RCC_peripheralEn(I2C3_EN);

	I2C_configurePins(I2Cn);

	/* Clock Configuration */
	I2Cn->CR2 |= (I2C_FREQ & 0x3F);

	/* Configure Address */
	if(config->addressSize == I2C_7_BIT){
		// clear address
		I2Cn->OAR1 &= 0x00;
		// Set the 7 bit address mode
		I2Cn->OAR1 &= ~(1<<15);
		I2Cn->OAR1 |= (1<<14); // This bit should be high by software (Reference Manual)
		// write the address
		I2Cn->OAR1 |= ((config->address<<1) & 0x00FE);

	}
	else{
		// 10 bit addressing mode
	}

	/* Speed Configuration */
	if(config->speedMode == I2C_STANDARD){
		//I2Cn->CCR = ((FREQ * (T_SCL/2)) & 0xFFF);
		I2Cn->CCR = ((I2C_FREQ * ((1000U/config->speed)/2)) & 0xFFF);
	}
	else if(config->speedMode == I2C_FAST){
		// Fast mode
	}
	I2Cn->TRISE = ((I2C_FREQ + 1) & 0x3F);

	// Peripheral Enable
	I2Cn->CR1 |= (1<<I2C_PE);

	/* ACK Control */
	if(config->ACK == I2C_ACK_EN)
		I2Cn->CR1 |= (1<<10);
	else
		I2Cn->CR1 &= ~(1<<10);
}

void I2C_masterSendData(st_I2C_RegDef_t* I2Cn, uint8_t address, uint8_t* data, uint32_t len, uint8_t repeatedStart){
	uint8_t slaveAddress;

	// Send Start bit
	I2Cn->CR1 |= (1<<I2C_START);

	// Send the address
	while(!(I2Cn->SR1 & (1<<I2C_FLAG_SB)));
	slaveAddress = address<<1;
	slaveAddress &= ~(1); // Clear LSB to enter Transmission mode
	I2Cn->DR = slaveAddress;

	// Wait for address to be sent
	while(!(I2Cn->SR1 & (1<<I2C_FLAG_ADDR)));
	uint8_t readSR2 = I2Cn->SR2; // Clear ADDR flag
	(void)readSR2;

	// Send the data
	for(uint32_t i=0; i<len; i++){
		while(!(I2Cn->SR1 & (1<<I2C_FLAG_TXE)));
		I2Cn->DR = data[i];
	}

	// Send Stop bit
	while( (!(I2Cn->SR1 & (1<<I2C_FLAG_TXE))) );
	if(repeatedStart == I2C_RS_DISABLE)
		I2Cn->CR1 |= (1<<I2C_STOP);
}

void I2C_masterReceiveData(st_I2C_RegDef_t* I2Cn,  uint8_t address, uint8_t* data, uint32_t len, uint8_t repeatedStart){
	uint32_t i=0;
	uint8_t slaveAddress;

	// Send Start bit
	I2Cn->CR1 |= (1<<I2C_START);

	// Send the address
	while(!(I2Cn->SR1 & (1<<I2C_FLAG_SB)));
	slaveAddress = address<<1;
	slaveAddress |= (1); // Set LSB to enter Receiving mode
	I2Cn->DR = slaveAddress;

	// Wait for address to be sent
	while(!(I2Cn->SR1 & (1<<I2C_FLAG_ADDR)));
	if(len==1) // Disable the ACK
		I2Cn->CR1 &= ~(1<<10);

	uint8_t readSR2 = I2Cn->SR2; // Clear ADDR flag
	(void)readSR2;

	// Receive the data
	for(i=0; i<len; i++){
		while(!(I2Cn->SR1 & (1<<I2C_FLAG_RXNE)));
		if(i == len-2) // Disable the ACK
			I2Cn->CR1 &= ~(1<<10);
		if((i==len-1) && (repeatedStart == I2C_RS_DISABLE))
			I2Cn->CR1 |= (1<<I2C_STOP);
		data[i] = I2Cn->DR;
	}

	// ReEnable ACK
	I2Cn->CR1 |= (1<<10);
}

void I2C_slaveSendData(st_I2C_RegDef_t* I2Cn, uint8_t data){
	I2Cn->DR = data;
}

void I2C_slaveReceiveData(st_I2C_RegDef_t* I2Cn, uint8_t* data){
	*data = I2Cn->DR;
}

void I2C_configurePins(st_I2C_RegDef_t* I2Cn){
	GPIO_Config_t I2C_config;
	I2C_config.mode = ALT_FN;
	I2C_config.outType = OPEN_DRAIN;
	I2C_config.pupdState = NO_PUPD;
	I2C_config.speed = HIGH_SPEED;

	if(I2Cn == I2C1){
		I2C_config.AltFuncMode = AF4;
		GPIO_initPin(PORTB, I2C1_SCL_PIN, &I2C_config); // SCL
		GPIO_initPin(PORTB, I2C1_SDA_PIN, &I2C_config); // SDA
	}
	else if(I2Cn == I2C2){
		I2C_config.AltFuncMode = AF4;
		GPIO_initPin(PORTB, 10, &I2C_config); // SCL
		I2C_config.AltFuncMode = AF9;
		GPIO_initPin(PORTB, 3, &I2C_config); // SDA
	}
	else if(I2Cn == I2C3){
		I2C_config.AltFuncMode = AF4;
		GPIO_initPin(PORTA, 8, &I2C_config); // SCL
		I2C_config.AltFuncMode = AF9;
		GPIO_initPin(PORTB, 4, &I2C_config); // SDA
	}
}

void I2C_reset(st_I2C_RegDef_t* I2Cn)
{
	I2Cn->CR1 |= (1<<15);
}


void I2C_masterSendDataIT(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle){
	// Initialize handle variables
	handle->TxOrRx = I2C_TX_MODE;
	handle->index = 0;
	handle->runningState = I2C_RUNNING;

	// Send Start bit
	I2Cn->CR1 |= (1<<I2C_START);
}

void I2C_masterReceiveDataIT(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle){
	// Initialize handle variables
	handle->TxOrRx = I2C_RX_MODE;
	handle->index = 0;
	handle->runningState = I2C_RUNNING;

	// Send Start bit
	I2Cn->CR1 |= (1<<I2C_START);
}

void I2C_eventInterruptHandler(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle){
	uint32_t SR1 = I2Cn->SR1;

	// 1- SB
	if(SR1 & (1<<I2C_FLAG_SB))
	{
		uint8_t slaveAddress = (handle->slaveAddress<<1);
		if(handle->TxOrRx == I2C_TX_MODE)
			slaveAddress &= ~(1); // Clear LSB to enter Transmission mode
		else
			slaveAddress |= (1); // Set LSB to enter Receiving mode
		I2Cn->DR = slaveAddress;
		(void)slaveAddress;
	}

	// 2- ADDR
	else if(SR1 & (1<<I2C_FLAG_ADDR))
	{
		if( I2Cn->SR2 & (1<<0) )
		{ // Master
			if( (handle->TxOrRx == I2C_RX_MODE) && (handle->len == 1) )
				I2Cn->CR1 &= ~(1<<10); // Disable the ACK
		}

		// Clear ADDR flag in case Master or Slave
		uint8_t readSR2 = I2Cn->SR2;
		(void)readSR2;
	}

	// 3- BTF
	else if(SR1 & (1<<I2C_FLAG_BTF))
	{
		if(handle->TxOrRx == I2C_TX_MODE)
		{
			if(handle->index == handle->len){
				if(handle->repeatedStart == I2C_RS_DISABLE)
					I2Cn->CR1 |= (1<<I2C_STOP);
				/* Notify Application Communication Ended */
				// To be Done
				handle->runningState = I2C_FINISHED;
			}
		}
	}

	// 4- STOPF
	else if(SR1 & (1<<I2C_FLAG_STOPF))
	{
		// Slave Mode
		uint32_t readCR1 = I2Cn->CR1;
		I2Cn->CR1 = readCR1; // Clear STOPF flag
		(void)readCR1;
		I2C_slaveHandleCallBackFunction(I2Cn, I2C_EVENT_RECEPTION_FINISHED);
	}

	// 5- RXNE
	else if(SR1 & (1<<I2C_FLAG_RXNE))
	{
		if( (I2Cn->SR2 & (1<<0)) ) // Master
		{
			if(handle->index == (handle->len-2))
				I2Cn->CR1 &= ~(1<<10);		// Disable the ACK

			if((handle->index==handle->len-1) && (handle->repeatedStart == I2C_RS_DISABLE))
				I2Cn->CR1 |= (1<<I2C_STOP);	// Generate Stop Bit

			// Read the data
			handle->data[handle->index] = I2Cn->DR;
			handle->index++;

			/* Notify Application Communication Ended */
			// To be Done
			if(handle->index == handle->len){
				handle->runningState = I2C_FINISHED;
				// ReEnable ACK
				I2Cn->CR1 |= (1<<10);
			}
		}
		else// Slave
		{
			I2C_slaveHandleCallBackFunction(I2Cn, I2C_EVENT_RECEIVE_DATA);
		}
	}

	// 6- TXE
	else if(SR1 & (1<<I2C_FLAG_TXE))
	{
		if( (I2Cn->SR2 & (1<<0)) ) // Master
		{
			if(handle->index < handle->len){
				I2Cn->DR = handle->data[handle->index];
				handle->index++;
			}
		}
		else // Slave
		{
			I2C_slaveHandleCallBackFunction(I2Cn, I2C_EVENT_REQUEST_DATA);
		}
	}
}

void I2C_errorInterruptHandler(st_I2C_RegDef_t* I2Cn, I2C_HandleIT_t* handle){
	uint32_t SR1 = I2Cn->SR1;

	// 1- BERR
	if(SR1 & (1<<I2C_FLAG_BERR))
	{
		I2Cn->SR1 &= ~(1<<I2C_FLAG_BERR);
		handle->runningState = I2C_ERROR_BERR;
	}
	// 2- ARLO
	else if(SR1 & (1<<I2C_FLAG_ARLO))
	{
		I2Cn->SR1 &= ~(1<<I2C_FLAG_ARLO);
		handle->runningState = I2C_ERROR_ARLO;
	}
	// 3- AF
	else if(SR1 & (1<<I2C_FLAG_AF))
	{
		I2Cn->SR1 &= ~(1<<I2C_FLAG_AF);
		if(I2Cn->SR2 & (1<<0)){
			handle->runningState = I2C_ERROR_AF;
		}
		else{
			I2C_slaveHandleCallBackFunction(I2Cn, I2C_EVENT_TRANSMISSION_FINISHED);
		}
	}
	// 4- OVR
	else if(SR1 & (1<<I2C_FLAG_OVR))
	{
		I2Cn->SR1 &= ~(1<<I2C_FLAG_OVR);
		handle->runningState = I2C_ERROR_OVR;
	}
	// 5- PECERR
	else if(SR1 & (1<<I2C_FLAG_PECERR))
	{
		I2Cn->SR1 &= ~(1<<I2C_FLAG_PECERR);
		handle->runningState = I2C_ERROR_PECERR;
	}
	// 6- TIMEOUT
	else if(SR1 & (1<<I2C_FLAG_TIMEOUT))
	{
		I2Cn->SR1 &= ~(1<<I2C_FLAG_TIMEOUT);
		handle->runningState = I2C_ERROR_TIMEOUT;
	}

}

void I2C_interruptControl(st_I2C_RegDef_t* I2Cn, uint8_t state){
	if(state == I2C_INT_EN){
		// Enable Interrupt
		I2Cn->CR2 |= (1<<I2C_ITBUFEN);
		I2Cn->CR2 |= (1<<I2C_ITEVTEN);
		I2Cn->CR2 |= (1<<I2C_ITERREN);
	}
	else{
		// Disable Interrupt
		I2Cn->CR2 &= ~(1<<I2C_ITBUFEN);
		I2Cn->CR2 &= ~(1<<I2C_ITEVTEN);
		I2Cn->CR2 &= ~(1<<I2C_ITERREN);
	}
}
