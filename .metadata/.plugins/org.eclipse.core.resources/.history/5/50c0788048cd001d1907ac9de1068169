/*
 * comm_fsm.c
 *
 *  Created on: Dec 24, 2022
 *      Author: leanhthi
 */

#include <com_receive.h>
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
	switch (cmd_type) {
				case BUTTON_ON:
					Turn_On();
					cmd_type=UNDEFINE;

					break;
				case BUTTON_OFF:
					Turn_Off();
					cmd_type=UNDEFINE;

					break;
				default:
					break;
			}
	switch (comm_status)
	{
	case SEND:
		send_data(typ, dat);
		setTimer0(500);
		comm_status = WAIT;
		break;
	case WAIT:
//		Print_HELLO();

		if(cmd_type == ACK)
		{
			Print_Ack();
			typ++;
			dat++;
			if(typ==3)typ=0;//demo
			comm_status = SEND;
			cmd_type = UNDEFINE;
		}
		else if(timer0_flag==1){
			comm_status = SEND;
		}
		break;
	default:
//		Print_HELLO();
		comm_status = SEND;
		break;
	}
}
