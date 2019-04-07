#include "Defines.h"

SPI_HandleTypeDef hspi2;

//functions

static spiSend(uint8_t byte);
extern void lcdCommand(uint8_t cmd);
extern void lcdInitScreen();

extern void lcdReset();

extern void lcdClear();
extern void lcdDrawLogo(const uint8_t * data);
extern void lcdCopy();
extern void lcdDrawText(int row, int col, const char* text);
extern inline void lcdDrawPixel(int x, int y);
extern void lcdDrawLine(int x1, int y1, int x2, int y2);

extern void lcd_copy();
