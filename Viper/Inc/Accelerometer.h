#include "lis3dsh.h"

SPI_HandleTypeDef hspi1;
float accX, accY, accZ, out[4];
uint8_t stan;

int control();
int moveUP();
int moveDOWN();
int moveLEFT();
int moveRIGHT();
