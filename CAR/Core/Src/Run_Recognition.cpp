/*
 * Run_Recognition.cpp
 *
 *  Created on: Nov 7, 2022
 *      Author: adam
 */
#include "Run_Recognition.hpp"
#include "can_interface.hpp"
#include "Send_times.hpp"

extern CAN_HandleTypeDef hcan1;

uint32_t time_in_milis;
uint32_t lap_time;

constexpr uint32_t discard_threshold = discard_minutes*1000;


void Recognize_run(Code c1)
{
	switch(c1.sector)
	{
		case START_FINISH:

			if(c1.last_sector == DEFAULT)
			{
				//Start timer.
				time_in_milis = HAL_GetTick();
			}
			else if(c1.last_sector == START_FINISH)
			{
				//Send lap time.
				Send_lap_time(HAL_GetTick() - time_in_milis);
				time_in_milis = HAL_GetTick();

			}
			else if(c1.last_sector == SECTOR_3_ACC)
			{
				if((HAL_GetTick() - time_in_milis) > discard_threshold)
				{
					lap_time = 0;
					time_in_milis = HAL_GetTick();
				}
				//Send sector 3 time and lap time.
				uint32_t s3 = HAL_GetTick() - time_in_milis;
				Send_sector3_time(s3);
				Send_lap_time(lap_time + s3);
				lap_time = 0;
			}
			break;

		case SECTOR_2_SKIDPAD:
			//send sector 1 time.
			{
				if(c1.last_sector == START_FINISH)
				{
					uint32_t s1 = HAL_GetTick() - time_in_milis;
					Send_sector1_time(s1);
					lap_time += s1;
				}
				else if(c1.last_sector == DEFAULT)
				{
					time_in_milis = HAL_GetTick();
				}
				else if(c1.last_sector == SECTOR_2_SKIDPAD)
				{
					Send_skidpad_time(HAL_GetTick() - time_in_milis);
					c1.last_sector = DEFAULT;
				}

			}
			break;

		case SECTOR_3_ACC:
			//Send sector 2 time OR acc time.
			if(c1.last_sector == SECTOR_2_SKIDPAD)
			{
				//Send sector 2 time.
				uint32_t s2 = HAL_GetTick() - time_in_milis;
				Send_sector2_time(s2);
				lap_time += s2;
			}
			else if(c1.last_sector == START_FINISH)
			{
				//Send Acc time.
				Send_acc_time(HAL_GetTick() - time_in_milis);
				c1.last_sector = DEFAULT;

			}
			else if(c1.last_sector == SECTOR_3_ACC)
			{
				//Send skidpad time
				Send_skidpad_time(HAL_GetTick() - time_in_milis);
			}
			break;
	}
}
