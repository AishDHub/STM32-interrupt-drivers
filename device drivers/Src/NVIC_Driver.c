/*
 * NVIC_Driver.c
 *
 *  Created on: Oct 19, 2026
 *      Author: Thirisha
 */
#include "NVIC_Driver.h"

/*This function enables the interrupt for the supplies IRQ number*/
void NVIC_EnableIRQ(uint8_t IRQn){

	NVIC_ISER[IRQn/32] = (1 << (IRQn % 32));    // ex 37=>( 1 << 5 )
}

/*This function disables the interrupt for the supplies IRQ number*/
void NVIC_DisableIRQ(uint8_t IRQn){

	NVIC_ICER[IRQn/32] = (1 << (IRQn % 32));
}

/*This function sets pending interrupt for the supplies IRQ number*/
void NVIC_SetPendingIRQ(uint8_t IRQn){

	NVIC_ISPR[IRQn/32] = (1 << (IRQn % 32));
}

/*This function clears the pending interrupt for the supplies IRQ number*/
void NVIC_ClearPendingIRQ(uint8_t IRQn){

	NVIC_ICPR[IRQn/32] = (1 << (IRQn % 32));
}

/*This function returns the status of the supplies IRQ number*/
bool NVIC_ReadActiveIRQ(uint8_t IRQn){

	return (NVIC_IABR[IRQn/32] & (1 << (IRQn % 32)));

}

/*This function sets the priority level for the  interrupt number supplied*/
void NVIC_SetIRQPriority(uint8_t IRQn, uint8_t priority){

	NVIC_IPRx_BASE_ADDR[IRQn] = (priority & 0x0F) << 4;
}

