/*
 * PIC16F676 - 5 LED Simple Blinking (All together)
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

#define _XTAL_FREQ 4000000      // 4MHz Internal Oscillator

void main(void) {
    // Configure oscillator (4MHz internal)
    OSCCON = 0b01100000;

    // Disable comparator
    CMCON = 0x07;

    // All pins digital
    ANSEL = 0x00;

    // Configure PORTC as output
    TRISC = 0b00000000;

    // Clear PORTC
    PORTC = 0x00;

    while(1) {
        // Turn ON all 5 LEDs (RC0-RC4)
        PORTC = 0b00011111;     // Binary: 00011111 = 0x1F (RC0-RC4 HIGH)
        __delay_ms(1000);       // 1 second ON

        // Turn OFF all 5 LEDs
        PORTC = 0b00000000;     // All LEDs OFF
        __delay_ms(1000);       // 1 second OFF
    }
}
