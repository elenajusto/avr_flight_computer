/* Constants */
#define F_CPU 16000000UL          // Arduino board clock frequency: 16 Mhz
#define MMA8452Q_ADDRESS 0x1D     // Register address of accelerometer

/* Header Files */
#include <avr/io.h>               // Pin definitions for AVR
#include <util/delay.h>           // Delay functions for AVR
#include <i2c.h>                  // Functions for I2C
#include <uart.h>                 // Drivers for UART
#include <stdio.h>                // For snprintf

/* Function Prototypes*/
void read_accelerometer_data();

/* Main Program */
int main(void) {

    // Initialisation
    i2c_init();                     // Start I2C hardware
    uart_init(9600);                // Start UART hardware with baud rate 9600 bps

    // Debug
    uart_print("Welcome to V1.0 of the Flight Computer :)\r\n");

    /* Main Loop */
    while(1) {

    }
    return 0;
}

/* Function Definitions */
void read_accelerometer_data() {
    uint8_t registerAddress = 0x01;        // Example register address
    i2c_start();
    i2c_write(MMA8452Q_ADDRESS << 1 | 0);  // Write operation
    i2c_write(registerAddress);
    i2c_start();                           // Repeated start for read operation
    i2c_write(MMA8452Q_ADDRESS << 1 | 1);  // Read operation
    uint8_t data = i2c_read_nack();        // Read data from the register

    // Now use the data variable
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%u", data); // Convert the data to a string
    uart_print("Accelerometer data: ");
    uart_print(buffer);
    uart_print("\r\n");

    i2c_stop();
}
