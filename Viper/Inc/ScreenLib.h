#include "Defines.h"

SPI_HandleTypeDef hspi2;

//functions

void spi_sendrecv(uint8_t byte);
void lcd_reset();
void lcd_command(uint8_t cmd);
void lcd_data(const uint8_t* data, int size);
void initial_screen();
void lcd_pixel(uint8_t X, uint8_t Y);
void lcd_clear();
