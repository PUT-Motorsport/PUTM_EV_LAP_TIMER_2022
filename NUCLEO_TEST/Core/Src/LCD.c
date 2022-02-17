/*
 * LCD.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */

#include "LCD.h"

extern UART_HandleTypeDef hlpuart1;

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
			Update_Time(t1cpy);
		}
		blink_time = HAL_GetTick() + 300;
		while(HAL_GetTick() < blink_time)
		{
			char bufferM[1] = "  ";
			HAL_UART_Transmit (&hlpuart1, bufferM, sizeof (bufferM), 100);
		}

	}
}
void Update_Time(struct time *t1)
{
	char bufferM[1];
	itoa(t1->minute, bufferM,10);
	HAL_UART_Transmit (&hlpuart1, bufferM, sizeof (bufferM), 100);
	char bufferZ[1] = ":";
	HAL_UART_Transmit (&hlpuart1, bufferZ, sizeof (bufferZ), 100);
	char bufferS[2];
	itoa(t1->seconds, bufferS,10);
	HAL_UART_Transmit (&hlpuart1, bufferS, sizeof (bufferS), 100);
	HAL_UART_Transmit (&hlpuart1, bufferZ, sizeof (bufferZ), 100);
	char bufferMs[3];
	itoa(t1->miliseconds, bufferMs,10);
	HAL_UART_Transmit (&hlpuart1, bufferMs, sizeof (bufferMs), 100);
	char newline[2] = "\r\n";
	HAL_UART_Transmit (&hlpuart1, (uint8_t *) newline, 2, 10);
}
