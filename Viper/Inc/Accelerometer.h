#include "lis3dsh.h"

uint8_t stan;

SPI_HandleTypeDef hspi1;
float accX, accY, accZ, out[4];

void control();
void moveUP();
void moveDOWN();
void moveLEFT();
void moveRIGHT();
