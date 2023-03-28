/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Leanhthi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//#define INIT 23092002
#define RUNNING 100
#define Waiting 99

#define STOP 0

#define TIME_RED 2000
#define TIME_GREEN 1700

#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_YELLOW 3

#define MAN_RED 11
#define MAN_GREEN 12
#define MAN_YELLOW 13


#define HAND_RED 21
#define HAND_GREEN 22
#define HAND_YELLOW 23


#define P_RED 31
#define P_GREEN 32


extern int timer;//LED 1 TIME
extern int timer2;//LED 2 TIME
extern int timer3;//P TIME

extern int status1;//LED 1
extern int status2;//LED 2
extern int status3;// MAIN MODE
extern int status4;// P MODE

extern int RED_TIME;
extern int GREEN_TIME;
extern int YELLOW_TIME;
extern int TIME_OUT;

extern int speaker;

void Print_HELLO();
void Print_TimeOut(int abc);
void Print_TimeP(int abc);
void Print_Mode(int abc);
void Print_Time(int abc);
void Print_Time1(int abc);
void Print_Time2(int abc);
void off_Speaker();
void toogle_Speaker();
void Print_ERROR();

#endif /* INC_GLOBAL_H_ */
