#include <string.h>
#include "ScreenLib.h"
#include "font.h"


static spiSend(uint8_t byte){
	HAL_SPI_Transmit(&hspi2, &byte, 1, HAL_MAX_DELAY);
}

void lcdCommand(uint8_t cmd){
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin|CE_Pin,0);
	spiSend(cmd);
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin|CE_Pin,1);
}

void lcdReset(){
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,0);
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,1);
}

void lcdInitScreen(){
	lcdReset();
	lcdCommand(0x21);
	lcdCommand(0x14);
	lcdCommand(0x80 | 0x3f);
	lcdCommand(0x20);
	lcdCommand(0x0c);
}

void lcdClear(){
	memset(lcd_buffer,0,LCD_BUFFER_SIZE);
}

void lcdDrawLogo(const uint8_t * data){
	lcdCommand(0x40 | 0x00); //Y 0
	lcdCommand(0x80 | 0x00); //X 0
	memcpy(lcd_buffer,data,LCD_BUFFER_SIZE);
}

void lcdDrawLine(int x1, int y1, int x2, int y2)
{
	int dx, dy, sx, sy;
	if (x2 >= x1) {
		dx = x2 - x1;
		sx = 1;
	} else {
		dx = x1 - x2;
		sx = -1;
	}
	if (y2 >= y1) {
		dy = y1 - y2;
		sy = 1;
	} else {
		dy = y2 - y1;
		sy = -1;
	}
	int dx2 = dx << 1;
	int dy2 = dy << 1;
    int err = dx2 + dy2;
    	while (1) {
    		lcdDrawPixel(x1,y1);
    		if (err >= dy) {
    			if (x1 == x2) break;
    			err += dy2;
    			x1 += sx;
    		}
    		if (err <= dx) {
    			if (y1 == y2) break;
    			err += dx2;
    			y1 += sy;
    		}
    	}
}

void lcdCopy() {
	int i;
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,0);
	for(i = 0;i<LCD_BUFFER_SIZE;i++){
		spiSend(lcd_buffer[i]);
	}
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,1);
}

void lcdDrawText(int row, int col, const char* text) {
	int i;
	uint8_t* pbuf = &lcd_buffer[row * 84 + col];
	while ((*text) && (pbuf < &lcd_buffer[LCD_BUFFER_SIZE - 6])) {
		int ch = *text++;
		const uint8_t* font = &font_ASCII[ch - ' '][0];
		for (i = 0; i < 5; i++) {
			*pbuf++ = *font++;
		}
		*pbuf++ = 0;
	}
}

inline void lcdDrawPixel(int x, int y) {
	lcd_buffer[ x + (y >> 3) * LCD_WIDTH] |= 1 << (y & 7);
}

void lcdDrawSquare(int x, int y, int h){
	for(int i = 0;i<h;i++){
		for(int j = 0;j<h;j++){
			lcdDrawPixel(x+i,y+j);
		}
	}
}
