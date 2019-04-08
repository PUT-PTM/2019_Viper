#include "Defines.h"
#include "Accelerometer.h"


float accX, accY, accZ, out[4];


void moveUP(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_ON;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  stan = UP;
}

void moveDOWN(){
	  GREEN_DIODE_ON;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  stan = DOWN;
}

void moveLEFT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_ON;
	  BLUE_DIODE_OFF;
	  stan = LEFT;
}

void moveRIGHT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_ON;
	  stan = RIGHT;
}

void control(){
	LIS3DSH_ReadACC(out);
	accX = out[0]/100;
	accY = out[1]/100;
	accZ = out[2]/100;
	//up
	if(accY>1) moveUP();
	//down
	else if(accY<-1) moveDOWN();
	//left
	else if(accX<-1) moveLEFT();
	//right
	else if(accX>1) moveRIGHT();
}
