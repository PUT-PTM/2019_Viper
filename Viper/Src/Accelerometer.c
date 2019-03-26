#include "main.h"
#include "Accelerometer.h"

float accX, accY, accZ, out[4];

void contorl(){
	LIS3DSH_ReadACC(out);
		  accX = out[0]/100;
		  accY = out[1]/100;
		  accZ = out[2]/100;

		  if(accY>8&&accY<10){
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,1);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0);
		  }
		  else if(accX>-9&&accX<-7){
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,1);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0);
		  }
		  else if(accY>-9&&accY<-7){
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,1);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0);
		  }
		  else if(accX>8&&accX<10){
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,1);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,0);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,0);
		  }
}
