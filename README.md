# ESP32 BadUSB Keystroke Injection Attack

**Platform:** ESP32-S3

This is a small project I made to explore USB HID using an ESP32-S3. Instead of adding an external push button, I use the BOOT button already available on the development board.

When I press BOOT, the ESP32-S3 behaves like a USB keyboard. It opens the Windows Run dialog and enters a command to schedule a restart after 60 seconds.

## Hardware
- ESP32-S3 development board
- USB data cable

The ESP32-S3 is the only electronic component used. The USB cable is for programming and connecting the board to the computer.

## How it works
1. The ESP32-S3 connects to the computer through its native USB port.
2. The board is configured to work as a USB HID keyboard.
3. The program checks the built-in BOOT button.
4. When BOOT is pressed, it sends the Windows + R shortcut.
5. It types `shutdown /r /t 60` and presses Enter.
6. Windows schedules a restart after 60 seconds.

## Setup
1. Install Arduino IDE and the Espressif ESP32 board package.
2. Select the ESP32-S3 board that matches your hardware.
3. Configure the native USB connection for USB HID.
4. Connect the board using a USB data cable.
5. Open the `.ino` firmware, compile it, and upload it.
6. Save your work before testing, then press BOOT once.

To cancel a scheduled restart, run `shutdown /a` in Windows.

## Important notes
- Save your work before testing because Windows may close open applications.
- GPIO 0 is the BOOT pin on many ESP32-S3 boards, but check the pinout for your exact board.
- The board must support USB HID through its native USB connection.
- This example is for Windows.
- Use it only on a computer you own or have permission to administer.

## About this project
I wanted to build a simple project using only the ESP32-S3 board and its built-in button. It demonstrates how USB HID works and how a microcontroller can send keyboard input to a computer.
