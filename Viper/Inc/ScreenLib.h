#include "main.h"


//defines

#define CE		GPIO_PIN_13
#define RST		GPIO_PIN_15 //reset - przy starcie stan 0 przez 100ns, potem 1 przy pracy
#define DC 		GPIO_PIN_14 // 1 - przesylanie danych, 0 - komendy dla wyswietlacza

#define GREEN_DIODE_ON 		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1)
#define ORANGE_DIODE_ON	 	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1)
#define RED_DIODE_ON			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1)
#define BLUE_DIODE_ON		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1)
#define GREEN_DIODE_OFF		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,0)
#define ORANGE_DIODE_OFF	 	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,0)
#define RED_DIODE_OFF		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,0)
#define BLUE_DIODE_OFF		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,0)

SPI_HandleTypeDef hspi2;

//functions

uint8_t spi_sendrecv(uint8_t byte);
void lcd_reset();
void lcd_command(uint8_t cmd);
void lcd_data(const uint8_t* data, int size);
void initial_screen();
