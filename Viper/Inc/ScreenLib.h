#include "Defines.h"

SPI_HandleTypeDef hspi2;

//functions

uint8_t spi_sendrecv(uint8_t byte);
void lcd_reset();
void lcd_command(uint8_t cmd);
void lcd_data(const uint8_t* data, int size);
void initial_screen();
