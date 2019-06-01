#include "Defines.h"
#include "Accelerometer.h"


// w dol -> w prawo
int moveRIGHT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_ON;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  return ACC_UP;
}

// w gore -> w lewo
int moveLEFT(){
	  GREEN_DIODE_ON;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  return ACC_DOWN;
}

// w lewo -> w dol
int moveDOWN(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_ON;
	  BLUE_DIODE_OFF;
	  return ACC_LEFT;
}

// prawo -> gora
int moveUP(){
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

	if(accY>1) return moveUP();			//up
	else if(accY<-1) return moveDOWN();	//down
	else if(accX<-1)  return moveLEFT();	//left
	else if(accX>1)  return moveRIGHT();//right
}
