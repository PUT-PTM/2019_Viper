#define DEFINES_H
#ifdef DEFINES_H

#include "main.h"
/*
 * Podpiecie pinow
 *
 * GND - GND
 * BL - 3V
 * VCC - 3V
 * CLK - PB10
 * Din - PC3
 * DC - PC14
 * CE - PC13
 * RST - PC15
 *
 * */

//defines

#define CE		GPIO_PIN_13
#define RST		GPIO_PIN_15 // reset - przy starcie stan 0 przez 100ns, potem 1 przy pracy
#define DC 		GPIO_PIN_14 // 1 - przesylanie danych, 0 - komendy dla wyswietlacza

#define GREEN_DIODE_ON 		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1)
#define ORANGE_DIODE_ON	 	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1)
#define RED_DIODE_ON		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1)
#define BLUE_DIODE_ON		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1)
#define GREEN_DIODE_OFF		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,0)
#define ORANGE_DIODE_OFF	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,0)
#define RED_DIODE_OFF		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,0)
#define BLUE_DIODE_OFF		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,0)

#define LCD_COMMAND  0
#define LCD_DATA     1

#define LCD_BUFFER_SIZE	(84 * 48 / 8)
#define LCD_WIDTH		84
#define LCD_HEIGHT		48

#define BLACK	1 //for drawing pixels
#define WHITE	0 //for clearing pixels

#define ACC_UP 		0
#define ACC_DOWN 	1
#define ACC_LEFT 	2
#define ACC_RIGHT 	3

uint8_t lcd_buffer[LCD_BUFFER_SIZE];
volatile int menuState ;
volatile int score;


#endif // DEFINES_H
