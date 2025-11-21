@echo off
REM ========================================
REM PIC16F676 HEX File Upload Script
REM সহজে HEX file upload করার জন্য
REM ========================================

echo.
echo ==========================================
echo   PIC16F676 LED Blinking Uploader
echo ==========================================
echo.

REM Check if pk2cmd exists
where pk2cmd >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] pk2cmd not found!
    echo.
    echo Please install PICkit 2 Command Line Tool from:
    echo https://www.microchip.com/
    echo.
    pause
    exit /b 1
)

echo [1] Detecting PICkit...
pk2cmd -P

echo.
echo [2] Uploading pic16f676_5led.hex...
pk2cmd -P PIC16F676 -F pic16f676_5led.hex -M -R

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ==========================================
    echo   SUCCESS! LED should be blinking now!
    echo ==========================================
) else (
    echo.
    echo ==========================================
    echo   UPLOAD FAILED! Check connections.
    echo ==========================================
)

echo.
pause
