#include <string.h>
#include "ScreenLib.h"
#include "font.h"


uint8_t lcd_buffer[LCD_BUFFER_SIZE];

void spi_sendrecv(uint8_t byte){
	HAL_SPI_Transmit(&hspi2, &byte, 1, HAL_MAX_DELAY);
}

void lcd_reset(){
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,0);
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,1);
}

void lcd_command(uint8_t cmd){
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,0);
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin|CE_Pin,0);
	spi_sendrecv(cmd);
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin|CE_Pin,1);
}

void lcd_data(const uint8_t* data, int size){
	lcd_command(0x40 | 0x00); //Y 0
	lcd_command(0x80 | 0x00); //X 0

	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,0);
	for(int i=0;i<size;i++){
			spi_sendrecv(data[i]);
		}
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,1);
}

void init_screen(){
	lcd_reset();
  	lcd_command(0x21);
  	lcd_command(0x14);
  	lcd_command(0x80 | 0x3f); //Ustawienie kontrastu
  	lcd_command(0x20);
  	lcd_command(0x0c);

  	lcd_clear();
}

void lcd_draw_pixel(uint8_t X, uint8_t Y) {
//0x70
	//lcd_command(0 | Y);
	//lcd_command(0x80 | X);

	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,0);
	spi_sendrecv(BLACK);
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,1);
}

void lcd_clear(){
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,0);
	for(int i=0;i<LCD_BUFFER_SIZE;i++){
		spi_sendrecv(WHITE);
	}
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,1);
}

void lcd_draw_char(uint8_t row, uint8_t col,const unsigned char ch){
	lcd_command(0x40 | row);
	lcd_command(0x80 | col);
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,0);
	const uint16_t ch_pos = ch - 0x20;
	for(uint8_t offset = 0; offset < 5; offset++){
		spi_sendrecv(font_ASCII[ch_pos][offset]);
	}
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,0);
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,1);
}

void lcd_draw_string(int width_divider,int height_divider,char text[],uint8_t size){
	uint8_t col = LCD_WIDTH/width_divider;
	for(uint8_t i = 0; i < size-1; i++){
		  lcd_draw_char(LCD_HEIGHT/height_divider, col, (unsigned char)text[i]);
		  col=col+6;
	  }
}

void lcd_draw_line(int x1, int y1, int x2, int y2)
{
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,0);
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
    		lcd_draw_pixel(x1,y1);
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
    HAL_GPIO_WritePin(CE_GPIO_Port,CE_Pin,1);
}
