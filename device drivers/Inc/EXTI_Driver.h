/*
 * EXTI_Driver.h
 *
 *  Created on: Oct 19, 2026
 *      Author: Thirisha
 */

#ifndef EXTI_DRIVER_H_
#define EXTI_DRIVER_H_

#include "stm32f103x8.h"
#include <stdint.h>
#include<stdbool.h>

typedef enum
{
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH
}EXTI_TriggerType;

void EXTI_EnableInterrupt(uint8_t EXTILineNum, EXTI_TriggerType TriggerType);//to release masking thereby to enabling interrupt
void EXTI_EnableEvent(uint8_t EXTILineNum,EXTI_TriggerType TriggerType);
void EXTI_ClearPending(uint8_t EXTILineNum);//to enable 1 manually thereby pending registers clear
bool EXTI_IsPending(uint8_t EXTILineNum);//to check for pending registers

#endif /* EXTI_DRIVER_H_ */
