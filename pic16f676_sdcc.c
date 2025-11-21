/*
 * PIC16F676 - 5 LED Blinking using SDCC (Small Device C Compiler)
 * Compiler: SDCC (Free & Open Source)
 * Size: Very small (~10MB download)
 *
 * Download SDCC: https://sdcc.sourceforge.net/
 *
 * Compile command:
 * sdcc -mpic14 -p16f676 pic16f676_sdcc.c
 */

#include <pic16f676.h>

// Configuration bits
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_INTRC_OSC_NOCLKOUT & _WDT_OFF & _PWRTE_ON &
                              _MCLRE_OFF & _BOREN_ON & _CP_OFF & _CPD_OFF);

// Simple delay function
void delay_ms(unsigned int count) {
    unsigned int i, j;
    for(i = 0; i < count; i++) {
        for(j = 0; j < 200; j++) {
            __asm nop __endasm;
        }
    }
}

void main(void) {
    // Configure oscillator
    OSCCON = 0x60;      // 4MHz internal

    // Disable comparator
    CMCON = 0x07;       // All pins digital

    // Disable analog
    ANSEL = 0x00;

    // Configure PORTC as output
    TRISC = 0x00;

    // Clear PORTC
    PORTC = 0x00;

    while(1) {
        // All LEDs ON (RC0-RC4)
        PORTC = 0x1F;   // 0b00011111
        delay_ms(500);

        // All LEDs OFF
        PORTC = 0x00;
        delay_ms(500);
    }
}
