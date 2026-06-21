# Troubleshooting

Common issues when using Digispark HID Toolkit and how to fix them.

---

## Arduino IDE Issues

### "Plug in device now..." never completes

**Cause:** The Digispark was already plugged in before clicking Upload, or the driver is not installed.

**Fix:**
1. Unplug the Digispark.
2. Click Upload in Arduino IDE.
3. Wait until you see `Plug in device now...`.
4. Only then plug in the Digispark.

If this still fails, install the Digistump drivers (see [hardware guide](hardware.md)).

---

### Board not found in Tools menu

**Fix:**
1. Open `File` > `Preferences`.
2. Paste `http://digistump.com/package_digistump_index.json` into Additional Board Manager URLs.
3. Open `Tools` > `Board` > `Board Manager`.
4. Search `Digistump AVR` and click Install.
5. Restart Arduino IDE.

---

### `DigiKeyboard.h: No such file or directory`

**Fix:** The Digistump board package was not installed. Follow the step above. The DigiKeyboard library ships with the board package.

---

### Sketch is too large

**Cause:** The ATtiny85 only has about 6 KB of usable flash.

**Fix:** Remove unused `DigiKeyboard.delay()` calls or shorten string prints. Each character in a `print()` call uses flash space.

---

## Payload Issues

### PowerShell does not open

**Cause:** The Win+R delay is too short for the target machine.

**Fix:** Increase `DigiKeyboard.delay(1000)` after `sendKeyStroke(KEY_R, MOD_GUI_LEFT)` to `2000`.

---

### PowerShell opens but the script runs too fast

**Cause:** The 4-second wait after pressing Enter is not long enough for slow machines.

**Fix:** Increase `DigiKeyboard.delay(4000)` to `6000` or higher.

---

### No data arrives in Telegram or Discord

1. Verify the token or webhook URL is correct by testing it manually from PowerShell.
2. Check that the target machine has internet access.
3. Check that `netsh wlan show profiles` returns results in a normal command prompt on that machine.

---

### WiFi credentials are blank

**Cause:** The target machine has no saved WiFi profiles, or the profiles were saved for another user account.

**Note:** `netsh wlan show profile key=clear` requires the profile to be available to the current user. Profiles saved by other user accounts may not appear.

---

## Windows Compatibility

| OS | Status |
|----|--------|
| Windows 10 | Tested, works |
| Windows 11 | Tested, works |
| Windows 7/8 | Should work, untested |
| Linux | Not targeted by current payloads |
| macOS | Not targeted by current payloads |

---

## Digispark Typing Wrong Characters

**Cause:** The Digispark keyboard layout defaults to US English. If the target machine uses a different layout, special characters may be typed incorrectly.

**Fix:** Ensure the target machine keyboard layout matches US English in Windows settings, or avoid special characters in the typed commands.
