/*
 * led_traffic.c
 *
 *  Created on: Nov 15, 2023
 *      Author: tanta
 */

#include "led_traffic.h"

void setColor1(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin | LED_YELLOW1_Pin, GPIO_PIN_SET);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin | LED_YELLOW1_Pin, GPIO_PIN_SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin | LED_YELLOW1_Pin, GPIO_PIN_SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin | LED_RED1_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void setColor2(int color) {
	switch (color) {
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin | LED_YELLOW2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin | LED_YELLOW2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin | LED_YELLOW2_Pin, GPIO_PIN_SET);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin | LED_RED2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void blinkLed1(int color) {
	switch (color) {
		case AUTO_RED:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin);
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin);
			break;
		default:
			break;
	}
}

void disable1() {
	HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
}

void disable2() {
	HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin, GPIO_PIN_SET);
}
