/*
 * AFIO_drivers.h
 *
 *  Created on: Oct 19, 2026
 *      Author: Thirisha
 */

#ifndef AFIO_DRIVERS_H_
#define AFIO_DRIVERS_H_

#include "stm32f103x8.h"
#include "stdint.h"


void  AFIO_SetEXTISource(uint8_t EXTILine, uint8_t EXTILineVal);


#endif /* AFIO_DRIVERS_H_ */
