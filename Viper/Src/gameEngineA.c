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
	x = LCD_HEIGHT/3;
	y = LCD_WIDTH/5;
	tailX[0] = x;
	tailY[0] = y;
	fruitX = rand()%LCD_WIDTH;
	fruitY = rand()%LCD_HEIGHT;
	score = 0;
	nTail = 10;
	tailLeng = 300* nTail;
}
void Draw() {

	for (int i = 0; i < LCD_HEIGHT - 4; i++) {
		for (int j = 0; j < LCD_WIDTH - 4; j++) {
			/*if (i == y && j == x) {
				printFrame();
				for (int i = 0; i < 7000000; i++);
				printHead(x, y);

			}*/

			bool print = false;
			for (int k = 0; k < nTail; k++)
			{
				if (tailX[k] == j && tailY[k] == i)
				{
					printFrame();
					for (int i = 0; i < (9000000/tailLeng); i++);
					printHead(tailX[k], tailY[k]);
					print = true;
				}
			}
		}
	}
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
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//zderzenie ze sciana
	if (tailX[0] == LCD_WIDTH - 1 || tailX[0] == 0 || tailY[0] == LCD_HEIGHT - 1 || tailY[0] == 0) {
		gameOver = true;
	}
	//zderzenie ze soba

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}

	//owocek!!
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % LCD_WIDTH;
		fruitY = rand() % LCD_HEIGHT;
		nTail++;
	}
}
