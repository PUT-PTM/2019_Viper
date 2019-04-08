#include "Defines.h"
#include "Accelerometer.h"

void moveUP(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_ON;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  stan = ACC_UP;
}

void moveDOWN(){
	  GREEN_DIODE_ON;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  stan = ACC_DOWN;
}

void moveLEFT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_ON;
	  BLUE_DIODE_OFF;
	  stan = ACC_LEFT;
}

void moveRIGHT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_ON;
	  stan = ACC_RIGHT;
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
