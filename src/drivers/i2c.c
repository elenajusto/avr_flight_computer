/* Constants */
#define F_CPU 16000000UL    // Arduino board clock frequency: 16 MHz
#define SCL_CLOCK 100000L   // I2C clock frequency 100 kHz

/* Header Files */
#include <avr/io.h>         // Pin definitions for AVR
#include <util/delay.h>     // Delay functions for AVR

/* Function Prototypes */
void ERROR(void);
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(uint8_t data);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);

/* I2C Initialization */
void i2c_init(void) {
    TWSR = 0x00;                                             // Set prescaler bits to zero
    TWBR = (uint8_t)(((F_CPU / SCL_CLOCK) - 16) / (2 * 1));  // Prescaler = 1
}

/* I2C Start Condition */
void i2c_start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

/* I2C Stop Condition */
void i2c_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/* I2C Write */
void i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

/* I2C Read with ACK */
uint8_t i2c_read_ack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

/* I2C Read with NACK */
uint8_t i2c_read_nack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

/* Error Handling Function */
void ERROR(void) {
    // Maybe set a flag, turn on an LED, or reset the I2C bus
}