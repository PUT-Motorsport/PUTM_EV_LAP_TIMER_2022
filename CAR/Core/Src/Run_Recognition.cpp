/*
 * Run_Recognition.cpp
 *
 *  Created on: Nov 7, 2022
 *      Author: adam
 */
#include "Run_Recognition.hpp"
#include "Send_times.hpp"
#include "LED.hpp"
#include <limits>

uint32_t time_in_milis;
uint32_t lap_time;

constexpr uint32_t lap_max_discard_threshold = 15*1000;
constexpr uint32_t lap_min_discard_threshold = 5*1000;

constexpr uint32_t acc_max_discard_threshold = 10*1000;
constexpr uint32_t acc_min_discard_threshold = 1*1000;

constexpr uint32_t skid_max_discard_threshold = 60*1000;
constexpr uint32_t skid_min_discard_threshold = 20*1000;

constexpr uint32_t uint32max = std::numeric_limits<uint32_t>::max();

extern Code c1;

void reset();

void Recognize_run()
{
	switch(c1.sector)
	{
		case START_FINISH:

			Set_Start_Finish();

			if(c1.last_sector == DEFAULT)
			{
				//Start timer.
				time_in_milis = HAL_GetTick();
			}
			else if(c1.last_sector == START_FINISH)
			{
				//Send lap time.
				uint32_t time = (((HAL_GetTick() - time_in_milis)%uint32max));
				if((time < lap_max_discard_threshold) && (time > lap_min_discard_threshold))
				{
					Send_lap_time(time);
					time_in_milis = HAL_GetTick();
				}
				else
				{
					reset();
				}
			}
			else if(c1.last_sector == SECTOR_3_ACC)
			{
				/*
				if((HAL_GetTick() - time_in_milis) > discard_threshold)
				{
					lap_time = 0;
					time_in_milis = HAL_GetTick();
				}
				*/
				//Send sector 3 time and lap time.
				uint32_t s3 = (HAL_GetTick() - time_in_milis)%uint32max;
				Send_sector_time(s3, 3);
				Send_lap_time(lap_time + s3);
				lap_time = 0;
			}
			else
			{
				//reset bo error.
			}
			HAL_Delay(1000);
			Reset_Detecion();
			break;

		case SECTOR_2_SKIDPAD:
			//send sector 1 time.
			Set_Sector2_Skidpad();
			{
				if(c1.last_sector == START_FINISH)
				{
					uint32_t s1 = (HAL_GetTick() - time_in_milis)%uint32max;
					Send_sector_time(s1, 1);
					lap_time += s1;
				}
				else if(c1.last_sector == DEFAULT)
				{
					time_in_milis = HAL_GetTick();
				}
				else if(c1.last_sector == SECTOR_2_SKIDPAD)
				{
					Send_skidpad_time((HAL_GetTick() - time_in_milis)%uint32max);
					c1.last_sector = DEFAULT;
				}
			}
			HAL_Delay(1000);
			Reset_Detecion();
			break;

		case SECTOR_3_ACC:
			//Send sector 2 time OR acc time.
			Set_Sector3_ACC();
			if(c1.last_sector == SECTOR_2_SKIDPAD)
			{
				//Send sector 2 time.
				uint32_t s2 = (HAL_GetTick() - time_in_milis)%uint32max;
				Send_sector_time(s2, 2);
				lap_time += s2;
			}
			else if(c1.last_sector == START_FINISH)
			{
				//Send Acc time.
				uint32_t time = (((HAL_GetTick() - time_in_milis)%uint32max));
				if((time < acc_max_discard_threshold) && (time > acc_min_discard_threshold))
				{
					Send_lap_time(time);
					reset();
					HAL_Delay(1000);
				}
				else
				{
					reset();
				}
			}
			else if(c1.last_sector == SECTOR_3_ACC)
			{
				//Send skidpad time
				Send_skidpad_time((HAL_GetTick() - time_in_milis)%uint32max);
			}
			HAL_Delay(1000);
			Reset_Detecion();
			break;
	}
}
void reset()
{
	time_in_milis = 0;
	c1.last_sector = DEFAULT;
	c1.sector = DEFAULT;
}
