/*
 * Send_times.hpp
 *
 *  Created on: Nov 7, 2022
 *      Author: adam
 */

#ifndef INC_SEND_TIMES_HPP_
#define INC_SEND_TIMES_HPP_

#include <cstdio>

void Send_lap_time(uint32_t time);

void Send_sector_time(uint32_t time, uint8_t sector);


void Send_acc_time(uint32_t time);
void Send_skidpad_time(uint32_t time);

#endif /* INC_SEND_TIMES_HPP_ */
