/*
 * display7SEG.c
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#include "display7SEG.h"

uint8_t segmentArray[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6F}; //From 0 to 9
int state7SEG = 1;

void display7SEG1(int8_t counter) {
	if (counter<0 || counter>9) return;
	for (int i=0; i<7; i++) {
		HAL_GPIO_WritePin(s0_GPIO_Port, s0_Pin << i, !((segmentArray[counter]>>i)&0x1));
	}
}

void display7SEG2(int8_t counter) {
	if (counter<0 || counter>9) return;
	for (int i=0; i<7; i++) {
		HAL_GPIO_WritePin(s7_GPIO_Port, s7_Pin << i, !((segmentArray[counter]>>i)&0x1));
	}
}

void scan7SEG(int counter1, int counter2) {
	int count1 = counter1%10;
	int count2 = (counter1-count1)/10;

	int count3 = counter2%10;
	int count4 = (counter2-count3)/10;
	switch (state7SEG) {
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);

			display7SEG1(count1);
			display7SEG2(count3);
			state7SEG = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG1(count2);
			display7SEG2(count4);
			state7SEG = 1;
			break;
		default:
			break;
	}
}
