/*
 * gameEngineA.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Alicja
 */

#include "gameEngineA.h"


void setUP(){
	gameOver = false;
	dir = STOP;
	x = LCD_WIDTH/3;
	y = LCD_HEIGHT/5;
	tailX[0] = x;
	tailY[0] = y;
	fruitX = rand()%LCD_WIDTH;
	fruitY = rand()%LCD_HEIGHT;
	score = 0;
	nTail = 5;
	tailLeng = 20*300*nTail;
}

void gameOVER(){
	dir=STOP;
	lcdClear();
	char title[] = "GAME OVER";
	lcdDrawText(3, 16, title);
	lcdCopy();
}

void Draw() {
	lcdClear();
	for (int i = 0; i < LCD_HEIGHT; i++) {
		for (int j = 0; j < LCD_WIDTH; j++) {
			lcdDrawLine(0, 0, 84, 0);
			lcdDrawLine(0, 0, 0, 48);
			lcdDrawLine(83, 47, 0, 47);
			lcdDrawLine(83, 47, 83, 0);

			if (i == y && j == x) {
				lcdDrawSquare(x, y, 3);

			} else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						lcdDrawSquare(tailX[k], tailY[k], 3);
						print = true;
					}
				}
			}
		}
	}
	lcdCopy();
	for (int i = 0; i < 900000; i++)
		;
}
void Input(){
	int stan = control();
	if(stan==ACC_RIGHT) dir = RIGHT;
	else if(stan==ACC_LEFT) dir = LEFT;
	else if(stan==ACC_UP) dir = UP;
	else if(stan==ACC_DOWN) dir = DOWN;

}
void Logic() {

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i <nTail ; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {
	case LEFT:
		x=x-3;
		break;
	case RIGHT:
		x=x+3;
		break;
	case UP:
		y=y-3;
		break;
	case DOWN:
		y=y+3;
		break;
	default:
		break;
	}

	//zderzenie ze sciana
	if (x >= LCD_WIDTH-3 || x < 0 || y >= LCD_HEIGHT-3 || y < 0) {
		gameOVER();
	}
	//zderzenie ze soba

	for (int i = 0; i < nTail; i++) {
		if (tailY[i] == x && tailX[i] == y)
			gameOVER();
	}

	//owocek!!
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % LCD_WIDTH;
		fruitY = rand() % LCD_HEIGHT;
		nTail++;
	}
}
