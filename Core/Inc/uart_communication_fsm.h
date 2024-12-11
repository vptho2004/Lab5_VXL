#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_

#include "global.h"
#include <stdio.h>

#define HANDLE1 21
#define SEND_DATA_1 22
#define HANDLE2 23
#define SEND_DATA_2 24

uint32_t ADC_value;

void uart_communication_fsm(void);


#endif
