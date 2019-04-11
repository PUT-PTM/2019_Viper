/*
 * gameEngine.h
 *
 *  Created on: 08.04.2019
 *      Author: Weronika Kowalska
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "Defines.h"
#include "ScreenLib.h"
#include "Accelerometer.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <time.h>

uint8_t length;	// poczatkowa dlugosc
uint8_t bend_no;
uint8_t len;
char key;	//w zaleznosci od stan akcelerometru
uint8_t life;
void Move();	// ta funkcja (bez while) bedzie w timerze
				// generuje sie tu jedzonko dla wensza,
				// inicjalizuje poczatkowa dlugosc
				// sprawdza na biezaco kierunek tuchu
				// kontrola ruchem, zliczanie miejsc zgiecia
void Food();	//gdy polozenie glowy jest rown polozneiu jedzonka
				// zmija sie wydluza
				// generuje sie w losowym miejscu jedzonko
uint8_t Score();
void gotoxy(int x, int y);	// ustawia kursor w odpowiednim miejscu
void GotoXY(int x, int y);
void Bend();
void Down();
void Left();
void Up();
void Right();
void ExitGame();	// wykrywanie kolizji
void Startup();

struct coordinates {
	uint8_t x;
	uint8_t y;
	uint8_t direction;
};

typedef struct coordinates coordinates;
coordinates head, bend[500],food,body[30];


// dziwne rzeczy do wyswietlania w danej pozycji w konsoli
// trzeba przerobic na wyswietlacz
//void gotoxy(int x, int y) {
//    COORD coord;	//to z biblioteki do kontroli kursora w konsoli
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//void GotoXY(int x, int y) {
//    HANDLE a;
//    COORD b;
//    fflush(stdout);
//    b.X = x;
//    b.Y = y;
//    a = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleCursorPosition(a,b);
//}

//// generuje losowa pozycje jedzonka
//void Food() {
//    if(head.x==food.x&&head.y==food.y) {
//        length++;
//        time_t a;
//        a=time(0);
//        srand(a);
//        food.x=rand()%70;
//        if(food.x<=10) food.x+=11;
//        food.y=rand()%30;
//        if(food.y<=10) food.y+=11;
//    }
//    else if(food.x==0) {/*to create food for the first time coz global variable are initialized with 0*/
//        food.x=rand()%70;
//        if(food.x<=10) food.x+=11;
//        food.y=rand()%30;
//        if(food.y<=10) food.y+=11;
//    }
//}
//
//// funkcja od zginania, dzikie rzeczy tu sa, wymaga glebszej analizy
//void Bend()
//{
//    int i,j,diff;
//    for(i=bend_no; i>=0&&len<length; i--) {
//        if(bend[i].x==bend[i-1].x) {
//            diff=bend[i].y-bend[i-1].y;
//            if(diff<0)
//                for(j=1; j<=(-diff); j++) {
//                    body[len].x=bend[i].x;
//                    body[len].y=bend[i].y+j;
//                    GotoXY(body[len].x,body[len].y);
//                    printf("*");
//                    len++;
//                    if(len==length) break;
//                }
//            else if(diff>0)
//                for(j=1; j<=diff; j++) {
//                    /*GotoXY(bend[i].x,(bend[i].y-j));
//                    printf("*");*/
//                    body[len].x=bend[i].x;
//                    body[len].y=bend[i].y-j;
//                    GotoXY(body[len].x,body[len].y);
//                    printf("*");
//                    len++;
//                    if(len==length) break;
//                }
//        }
//        else if(bend[i].y==bend[i-1].y) {
//            diff=bend[i].x-bend[i-1].x;
//            if(diff<0)
//                for(j=1; j<=(-diff)&&len<length; j++) {
//                    /*GotoXY((bend[i].x+j),bend[i].y);
//                    printf("*");*/
//                    body[len].x=bend[i].x+j;
//                    body[len].y=bend[i].y;
//                    GotoXY(body[len].x,body[len].y);
//                    printf("*");
//                    len++;
//                    if(len==length) break;
//                }
//            else if(diff>0)
//                for(j=1; j<=diff&&len<length; j++)
//                {
//                    /*GotoXY((bend[i].x-j),bend[i].y);
//                    printf("*");*/
//                    body[len].x=bend[i].x-j;
//                    body[len].y=bend[i].y;
//                    GotoXY(body[len].x,body[len].y);
//                    printf("*");
//                    len++;
//                    if(len==length) break;
//                }
//        }
//    }
//}
//
//// tez do glebszej analizy
//void ExitGame() {
//    int i,check=0;
//    for(i=4; i<length; i++) { //starts with 4 because it needs minimum 4 element to touch its own body
//        if(body[0].x==body[i].x && body[0].y==body[i].y) {
//            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
//        }
//        if(i==length||check!=0) break;
//    }
//    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0) {
//        life--;
//        if(life>=0) {
//            head.x=25;
//            head.y=20;
//            bend_no=0;
//            head.direction=RIGHT;
//            Move();
//        }
//        else {
//            system("cls");
//            printf("You loose!\n");
//            record();
//            exit(0);
//        }
//    }
//}
//
//int Score() {
//    int score;
//    score=length-5;
//    return score;
//}

#endif /* GAMEENGINE_H_ */
