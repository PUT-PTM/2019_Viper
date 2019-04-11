#include "lis3dsh.h"

SPI_HandleTypeDef hspi1;
float accX, accY, accZ, out[4];
uint8_t stan;

void control();
void moveUP();
void moveDOWN();
void moveLEFT();
void moveRIGHT();
