/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Leanhthi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include <main.h>



void Print_HELLO();



#define MAX_ARRAY_DATA 20
typedef struct
{
	uint32_t	ID;
	uint32_t 	Temp;
	uint32_t 	Humi;
	uint32_t 	Lux;
} DATA_ARRAY;

extern DATA_ARRAY data_array[MAX_ARRAY_DATA];
extern int current_index_array;
extern int current_ID;




#endif /* INC_GLOBAL_H_ */
