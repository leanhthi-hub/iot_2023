/*
 * DHT20_Handle.h
 *
 *  Created on: Apr 24, 2023
 *      Author: hatru
 */

#ifndef INC_DHT20_HANDLE_H_
#define INC_DHT20_HANDLE_H_

#include <stdint.h>
#include <stdio.h>
#include "main.h"

#define MAX_ARRAY_DATA 20 	//The buffer can handle at most 20 values

typedef struct
{
	uint32_t	ID;
//	uint32_t 	Type;
	uint32_t 	Temp;
	uint32_t 	Humi;
	uint32_t 	Lux;
} DATA_ARRAY;

extern DATA_ARRAY data_array[MAX_ARRAY_DATA];
extern int current_index_array;
extern int current_ID;

extern int t;
extern int h;
extern int l;


void read_data();
char* make_data();
void send_data();
void remove_data();


#endif /* INC_DHT20_HANDLE_H_ */
