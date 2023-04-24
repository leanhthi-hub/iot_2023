/* * com_reiceive.c
 *
 *  Created on: Dec 24, 2022
 *      Author: leanhthi
 */

#include <com_handle.h>
//#include "SOFTWARE_TIMER.h"

int cmd_type = 0;
int cmd_flag = 0;
int pos = 0;

char curr_char;
int curr_par;

char ack_message[6] = "!ACK";
char req_message[6] = "!REQ";

void cmd_init()
{
	cmd_type = UNDEFINE;
}

void cmd_parser()
{
	cmd_type = UNDEFINE;
	if(!strcmp((char*)buffer, ack_message))
	{
		cmd_type = ACK;
	}
	else if(!strcmp((char*)buffer, req_message))
	{
		cmd_type = REQ;
	}
	else
	{
		cmd_type = UNDEFINE;
	}

}
