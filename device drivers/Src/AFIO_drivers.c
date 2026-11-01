/*
 * AFIO_drivers.c
 *
 *  Created on: Oct 19, 2026
 *      Author: Thirisha
 */
#include "AFIO_drivers.h"

/*this function accepts inputs of two and configures the AFIO_EXTICRx registers here EXTILine is EXTIX where x can be 0,1,2,3 upto 15 refer reference manual of register mapping of AFIO*/
void  AFIO_SetEXTISource(uint8_t EXTILine, uint8_t EXTILineVal)
{
	uint8_t regIndex;
	uint8_t bitPos;

	/*EXTILine will be between 0 and 15*/
	regIndex = EXTILine/4;
	bitPos = (EXTILine % 4)*4; // where here 2 is EXTILine chosen by user use reg map of AFIO (2 % 4 = 2)*4 = 8 so now it can access 8th bit which is the starting bit of the desired EXTILine


	/*clear all the relevant bits 0x0F those 4 bits alone*/
	AFIO->AFIO_EXTICR[regIndex] &= ~(0x0F) << bitPos;

	/*(EXTILineVal & 0x0F) this is that is 8 bit so unintentionally it writes  8 bits required is 4 bits for that purpose it is masked*/
    AFIO->AFIO_EXTICR[regIndex] |= (EXTILineVal & 0x0F) << bitPos;// these (EXTILineVal & 0x0F) bits will be written in this position bitPos
}

