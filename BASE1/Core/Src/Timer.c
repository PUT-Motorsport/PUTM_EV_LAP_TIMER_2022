/*
 * Timer.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */
#include "Timer.h"

extern uint8_t show_time;
extern uint8_t update_lcd;
extern uint8_t car_passed;

struct time timer1;
struct time Best;
/**
* @brief Timer callback
* This function keeps track of lap time.
* @param: Pointer to timer handler
* @retval none
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	timer1.miliseconds++;
	if(timer1.miliseconds == 1000)
		{
			timer1.seconds++;
			timer1.miliseconds = 0;
			HAL_GPIO_WritePin(GPIOC, LED_2_Pin, 1);
			car_passed = 3;
		}
	if(timer1.seconds == 60)
		{
			timer1.minute++;
			timer1.seconds = 0;
		}
	if(update_state == 1)
		{
			show_time = 1;
		}
	else
		{
			show_time = 0;
		}
		update_lcd = 1;
}
/**
* @brief Reset
* This function Reset timer, calculate best time and induces function that display time on LCD.
* @param: none
* @retval none
*/
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
	Show_Time(&timer_cpy, &Best);
	update_state = 1;
}
/**
* @brief Update LCD
* This function updates lcd
* @param: none
* @retval none
*/
void update()
{
	Update_Time(&timer1);
}
/**
* @brief Init
* This function initialize best time
* @param: none
* @retval none
*/
void Init()
{
	Best.miliseconds = 999;
	Best.seconds = 59;
	Best.minute = 10;
}
