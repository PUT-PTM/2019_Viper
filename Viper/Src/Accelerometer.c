#include "Defines.h"
#include "Accelerometer.h"

float accX, accY, accZ, out[4];
int state[4];

int getState(){
	for(int i = 0; i < 4; i++){
		if(state[i] == 1)
			return i;
	}
}

void setUP(){
	state[0] = 1;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
}

void setDOWN(){
	state[0] = 0;
	state[1] = 1;
	state[2] = 0;
	state[3] = 0;
}

void setLEFT(){
	state[0] = 0;
	state[1] = 0;
	state[2] = 1;
	state[3] = 0;
}

void setRIGHT(){
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 1;
}

void moveUP(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_ON;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  setUP();
}

void moveDOWN(){
	  GREEN_DIODE_ON;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_OFF;
	  setDOWN();
}

void moveLEFT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_ON;
	  BLUE_DIODE_OFF;
	  setLEFT();
}

void moveRIGHT(){
	  GREEN_DIODE_OFF;
	  RED_DIODE_OFF;
	  ORANGE_DIODE_OFF;
	  BLUE_DIODE_ON;
	  setRIGHT();
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
