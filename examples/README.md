# Examples

Beginner-friendly Digispark ATtiny85 sketches for learning USB HID automation.

These examples do nothing harmful. They are designed to show how HID keyboard emulation works before you build more advanced payloads.

---

## Available Examples

| Folder | What it does |
|--------|-------------|
| [hello-world/](hello-world/) | Types "Hello World" into any focused text field |
| [open-notepad/](open-notepad/) | Opens Notepad on Windows and types a message |
| [keyboard-test/](keyboard-test/) | Types all alphanumeric characters to test key mapping |

---

## How to Use

1. Open any `.ino` file in Arduino IDE.
2. Select `Tools > Board > Digistump AVR Boards > Digispark (Default - 16.5mhz)`.
3. Click Upload.
4. Wait for the `Plug in device now...` prompt, then plug in your Digispark.
5. Open a text editor or browser address bar on your computer.
6. The sketch will type automatically.

---

## Understanding the Code

Every Digispark sketch follows the same structure:

```cpp
#include "DigiKeyboard.h"

void setup() {
  // Everything runs once when the device is plugged in
  DigiKeyboard.delay(2000);          // Wait for the OS to detect the device
  DigiKeyboard.print("Hello");       // Type text
  DigiKeyboard.sendKeyStroke(KEY_ENTER);  // Press Enter
}

void loop() {
  // Leave this empty for HID payloads
}
```

`DigiKeyboard.delay()` is in milliseconds. `1000` = 1 second.
