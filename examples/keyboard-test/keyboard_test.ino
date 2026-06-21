#include "DigiKeyboard.h"

void setup() {
  // Wait for HID enumeration
  DigiKeyboard.delay(2000);

  // Type all lowercase letters
  DigiKeyboard.print("abcdefghijklmnopqrstuvwxyz ");

  // Type all digits
  DigiKeyboard.print("0123456789 ");

  // Type common symbols (US layout)
  DigiKeyboard.print("!@#$%^&*()-_=+[]{}|;':,./<>?");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("Keyboard test complete.");
}

void loop() {}
