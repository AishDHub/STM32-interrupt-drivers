/*
 * EXTI_Driver.c
 *
 *  Created on: Oct 19, 2026
 *      Author: Thirisha
 */

#include "EXTI_Driver.h"

/*This function enables the interrupt of EXTI by un masking the IMR register*/
void EXTI_EnableInterrupt(uint8_t EXTILineNum, EXTI_TriggerType TriggerType)
{
	EXTI->IMR |= ( 1<< EXTILineNum);

	switch(TriggerType)
	{

	case EXTI_TRIGGER_RISING:
			   EXTI->RTSR |= ( 1<< EXTILineNum);
			   EXTI->FTSR &= ~( 1<< EXTILineNum);
			   break;

	case EXTI_TRIGGER_FALLING:
				   EXTI->FTSR |= ( 1<< EXTILineNum);
				   EXTI->RTSR &= ~( 1<< EXTILineNum);
				   break;

	case EXTI_TRIGGER_BOTH:
				   EXTI->RTSR |= ( 1<< EXTILineNum);
				   EXTI->FTSR |= ( 1<< EXTILineNum);
				   break;

	default:
		break;

	}

}

/*This function enables the event of EXTI by unmasking the EMR register*/
void EXTI_EnableEvent(uint8_t EXTILineNum, EXTI_TriggerType TriggerType )
{
	EXTI->EMR |= ( 1<< EXTILineNum);

		switch(TriggerType)
		{

		case EXTI_TRIGGER_RISING:
				   EXTI->RTSR |= ( 1<< EXTILineNum);
				   EXTI->FTSR &= ~( 1<< EXTILineNum);
				   break;

		case EXTI_TRIGGER_FALLING:
					   EXTI->FTSR |= ( 1<< EXTILineNum);
					   EXTI->RTSR &= ~( 1<< EXTILineNum);
					   break;

		case EXTI_TRIGGER_BOTH:
					   EXTI->RTSR |= ( 1<< EXTILineNum);
					   EXTI->FTSR |= ( 1<< EXTILineNum);
					   break;

		default:
			break;
		}
}

/*this function clears the pending bit in th PR register for a particular EXTI Line*/
void EXTI_ClearPending(uint8_t EXTILineNum)
{
      EXTI -> PR |= ( 1 << EXTILineNum );
}

/*This function returns the pending status of the particular EXTI line*/
bool EXTI_IsPending(uint8_t EXTILineNum)
{
	return (EXTI -> PR & ( 1 << EXTILineNum)) ? 1:0;//ternary operated used here if true return 1 false return 0
}

