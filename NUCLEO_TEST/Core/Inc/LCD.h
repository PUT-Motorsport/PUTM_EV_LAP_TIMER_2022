/*
 * LCD.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Adam Wasilewski
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "Timer.h"
#include "main.h"

void Show_Time(struct time *t1);
void Update_Time(struct time *t1);


char  bufferM[3];
char  bufferS[3];
char  bufferMs[3];

#endif /* INC_LCD_H_ */
