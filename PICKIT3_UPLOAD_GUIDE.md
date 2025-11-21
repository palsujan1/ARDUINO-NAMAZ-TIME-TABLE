# PICkit 3 দিয়ে HEX File Upload করার সম্পূর্ণ গাইড

**PIC16F676 এ LED Blinking প্রোগ্রাম আপলোড করুন**

---

## 🔌 ধাপ ১: Hardware সংযোগ (Circuit Connection)

### PICkit 3 Pin Configuration:

```
PICkit 3 Connector (6 pins):
┌──────────────┐
│ 1  2  3  4  5  6 │
└──────────────┘
  │  │  │  │  │  │
  1. MCLR (Master Clear / Programming Voltage)
  2. VDD  (Power +5V)
  3. VSS  (Ground)
  4. PGD  (Programming Data)
  5. PGC  (Programming Clock)
  6. LVP  (Low Voltage Programming - not used)
```

### PIC16F676 Pin Layout:

```
        PIC16F676 (14-pin DIP)
     ┌─────────────────────┐
VDD  │1                  14│ VSS (GND)
RA5  │2                  13│ RA0/ICSPDAT (PGD)
RA4  │3                  12│ RA1/ICSPCLK (PGC)
RA3  │4  ●               11│ RA2
RC5  │5                  10│ RC0 → LED1
RC4  │6                   9│ RC1 → LED2
RC3  │7                   8│ RC2 → LED3
     └─────────────────────┘
```

### সংযোগ তালিকা:

| PICkit 3 Pin | তার রঙ (সাধারণত) | PIC16F676 Pin | বর্ণনা |
|--------------|-------------------|---------------|---------|
| Pin 1 (MCLR) | সাদা/কালো | Pin 4 (RA3) | Programming Enable |
| Pin 2 (VDD)  | লাল | Pin 1 (VDD) | +5V Power |
| Pin 3 (VSS)  | কালো | Pin 14 (VSS) | Ground |
| Pin 4 (PGD)  | সাদা | Pin 13 (RA0) | Data Line |
| Pin 5 (PGC)  | হলুদ | Pin 12 (RA1) | Clock Line |
| Pin 6 (LVP)  | - | - | ব্যবহার হয় না |

### Breadboard সংযোগ চিত্র:

```
PICkit 3                    PIC16F676
┌────────┐                 ┌──────────┐
│1 MCLR  │────────────────→│RA3 (4)   │
│2 VDD   │────────────────→│VDD (1)   │───→ +5V
│3 VSS   │────────────────→│VSS (14)  │───→ GND
│4 PGD   │────────────────→│RA0 (13)  │
│5 PGC   │────────────────→│RA1 (12)  │
│6 LVP   │    (not used)
└────────┘

LED Connections:
RC0 (10) ──→ LED1 ──→ 330Ω ──→ GND
RC1 (9)  ──→ LED2 ──→ 330Ω ──→ GND
RC2 (8)  ──→ LED3 ──→ 330Ω ──→ GND
RC3 (7)  ──→ LED4 ──→ 330Ω ──→ GND
RC4 (6)  ──→ LED5 ──→ 330Ω ──→ GND
```

---

## 💻 ধাপ ২: Software Installation

### Option 1: MPLAB IPE (সবচেয়ে সহজ - Recommended!)

**Download:**
```
https://www.microchip.com/mplab/mplab-integrated-programming-environment

File: MPLAB-IPE-v6.xx-installer.exe
Size: ~150MB
```

**Install:**
1. Installer run করুন
2. "Next" → "I Accept" → "Next"
3. Install location: `C:\Program Files\Microchip\MPLABX\`
4. Install করুন (5-10 মিনিট)

---

### Option 2: MPLAB X IDE (Full IDE)

**Download:**
```
https://www.microchip.com/mplab/mplab-x-ide

File: MPLAB-X-v6.xx-windows-installer.exe
Size: ~500MB
```

**Note:** শুধু HEX upload এর জন্য IPE যথেষ্ট!

---

## 🚀 ধাপ ৩: HEX File Upload (Step-by-Step)

### পদ্ধতি A: MPLAB IPE দিয়ে (সবচেয়ে সহজ!)

#### Step 1: MPLAB IPE খুলুন
```
Start Menu → Microchip → MPLAB IPE
```

#### Step 2: Device Select করুন
```
1. Family: Mid-Range 8-bit MCUs (PIC10/12/16/MCP)
2. Device: PIC16F676 (dropdown থেকে)
3. Tool: PICkit 3 (automatically detect হবে)
```

যদি PICkit 3 detect না হয়:
- USB cable চেক করুন
- PICkit 3 LED দেখুন (সবুজ = OK)
- Tool → Reconnect চেষ্টা করুন

#### Step 3: Settings (Optional)
```
Settings বাটন ক্লিক করুন:
- Power: Check "Power target circuit from tool" (5V)
- Program Speed: Default (Low speed = more reliable)
```

#### Step 4: HEX File Browse করুন
```
1. "Source" section এ যান
2. "Browse" বাটন ক্লিক করুন
3. Navigate করে `pic16f676_5led.hex` select করুন
4. "Open" করুন
```

#### Step 5: Connect & Program
```
1. "Connect" বাটন চাপুন (PICkit 3 সংযুক্ত হবে)
   → Status: Connected

2. "Program" বাটন চাপুন (সবুজ বাটন)
   → Programming...
   → Verifying...
   → Programming/Verify complete

3. ✅ Success! Output window এ দেখাবে:
   "Programming complete"
   "Verification complete"
```

#### Step 6: Disconnect
```
1. "Disconnect" বাটন চাপুন
2. PICkit 3 USB থেকে খুলে নিন
3. PIC16F676 power দিন (5V)
4. ✨ LED ব্লিঙ্ক শুরু হবে!
```

---

### পদ্ধতি B: MPLAB X IDE দিয়ে

#### Step 1: Open IDE
```
Start Menu → Microchip → MPLAB X IDE
```

#### Step 2: Import HEX
```
1. File → Import → HEX/ELF File
2. Browse করে `pic16f676_5led.hex` select করুন
3. Device: PIC16F676
4. Finish
```

#### Step 3: Configure PICkit 3
```
1. Right-click project → Properties
2. Categories → Conf: [default]
3. Hardware Tool: PICkit 3
4. Apply → OK
```

#### Step 4: Program Device
```
1. Production → Make and Program Device Main Project
   অথবা
2. Toolbar তে lightning bolt (⚡) icon ক্লিক করুন
```

Output:
```
Programming...
Verifying...
Programming/Verify complete
BUILD SUCCESSFUL
```

---

### পদ্ধতি C: Command Line (pk2cmd / ipecmd)

#### For Advanced Users:

**Using ipecmd (MPLAB IPE Command Line):**

```bash
cd "C:\Program Files\Microchip\MPLABX\mplab_platform\bin\"

ipecmd.exe -P PIC16F676 -T PICKIT3 -F "path\to\pic16f676_5led.hex" -M

# -P = Device
# -T = Tool
# -F = File path
# -M = Program and verify
```

**Full Script:**
```batch
@echo off
echo Programming PIC16F676 with PICkit 3...

set IPECMD="C:\Program Files\Microchip\MPLABX\mplab_platform\bin\ipecmd.exe"
set HEXFILE="pic16f676_5led.hex"

%IPECMD% -P PIC16F676 -T PICKIT3 -F %HEXFILE% -M

if %ERRORLEVEL% EQU 0 (
    echo SUCCESS! Programming complete.
) else (
    echo ERROR! Programming failed.
)
pause
```

---

## 🎥 Screenshot Guide (Visual Steps)

### MPLAB IPE Interface:

```
┌─────────────────────────────────────────────────┐
│ MPLAB IPE v6.xx                             [_][□][X] │
├─────────────────────────────────────────────────┤
│ Family: [Mid-Range 8-bit▼]  Device: [PIC16F676▼]│
│ Tool:   [PICkit3         ▼]                      │
├─────────────────────────────────────────────────┤
│                                                   │
│ ┌─ Source ─────────────────────────────────┐   │
│ │ Hex File: [C:\...\pic16f676_5led.hex ] [Browse]│
│ └─────────────────────────────────────────┘   │
│                                                   │
│ [Connect]  [Program]  [Verify]  [Blank Check]  │
│                                                   │
│ ┌─ Output ─────────────────────────────────┐   │
│ │ Connecting to PICkit 3...                │   │
│ │ Target detected: PIC16F676               │   │
│ │ Programming...                           │   │
│ │ Programming complete                     │   │
│ │ Verification complete                    │   │
│ └─────────────────────────────────────────┘   │
└─────────────────────────────────────────────────┘
```

---

## ⚙️ Configuration Bits (Automatic)

HEX file এ configuration bits included আছে:

```
Oscillator: INTOSC (4MHz)
Watchdog Timer: OFF
Power-up Timer: ON
MCLR: OFF (RA3 as digital input)
Brown-out Reset: ON
Code Protection: OFF
```

**আপনার কিছু করতে হবে না - HEX file এ সব included!**

---

## 🔍 Troubleshooting (সমস্যা সমাধান)

### Problem 1: PICkit 3 Detected না হলে

**লক্ষণ:**
```
Tool: No Tool Detected
```

**সমাধান:**
1. USB cable ঠিকমত লাগানো আছে কিনা চেক করুন
2. PICkit 3 LED দেখুন:
   - সবুজ = OK
   - লাল = Error
3. Device Manager এ দেখুন:
   - Device Manager → Universal Serial Bus devices
   - "Microchip PICkit 3" থাকতে হবে
4. Driver update করুন:
   - Right-click PICkit 3 → Update Driver

---

### Problem 2: Target Not Detected

**লক্ষণ:**
```
Error: Target device not detected
```

**সমাধান:**
1. **সব সংযোগ চেক করুন:**
   ```
   PICkit 3 → PIC16F676
   Pin 1 → Pin 4  ✓
   Pin 2 → Pin 1  ✓
   Pin 3 → Pin 14 ✓
   Pin 4 → Pin 13 ✓
   Pin 5 → Pin 12 ✓
   ```

2. **Power চেক করুন:**
   - VDD (Pin 1) = 5V থাকতে হবে
   - VSS (Pin 14) = GND থাকতে হবে
   - Multimeter দিয়ে মেপে দেখুন

3. **PICkit 3 থেকে Power দিন:**
   - Settings → Power Target Circuit from Tool
   - Voltage: 5.0V

---

### Problem 3: Programming Failed

**লক্ষণ:**
```
Programming...
Error: Programming failed at address 0x0000
```

**সমাধান:**
1. **Erase করুন আগে:**
   - Operations → Erase
   - তারপর আবার Program করুন

2. **Program Speed কমান:**
   - Settings → Advanced Mode
   - Program Speed: Low (slower = more reliable)

3. **Blank Check করুন:**
   - Operations → Blank Check
   - যদি Failed হয় → Bulk Erase করুন

---

### Problem 4: Verification Failed

**লক্ষণ:**
```
Programming complete
Verification failed at address 0x00XX
```

**সমাধান:**
1. Erase → Program আবার করুন
2. PIC chip ঠিক আছে কিনা চেক করুন
3. অন্য PIC chip চেষ্টা করুন (chip নষ্ট হতে পারে)

---

### Problem 5: LED জ্বলছে না Programming এর পরে

**সমাধান:**
1. **Power disconnect করুন PICkit থেকে:**
   - IPE disconnect করুন
   - PICkit USB খুলে নিন
   - আলাদা 5V power supply দিন PIC কে

2. **LED circuit চেক করুন:**
   ```
   RC0 → LED (+) → (-) → 330Ω → GND

   LED সঠিক দিকে আছে?
   + (long leg) → RC pin
   - (short leg) → Resistor → GND
   ```

3. **Config bits চেক করুন:**
   - IPE → Settings → Configuration
   - দেখুন MCLRE = OFF আছে কিনা

---

## 📹 Video Tutorial (Step by Step)

### Quick Video Guide:

```
1. Connect PICkit 3
   [0:00 - 0:30]

2. Open MPLAB IPE
   [0:30 - 1:00]

3. Select Device & Tool
   [1:00 - 1:30]

4. Browse HEX File
   [1:30 - 2:00]

5. Program & Verify
   [2:00 - 3:00]

6. Test LEDs
   [3:00 - 3:30]
```

---

## 📝 Quick Reference Card

### সবচেয়ে দ্রুত পদ্ধতি:

```
1. PICkit 3 সংযোগ করুন (5 pins)
2. MPLAB IPE খুলুন
3. Device: PIC16F676
4. Tool: PICkit 3
5. Browse: pic16f676_5led.hex
6. Connect → Program
7. ✅ Done!
```

### PICkit 3 LED Status:

| LED রঙ | অর্থ |
|--------|------|
| সবুজ (Green) | সব ঠিক আছে |
| হলুদ (Yellow) | Busy (programming) |
| লাল (Red) | Error! |
| নীল (Blue) | Target powered |

---

## 🎯 Pro Tips:

1. **সবসময় 5V power ব্যবহার করুন** - 3.3V নয়
2. **তার ছোট রাখুন** - Long wires = errors
3. **PICkit থেকে আলাদা power দিন** final test এ
4. **Config bits HEX এ included** - manually change করতে হবে না
5. **Backup রাখুন** working HEX file এর

---

## 📦 অতিরিক্ত Files:

আমি তৈরি করে দিয়েছি:

1. **`pic16f676_5led.hex`** ← এই file upload করবেন
2. **`upload_to_pic.bat`** ← Windows script (double-click!)
3. **`simple_pic_uploader.py`** ← Python GUI
4. **`QUICK_START.md`** ← ৫ মিনিট গাইড
5. **`PICKIT3_UPLOAD_GUIDE.md`** ← এই file (বিস্তারিত)

---

## ✅ Success Checklist:

```
□ PICkit 3 USB এ connected
□ 5 wires সঠিকভাবে connected
□ MPLAB IPE installed
□ PIC16F676 device selected
□ PICkit 3 tool selected
□ HEX file browsed
□ Connect successful
□ Programming complete
□ Verification complete
□ Power from 5V supply
□ LEDs blinking! ✨
```

---

**সফল হোক! 🎉**

কোন সমস্যা হলে এই গাইড আবার দেখুন।
