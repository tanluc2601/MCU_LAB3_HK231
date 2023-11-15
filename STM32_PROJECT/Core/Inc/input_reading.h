/*
 * input_reading.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "global.h"

int check_button_flag(int);
void button_reading(void);
unsigned char is_button_pressed(unsigned char);
unsigned char is_button_pressed_1s(unsigned char);

void fsm_for_input_processing(void);

#endif /* INC_INPUT_READING_H_ */
