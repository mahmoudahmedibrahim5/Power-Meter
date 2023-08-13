/*
 * Powermeter with protection mode
 *
 *  Created on: Feb 8, 2023
 *      Author: MAhmoud Ahmed Ibrahim
 */

#include "../APP/APP.h"

int main()
{
	System_init();

	createTasks();
	vTaskStartScheduler();

	while(1)
	{

	}
}
