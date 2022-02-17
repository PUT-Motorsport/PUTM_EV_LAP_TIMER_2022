/*
 * Timer.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */
#include "Timer.h"



struct time timer1;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	update();
}
void Reset()
{
	struct time timer_cpy;
	timer_cpy.miliseconds = timer1.miliseconds;
	timer_cpy.seconds = timer1.seconds;
	timer_cpy.minute = timer1.minute;
	timer1.miliseconds = 0;
	timer1.seconds = 0;
	timer1.minute = 0;
	Show_Time(&timer_cpy);
	update_state = 1;
}
void update()
{
	timer1.miliseconds++;
	if(timer1.miliseconds == 1000)
	{
		timer1.seconds++;
		//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		timer1.miliseconds = 0;
	}
	if(timer1.seconds == 60)
	{
		timer1.minute++;
		timer1.seconds = 0;
	}
	if(update_state == 1)
	{
		Update_Time(&timer1);
	}
	else
	{

	}

	/*
	char bufferM[1];
	itoa(minutes, bufferM,10);
	HAL_UART_Transmit (&huart2, bufferM, sizeof (bufferM), 100);
	char bufferZ[1] = ":";
	HAL_UART_Transmit (&huart2, bufferZ, sizeof (bufferZ), 100);
	char bufferS[2];
	itoa(seconds, bufferS,10);
	HAL_UART_Transmit (&huart2, bufferS, sizeof (bufferS), 100);
	HAL_UART_Transmit (&huart2, bufferZ, sizeof (bufferZ), 100);
	char bufferMs[3];
	itoa(miliseconds, bufferMs,10);
	HAL_UART_Transmit (&huart2, bufferMs, sizeof (bufferMs), 100);
	char newline[2] = "\r\n";
	HAL_UART_Transmit (&huart2, (uint8_t *) newline, 2, 10);
	*/
}
