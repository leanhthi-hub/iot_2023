/*
 * DHT20_Handle.c
 *
 *  Created on: Apr 24, 2023
 *      Author: hatru
 */

#include "DHT20_Handle.h"

DATA_ARRAY data_array[MAX_ARRAY_DATA];
int current_index_array = 0;
int current_ID = 0;

int t = 10;
int h = 19;
int l = 35;

void read_data(){
//	Print_HELLO();
	if(current_index_array< MAX_ARRAY_DATA){
		data_array[current_index_array].ID = current_ID;
		current_ID++;
		data_array[current_index_array].Temp = t;
		data_array[current_index_array].Humi = h;
		data_array[current_index_array].Lux = l;
		current_index_array ++;
		t++;
		h++;
		l++;
	}
}

char* make_data(){
	char str[30];
	int temp = data_array[0].Temp;
	int humi = data_array[0].Humi;
	int lux = data_array[0].Lux;
	sprintf(str, "!temp:%d,humi:%d,lux:%d#\n\r",temp,humi,lux );
	char* return_value = str;
	return return_value;
}


void remove_data(){

		   for( int i = 0; i < current_index_array - 1; i++)
		   {
			   data_array[i].ID = data_array[i+1].ID;
			   data_array[i].Temp = data_array[i+1].Temp;
			   data_array[i].Humi = data_array[i+1].Humi;
			   data_array[i].Lux = data_array[i+1].Lux;
		   }
		   if(current_index_array>0) {
			   current_index_array--;
		   }
}

//void send_data(int type, int data)
//{
//	char str[30];
//	switch (type){
//	case 0:
//		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!temp: %d#\n\r", data), 1000);
//		break;
//	case 1:
//		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!Humi: %d#\n\r", data), 1000);
//		break;
//	case 2:
//		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!Lux: %d#\n\r", data), 1000);
//		break;
//	}
//
//}
