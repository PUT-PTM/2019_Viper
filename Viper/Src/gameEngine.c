/*
 * gameEngine.c
 *
 *  Created on: 10.04.2019
 *      Author: Weronika Kowalska
 */
#include "gameEngine.h"

void Startup() {
	lcdClear();
	printFrame();

    length = 5;	// poczatkowa dlugoc
    head.x = 25;	// poczatkowa pozycja glowy zmiji
    head.y = 20;


    //	to musi sie dziac w innym miejscu
    head.direction = ACC_RIGHT;			//!!!!!!!!!!!!!!!!



    //Food(); 	// generacja poczatkowa jedzonka
    //life = 3; 	// liczba zyc
    bend[0] = head;
    Move();
}

void Move() {
    int a,i;
	//Food();
	//fflush(stdin);	// ?
	len=0;
	for(i=0; i<30; i++) {
		body[i].x=0;
		body[i].y=0;
		if(i==length) break;
	}

	if(head.direction==ACC_RIGHT) Right();
	if(head.direction==ACC_LEFT) Left();
//	else if(head.direction==ACC_DOWN) Down();
//	else if(head.direction==ACC_UP) Up();

//	ExitGame();	//kolizja

	// funkcja kontrolujaca koniec gry

//    if(	(key==RIGHT && head.direction!=LEFT && head.direction!=RIGHT)||
//		(key==LEFT && head.direction!=RIGHT && head.direction!=LEFT)||
//		(key==UP && head.direction!=DOWN && head.direction!=UP)||
//		(key==DOWN && head.direction!=UP && head.direction!=DOWN)) {
//			bend_no++;
//			bend[bend_no] = head;
//			head.direction = key;	// akcelerometr
//			if(key==UP) head.y--;
//			if(key==DOWN) head.y++;
//			if(key==RIGHT) head.x++;
//			if(key==LEFT) head.x--;
//			Move();
//    } else if(key==27) {	// przerwanie
//		// jesli uzytkownik bedzie chcial zakonczyc gre
//    } else {
//		// tutaj jeszcze nwm
//        printf("\a");
//        Move();
//    }
}

void Left() {
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++) {
        body[len].x=head.x+i;
        body[len].y=head.y;

        printFrame();
        lcdDrawSquare(body[len].x,body[len].y,3);
        lcdCopy();
        for(int i = 0; i < 6000000; i++);
        lcdClear();
//        GotoXY((head.x+i),head.y);
//        {
//			// wyœwietlanie w odpowiednim miejscu zmiji
//            if(len==0) printf("<");
//            else printf("=");
//        }
        len++;
    }
//    Bend();
    head.x--;
}

void Right() {
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++) {
        body[len].x=head.x-i;
        body[len].y=head.y;

        printFrame();
        lcdDrawSquare(body[len].x,body[len].y,3);
        lcdCopy();
        for(int i = 0; i < 6000000; i++);
        lcdClear();
//        GotoXY(body[len].x,body[len].y);
//        {
//			// wyœwietlanie w odpowiednim miejscu zmiji
//            if(len==0) printf(">");
//            else printf("=");
//        }
        len--;
    }
//    Bend();
    head.x++;
}

