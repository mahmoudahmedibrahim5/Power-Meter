/*
 * APP.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Mahmoud Ahmed
 */

#include "APP.h"

ST_SensorReading_t currentReading;
ST_SensorReading_t maxValue;

INA219_t sensor = {I2C1, 0x40};
TFT_t screen = {SPI1, PORTA, 3, 4};
BT_t bluetooth = {USART1, 9600};

LED_t red = {PORTA, 0};
LED_t green = {PORTA, 1};

u8 voltageMessage[] = "Voltage = 000 mV\n";
u8 currentMessage[] = "Current = 000 uA\n";
u8 powerMessage[] 	= "Power = 000 mW\n";

u8 maxValueMessage[] = "Enter the maximum value: ";
u8 invalidMessage[] = "Invalid\n";

EN_Message_t currentDisplay = CURRENT;
u8 protectionMode = 0;

void APP_voidInit(void)
{
	RCC_voidInit();

	RCC_voidPeripheralEnable(GPIOA_EN);
	RCC_voidPeripheralEnable(GPIOB_EN);
	RCC_voidPeripheralEnable(USART1_EN);
	RCC_voidPeripheralEnable(SPI1_EN);
	RCC_voidPeripheralEnable(I2C1_EN);
	RCC_voidPeripheralEnable(TIM2_EN);

	INA219_voidInit(&sensor);
	TFT_voidInit(&screen);
	BT_voidInit(&bluetooth);

	LED_voidInit(&red);
	LED_voidInit(&green);
}

void APP_voidSensorRead(void)
{
	currentReading.BusVolage = INA219_u16ReadBusVoltage(&sensor);
	currentReading.Current = INA219_s16ReadCurrent(&sensor);
	currentReading.Power = INA219_u16ReadPower(&sensor);
	if(protectionMode)
	{
		switch(currentDisplay)
		{
		case POWER:
			if(currentReading.Power > maxValue.Power){
				LED_voidTurnON(&red);
				LED_voidTurnOFF(&green);
			}
			else{
				LED_voidTurnON(&green);
				LED_voidTurnOFF(&red);
			}
			break;
		case VOLT:
			if(currentReading.BusVolage > maxValue.BusVolage){
				LED_voidTurnON(&red);
				LED_voidTurnOFF(&green);
			}
			else{
				LED_voidTurnON(&green);
				LED_voidTurnOFF(&red);
			}
			break;
		case CURRENT:
			if(currentReading.Current > maxValue.Current){
				LED_voidTurnON(&red);
				LED_voidTurnOFF(&green);
			}
			else{
				LED_voidTurnON(&green);
				LED_voidTurnOFF(&red);
			}
			break;
		}
	}
	else{
		LED_voidTurnON(&green);
		LED_voidTurnOFF(&red);
	}
}

void APP_voidScreenPrint(EN_Message_t msg)
{

}

void APP_voidCheckInput(void)
{
	u8 check = 0;
	BT_voidReceiveDataTimeOut(&bluetooth, &check, 1);

	if(check < 128) // If any message sent
	{

		if(check == 'M') // Set Maximum Value
		{
			u16 value = 0;
			u8 tmp[6] = {0, 0, 0, 0, 0, 0};
			u8 i, j;
			BT_voidSendData(&bluetooth, maxValueMessage, 25);
			for(i = 0; i < 6; i++){
				BT_voidReceiveData(&bluetooth, &tmp[i], 1);
				if(tmp[i] == '\n')
					break;
				BT_voidSendData(&bluetooth, &tmp[i], 1);
			}
			u8 newLine = '\n';
			BT_voidSendData(&bluetooth, &newLine, 1);
			for(j = 0; j < i; j++){
				value *= 10;
				value += (tmp[j]-'0');
			}
			switch(currentDisplay)
			{
			case POWER:
				maxValue.Power = value;
				break;
			case VOLT:
				maxValue.BusVolage = value;
				break;
			case CURRENT:
				maxValue.Current = value;
				break;
			}
			protectionMode = 1;
		}
		else if(check == 'P')
			currentDisplay = POWER;
		else if(check == 'V')
			currentDisplay = VOLT;
		else if(check == 'C')
			currentDisplay = CURRENT;
		else
			BT_voidSendData(&bluetooth, invalidMessage, 8);
	}
}

void APP_voidBluetoothSend(void)
{
	u16 value;
	switch(currentDisplay)
	{
	case POWER:
		value = currentReading.Power;
		powerMessage[10] = '0' + value % 10;
		value /= 10;
		powerMessage[9] = '0' + value % 10;
		value /= 10;
		powerMessage[8] = '0' + value % 10;
		BT_voidSendData(&bluetooth, powerMessage, 15);
		break;
	case VOLT:
		value = currentReading.BusVolage;
		if( (value > 999) && (value < 10000) ){
			voltageMessage[10] = '0' + value/1000;
			voltageMessage[11] = '.';
			voltageMessage[12] = '0' + ((value/100)%10);
			voltageMessage[14] = 'V';
			voltageMessage[15] = ' ';
		}
		else{
			if(value>999)
				voltageMessage[14] = ' ';
			else
				voltageMessage[14] = 'm';
			voltageMessage[15] = 'V';
			voltageMessage[12] = '0' + value % 10;
			value /= 10;
			voltageMessage[11] = '0' + value % 10;
			value /= 10;
			voltageMessage[10] = '0' + value % 10;
		}
		BT_voidSendData(&bluetooth, voltageMessage, 17);
		break;
	case CURRENT:
		value = currentReading.Current;
		if(value > 999){
			currentMessage[14] = 'm';
			value /= 1000;
		}
		else
			currentMessage[14] = 'u';
		currentMessage[12] = '0' + value % 10;
		value /= 10;
		currentMessage[11] = '0' + value % 10;
		value /= 10;
		currentMessage[10] = '0' + value % 10;
		BT_voidSendData(&bluetooth, currentMessage, 17);
		break;
	}
}
