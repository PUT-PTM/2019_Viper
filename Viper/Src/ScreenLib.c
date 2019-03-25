#include "ScreenLib.h"

uint8_t spi_sendrecv(uint8_t byte){
	uint8_t answer;
	HAL_SPI_TransmitReceive(&hspi2, &byte, &answer, 1, HAL_MAX_DELAY);
	return answer;
}

void lcd_reset(){
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,0);
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin,1);
}

void lcd_command(uint8_t cmd){
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,0);
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin|CE_Pin,0);
	spi_sendrecv(cmd);
	BLUE_DIODE_ON;
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin|CE_Pin,1);
}

void lcd_data(const uint8_t* data, int size){
	int i;
	HAL_GPIO_WritePin(DC_GPIO_Port,DC_Pin,1);
	HAL_GPIO_WritePin(DC_GPIO_Port,CE_Pin,0);
	for (i = 0; i < size; i++);
	for(i=0;i<size;i++){
		GREEN_DIODE_ON;
		spi_sendrecv(data[i]);

	}

	GREEN_DIODE_OFF;
	ORANGE_DIODE_ON;
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
