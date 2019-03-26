#include "Defines.h"
#include "Accelerometer.h"

float accX, accY, accZ, out[4];

void control(){
	LIS3DSH_ReadACC(out);
		  accX = out[0]/100;
		  accY = out[1]/100;
		  accZ = out[2]/100;

		  //up
		  if(accY>1){
			  GREEN_DIODE_OFF;
			  RED_DIODE_ON;
			  ORANGE_DIODE_OFF;
			  BLUE_DIODE_OFF;
		  }	//down
		  else if(accY<-1){
			  GREEN_DIODE_ON;
			  RED_DIODE_OFF;
			  ORANGE_DIODE_OFF;
			  BLUE_DIODE_OFF;
		  }	//left
		  else if(accX<-1){
			  GREEN_DIODE_OFF;
			  RED_DIODE_OFF;
			  ORANGE_DIODE_ON;
			  BLUE_DIODE_OFF;
		  }	//right
		  else if(accX>1){
			  GREEN_DIODE_OFF;
			  RED_DIODE_OFF;
			  ORANGE_DIODE_OFF;
			  BLUE_DIODE_ON;
		  }
}
