///*
// * fsm.c
// *
// *  Created on: Dec 10, 2022
// *      Author: Leanhthi
// */
//
//#define OneSec 100
//#include "fsm.h"
//#include "main.h"
//
//#define ON GPIO_PIN_SET
//#define OFF GPIO_PIN_RESET
//
//
//
//void toogleRed(){
//	HAL_GPIO_WritePin(GPIOA,led1a_Pin, ON);
//	HAL_GPIO_WritePin(GPIOB,led1b_Pin, OFF);
//}
//void toogleGreen(){
//	HAL_GPIO_WritePin(GPIOA,led1a_Pin, OFF);
//	HAL_GPIO_WritePin(GPIOB,led1b_Pin, ON);
//}
//void toogleYellow(){
//	HAL_GPIO_WritePin(GPIOA,led1a_Pin, ON);
//	HAL_GPIO_WritePin(GPIOB,led1b_Pin, ON);
//}
//void toogleRed1(){
//	HAL_GPIO_WritePin(GPIOB,led2a_Pin, ON);
//	HAL_GPIO_WritePin(GPIOB,led2b_Pin, OFF);
//}
//void toogleGreen1(){
//	HAL_GPIO_WritePin(GPIOB,led2a_Pin, OFF);
//	HAL_GPIO_WritePin(GPIOB,led2b_Pin, ON);
//}
//void toogleYellow1(){
//	HAL_GPIO_WritePin(GPIOB,led2a_Pin, ON);
//	HAL_GPIO_WritePin(GPIOB,led2b_Pin, ON);
//}
//void redP(){
//	HAL_GPIO_WritePin(GPIOB,ledpa_Pin, ON);
//	HAL_GPIO_WritePin(GPIOA,ledpb_Pin, OFF);
//}
//void greenP(){
//	HAL_GPIO_WritePin(GPIOB,ledpa_Pin, OFF);
//	HAL_GPIO_WritePin(GPIOA,ledpb_Pin, ON);
//}
//void offP(){
//	HAL_GPIO_WritePin(GPIOB,ledpa_Pin, OFF);
//	HAL_GPIO_WritePin(GPIOA,ledpb_Pin, OFF);
//}
//void fsm_automatic_run1(){
//	switch (status1	) {
//		case INIT:
//			status1 = AUTO_RED;
//			timer = RED_TIME/OneSec;
//			break;
//		case AUTO_RED:
//			toogleRed();
//			if(timer==STOP){
//				status1 = AUTO_GREEN;
//				timer=GREEN_TIME/OneSec;
//			}
//			break;
//		case AUTO_GREEN:
//			toogleGreen();
//			if(timer==STOP){
//				status1 = AUTO_YELLOW;
//				timer=YELLOW_TIME/OneSec;
//			}
//			break;
//		case AUTO_YELLOW:
//			toogleYellow();
//			if(timer==STOP){
//				status1 = AUTO_RED;
//				timer=RED_TIME/OneSec;
//			}
//			break;
//		default:
//			break;
//	}
//}
//
//
//void fsm_automatic_run2(){
//	switch (status2	) {
//		case INIT:
//			status2 = AUTO_GREEN;
//			timer2=GREEN_TIME/OneSec;
//			break;
//		case AUTO_RED:
//			toogleRed1();
//			if(timer2==STOP){
//				status2 = AUTO_GREEN;
//				timer2=GREEN_TIME/OneSec;
//			}
//			break;
//		case AUTO_GREEN:
//			toogleGreen1();
//			if(timer2==STOP){
//				status2 = AUTO_YELLOW;
//				timer2=YELLOW_TIME/OneSec;
//			}
//
//
//			break;
//		case AUTO_YELLOW:
//			toogleYellow1();
//			if(timer2==STOP){
//				status2 = AUTO_RED;
//				timer2=RED_TIME/OneSec;
//			}
//			break;
//		default:
//			break;
//	}
//}
//void fsm_p(){
//	switch (status4) {
//		case INIT:
//			status4=Waiting;
//			timer3 = 0;
//			offP();
//			off_Speaker();
//			break;
//		case Waiting:
//			break;
//		case P_RED://----------------------------------------
//			redP();
//			if(timer3==STOP){
//				status4=P_GREEN;
//				timer3 = RED_TIME/OneSec-1;
//				offP();
//				setTimer3 (1);
//				}
//			break;
//		case P_GREEN:
//			greenP();
//			if( timer3_flag == 1) {
//				toogle_Speaker();
//				setTimer3 (timer3*4) ;
//				}
//			if(timer3==STOP){
//				status4=INIT;
//			}
//			break;
//		default:
//			break;
//	}
//}
//void fsm_automatic_run3(){
//	switch (status3	) {
//		case RUNNING://AUTOMATIC MODE MAIN FSM
//			if( timer0_flag == 1) {
//				Print_Time1(timer);//TIMER FOR LED 1
//				Print_Time2(timer2);//TIMER FOR LED 2
//				timer--;//IF timer == 0 fsm1 will change status and set timer again
//				timer2--;// timer for fsm2 work like timer
//				if(status4==P_RED||status4==P_GREEN){//when P_mode is enable it will cout down timer for P_mode
//					Print_Mode(status4);
//					Print_TimeOut(timer3);
//					timer3--;//if timer == 0 P_mode will change status form red to green and set timer again or disable P_mode
//				}
//				setTimer0 (OneSec);
//				}
//			if(button_flag[0]==1){// button 1 turn MAIN FSM to manual mode to adjust time for AUTOMATIC
//								//It will turn FSM1 FSM2 to waiting
//								//when change status it will use timer for MODE. timer2 for time of this mode
//								//it will enable timer 3 for timeOut
//				button_flag[0]=0;
//				status1=Waiting;
//				status2=Waiting;
//				status4=Waiting;
//				status3=MAN_RED;
//				setTimer0(OneSec);
//				timer = MAN_RED;
//				timer2=RED_TIME/OneSec;
//				timer3= TIME_OUT/OneSec;
//			}
//			if(button_flag[1]==1)//button 2 turn MAIN FSM to HAND mode to turn led by RED_GREEN_YELLOW
//								//FSM will use timer for timeOut
//			{
//				button_flag[1] = 0;
//				Print_HELLO();
//				switch (status1) {
//					case AUTO_RED:
//						status3 = HAND_GREEN;
//						break;
//					case AUTO_YELLOW:
//						status3 = HAND_RED;
//						break;
//					case AUTO_GREEN:
//						status3 = HAND_YELLOW;
//						break;
//					default:
//						break;
//				}
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//				status1 = Waiting;
//				status2 = Waiting;
//				status4 = Waiting;
//			}
//			if(button_flag[3]==1){//button 3 enable P_MOde
//				button_flag[3]=0;
//				if(status1== AUTO_RED){
//					status4=P_GREEN;
//					setTimer3(OneSec);
//					timer3=timer;
//				}
//				if(status1== AUTO_GREEN){
//					status4=P_RED;
//					setTimer3(OneSec);
//					timer3=timer+YELLOW_TIME/OneSec;
//				}
//				if(status1== AUTO_YELLOW){
//					status4=P_RED;
//					offP();
//					setTimer3(OneSec);
//					timer3=timer;
//				}
//			}
//			break;
//		case INIT:
//			Print_Mode(INIT);
//			offP();
//			Print_ERROR();// check if RED_TIME == GREEN_TIME + YELLOW_TIME
//			timer3=0;
//			setTimer0(OneSec);
//			status1=INIT;
//			status2=INIT;
//			status4=INIT;
//			status3=RUNNING;
//			break;
//		case MAN_RED:
//			toogleRed();
//			toogleRed1();
//			if( timer0_flag == 1) {
//				Print_Mode(timer);
//				Print_Time(timer2);
//				Print_TimeOut(timer3);
//				timer3--;
//				setTimer0 (OneSec) ;
//				}
//			if(timer2>99)timer2=0;
//			RED_TIME=timer2*100;
//			if(button_flag[0]==1){
//				button_flag[0]=0;
//				timer2=GREEN_TIME/OneSec;
//				timer = MAN_GREEN;
//				status3=MAN_GREEN;
//				setTimer0 (OneSec);
//				timer3= TIME_OUT/OneSec;
//			}
//			if(button_flag[1]==1){
//				button_flag[1]=0;
//				timer3= TIME_OUT/OneSec;
//				timer2++;
//			}
//			if(button_flag[2]==1){
//				button_flag[2]=0;
//				timer3= TIME_OUT/OneSec;
//				timer2--;
//			}
//			if(timer3==STOP){
//				status3=INIT;
//			}
//			break;
//		case MAN_GREEN:
//			if( timer0_flag == 1) {
//				Print_Mode(timer);
//				Print_Time(timer2);
//				Print_TimeOut(timer3);
//				timer3--;
//				setTimer0 (OneSec) ;
//				}
//			toogleGreen();
//			toogleGreen1();
//			if(timer2>99)timer2=0;
//			GREEN_TIME=timer2*100;
//			if(button_flag[0]==1){
//				button_flag[0]=0;
//				timer2=YELLOW_TIME/OneSec;
//				status3=MAN_YELLOW;
//				timer = MAN_YELLOW;
//				setTimer0(OneSec);
//				timer3= TIME_OUT/OneSec;
//			}
//			if(button_flag[1]==1){
//				button_flag[1]=0;
//				timer3= TIME_OUT/OneSec;
//				timer2++;
//			}
//			if(button_flag[2]==1){
//				button_flag[2]=0;
//				timer3= TIME_OUT/OneSec;
//				timer2--;
//			}
//			if(timer3==STOP){
//				status3=INIT;
//			}
//
//			break;
//		case MAN_YELLOW:
//			if( timer0_flag == 1) {
//				Print_Mode(timer);
//				Print_Time(timer2);
//				Print_TimeOut(timer3);
//				setTimer0 (OneSec) ;
//				timer3--;
//				}
//			toogleYellow();
//			toogleYellow1();
//			if(timer2>99)timer2=3;
//			if(timer2<3)timer2=3;
//			YELLOW_TIME=timer2*100;
//			if(button_flag[0]==1){
//				button_flag[0]=0;
//				status3=INIT;
//			}
//			if(button_flag[1]==1){
//				button_flag[1]=0;
//				timer2++;
//				timer3= TIME_OUT/OneSec;
//			}
//			if(button_flag[2]==1){
//				button_flag[2]=0;
//				timer2--;
//				timer3= TIME_OUT/OneSec;
//			}
//			if(timer3==STOP){
//				status3=INIT;
//			}
//			break;
//		case HAND_RED:
//			if(timer0_flag == 1) {
//				timer--;
//				Print_Mode(HAND_RED);
//				Print_TimeOut(timer);
//				setTimer0 (OneSec) ;
//			}
//			if(button_flag[1]==1){
//				button_flag[1]=0;
//				status3=HAND_GREEN;
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//			}
//			if(button_flag[2]==1){
//				button_flag[2]=0;
//				status3=HAND_YELLOW;
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//			}
//			if(timer==STOP){
//				status3=INIT;
//			}
//			 toogleGreen1();
//			 toogleRed();
//			 greenP();
//			break;
//		case HAND_GREEN:
//			if(timer0_flag == 1) {
//				timer--;
//				Print_Mode(HAND_GREEN);
//				Print_TimeOut(timer);
//				setTimer0 (OneSec) ;
//				}
//			if(button_flag[1]==1){
//				button_flag[1]=0;
//				status3=HAND_YELLOW;
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//			}
//			if(button_flag[2]==1){
//				button_flag[2]=0;
//				status3=HAND_RED;
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//			}
//			if(timer==STOP){
//				status3=INIT;
//			}
//			toogleRed1();
//			toogleGreen();
//			redP();
//			break;
//		case HAND_YELLOW:
//			if(timer0_flag == 1) {
//				timer--;
//				Print_Mode(HAND_YELLOW);
//				Print_TimeOut(timer);
//				setTimer0 (OneSec) ;
//				}
//			if(button_flag[1]==1){
//				button_flag[1]=0;
//				status3=HAND_RED;
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//			}
//			if(button_flag[2]==1){
//				button_flag[2]=0;
//				status3=HAND_GREEN;
//				setTimer0 (OneSec);
//				timer=TIME_OUT/OneSec;
//			}
//			if(timer==STOP){
//				status3=INIT;
//			}
//			toogleRed1();
//			toogleYellow();
//			redP();
//			break;
//		default:
//			break;
//	}
//}
