/*
 * fsm_automatic.c
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#include "fsm_automatic.h"

void fsm_automatic_run () {
	switch (status) {
		case INIT:
			setTimer1 (1000);
			status = RED_GREEN;
			counter1 = redDuration;
			counter2 = greenDuration;
			setColor1(AUTO_RED);
			setColor2(AUTO_GREEN);
			break;
		case RED_GREEN:
			if (timer1_flag == 1) {
				if (counter2 == 1) {
					status = RED_YELLOW;
					counter1 --;
					counter2 = yellowDuration;
					setColor2(AUTO_YELLOW);
					setTimer1(1000);
				}
				else {
					counter1 --;
					counter2 --;
					setTimer1(1000);
				}
			}
			break;
		case RED_YELLOW:
			if (timer1_flag == 1) {
				if (counter1 == 1) {
					status = GREEN_RED;
					counter1 = greenDuration;
					counter2 = redDuration;
					setColor1(AUTO_GREEN);
					setColor2(AUTO_RED);
					setTimer1(1000);
				}
				else {
					counter1 --;
					counter2 --;
					setTimer1(1000);
				}
			}
			break;
		case GREEN_RED:
			if (timer1_flag == 1) {
				if (counter1 == 1) {
					status = YELLOW_RED;
					counter1 = yellowDuration;
					counter2 --;
					setColor1(AUTO_YELLOW);
					setTimer1(1000);
				}
				else {
					counter1 --;
					counter2 --;
					setTimer1(1000);
				}
			}
			break;
		case YELLOW_RED:
			if (timer1_flag == 1) {
				if (counter1 == 1) {
					status = RED_GREEN;
					counter1 = redDuration;
					counter2 = greenDuration;
					setColor1(AUTO_RED);
					setColor2(AUTO_GREEN);
					setTimer1(1000);
				}
				else {
					counter1 --;
					counter2 --;
					setTimer1(1000);
				}
			}
			break;
		default:
			break;
	}
}
