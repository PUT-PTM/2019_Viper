/*
 * gameEngineA.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Alicja
 */

#include "gameEngineA.h"

void setUP() {
	dir = STOP;
	x = LCD_WIDTH/3;
	y = LCD_HEIGHT/4;
	tailX[0] = x;
	tailY[0] = y;
	fruitX = (rand() % LCD_WIDTH + 3) - 3;
	fruitY = (rand() % LCD_HEIGHT + 3) - 3;
	score = 0;
	nTail = 3;
}

int gameOVER() {
	if (state == stateGameOver && dir == STOP)
		return 1;
	else
		return 0;
}

void Draw() {
	lcdClear();
	for (int i = 0; i < LCD_HEIGHT; i++) {
		for (int j = 0; j < LCD_WIDTH; j++) {
			lcdDrawLine(0, 0, 84, 0);
			lcdDrawLine(0, 0, 0, 48);
			lcdDrawLine(83, 47, 0, 47);
			lcdDrawLine(83, 47, 83, 0);

			lcdDrawSquare(fruitX, fruitY, 3);

			if (i == y && j == x) {
				lcdDrawSquare(x, y, 3);

			} else {
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						lcdDrawSquare(tailX[k], tailY[k], 3);
					}
				}
			}
		}
	}
	lcdCopy();
	for (int i = 0; i < 900000; i++)
		;
}
void Input() {
	int stan = control();
	if (stan == ACC_RIGHT && dir != LEFT)
		dir = RIGHT;
	else if (stan == ACC_LEFT && dir != RIGHT)
		dir = LEFT;
	else if (stan == ACC_UP && dir != DOWN)
		dir = UP;
	else if (stan == ACC_DOWN && dir != UP)
		dir = DOWN;

}
void Logic() {

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {
	case LEFT:
		x = x - 3;
		state = stateLEFT;
		break;
	case RIGHT:
		x = x + 3;
		state = stateRIGHT;
		break;
	case UP:
		y = y - 3;
		state = stateUP;
		break;
	case DOWN:
		y = y + 3;
		state = stateUP;
		break;
	default:
		break;
	}

	//zderzenie ze sciana
	if (tailX[0] >= LCD_WIDTH - 3 || x < 0 || tailY[0] >= LCD_HEIGHT - 3
			|| y < 0) {
		state = stateGameOver;
		dir = STOP;
	}
	//zderzenie ze soba

	if (nTail > 5) {
		for (int i = 1; i < nTail; i++) {
			if (tailY[i] == y && tailX[i] == x) {
				state = stateGameOver;
				dir = STOP;
			}
		}
	}

	//owocek!!
	if ((x <= fruitX + 3 && x >= fruitX - 3)
			&& (y <= fruitY + 1 && y >= fruitY - 1)) {
		score += 10;
		fruitX = (rand() % LCD_WIDTH + 3) - 3;
		fruitY = (rand() % LCD_HEIGHT + 3) - 3;
		nTail++;
	}
}

void Restart() {
	lcdClear();
	dir = STOP;
	x = LCD_WIDTH/3;
	y = LCD_HEIGHT/4;
	tailX[0] = x;
	tailY[0] = y;
	nTail = 0;
	lcdCopy();
}
