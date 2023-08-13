/*
 * APP.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "APP.h"

uint32_t SystemCoreClock = 16000000;

TaskHandle_t HandleSensorTask;
TaskHandle_t HandleBluetoothTask;
TaskHandle_t HandleScreenTask;

LED_t red = {PORTA, 8};
LED_t green = {PORTA, 0};

void System_init(void)
{
	LED_init(&red);
	LED_init(&green);

	TIMERS_init(TIMERS_DELAY_TIMER);
}

void createTasks(void)
{
	xTaskCreate(sensorTask, "sensor", configMINIMAL_STACK_SIZE, NULL, 1, &HandleSensorTask);
	xTaskCreate(bluetoothTask, "bluetooth", configMINIMAL_STACK_SIZE, NULL, 1, &HandleBluetoothTask);
	xTaskCreate(screenTask, "screen", configMINIMAL_STACK_SIZE, NULL, 1, &HandleScreenTask);
}

void sensorTask(void* par)
{
	while(1)
	{

	}
}

void bluetoothTask(void* par)
{
	while(1)
	{
		LED_toggle(&red);
		TIMERS_delayMilliSec(500);
	}
}

void screenTask(void* par)
{
	while(1)
	{
		LED_toggle(&green);
		TIMERS_delayMilliSec(500);
	}
}

void vApplicationMallocFailedHook(){
	while(1);
}
