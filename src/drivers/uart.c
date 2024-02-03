#define F_CPU 16000000UL // 16 MHz
#define BAUD 9600
#define BRC ((F_CPU/16/BAUD) - 1) // Calculate baud rate setting

#include <avr/io.h>

void uart_init(void) {
    UBRR0H = (BRC >> 8);
    UBRR0L = BRC;

    UCSR0B = (1 << TXEN0)  | (1 << RXEN0);   // Enable transmitter and receiver
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  // Set frame: 8data, 1 stop bit
}

void uart_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait for empty transmit buffer
    UDR0 = data;                      // Put data into buffer, sends the data
}

void uart_print(const char* str) {
    while (*str) {
        uart_transmit(*str++);
    }
}