/*
 * Timer.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */
#include "Timer.h"

extern uint8_t show_time;
struct time timer1;
struct time Best;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	timer1.miliseconds++;
	if(timer1.miliseconds == 1000)
		{
			timer1.seconds++;
			timer1.miliseconds = 0;
		}
	if(timer1.seconds == 60)
		{
			timer1.minute++;
			timer1.seconds = 0;
		}
}

void Reset(void)
{
	struct time timer_cpy;
	if(Best.seconds > timer1.seconds)
	{
		Best.minute = timer1.minute;
		Best.seconds = timer1.seconds;
		Best.miliseconds = timer1.miliseconds;
	}
	else if(Best.seconds == timer1.seconds)
	{
		if(Best.miliseconds > timer1.miliseconds)
			{
				Best.minute = timer1.minute;
				Best.seconds = timer1.seconds;
				Best.miliseconds = timer1.miliseconds;
			}
	}
	timer_cpy.miliseconds = timer1.miliseconds;
	timer_cpy.seconds = timer1.seconds;
	timer_cpy.minute = timer1.minute;
	timer1.miliseconds = 0;
	timer1.seconds = 0;
	timer1.minute = 0;
	update_state = 1;
}
void Init()
{
	Best.miliseconds = 999;
	Best.seconds = 59;
	Best.minute = 10;
}