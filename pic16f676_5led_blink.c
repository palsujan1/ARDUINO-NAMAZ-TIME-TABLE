/*
 * PIC16F676 - 5 LED Blinking Program
 * Compiler: MPLAB XC8
 *
 * Hardware Connection:
 * RC0 - LED1 (through 330 ohm resistor to GND)
 * RC1 - LED2 (through 330 ohm resistor to GND)
 * RC2 - LED3 (through 330 ohm resistor to GND)
 * RC3 - LED4 (through 330 ohm resistor to GND)
 * RC4 - LED5 (through 330 ohm resistor to GND)
 */

// CONFIG
#pragma config FOSC = INTRCIO   // Internal RC oscillator
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = ON       // Power-up Timer enabled
#pragma config MCLRE = OFF      // MCLR pin function is digital input
#pragma config BOREN = ON       // Brown-out Reset enabled
#pragma config CP = OFF         // Code Protection disabled
#pragma config CPD = OFF        // Data Code Protection disabled

#include <xc.h>

// Define CPU Frequency for delay functions
#define _XTAL_FREQ 4000000      // 4MHz Internal Oscillator

// LED pins definition
#define LED1 RC0
#define LED2 RC1
#define LED3 RC2
#define LED4 RC3
#define LED5 RC4

// Function prototypes
void delay_ms(unsigned int ms);
void init_system(void);

void main(void) {
    init_system();          // Initialize PIC16F676

    while(1) {
        // Pattern 1: All LEDs ON
        LED1 = 1;
        LED2 = 1;
        LED3 = 1;
        LED4 = 1;
        LED5 = 1;
        __delay_ms(500);    // 500ms delay

        // Pattern 2: All LEDs OFF
        LED1 = 0;
        LED2 = 0;
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
        __delay_ms(500);    // 500ms delay

        // Pattern 3: Sequential ON (Left to Right)
        LED1 = 1;
        __delay_ms(200);
        LED2 = 1;
        __delay_ms(200);
        LED3 = 1;
        __delay_ms(200);
        LED4 = 1;
        __delay_ms(200);
        LED5 = 1;
        __delay_ms(500);

        // Pattern 4: Sequential OFF (Left to Right)
        LED1 = 0;
        __delay_ms(200);
        LED2 = 0;
        __delay_ms(200);
        LED3 = 0;
        __delay_ms(200);
        LED4 = 0;
        __delay_ms(200);
        LED5 = 0;
        __delay_ms(500);

        // Pattern 5: Alternate blinking
        LED1 = 1;
        LED3 = 1;
        LED5 = 1;
        LED2 = 0;
        LED4 = 0;
        __delay_ms(300);

        LED1 = 0;
        LED3 = 0;
        LED5 = 0;
        LED2 = 1;
        LED4 = 1;
        __delay_ms(300);
    }
}

// Initialize PIC16F676
void init_system(void) {
    // Configure oscillator (4MHz internal)
    OSCCON = 0b01100000;    // 4MHz internal oscillator

    // Disable comparator
    CMCON = 0x07;           // Comparator off, all pins digital I/O

    // Configure analog inputs (disable all)
    ANSEL = 0x00;           // All pins digital

    // Configure I/O ports
    TRISA = 0b00000000;     // All PORTA as output
    TRISC = 0b00000000;     // All PORTC as output

    // Clear all outputs
    PORTA = 0x00;
    PORTC = 0x00;
}
