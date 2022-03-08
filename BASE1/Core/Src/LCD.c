/*
 * LCD.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */

#include "LCD.h"
#include "stdio.h"

/**
* @brief Display lap time.
* This function displays lap time after the car crosses a start-finish line.
* @param: Pointer to structure containing last lap time and best time.
* @retval none
*/
void Show_Time(struct time *t1cpy, struct time *Best)
{
	update_state = 0;
	uint32_t blink_time;
	uint32_t whole_time = HAL_GetTick() + 2500;
	while(HAL_GetTick() < whole_time)
	{
		blink_time = HAL_GetTick() + 500;
		while(HAL_GetTick() < blink_time)
		{
			Update_Time(t1cpy);
		}
		blink_time = HAL_GetTick() + 250;
		while(HAL_GetTick() < blink_time)
		{
			Clear_first_row();
		}
	}
	Show_Best(Best);
}
/**
* @brief Clear first row.
* This function clears first row on LCD screen in order tu update current lap time.
* It takes less time to print "       " than to use lcd.clear() function.
* @param: none.
* @retval none
*/
void Clear_first_row()
{
	setCursor(0,0);
	print("               ");

}
/**
* @brief Update.
* This function updates lcd.
* @param: Pointer to current running time.
* @retval none
*/
void Update_Time(struct time *t1)
{
	setCursor(0,0);
	itoa(t1->minute,      bufferM,  10);
	itoa(t1->seconds,     bufferS,  10);
	itoa(t1->miliseconds, bufferMs, 10);
	print(bufferM);
	print(":");
	print(bufferS);
	print(":");
	print(bufferMs);
	print(" ");
}
/**
* @brief Display best.
* This function displays best time, if one was set.
* @param: Pointer to structure holding best time.
* @retval none
*/
void Show_Best(struct time *t1)
{
	setCursor(0,1);
	itoa(t1->minute,      bufferM,  10);
	itoa(t1->seconds,     bufferS,  10);
	itoa(t1->miliseconds, bufferMs, 10);
	print("Best: ");
	print(bufferM);
	print(":");
	print(bufferS);
	print(":");
	print(bufferMs);
	print(" ");
}
