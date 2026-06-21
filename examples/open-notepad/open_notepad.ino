#include "DigiKeyboard.h"

void setup() {
  // Wait for HID enumeration
  DigiKeyboard.delay(2000);

  // Open the Run dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);

  // Launch Notepad
  DigiKeyboard.print("notepad");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  // Type a message
  DigiKeyboard.print("Digispark HID Toolkit - USB keyboard emulation demo.");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("This text was typed by a Digispark ATtiny85.");
}

void loop() {}
