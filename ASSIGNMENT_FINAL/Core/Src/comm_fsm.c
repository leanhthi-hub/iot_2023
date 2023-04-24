/*
 * comm_fsm.c
 *
 *  Created on: Dec 24, 2022
 *      Author: leanhthi
 */

#include "com_handle.h"
#include "DHT20_Handle.h"
#include <timer.h>
#include "main.h"
int comm_status = 0;
int ack = 0;
int typ = 0;//demo
int dat = 10;
void uart_communiction_innit()
{
	comm_status = SEND;
}

void uart_communication_fsm()
{
	switch (comm_status)
	{
	case SEND:
//		send_data(typ, dat);
		send_data();
		setTimer0(500);
		comm_status = WAIT;
		break;
	case WAIT:
		if(cmd_type == ACK)
		{
			remove_data();
			comm_status = WAIT;
			cmd_type = UNDEFINE;
			setTimer0(0);
		}
		else if(cmd_type == REQ)
		{
			comm_status = SEND;
			cmd_type = UNDEFINE;
		}
		else if(timer0_flag==1){
			comm_status = SEND;
		}
		break;
	default:
		comm_status = SEND;
		break;
	}
}
