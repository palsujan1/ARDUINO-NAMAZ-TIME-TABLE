# PIC16F676 - সেরা ছোট Compiler বিকল্প (SDCC সমস্যার সমাধান)

## ⚠️ SDCC সমস্যা:
- SDCC মূলত **8051** এর জন্য
- PIC support আছে কিন্তু **experimental**
- অনেক bug এবং সমস্যা
- Documentation কম

---

## ✅ সমাধান: PIC এর জন্য সেরা ৩টি Compiler

### 🏆 #1: Great Cow BASIC (সবচেয়ে ভালো!)

**কেন সেরা:**
- ✅ PIC এর জন্য **specially তৈরি**
- ✅ মাত্র **15MB** size
- ✅ **BASIC language** - সবচেয়ে সহজ
- ✅ PIC16F676 পুরোপুরি support করে
- ✅ 100% FREE & Open Source
- ✅ GUI interface
- ✅ একদম stable

**Download:**
```
https://gcbasic.sourceforge.net/
Windows: Great_Cow_BASIC_Install.exe (15MB)
```

**Code Example:**
```basic
#chip 16F676, 4          'শুধু chip number লিখুন

#define LED1 PORTC.0
#define LED2 PORTC.1
#define LED3 PORTC.2
#define LED4 PORTC.3
#define LED5 PORTC.4

Dir LED1 Out
Dir LED2 Out
Dir LED3 Out
Dir LED4 Out
Dir LED5 Out

Do Forever
    'All ON
    LED1 = 1: LED2 = 1: LED3 = 1: LED4 = 1: LED5 = 1
    Wait 1 s              'দেখুন কত সহজ!

    'All OFF
    LED1 = 0: LED2 = 0: LED3 = 0: LED4 = 0: LED5 = 0
    Wait 1 s
Loop
```

**Compile:**
```
1. Great Cow BASIC IDE খুলুন
2. File → Open → pic16f676_led.gcb
3. F5 চাপুন (বা Build বাটন)
4. HEX file তৈরি হবে
5. PICkit দিয়ে upload করুন
```

---

### 🥈 #2: JAL (Just Another Language) - PIC এর জন্য

**Features:**
- PIC এর জন্য specially designed
- Pascal-like syntax
- Small size (~20MB)
- Excellent PIC support

**Download:**
```
http://justanotherlanguage.org/
```

**Code Example:**
```pascal
include 16f676

pragma target clock 4_000_000
pragma target OSC INTOSC_NOCLKOUT

enable_digital_io()

alias led1 is pin_c0
alias led2 is pin_c1
alias led3 is pin_c2
alias led4 is pin_c3
alias led5 is pin_c4

pin_c0_direction = output
pin_c1_direction = output
pin_c2_direction = output
pin_c3_direction = output
pin_c4_direction = output

forever loop
   led1 = high
   led2 = high
   led3 = high
   led4 = high
   led5 = high
   delay_1s(1)

   led1 = low
   led2 = low
   led3 = low
   led4 = low
   led5 = low
   delay_1s(1)
end loop
```

---

### 🥉 #3: mikroC (Free Limited Version)

**Features:**
- Professional compiler
- GUI IDE
- Free version available (2KB limit)
- Good for small projects

**Download:**
```
https://www.mikroe.com/mikroc-pic
Free version: mikroC PRO for PIC (2KB code limit)
```

**Note:** 2KB limit যথেষ্ট ছোট projects এর জন্য

---

### 🚫 #4: Assembly (Compiler লাগবে না!)

যদি সব compiler এড়াতে চান:

**File:** `pic16f676_5led_blink.asm`

**Assembler:**
- **MPASM** (Microchip official) - FREE
- **gpasm** (Open source) - FREE

**Download MPASM:**
```
https://www.microchip.com/mplab/mplab-integrated-development-environment
শুধু Assembler টা install করুন (ছোট)
```

**Assemble Command:**
```bash
mpasm pic16f676_5led_blink.asm
```

---

## 📊 তুলনা:

| Compiler | Size | PIC Support | Difficulty | Best For |
|----------|------|-------------|------------|----------|
| **Great Cow BASIC** | 15MB | ⭐⭐⭐⭐⭐ Excellent | ⭐ Easy | **সবার জন্য!** |
| **JAL** | 20MB | ⭐⭐⭐⭐⭐ Excellent | ⭐⭐ Medium | Pascal lovers |
| **mikroC Free** | 100MB | ⭐⭐⭐⭐⭐ Excellent | ⭐⭐⭐ Medium | Small projects |
| **Assembly** | 50MB | ⭐⭐⭐⭐⭐ Native | ⭐⭐⭐⭐ Hard | Experts |
| **SDCC** | 50MB | ⭐⭐ Poor PIC | ⭐⭐⭐ Medium | 8051 only! |
| **XC8** | 500MB | ⭐⭐⭐⭐⭐ Best | ⭐⭐⭐⭐ Hard | Professional |

---

## 🎯 আমার সুপারিশ:

### নতুনদের জন্য:
```
1. Great Cow BASIC ব্যবহার করুন
   - সবচেয়ে সহজ
   - PIC এর জন্য perfect
   - 15MB size
```

### যদি কোন compiler না চান:
```
1. Pre-compiled HEX file ব্যবহার করুন
   File: pic16f676_5led.hex
   - কোন compiler লাগবে না
   - সরাসরি upload করুন
```

### Assembly জানলে:
```
1. MPASM ব্যবহার করুন
   File: pic16f676_5led_blink.asm
   - সবচেয়ে efficient code
   - Full control
```

---

## 🚀 Quick Start with Great Cow BASIC:

### ধাপ ১: Download & Install (2 মিনিট)
```
1. https://gcbasic.sourceforge.net/ এ যান
2. Download → Great_Cow_BASIC_Install.exe
3. Install করুন (15MB)
```

### ধাপ ২: Open & Compile (1 মিনিট)
```
1. Great Cow BASIC IDE খুলুন
2. File → Open → pic16f676_led.gcb
3. Build → Compile (F5)
4. HEX file তৈরি হবে same folder এ
```

### ধাপ ৩: Upload (1 মিনিট)
```
1. PICkit সংযোগ করুন
2. PICkit Software দিয়ে HEX upload করুন
3. ✅ Done!
```

---

## 💡 Great Cow BASIC এর সুবিধা:

### 1. খুব সহজ Syntax:
```basic
Wait 1 s              'SDCC: delay_ms(1000)
LED1 = 1              'SDCC: RC0 = 1
Dir LED1 Out          'SDCC: TRISC0 = 0
```

### 2. Built-in Functions:
```basic
Wait 1 s              '1 second
Wait 500 ms           '500 milliseconds
Wait 10 us            '10 microseconds

PulseOut LED1, 100 ms '100ms pulse
Toggle LED1           'Toggle state
```

### 3. Easy Loops:
```basic
For i = 1 to 5
    LED = i
    Wait 100 ms
Next

Repeat 10
    Toggle LED1
    Wait 200 ms
End Repeat
```

### 4. Automatic Configuration:
```basic
#chip 16F676, 4       'Automatically configures:
                      '- Oscillator
                      '- Analog/Digital pins
                      '- All settings
```

---

## 🔧 Installation Steps বিস্তারিত:

### Great Cow BASIC:

1. **Download:**
   - যান: https://gcbasic.sourceforge.net/
   - Click: Downloads
   - Select: Windows Installer (Latest Version)

2. **Install:**
   ```
   - Double click: Great_Cow_BASIC_Install.exe
   - Next → I Agree → Next → Install
   - Finish
   ```

3. **First Run:**
   ```
   - Start Menu → Great Cow BASIC → GCB@SYN
   - File → New → Save as: test.gcb
   - Write code
   - F5 (Compile)
   ```

---

## 📝 Sample Projects with Great Cow BASIC:

### Project 1: Blinking Pattern
```basic
#chip 16F676, 4

#define LED1 PORTC.0
#define LED2 PORTC.1
#define LED3 PORTC.2
#define LED4 PORTC.3
#define LED5 PORTC.4

Dir PORTC Out

Do Forever
    'Pattern 1: All together
    PORTC = 0b00011111
    Wait 500 ms
    PORTC = 0b00000000
    Wait 500 ms

    'Pattern 2: Sequential
    For i = 0 to 4
        PORTC = 1 << i
        Wait 200 ms
    Next

    'Pattern 3: Reverse
    For i = 4 to 0 Step -1
        PORTC = 1 << i
        Wait 200 ms
    Next
Loop
```

### Project 2: Button Control
```basic
#chip 16F676, 4

#define BUTTON PORTA.0
#define LED1 PORTC.0

Dir BUTTON In
Dir LED1 Out

Do Forever
    If BUTTON = 1 Then
        LED1 = 1
    Else
        LED1 = 0
    End If
Loop
```

---

## ✅ সারসংক্ষেপ:

**SDCC সমস্যা:**
- ❌ PIC support দুর্বল
- ❌ 8051 এর জন্য বেস্ট
- ❌ PIC এ bug বেশি

**সমাধান:**
- ✅ **Great Cow BASIC ব্যবহার করুন** (সবচেয়ে ভালো!)
- ✅ PIC এর জন্য specially তৈরি
- ✅ 15MB size
- ✅ সবচেয়ে সহজ
- ✅ 100% stable

---

**ডাউনলোড লিঙ্ক:**
```
Great Cow BASIC: https://gcbasic.sourceforge.net/
JAL: http://justanotherlanguage.org/
mikroC: https://www.mikroe.com/mikroc-pic
```

**আমি Great Cow BASIC recommend করি!** 🏆
