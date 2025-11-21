;******************************************************************************
; PIC16F676 - 5 LED Blinking Program (Assembly)
; Assembler: MPASM/MPLAB X
;
; Hardware Connection:
; RC0 - LED1 (through 330 ohm resistor to GND)
; RC1 - LED2 (through 330 ohm resistor to GND)
; RC2 - LED3 (through 330 ohm resistor to GND)
; RC3 - LED4 (through 330 ohm resistor to GND)
; RC4 - LED5 (through 330 ohm resistor to GND)
;******************************************************************************

    LIST    P=16F676
    #include <p16f676.inc>

; CONFIG
    __CONFIG _FOSC_INTRCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF & _BOREN_ON & _CP_OFF & _CPD_OFF

;******************************************************************************
; Variables
;******************************************************************************
DELAY1      EQU 0x20
DELAY2      EQU 0x21
DELAY3      EQU 0x22

;******************************************************************************
; Reset Vector
;******************************************************************************
    ORG     0x0000
    GOTO    START

;******************************************************************************
; Main Program
;******************************************************************************
START
    ; Configure oscillator (4MHz internal)
    BSF     STATUS, RP0         ; Bank 1
    MOVLW   b'01100000'
    MOVWF   OSCCON

    ; Disable comparator
    MOVLW   0x07
    BCF     STATUS, RP0         ; Bank 0
    MOVWF   CMCON

    ; All pins digital
    BSF     STATUS, RP0         ; Bank 1
    CLRF    ANSEL

    ; Configure PORTC as output
    CLRF    TRISC               ; PORTC all outputs

    BCF     STATUS, RP0         ; Bank 0
    CLRF    PORTC               ; Clear PORTC

MAIN_LOOP
    ; Turn ON all 5 LEDs
    MOVLW   b'00011111'         ; RC0-RC4 HIGH
    MOVWF   PORTC
    CALL    DELAY_500MS

    ; Turn OFF all 5 LEDs
    CLRF    PORTC
    CALL    DELAY_500MS

    GOTO    MAIN_LOOP

;******************************************************************************
; Delay Subroutine - Approximately 500ms at 4MHz
;******************************************************************************
DELAY_500MS
    MOVLW   0x03
    MOVWF   DELAY3
DELAY3_LOOP
    MOVLW   0xFF
    MOVWF   DELAY2
DELAY2_LOOP
    MOVLW   0xFF
    MOVWF   DELAY1
DELAY1_LOOP
    DECFSZ  DELAY1, F
    GOTO    DELAY1_LOOP
    DECFSZ  DELAY2, F
    GOTO    DELAY2_LOOP
    DECFSZ  DELAY3, F
    GOTO    DELAY3_LOOP
    RETURN

    END
