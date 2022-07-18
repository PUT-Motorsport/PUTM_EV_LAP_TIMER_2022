/*
 * Timer.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */

#ifndef INC_TIMER_HPP_
#define INC_TIMER_HPP_

#include "main.h"

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
time Measure_Acc(bool Is_acc_measured);
time Return_Lap_Time();
#endif /* INC_TIMER_HPP_ */
