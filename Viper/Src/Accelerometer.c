#include "Defines.h"
#include "Accelerometer.h"

int moveDOWN(){
	GREEN_DIODE_ON;
	RED_DIODE_OFF;
	ORANGE_DIODE_OFF;
	BLUE_DIODE_OFF;
	return ACC_UP;
}

int moveUP(){
	GREEN_DIODE_OFF;
	RED_DIODE_ON;
	ORANGE_DIODE_OFF;
	BLUE_DIODE_OFF;
	return ACC_DOWN;
}

int moveLEFT(){
	GREEN_DIODE_OFF;
	RED_DIODE_OFF;
	ORANGE_DIODE_ON;
	BLUE_DIODE_OFF;
	return ACC_LEFT;
}

int moveRIGHT(){
	GREEN_DIODE_OFF;
	RED_DIODE_OFF;
	ORANGE_DIODE_OFF;
	BLUE_DIODE_ON;
	return ACC_RIGHT;
}

int control(){
	LIS3DSH_ReadACC(out);

	accX = out[0]/100;
	accY = out[1]/100;
	accZ = out[2]/100;

	if(accY>0.5) return moveUP();			//up
	else if(accY<-0.5) return moveDOWN();	//down
	else if(accX<-0.5)  return moveLEFT();	//left
	else if(accX>0.5)  return moveRIGHT();	//right

}
