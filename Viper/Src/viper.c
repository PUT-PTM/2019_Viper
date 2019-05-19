/*
 * viper.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Alicja
 */
#include "viper.h"

extern void printLogo(const uint8_t * data){
	lcdDrawLogo(data);
	lcdCopy();
	HAL_Delay(1000);
	lcdClear();
}

extern void printMenu(int i){
	lcdClear();

	char title[] = "MENU";
	char start[] = "START";
	char scores[] = "SCORES";
	char exit[] = "EXIT";

	lcdDrawText(0, 16, title);
	lcdDrawText(2, 16, start);
	lcdDrawText(3, 16, scores);
	lcdDrawText(4, 16, exit);

	if (i == 0) {
		lcdDrawSquare(10, 18, 3);
	} else if (i == 1) {
		lcdDrawSquare(10, 26, 3);
	} else if (i == 2) {
		lcdDrawSquare(10, 34, 3);
	}

	lcdCopy();
}

extern void printFrame(){
	lcdDrawLine(0,0,84,0);
	lcdDrawLine(0,0,0,48);
	lcdDrawLine(83,47,0,47);
	lcdDrawLine(83,47,83,0);
	lcdCopy();
}

extern void printScoreMenu(){
	lcdClear();

	char title[] = "BEST SCORES";
	lcdDrawText(0, 0, title);
	lcdCopy();
}

void printHead(int x, int y){
	lcdClear();
	lcdDrawSquare(x,y,3);
	lcdCopy();
}

void printFruit(int x, int y){
	lcdClear();
	lcdDrawSquare(x,y,5);
	lcdCopy();
}

