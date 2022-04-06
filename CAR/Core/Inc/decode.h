/*
 * decode.h
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam
 */

#ifndef INC_DECODE_H_
#define INC_DECODE_H_

#include "stm32l4xx_hal.h"

typedef enum{
	PULSE_OK,
	PULSE_NOT_OK
}CODE_LEADING_PULSE;

typedef struct {

	uint32_t risingedge[4];
	uint32_t fallingedge[4];

	CODE_LEADING_PULSE leading_pulse;

	uint8_t value[2];

	uint8_t sector;

	TIM_HandleTypeDef* htim;

}Code;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim);


#endif /* INC_DECODE_H_ */
