# 🚀 PIC16F676 - ৫ মিনিটে শুরু করুন!

**সবচেয়ে সহজ পদ্ধতি - কোন Compiler লাগবে না!**

---

## 📦 আপনার যা লাগবে:

✅ PIC16F676 microcontroller - 1টি
✅ LED - 5টি (যেকোনো রঙ)
✅ 330Ω Resistor - 5টি
✅ Breadboard
✅ PICkit 3/4 Programmer
✅ USB cable
✅ 5V Power supply

---

## ⚡ 3 ধাপে LED জ্বালান:

### ধাপ ১: Circuit তৈরি করুন (5 মিনিট)

```
PIC16F676 Pin Layout:
     ┌─────────────┐
VDD  │1          14│ VSS → GND
RA5  │2          13│ RA0
RA4  │3          12│ RA1
RA3  │4          11│ RA2
RC5  │5          10│ RC0 → LED1 → 330Ω → GND
RC4  │6           9│ RC1 → LED2 → 330Ω → GND
RC3  │7           8│ RC2 → LED3 → 330Ω → GND
     └─────────────┘

LED4 ← RC3 (Pin 7) → 330Ω → GND
LED5 ← RC4 (Pin 6) → 330Ω → GND
```

**সংযোগ:**
1. **Pin 1 (VDD)** → +5V
2. **Pin 14 (VSS)** → GND
3. **Pin 10 (RC0)** → LED1 → 330Ω → GND
4. **Pin 9 (RC1)** → LED2 → 330Ω → GND
5. **Pin 8 (RC2)** → LED3 → 330Ω → GND
6. **Pin 7 (RC3)** → LED4 → 330Ω → GND
7. **Pin 6 (RC4)** → LED5 → 330Ω → GND

---

### ধাপ ২: HEX File Upload করুন (2 মিনিট)

#### পদ্ধতি A: PICkit Software দিয়ে (সবচেয়ে সহজ)

1. **Download PICkit Software** (যদি না থাকে):
   - https://www.microchip.com/
   - Search: "PICkit Programmer Application"
   - Size: ~50MB

2. **PICkit সংযোগ করুন:**
   ```
   PICkit → PIC16F676
   ─────────────────────
   Pin 1 (MCLR) → Pin 4 (RA3)
   Pin 2 (VDD)  → Pin 1 (VDD)
   Pin 3 (GND)  → Pin 14 (VSS)
   Pin 4 (PGD)  → Pin 12 (RA0)
   Pin 5 (PGC)  → Pin 13 (RA1)
   ```

3. **Upload করুন:**
   - PICkit Software খুলুন
   - Device Family: **Midrange**
   - Device: **PIC16F676**
   - File → Import Hex → **pic16f676_5led.hex**
   - **Write** button চাপুন
   - ✅ Done!

#### পদ্ধতি B: Windows Batch Script (এক ক্লিকে!)

```batch
# শুধু double-click করুন:
upload_to_pic.bat
```

#### পদ্ধতি C: Python GUI (সব OS এ)

```bash
# Terminal এ:
python simple_pic_uploader.py

# GUI খুলবে → Browse → Upload
```

---

### ধাপ ৩: Power ON করুন!

1. 5V power supply connect করুন
2. ✨ **LED ব্লিঙ্ক শুরু হবে!**

```
LED Pattern:
● ● ● ● ●  (1 sec ON)
○ ○ ○ ○ ○  (1 sec OFF)
● ● ● ● ●  (repeat...)
```

---

## 🎯 নিজে Program করতে চান?

### Option 1: **Great Cow BASIC** (সবচেয়ে সহজ!)

**Download:** https://gcbasic.sourceforge.net/ (15MB)

**Code Example:**
```basic
#chip 16F676, 4

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
    LED1 = 1: LED2 = 1: LED3 = 1: LED4 = 1: LED5 = 1
    Wait 1 s
    LED1 = 0: LED2 = 0: LED3 = 0: LED4 = 0: LED5 = 0
    Wait 1 s
Loop
```

**Steps:**
1. Great Cow BASIC IDE খুলুন
2. উপরের code লিখুন
3. F5 চাপুন (Compile)
4. HEX file upload করুন

---

### Option 2: **SDCC** (C Programming)

**Download:** https://sdcc.sourceforge.net/ (50MB)

**File:** `pic16f676_sdcc.c` (already provided)

**Compile:**
```bash
sdcc -mpic14 -p16f676 pic16f676_sdcc.c
```

---

## 🎨 Custom Patterns বানান:

### Pattern 1: Sequential (ধারাবাহিক)
```c
LED1 = 1; delay(200);
LED2 = 1; delay(200);
LED3 = 1; delay(200);
LED4 = 1; delay(200);
LED5 = 1; delay(200);
```

### Pattern 2: Alternate (পর্যায়ক্রমে)
```c
LED1 = 1; LED3 = 1; LED5 = 1;
LED2 = 0; LED4 = 0;
delay(300);

LED1 = 0; LED3 = 0; LED5 = 0;
LED2 = 1; LED4 = 1;
delay(300);
```

### Pattern 3: Running Light (চলন্ত আলো)
```c
for(i=0; i<5; i++) {
    PORTC = (1 << i);
    delay(200);
}
```

---

## 📊 Size Comparison:

| Compiler | Download | Installed | Difficulty |
|----------|----------|-----------|------------|
| **Pre-compiled HEX** | 0 MB | 0 MB | ⭐ |
| **PICkit Software** | 50 MB | 100 MB | ⭐ |
| **Great Cow BASIC** | 10 MB | 15 MB | ⭐⭐ |
| **SDCC** | 10 MB | 50 MB | ⭐⭐⭐ |
| **XC8** | 500 MB | 1 GB+ | ⭐⭐⭐⭐ |

---

## ❓ সমস্যা হলে:

### LED জ্বলছে না?
- ✅ Power supply চেক করুন (5V)
- ✅ LED polarity সঠিক আছে? (+ve pin RC এ)
- ✅ Resistor আছে? (330Ω)

### Upload Error?
- ✅ PICkit সঠিকভাবে connected?
- ✅ Device selected: PIC16F676?
- ✅ Target power ON?

### Compile Error?
- ✅ Compiler installed?
- ✅ Correct file extension (.c / .gcb)?

---

## 📂 সব Files:

```
pic16f676_5led.hex          ← Upload this (no compiler!)
pic16f676_led.gcb           ← Great Cow BASIC
pic16f676_sdcc.c            ← SDCC C code
pic16f676_5led_blink.c      ← XC8 C code (advanced)
pic16f676_5led_simple.c     ← XC8 simple
pic16f676_5led_blink.asm    ← Assembly

QUICK_START.md              ← This file
SMALL_COMPILER_GUIDE.md     ← Detailed guide
PIC16F676_LED_README.md     ← Full documentation

upload_to_pic.bat           ← Windows upload script
simple_pic_uploader.py      ← Python GUI uploader
```

---

## 🎓 Learning Path:

```
Day 1: ✅ Use pre-compiled HEX
       (Test hardware)
       ↓
Day 2: 📝 Learn Great Cow BASIC
       (Simple programming)
       ↓
Week 1: 💻 Try SDCC (C language)
       (More control)
       ↓
Month 1: 🚀 Advanced projects!
```

---

## 🏆 সফলতার টিপস:

1. **ধাপে ধাপে এগোন** - তাড়াহুড়া নয়
2. **Circuit সঠিকভাবে বানান** - দুবার চেক করুন
3. **Simple দিয়ে শুরু** - HEX file দিয়ে
4. **Practice করুন** - নিজে code লিখুন
5. **Experiment করুন** - নতুন pattern try করুন

---

## 🌟 Next Projects:

- ✨ 7-segment display
- 🚦 Traffic light controller
- 🎵 Buzzer with melody
- 🌡️ Temperature sensor
- 📡 IR remote control

---

**মনে রাখবেন:** প্রথমবারে নাও হতে পারে - এটা normal!
চেষ্টা করতে থাকুন! 💪

---

**বাংলা সাপোর্ট** | **100% FREE** | **Open Source**

**Created with ❤️ for Bangladeshi makers**
