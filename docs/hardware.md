# Hardware Guide

## What is the Digispark ATtiny85?

The Digispark is a development board built around the Atmel ATtiny85 microcontroller. It connects directly to a USB port and is programmable via Arduino IDE. Originally designed for small automation projects, it became popular in the security research community because it emulates a USB HID device.

When plugged in, the host operating system sees it as a keyboard. No drivers are installed, no USB mass storage appears and no security prompt fires.

---

## Specifications

| Property | Value |
|----------|-------|
| Microcontroller | Atmel ATtiny85 |
| Clock speed | 16.5 MHz (USB mode) |
| Flash memory | 8 KB (about 6 KB available after bootloader) |
| RAM | 512 bytes |
| GPIO pins | 6 (P0 to P5) |
| USB type | USB-A directly on board |
| Operating voltage | 5V |
| Approximate cost | Under ₹300 (~$3 USD) |

---

## Where to Buy

The Digispark ATtiny85 is available at:

- Amazon India
- Robu.in
- AliExpress
- Adafruit (Digistump branded)
- Local electronics stores in most cities

Search for: `Digispark ATtiny85`

Make sure you buy the version with the USB-A connector built in, not the micro USB variant.

---

## Board Versions

| Version | Connector | Notes |
|---------|-----------|-------|
| Digispark (original) | USB-A male directly on board | Most common, recommended |
| Digispark Pro | USB-A with pro features | More expensive, more pins |
| Digispark clone | USB-A | Widely available, works the same way |

All variants are programmed the same way using Arduino IDE.

---

## LED Indicator

The built-in LED is on pin P1. It blinks during USB enumeration and can be controlled in your sketch.

---

## Driver Installation (Windows)

Windows may require the Digispark driver to be installed the first time. The Digistump board package installs drivers automatically on most systems.

If the device is not recognized:

1. Download the Digistump drivers from: `https://github.com/digistump/DigistumpArduino/releases`
2. Extract and run `Install Drivers.exe`
3. Restart Arduino IDE

---

## Physical Notes

- The board fits directly into any USB-A port
- It does not get hot during normal operation
- The ATtiny85 chip is soldered on and cannot be easily replaced
- There is no reset button — to re-enter bootloader mode, unplug and replug within 5 seconds of powering on
