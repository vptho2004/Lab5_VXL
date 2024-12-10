#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include <string.h>
#include "software_timer.h"
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

int command_flag ;
int command_data ;
int buffer_flag ;
int timer_flag;

int command_parse_state;
int uart_communication_state;

#define TIMER_CYCLE 10

#define RST_FLAG 11
#define OK_FLAG 12
#define NO_COMMAND 13


#define MAX_BUFFER_SIZE 30
uint8_t temp;
int8_t buffer[ MAX_BUFFER_SIZE ];
uint8_t index_buffer;


void system_init(void);

#endif
