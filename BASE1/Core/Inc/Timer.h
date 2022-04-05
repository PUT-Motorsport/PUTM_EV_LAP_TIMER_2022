/*
 * Timer.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "LCD.h"

//uint8_t update_state;

struct time
{
	uint8_t minute;
	uint8_t seconds;
	uint16_t miliseconds;
};


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);
void Reset(void);
void update(void);
void Init(void);

#endif /* INC_TIMER_H_ */
