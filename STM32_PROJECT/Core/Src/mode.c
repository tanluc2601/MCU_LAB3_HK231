/*
 * mode.c
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#include "mode.h"

void fsm_mode() {
	switch (mode) {
		case 1:
			fsm_automatic_run();
			if (is_button_pressed_1s(0)) {
				if (timer1_flag == 1) {
					mode = 2;
					tmp = redDuration;
					setColor1(AUTO_RED);
					setTimer1(1000);
				}
			} else {
				if (check_button_flag(0)) {
					mode = 2;
					tmp = redDuration;
					counter1 = redDuration;
					counter2 = mode;
					setColor1(AUTO_RED);
					disable2();
					setTimer1(500);
					setTimer3(200);
				}
			}
			break;
		case 2:
			if (is_button_pressed_1s(0)) {
				if (timer1_flag == 1) {
					mode = 3;
					tmp = yellowDuration;
					setColor1(AUTO_YELLOW);
					setTimer1(1000);
				}
			} else {
				if (timer1_flag == 1) {
					blinkLed1(AUTO_RED);
					setTimer1(500);
				}
				if (check_button_flag(0)) {
					counter1 = yellowDuration;
					counter2 = mode;
					mode = 3;
					tmp = yellowDuration;
					setColor1(AUTO_YELLOW);
					setTimer1(500);
				}
			}
			if (is_button_pressed_1s(1)) {
				if (timer3_flag == 1) {
					if (tmp > 99) {
						tmp = 1;
					} else {
						tmp++;
					}
					setTimer3(200);
				}
			} else {
				if (check_button_flag(1)) {
					if (tmp > 99) {
						tmp = 1;
					} else {
						tmp++;
					}
				}
			}
			if (check_button_flag(2)) {
				redDuration = tmp;
				if (redDuration > (yellowDuration + greenDuration)) {
					greenDuration = redDuration - yellowDuration;
				} else if (redDuration < (yellowDuration + greenDuration)) {
					yellowDuration = redDuration/2;
					greenDuration = redDuration/2;
					if (redDuration%2 != 0)
						greenDuration++;
				}
			}
			break;
		case 3:
			if (is_button_pressed_1s(0)) {
				if (timer1_flag == 1) {
					mode = 4;
					tmp = greenDuration;
					setColor1(AUTO_GREEN);
					setTimer1(1000);
				}
			} else {
				if (timer1_flag == 1) {
					blinkLed1(AUTO_YELLOW);
					setTimer1(500);
				}
				if (check_button_flag(0)) {
					counter1 = greenDuration;
					counter2 = mode;
					mode = 4;
					tmp = greenDuration;
					setColor1(AUTO_GREEN);
					setTimer1(500);
				}
			}
			if (is_button_pressed_1s(1)) {
				if (timer3_flag == 1) {
					if (tmp > 99) {
						tmp = 1;
					} else {
						tmp++;
					}
					setTimer3(200);
				}
			} else {
				if (check_button_flag(1)) {
					if (tmp > 99) {
						tmp = 1;
					} else {
						tmp++;
					}
				}
			}
			if (check_button_flag(2)) {
				yellowDuration = tmp;
				if (redDuration != yellowDuration + greenDuration) {
					redDuration = yellowDuration + greenDuration;
					if (redDuration > 99) {
						redDuration = 99;
						greenDuration = redDuration - yellowDuration;
					}
				}
			}
			break;
		case 4:
			if (is_button_pressed_1s(0)) {
				if (timer1_flag == 1) {
					mode = 2;
					tmp = redDuration;
					setColor1(AUTO_RED);
					setTimer1(1000);
				}
			} else {
				if (timer1_flag == 1) {
					blinkLed1(AUTO_GREEN);
					setTimer1(500);
				}
				if (check_button_flag(0)) {
					counter1 = redDuration;
					counter2 = mode;
					mode = 1;
					tmp = redDuration;
					setColor1(INIT);
					setTimer1(500);
					status = INIT;
				}
			}
			if (is_button_pressed_1s(1)) {
				if (timer3_flag == 1) {
					if (tmp > 99) {
						tmp = 1;
					} else {
						tmp++;
					}
					setTimer3(200);
				}
			} else {
				if (check_button_flag(1)) {
					if (tmp > 99) {
						tmp = 1;
					} else {
						tmp++;
					}
				}
			}
			if (check_button_flag(2)) {
				greenDuration = tmp;
				if (redDuration != yellowDuration + greenDuration) {
					redDuration = yellowDuration + greenDuration;
					if (redDuration > 99) {
						redDuration = 99;
						yellowDuration = redDuration - greenDuration;
					}
				}
			}
			break;
		default:
			break;
	}
}





















