/*
 * TFT_Program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Mahmoud Ahmed
 */

#include "TFT_Interface.h"

void TFT_voidInit(TFT_t* tft)
{
	SPI_Config_t spiConfig;
	spiConfig.dataOrder = SPI_FIRST_BIT_MSB;
	spiConfig.mode = SPI_MASTER;
	spiConfig.dataSize = SPI_DATA_LENGTH_8_BIT;
	spiConfig.duplex = SPI_HALF_DUPLEX_TX;
	spiConfig.slaveControl = SPI_SLAVE_CONTROL_SOFTWARE;
	spiConfig.baudrate = SPI_PRESCALER8;

	SPI_voidInit(tft->SPIn, &spiConfig);

	GPIO_Config_t gpioConfig;
	gpioConfig.mode = GPIO_OUTPUT;
	gpioConfig.outType = GPIO_PUSH_PULL;
	gpioConfig.pupdState = GPIO_PULL_UP;
	gpioConfig.speed = GPIO_HIGH_SPEED;

	GPIO_voidInitPin(tft->port, tft->CSX, &gpioConfig);
	GPIO_voidInitPin(tft->port, tft->DCX, &gpioConfig);
}

void TFT_voidSendCommand(TFT_t* tft, u8 cmd)
{
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_COMMAND);
	GPIO_voidSetPinValue(tft->port, tft->CSX, 0);
	for(u8 i=0; i<1080; i++);
	SPI_voidSendData(tft->SPIn, cmd);
	GPIO_voidSetPinValue(tft->port, tft->CSX, 1);
}

void TFT_voidWrite(TFT_t* tft)
{
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_COMMAND);
	GPIO_voidSetPinValue(tft->port, tft->CSX, 0);


	/*SPI_voidSendData(tft->SPIn, TFT_CMD_COLMOD);
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_DATA);
	SPI_voidSendData(tft->SPIn, 0x05);

	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_COMMAND);
	SPI_voidSendData(tft->SPIn, TFT_CMD_MADCTL);
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_DATA);
	SPI_voidSendData(tft->SPIn, 0x00);

	 Set Boundaries
	SPI_voidSendData(tft->SPIn, TFT_CMD_CASET);
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_DATA);
	SPI_voidSendData(tft->SPIn, 0x00);
	SPI_voidSendData(tft->SPIn, 30);
	SPI_voidSendData(tft->SPIn, 0x00);
	SPI_voidSendData(tft->SPIn, 60);

	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_COMMAND);
	SPI_voidSendData(tft->SPIn, TFT_CMD_RASET);
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_DATA);
	SPI_voidSendData(tft->SPIn, 0x00);
	SPI_voidSendData(tft->SPIn, 30);
	SPI_voidSendData(tft->SPIn, 0x00);
	SPI_voidSendData(tft->SPIn, 60);*/

	/* RAM Data Write */
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_COMMAND);
	SPI_voidSendData(tft->SPIn, TFT_CMD_RAM_WR);
	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_DATA);
	for(u8 i=0; i<100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for(u8 i=0; i<100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);
	for (u8 i = 0; i < 100; i++)
		SPI_voidSendData(tft->SPIn, i);

	GPIO_voidSetPinValue(tft->port, tft->DCX, TFT_DCX_PIN_COMMAND);
		SPI_voidSendData(tft->SPIn, TFT_CMD_DSP_ON);
	GPIO_voidSetPinValue(tft->port, tft->CSX, 1);
}
