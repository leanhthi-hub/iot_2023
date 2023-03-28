/*
 * com_reiceive.c
 *
 *  Created on: Dec 24, 2022
 *      Author: leanhthi
 */

#include <com_receive.h>
//#include "SOFTWARE_TIMER.h"

int cmd_status = 0;
int cmd_type = 0;
int cmd_flag = 0;
int pos = 0;

char curr_char;
int curr_par;

char ack_mess_cap[30] = "ACK#";
char ack_mess_nocap[30] = "ack#";
#define start_mess_length 4

char button_on_mess_cap[30] = "BON#";
char button_on_mess_nocap[30] = "bon#";

char button_off_mess_cap[30] = "BOF#";
char button_off_mess_nocap[30] = "bof#";


#define end_mess_length 4

void cmd_init()
{
	cmd_status = INIT;
	cmd_type = UNDEFINE;
	cmd_flag = 0;
	curr_par = 0;
//	index_buffer = 0;
	buffer_flag = 0;
}

void cmd_parser_fsm()
{
//	Print_Ack();


	curr_char = buffer[pos ++];
	switch (cmd_status) {
	case INIT:
				cmd_type = UNDEFINE;
				curr_par = 0;
				if(curr_char == '!')
				{
					cmd_status = START_STATE;
				}
				break;
			case START_STATE:
				if(curr_char == ack_mess_cap[0] || curr_char == ack_mess_nocap[0])
				{
					curr_par++;
					cmd_status = ACK;
				}
				else if(curr_char == button_on_mess_cap[0] || curr_char == button_on_mess_nocap[0])
				{
					curr_par++;
					cmd_status = BUTTON_ON;
				}
				else cmd_status = INIT;
				break;
			case ACK:
				if(curr_char == ack_mess_cap[curr_par] || curr_char == ack_mess_nocap[curr_par])
				{
					if(curr_char == '#')
					{
						cmd_status = INIT;
						cmd_type = ACK;
						cmd_flag = 1;
						curr_par = 0;
						pos = 0;
					}
					else curr_par++;
				}
				else
				{
					cmd_status = INIT;
					curr_par = 0;
					cmd_flag = 1;
					pos = 0;

				}
				break;

			case BUTTON_ON:
				if(curr_char == button_on_mess_cap[curr_par] || curr_char == button_on_mess_nocap[curr_par])
				{
					if(curr_char == '#')
					{
						cmd_status = INIT;
						cmd_type = BUTTON_ON;
						curr_par = 0;
						cmd_flag = 1;
						pos = 0;
					}
					else curr_par++;
				}
				else if (curr_char == button_off_mess_cap[curr_par] || curr_char == button_off_mess_nocap[curr_par]){
					cmd_type = BUTTON_OFF;
					pos--;
				}
				else
				{
					cmd_status = INIT;
					curr_par = 0;
					cmd_flag = 1;
					pos = 0;
				}
				break;
			case BUTTON_OFF:
				if(curr_char == button_off_mess_cap[curr_par] || curr_char == button_off_mess_nocap[curr_par])
				{
					if(curr_char == '#')
					{
						cmd_status = INIT;
						cmd_type = BUTTON_OFF;
						curr_par = 0;
						cmd_flag = 1;
						pos = 0;
					}
					else curr_par++;
				}
				else
				{
					cmd_status = INIT;
					curr_par = 0;
					cmd_flag = 1;
					pos = 0;
				}
				break;

		default:
			break;
	}
}
