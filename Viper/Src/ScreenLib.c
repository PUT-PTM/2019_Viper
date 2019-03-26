#include "ScreenLib.h"

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

void initial_screen(){
	lcd_reset();
  	lcd_command(0x21);
  	lcd_command(0x14);
  	lcd_command(0x80 | 0x3f); //Ustawienie kontrastu
  	lcd_command(0x20);
  	lcd_command(0x0c);
}

void lcd_pixel(uint8_t X, uint8_t Y) {
//0x70
	lcd_command(0x40 | Y); //Y 0
	lcd_command(0x80 | X); //X 0
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,0);
	spi_sendrecv(0x70);
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,1);
}
