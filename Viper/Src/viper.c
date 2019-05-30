/*
 * viper.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Alicja
 */
#include "viper.h"
#include<stdlib.h>

void printLogo(const uint8_t * data){
	lcdDrawLogo(data);
	lcdCopy();
	HAL_Delay(1000);
	lcdClear();
}

void printMenu(int i){
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

void printFrame(){
	lcdDrawLine(0,0,84,0);
	lcdDrawLine(0,0,0,48);
	lcdDrawLine(83,47,0,47);
	lcdDrawLine(83,47,83,0);
	lcdCopy();
}

void printScoreMenu(){
	lcdClear();
	char title[] = "BEST SCORES";
	lcdDrawText(0, 0, title);
	lcdCopy();
}

void printGameOver(){
	lcdClear();
	char cScore[10] = "";
	char title[] = "GAME OVER";
	char scoreBar[] = "YOUR SCORE IS";
	lcdDrawText(2, 16, title);
	lcdDrawText(3,4,scoreBar);
	lcdDrawText(4,38,itoa(score-1,cScore,10));
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

