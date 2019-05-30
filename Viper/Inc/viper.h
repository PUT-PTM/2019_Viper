/*
 * viper.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Alicja
 */

#ifndef VIPER_H_
#define VIPER_H_

#include "ScreenLib.h"

void printLogo(const uint8_t * data);
void printMenu(int i);
void printFrame();
void printScoreMenu();
void printGameOver();

void printHead(int x, int y);
void printFruit(int x, int y);


#endif /* VIPER_H_ */
