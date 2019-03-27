#include "Defines.h"

SPI_HandleTypeDef hspi2;

//functions

void spi_sendrecv(uint8_t byte);
void lcd_reset();
void lcd_command(uint8_t cmd);
void lcd_data(const uint8_t* data, int size);
void init_screen();
void lcd_draw_pixel(uint8_t X, uint8_t Y);
void lcd_clear();
void lcd_draw_char(uint8_t row, uint8_t col,const unsigned char text);
void lcd_copy();
void lcd_draw_string(int width_divider,int height_divider,char text[],uint8_t size);
void lcd_draw_line(int x1, int y1, int x2, int y2);
