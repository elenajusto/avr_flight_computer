// uart.h
#ifndef UART_H
#define UART_H

#include <avr/io.h>

// Function to initialize the UART with given baud rate
void uart_init(unsigned int baud);

// Function to transmit a single character
void uart_transmit(char data);

// Function to transmit a null-terminated string
void uart_print(const char *str);

// Function to receive a single character
char uart_receive(void);

// Function to receive a string until a newline character is received
void uart_receive_line(char *buffer, unsigned int buffer_size);

#endif // UART_H