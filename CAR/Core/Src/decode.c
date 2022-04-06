/*
 * decode.c
 *
 *  Created on: 6 Apr 2022
 *      Author: Adam
 */

#include "decode.h"

extern Code c1;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim3)
{
	uint32_t leading_diff = ((c1.risingedge[0] - c1.fallingedge[0])/1000);
	if(leading_diff == 2)
	{
		c1.leading_pulse == PULSE_OK;
		for(int i = 0;i<2;i++)
		{
			float NEC_impulse = (((float)(c1.risingedge[1+i])  - ((float)c1.fallingedge[1+i]))/1000);
			float NEC_pause =   (((float)(c1.fallingedge[2+i]) - ((float)c1.risingedge[1+i]))/1000);
			if((NEC_impulse > 0.4) && (NEC_impulse < 0.8))
			{
				if((NEC_pause > 1.2) && (NEC_impulse < 1.8))
				{
					c1.value[i] = 1;
				}
				else if((NEC_pause > 0.4) && (NEC_impulse < 0.8))
				{
					c1.value[i] = 0;
				}
			}
			else
			{

			}
		}
		c1.sector = c1.value[0] || c1.value[1];
	}
}
/*
void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // wait for the counter to reach the us input in the parameter
}
*/
