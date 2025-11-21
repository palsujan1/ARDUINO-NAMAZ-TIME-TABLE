# PIC16F676 - 5 LED Blinking Project

এই প্রজেক্টে PIC16F676 মাইক্রোকন্ট্রোলার দিয়ে ৫টি LED ব্লিঙ্ক করা হয়েছে।

## Hardware Requirements (হার্ডওয়্যার প্রয়োজন)

1. **PIC16F676 Microcontroller** - 1 piece
2. **LEDs (Any Color)** - 5 pieces
3. **330Ω Resistors** - 5 pieces
4. **Breadboard** - 1 piece
5. **Power Supply** - 5V DC
6. **Connecting Wires**
7. **PICkit 3/4 Programmer** (for uploading code)

## Circuit Connection (সার্কিট সংযোগ)

### PIC16F676 Pin Configuration:
```
        PIC16F676
     ┌─────────────┐
VDD  │1          14│ VSS (GND)
RA5  │2          13│ RA0
RA4  │3          12│ RA1
RA3  │4          11│ RA2
RC5  │5          10│ RC0 → LED1 → 330Ω → GND
RC4  │6           9│ RC1 → LED2 → 330Ω → GND
RC3  │7           8│ RC2 → LED3 → 330Ω → GND
     └─────────────┘
         ↓
      LED4 → 330Ω → GND (RC3)
      LED5 → 330Ω → GND (RC4)
```

### LED Connections:
- **RC0 (Pin 10)** → LED1 → 330Ω Resistor → GND
- **RC1 (Pin 9)**  → LED2 → 330Ω Resistor → GND
- **RC2 (Pin 8)**  → LED3 → 330Ω Resistor → GND
- **RC3 (Pin 7)**  → LED4 → 330Ω Resistor → GND
- **RC4 (Pin 6)**  → LED5 → 330Ω Resistor → GND

### Power Connections:
- **Pin 1 (VDD)** → +5V
- **Pin 14 (VSS)** → GND

## Available Programs (উপলব্ধ প্রোগ্রাম)

### 1. **pic16f676_5led_simple.c** (সবচেয়ে সহজ)
- সব LED একসাথে জ্বলে এবং নিভে
- 1 second ON, 1 second OFF
- নতুনদের জন্য সবচেয়ে ভালো

### 2. **pic16f676_5led_blink.c** (Advanced Pattern)
- ৫টি ভিন্ন প্যাটার্ন:
  - Pattern 1: সব LED একসাথে ON/OFF
  - Pattern 2: Sequential ON (Left to Right)
  - Pattern 3: Sequential OFF
  - Pattern 4: Alternate blinking

### 3. **pic16f676_5led_blink.asm** (Assembly Version)
- Assembly language code
- Advanced users এর জন্য

## Software Requirements (সফটওয়্যার প্রয়োজন)

1. **MPLAB X IDE** - Latest version
   - Download: https://www.microchip.com/mplab/mplab-x-ide

2. **XC8 Compiler** (for C programs)
   - Download: https://www.microchip.com/mplab/compilers

3. **PICkit 3/4 Programmer Software**

## How to Compile (কম্পাইল করার নিয়ম)

### For C Programs:
1. MPLAB X IDE খুলুন
2. File → New Project
3. Select "Microchip Embedded" → "Standalone Project"
4. Device: **PIC16F676**
5. Programmer: **PICkit 3** বা **PICkit 4**
6. Compiler: **XC8**
7. প্রজেক্টে `.c` ফাইল add করুন
8. **Build** (হাতুড়ি আইকন) ক্লিক করুন

### For Assembly Programs:
1. Same steps as above
2. Compiler select করুন: **mpasm**
3. `.asm` ফাইল add করুন

## How to Upload (আপলোড করার নিয়ম)

1. PICkit 3/4 দিয়ে PIC16F676 এর সাথে সংযোগ করুন:
   - **MCLR** → PIC Pin 4 (RA3/MCLR)
   - **VDD** → PIC Pin 1
   - **VSS** → PIC Pin 14
   - **PGD** → PIC Pin 12 (RA0/ICSPDAT)
   - **PGC** → PIC Pin 13 (RA1/ICSPCLK)

2. MPLAB X IDE তে:
   - **Make and Program Device** বাটন ক্লিক করুন
   - অথবা মেনু থেকে: Run → Run Project

## LED Blinking Patterns (LED ব্লিঙ্ক প্যাটার্ন)

### Simple Version:
```
All ON:  ● ● ● ● ●  (1 sec)
All OFF: ○ ○ ○ ○ ○  (1 sec)
```

### Advanced Version Patterns:
```
Pattern 1 - All Together:
ON:  ● ● ● ● ●  (500ms)
OFF: ○ ○ ○ ○ ○  (500ms)

Pattern 2 - Sequential ON:
● ○ ○ ○ ○  (200ms)
● ● ○ ○ ○  (200ms)
● ● ● ○ ○  (200ms)
● ● ● ● ○  (200ms)
● ● ● ● ●  (500ms)

Pattern 3 - Alternate:
● ○ ● ○ ●  (300ms)
○ ● ○ ● ○  (300ms)
```

## Troubleshooting (সমস্যা সমাধান)

### LED জ্বলছে না:
1. Power supply চেক করুন (VDD = 5V, VSS = GND)
2. LED এর polarity চেক করুন (+ terminal RC pin এ)
3. 330Ω resistor সঠিকভাবে লাগানো আছে কিনা দেখুন
4. PICkit দিয়ে code সঠিকভাবে upload হয়েছে কিনা verify করুন

### Programming Error:
1. PICkit এর সংযোগ চেক করুন
2. Target Power চালু আছে কিনা দেখুন
3. MCLR pin সঠিকভাবে connected আছে কিনা চেক করুন

### Compile Error:
1. XC8 Compiler installed আছে কিনা চেক করুন
2. Device (PIC16F676) সঠিকভাবে select করা আছে কিনা দেখুন
3. Configuration bits সঠিক আছে কিনা verify করুন

## Modifications (পরিবর্তন)

### Blinking Speed পরিবর্তন:
```c
__delay_ms(1000);  // 1000 = 1 second
__delay_ms(500);   // 500 = 0.5 second
__delay_ms(100);   // 100 = 0.1 second (fast)
```

### অন্য Pin ব্যবহার করতে চাইলে:
```c
// PORTA ব্যবহার করার জন্য:
TRISA = 0b00000000;  // PORTA as output
// এরপর:
RA0 = 1;  // LED ON
RA0 = 0;  // LED OFF
```

## Author
Created for PIC16F676 LED Blinking Tutorial

## License
Free to use for educational purposes

---
**বাংলা সাপোর্ট:** এই প্রজেক্ট সম্পূর্ণ বাংলা নির্দেশনা সহ তৈরি করা হয়েছে।
