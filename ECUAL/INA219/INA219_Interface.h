/*
 * INA219_Interface.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef INA219_INA219_INTERFACE_H_
#define INA219_INA219_INTERFACE_H_

#include "../../MCAL/I2C/I2C_Interface.h"
#include "INA219_Registers.h"
#include "INA219_Config.h"

void INA219_voidInit(INA219_t* config);
s16 INA219_s16ReadShuntVoltage(INA219_t* config);
u16 INA219_u16ReadBusVoltage(INA219_t* config);
s16 INA219_s16ReadCurrent(INA219_t* config);
u16 INA219_u16ReadPower(INA219_t* config);


#endif /* INA219_INA219_INTERFACE_H_ */
