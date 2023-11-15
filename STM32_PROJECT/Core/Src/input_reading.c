/*
 * input_reading.c
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#include "input_reading.h"

#define NO_OF_BUTTONS					3
#define DURATION_FOR_AUTO_INCREASING	100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static	GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static	GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static	GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static	GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];
static	uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static	uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
int button_flag[NO_OF_BUTTONS];

int check_button_flag(int i) {
	if (button_flag[i] == 1) {
		button_flag[i] = 0;
		return 1;
	}
	return 0;
}

void button_reading(void) {
	for (unsigned char i=0; i<NO_OF_BUTTONS; i++) {
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		switch (i) {
			case 0:
				debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
				break;
			case 1:
				debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
				break;
			case 2:
				debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
				break;
			default:
				break;
		}
		if ((debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) && (debounceButtonBuffer1[i] == debounceButtonBuffer3[i])) {
			if (buttonBuffer[i] == BUTTON_IS_RELEASED && debounceButtonBuffer1[i] == BUTTON_IS_PRESSED) {
				button_flag[i] = 1;
			}
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i]++;
			} else {
				flagForButtonPress1s[i] = 1;
			}
		} else {
			button_flag[i] = 0;
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(uint8_t index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}

