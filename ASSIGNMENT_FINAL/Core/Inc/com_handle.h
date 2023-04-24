/*
 * com_reiceive.h
 *
 *  Created on: Dec 24, 2022
 *      Author: leanhthi
 */

#ifndef INC_COM_RECEIVE_H_
#define INC_COM_RECEIVE_H_
#include "main.h"
#include "string.h"
#include <stdint.h>

#define ACK				21
#define REQ				22
#define UNDEFINE		-1

#define SEND			31
#define WAIT			32

#define MAX_BUFFER_SIZE 30

#define time_out  500
#define MAX_MES_TYPES 2

extern int comm_status;
extern int cmd_type;		//message type

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;

extern int ack;
void cmd_init();
void cmd_parser();

void uart_communiction_innit();
void uart_communication_fsm();
#endif /* INC_COM_RECEIVE_H_ */
