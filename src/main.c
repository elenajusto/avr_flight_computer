/* Constants */
#define F_CPU 16000000UL          // Arduino board clock frequency: 16 Mhz
#define MMA8452Q_ADDRESS 0x1D     // Register address of accelerometer

/* Header Files */
#include <avr/io.h>               // Pin definitions for AVR
#include <util/delay.h>           // Delay functions for AVR
#include <drivers/i2c.h>          // Functions for I2C
#include <drivers/uart.h>         // Drivers for UART

/* Function Prototypes*/
void read_accelerometer_data();

/* Main Program */
int main(void) {

    // Initialisation
    i2c_init();                     // Start I2C hardware
    uart_init();                    // Start UART hardware

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
    i2c_stop();
}