#include "DigiKeyboard.h"

void setup() {
  // Wait for the host OS to finish enumerating the HID device
  DigiKeyboard.delay(2000);

  // Type into whatever text field is currently focused
  DigiKeyboard.print("Hello World from Digispark ATtiny85!");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
