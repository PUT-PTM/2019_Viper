#include "Defines.h"

SPI_HandleTypeDef hspi2;

//functions

static spiSend(uint8_t byte);
void lcdCommand(uint8_t cmd);
void lcdInitScreen();

void lcdReset();

void lcdClear();
void lcdDrawLogo(const uint8_t * data);
void lcdCopy();
void lcdDrawText(int row, int col, const char* text);
void lcdDrawPixel(int x, int y);
void lcdDrawLine(int x1, int y1, int x2, int y2);
void lcdDrawSquare(int x, int y,int h);

void lcd_copy();
