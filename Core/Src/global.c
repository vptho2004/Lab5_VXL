#include "global.h"
#include "command_parser_fsm.h"
#include "uart_communication_fsm.h"

void system_init(void){
	uart_communication_state = IDLE1;
	command_parse_state = IDLE;
	timer_flag = 0;
	buffer_flag = 0;
	command_flag = 1;

}
