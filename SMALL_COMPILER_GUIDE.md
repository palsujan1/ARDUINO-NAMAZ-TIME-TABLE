# PIC16F676 - ছোট ও সহজ Compiler গাইড

XC8 compiler অনেক বড় (500MB+)। এখানে ছোট এবং সহজ বিকল্প দেওয়া হলো।

---

## 🎯 তিনটি সহজ পদ্ধতি:

### ✅ পদ্ধতি ১: **Pre-compiled HEX File** (সবচেয়ে সহজ - কোন Compiler লাগবে না!)

**ফাইল:** `pic16f676_5led.hex`

#### ধাপ:
1. **শুধু PICkit Programmer সফটওয়্যার দরকার**
   - Download: https://www.microchip.com/en-us/tools-resources/develop/pickit-software
   - Size: মাত্র ~50MB

2. **সরাসরি Upload করুন:**
   ```
   - PICkit সফটওয়্যার খুলুন
   - Device: PIC16F676 select করুন
   - "Import Hex" করুন → pic16f676_5led.hex
   - "Write" button চাপুন
   ```

3. **✅ শেষ!** LED ব্লিঙ্ক করা শুরু করবে!

**সুবিধা:**
- ✅ কোন compiler install লাগবে না
- ✅ সবচেয়ে দ্রুত এবং সহজ
- ✅ মাত্র 50MB সফটওয়্যার

---

### ✅ পদ্ধতি ২: **Great Cow BASIC** (সবচেয়ে সহজ Programming)

**ফাইল:** `pic16f676_led.gcb`

#### Installation:
1. **Download Great Cow BASIC:**
   - Website: https://gcbasic.sourceforge.net/
   - Size: মাত্র ~15MB
   - Windows installer: GCBASIC_Setup.exe

2. **Install করুন:**
   - Simply double-click installer
   - Next → Next → Install
   - সম্পন্ন!

#### কিভাবে ব্যবহার করবেন:
```
1. Great Cow BASIC IDE খুলুন
2. File → Open → pic16f676_led.gcb
3. Build → Compile (F5)
4. HEX file তৈরি হবে
5. PICkit দিয়ে upload করুন
```

#### Program Example:
```basic
#chip 16F676, 4          'Chip select

'LED pins
#define LED1 PORTC.0
#define LED2 PORTC.1
#define LED3 PORTC.2
#define LED4 PORTC.3
#define LED5 PORTC.4

'Set as output
Dir LED1 Out
Dir LED2 Out
Dir LED3 Out
Dir LED4 Out
Dir LED5 Out

'Main loop
Do Forever
    'All ON
    LED1 = 1
    LED2 = 1
    LED3 = 1
    LED4 = 1
    LED5 = 1
    Wait 1 s         'খুব সহজ delay!

    'All OFF
    LED1 = 0
    LED2 = 0
    LED3 = 0
    LED4 = 0
    LED5 = 0
    Wait 1 s
Loop
```

**সুবিধা:**
- ✅ খুবই ছোট (15MB)
- ✅ BASIC language - সবচেয়ে সহজ
- ✅ Bengali-friendly syntax
- ✅ GUI interface
- ✅ Built-in examples
- ✅ 100% FREE

---

### ✅ পদ্ধতি ৩: **SDCC (Small Device C Compiler)**

**ফাইল:** `pic16f676_sdcc.c`

#### Installation:
1. **Download SDCC:**
   - Website: https://sdcc.sourceforge.net/
   - Windows: sdcc-4.4.0-x64-setup.exe
   - Size: ~10MB download, ~50MB installed

2. **Install করুন:**
   - Run installer
   - Default settings রাখুন
   - Install

#### Compile Command:
```bash
# Windows Command Prompt এ:
cd C:\Users\YourName\Documents\PIC_Projects
sdcc -mpic14 -p16f676 pic16f676_sdcc.c

# HEX file তৈরি হবে: pic16f676_sdcc.hex
```

#### Full Steps:
```
1. pic16f676_sdcc.c ফাইল তৈরি করুন
2. Command Prompt খুলুন
3. cd করে folder এ যান
4. Compile: sdcc -mpic14 -p16f676 pic16f676_sdcc.c
5. .hex file upload করুন PICkit দিয়ে
```

**সুবিধা:**
- ✅ খুব ছোট (~50MB)
- ✅ 100% FREE & Open Source
- ✅ C language support
- ✅ Command line - professional
- ✅ Cross-platform (Windows/Linux/Mac)

---

## 📊 তুলনা:

| Compiler | Size | Language | Difficulty | Free? | Best For |
|----------|------|----------|------------|-------|----------|
| **Pre-compiled HEX** | 50MB | - | ⭐ Easy | ✅ Yes | একদম নতুন যারা |
| **Great Cow BASIC** | 15MB | BASIC | ⭐⭐ Easy | ✅ Yes | সহজ programming চান |
| **SDCC** | 50MB | C | ⭐⭐⭐ Medium | ✅ Yes | Professional |
| **XC8** | 500MB+ | C | ⭐⭐⭐⭐ Hard | ❌ Paid/Limited | Advanced projects |

---

## 🏆 আমার সুপারিশ:

### নতুনদের জন্য:
1. **প্রথমে:** Pre-compiled HEX file দিয়ে শুরু করুন
2. **তারপর:** Great Cow BASIC শিখুন (খুব সহজ!)
3. **পরে:** SDCC দিয়ে C শিখুন

### এক্সপার্টদের জন্য:
- **SDCC** - Professional, free, small

---

## 🔧 PICkit Software শুধু Upload এর জন্য:

যদি শুধু HEX file upload করতে চান:

### Option 1: **PICkit 3 Programmer Application**
- Download: Microchip website
- Size: ~50MB
- শুধু upload করার জন্য

### Option 2: **pk2cmd (Command Line)**
- Size: ~2MB (খুবই ছোট!)
- Download: https://www.microchip.com/en-us/development-tool/pg164120
- Command:
  ```bash
  pk2cmd -P PIC16F676 -F pic16f676_5led.hex -M
  ```

---

## 📁 ফাইল সংক্রান্ত:

### Pre-compiled HEX:
- **File:** `pic16f676_5led.hex`
- **সরাসরি upload করুন - কোন compiler লাগবে না!**

### Great Cow BASIC:
- **File:** `pic16f676_led.gcb`
- **Compiler:** Great Cow BASIC IDE

### SDCC:
- **File:** `pic16f676_sdcc.c`
- **Compile:** `sdcc -mpic14 -p16f676 pic16f676_sdcc.c`

---

## ❓ সমস্যা সমাধান:

### SDCC compile error:
```bash
# Error: sdcc not recognized
# Solution: PATH add করুন:
set PATH=%PATH%;C:\Program Files\SDCC\bin
```

### Great Cow BASIC not opening:
- Windows Defender বন্ধ করুন temporary
- Re-install করুন

### HEX file upload error:
- PICkit সংযোগ চেক করুন
- Device power চালু আছে কিনা দেখুন
- Correct device (PIC16F676) selected আছে কিনা verify করুন

---

## 🎓 শিখার পথ:

```
দিন ১: Pre-compiled HEX দিয়ে test করুন
       ↓
দিন ২-৩: Great Cow BASIC শিখুন (BASIC language)
       ↓
সপ্তাহ ১: নিজের program লিখুন BASIC এ
       ↓
সপ্তাহ ২: SDCC দিয়ে C শিখুন
       ↓
মাস ১: Complex projects তৈরি করুন
```

---

## 🌐 Download Links:

### Great Cow BASIC:
```
https://gcbasic.sourceforge.net/
→ Downloads → Windows Installer
```

### SDCC:
```
https://sdcc.sourceforge.net/
→ Download → Windows x64 Setup
```

### PICkit Software:
```
https://www.microchip.com/
→ Search: "PICkit 3 Programmer"
```

---

## ✨ সারসংক্ষেপ:

**যদি একদম নতুন হন:**
→ `pic16f676_5led.hex` সরাসরি upload করুন

**যদি সহজে programming শিখতে চান:**
→ Great Cow BASIC ব্যবহার করুন

**যদি professional হতে চান:**
→ SDCC ব্যবহার করুন

---

**বাংলা সাপোর্ট:** সম্পূর্ণ বাংলা নির্দেশনা সহ তৈরি
**FREE:** সব software 100% ফ্রি
**SMALL:** সব software ছোট (<50MB)

---

## 📞 যোগাযোগ:
কোন সমস্যা হলে জিজ্ঞাসা করুন!
