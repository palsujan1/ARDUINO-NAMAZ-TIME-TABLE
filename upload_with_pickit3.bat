@echo off
REM ============================================
REM PIC16F676 HEX Upload using PICkit 3
REM Uses MPLAB IPE Command Line (ipecmd)
REM ============================================

echo.
echo ==========================================
echo   PIC16F676 Uploader (PICkit 3)
echo ==========================================
echo.

REM Check if MPLAB IPE is installed
set IPECMD="C:\Program Files\Microchip\MPLABX\mplab_platform\bin\ipecmd.exe"

if not exist %IPECMD% (
    echo [ERROR] MPLAB IPE not found!
    echo.
    echo Please install MPLAB IPE from:
    echo https://www.microchip.com/mplab/mplab-integrated-programming-environment
    echo.
    pause
    exit /b 1
)

REM Check if HEX file exists
if not exist "pic16f676_5led.hex" (
    echo [ERROR] pic16f676_5led.hex not found!
    echo.
    echo Please make sure the HEX file is in the same folder.
    echo.
    pause
    exit /b 1
)

echo [Step 1/3] Checking connections...
echo   - Make sure PICkit 3 is connected via USB
echo   - Make sure PIC16F676 is properly wired
echo.
pause

echo.
echo [Step 2/3] Detecting PICkit 3...
%IPECMD% -P PIC16F676 -T PICKIT3
echo.

if %ERRORLEVEL% NEQ 0 (
    echo [WARNING] PICkit 3 detection issue!
    echo Please check:
    echo   1. PICkit 3 USB connection
    echo   2. Target power (5V)
    echo   3. All 5 wires connected properly
    echo.
    choice /C YN /M "Continue anyway?"
    if errorlevel 2 exit /b 1
)

echo.
echo [Step 3/3] Programming PIC16F676...
echo.
echo This will:
echo   1. Erase the chip
echo   2. Program the HEX file
echo   3. Verify programming
echo.
echo Please wait...
echo.

%IPECMD% -P PIC16F676 -T PICKIT3 -F "pic16f676_5led.hex" -M -OL

echo.
if %ERRORLEVEL% EQU 0 (
    echo ==========================================
    echo   SUCCESS! Programming complete!
    echo ==========================================
    echo.
    echo Next steps:
    echo   1. Disconnect PICkit 3
    echo   2. Power your PIC16F676 with 5V
    echo   3. LEDs should start blinking!
    echo.
) else (
    echo ==========================================
    echo   FAILED! Programming unsuccessful!
    echo ==========================================
    echo.
    echo Please check:
    echo   1. All connections (5 wires)
    echo   2. Target device power (5V on VDD)
    echo   3. Ground connection (VSS)
    echo   4. PICkit 3 is working properly
    echo.
    echo Try manual programming with MPLAB IPE.
    echo.
)

pause
