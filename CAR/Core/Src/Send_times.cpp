/*
 * Send_times.cpp
 *
 *  Created on: Nov 7, 2022
 *      Author: adam
 */

#include "Send_times.hpp"
#include "PUTM_EV_CAN_LIBRARY/lib/can_interface.hpp"

using namespace PUTM_CAN;

extern  CAN_HandleTypeDef hcan1;

void Send_lap_time(uint32_t time)
{
	Lap_timer_Lap_time lap_time{
		.Lap_time = time
	};
	auto timer_lap = Can_tx_message<Lap_timer_Lap_time>(lap_time, can_tx_header_LAP_TIMER_LAP_TIME);
	timer_lap.send(hcan1);

}
void Send_sector_time(uint32_t time, uint8_t sector)
{
	Lap_timer_Sector sector_time{
		.Sector = sector,
		.Sector_time = time
	};
	auto time_sector = Can_tx_message<Lap_timer_Sector>(sector_time, can_tx_header_LAP_TIMER_SECTOR);
	time_sector.send(hcan1);
}
void Send_acc_time(uint32_t time)
{
	Lap_timer_Acc_time acc_time{
		.Acc_Time = time
	};
	auto time_acc = Can_tx_message<Lap_timer_Acc_time>(acc_time, can_tx_header_LAP_TIMER_ACC_TIME);
	time_acc.send(hcan1);

}
void Send_skidpad_time(uint32_t time)
{
	Lap_timer_Skidpad_time skidpad_time{
		.Skidpad_time = time
	};
	auto time_skidpad = Can_tx_message<Lap_timer_Skidpad_time>(skidpad_time, can_tx_header_LAP_TIMER_SKIDPAD_TIME);
	time_skidpad.send(hcan1);
}
void SendMain(uint8_t _state)
{
	PUTM_CAN::Lap_timer_Main main{
		.device_state = Lap_timer_states(_state)
	};
	auto mainFrame = Can_tx_message<Lap_timer_Main>(main, can_tx_header_LAP_TIMER_MAIN);
	mainFrame.send(hcan1);
}
