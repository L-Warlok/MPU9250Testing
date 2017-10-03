/*
 * Serial.h
 *
 * Created: 2/03/2015 5:41:43 PM
 *  Author: Robert
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

//include libraries
# include <avr/io.h>

#define USART_BAUDRATE 9600

//macros
# define BAUD_PRESCALE ((((F_CPU/16)+(USART_BAUDRATE/2))/(USART_BAUDRATE))-1)

//function prototypes
void serial0_init(void);
void serial0_print_string(char * string_pointer);
void serial0_write_byte(uint8_t data_byte);


#endif /* SERIAL_H_ */
