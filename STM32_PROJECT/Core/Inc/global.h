/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "input_reading.h"
#include "software_timer.h"


#define INIT			1
#define AUTO_RED		2
#define AUTO_GREEN		3
#define AUTO_YELLOW		4

#define RED_GREEN		5
#define RED_YELLOW		6
#define GREEN_RED		7
#define YELLOW_RED		8

extern int CYCLE;

extern int status;
extern int counter1;
extern int counter2;
extern int redDuration;
extern int yellowDuration;
extern int greenDuration;

extern int mode;
extern int tmp;

#endif /* INC_GLOBAL_H_ */
