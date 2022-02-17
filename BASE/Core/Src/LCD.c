/*
 * LCD.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */

#include "LCD.h"

void Show_Time(struct time *t1cpy)
{
	update_state = 0;
	uint32_t blink_time;
	uint32_t whole_time = HAL_GetTick() + 2400;
	while(HAL_GetTick() < whole_time)
	{
		blink_time = HAL_GetTick() + 300;
		while(HAL_GetTick() < blink_time)
		{
			//show time
		}
		blink_time = HAL_GetTick() + 300;
		while(HAL_GetTick() < blink_time)
		{
			//show blank screen
		}

	}
}
void Update_Time(struct time *t1)
{





}
