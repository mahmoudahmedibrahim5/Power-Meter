/*
 * Powermeter with protection mode
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "../APP/APP.h"

int main()
{
	APP_voidInit();

	while(1)
	{
		APP_voidSensorRead();
		APP_voidCheckInput();
		APP_voidBluetoothSend();
		TIMERS_voidDelayMilliSec(100);
	}
}
