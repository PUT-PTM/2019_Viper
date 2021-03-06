/*
 * gameEngineA.h
 *
 *  Created on: May 15, 2019
 *      Author: Alicja
 */

#ifndef GAMEENGINEA_H_
#define GAMEENGINEA_H_

#include "Defines.h"
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <viper.h>
#include <ScreenLib.h>
#include "Accelerometer.h"

#define bool int
#define true 1
#define false 0

bool gameOver;
uint8_t x,y,fruitX,fruitY;

//viper
uint8_t tailX[100], tailY[100];
uint8_t nTail, tailLeng;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN}dir;
enum STATE {stateSTART, stateLEFT,stateRIGHT,stateUP,stateDOWN, stateGameOver}state;

void setUP();
int gameOVER();
void Draw();
void Input();
void Logic();
void Restart();

#endif /* GAMEENGINEA_H_ */
