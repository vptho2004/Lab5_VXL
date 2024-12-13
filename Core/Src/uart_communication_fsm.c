#include "uart_communication_fsm.h"

void uart_communication_fsm(void){
	unsigned char str[100] = "";
	if (command_flag){
		switch (uart_communication_state){

			case HANDLE1:
				// do nothing
				if (command_data == RST_FLAG){
					uart_communication_state = SEND_DATA_1;
				}
				if(command_data == NO_COMMAND) break;

				break;
			case SEND_DATA_1:

				// send data
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);

				sprintf ((char *)str , "\r\n!ADC=%ld#\r\n", ADC_value);
				HAL_UART_Transmit (&huart2 , str , sizeof(str), 1000);
				setTimer(3000);
				uart_communication_state = HANDLE2;

				break;
			case HANDLE2:

				// do nothing
				if (command_data == OK_FLAG) {
					if(timer_flag == 1){
					uart_communication_state = HANDLE1;
					command_data = NO_COMMAND;
					command_flag = 0;
					}
				}else if (timer_flag == 1) {
					uart_communication_state = SEND_DATA_2;
					timer_flag = 0;
				}

				break;
			case SEND_DATA_2:
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				sprintf ((char *)str , "\r\n!ADC=%ld#\r\n", ADC_value);
				HAL_UART_Transmit (&huart2 , str , sizeof(str), 1000);
				setTimer(3000);
				uart_communication_state = HANDLE2;
				break;

		}
	}
}
