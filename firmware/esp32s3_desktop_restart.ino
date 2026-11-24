#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

const int BOOT_BUTTON_PIN = 0;   // BOOT button on many ESP32-S3 boards
bool previousButtonState = HIGH;

void setup() {
  pinMode(BOOT_BUTTON_PIN, INPUT_PULLUP);

  Keyboard.begin();
  USB.begin();

  delay(1500); // Allow USB enumeration to finish
}

void loop() {
  bool currentButtonState = digitalRead(BOOT_BUTTON_PIN);

  // Detect one press: the button changes from HIGH to LOW.
  if (previousButtonState == HIGH && currentButtonState == LOW) {
    delay(40); // Simple button debounce

    if (digitalRead(BOOT_BUTTON_PIN) == LOW) {
      // Open Windows Run dialog (Windows key + R).
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(100);
      Keyboard.releaseAll();

      delay(500);

      // Schedule a restart after 60 seconds.
      Keyboard.print("shutdown /r /t 60");
      Keyboard.write(KEY_RETURN);

      // Wait for the button to be released to avoid repeat triggering.
      while (digitalRead(BOOT_BUTTON_PIN) == LOW) {
        delay(10);
      }
    }
  }

  previousButtonState = digitalRead(BOOT_BUTTON_PIN);
  delay(10);
}
