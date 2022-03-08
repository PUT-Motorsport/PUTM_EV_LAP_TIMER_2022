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
#include "LiquidCrystal.h"
#include "stdio.h"

struct time t1cpy;

void Show_Time(struct time *t1cpy, struct time *Best);
void Clear_first_row();
void Update_Time(struct time *t1);
void Show_Best(struct time *t1);

char  bufferM[3];
char  bufferS[2];
char  bufferMs[3];

#endif /* INC_LCD_H_ */
