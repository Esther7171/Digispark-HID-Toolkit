# Telegram Integration Guide

This guide walks you through creating a Telegram bot, getting your chat ID and wiring everything into the Digispark sketch.

---

## What you need

- A Telegram account (mobile or desktop)
- The file `digispark/telegram/r00t_b0t.ino` open in Arduino IDE

---

## Step 1: Create a Bot with BotFather

BotFather is Telegram's official bot creation tool. It has a blue verified tick next to its name.

1. Open Telegram and tap the search icon.
2. Search for `@BotFather` — make sure you select the verified account.
3. Tap **Start** or type `/start` and send.
4. Type `/newbot` and send.

BotFather will now ask two questions:

**Question 1: Name**
> Alright, a new bot. How are we going to call it? Please choose a name for your bot.

- Enter any display name. Example: `Data Collector`
- This is what shows up at the top of the chat. It can contain spaces.

**Question 2: Username**
> Good. Now let's choose a username for your bot. It must end in `bot`.

- Enter a unique username ending in `bot`. Example: `my_data_r00t_bot`
- Usernames are case-insensitive and must be globally unique on Telegram.
- If the username is taken, BotFather will ask you to choose another.

Once done, BotFather sends a confirmation message that includes your **API token**:

```
Done! Congratulations on your new bot. You will find it at t.me/my_data_r00t_bot.
You can now add a description, about section and profile picture for your bot.
Use this token to access the HTTP API:

1234567890:ABCDefghIJKLmnoPQRsTUVwxyz1234567890

Keep your token secure and store it safely.
```

Copy the token exactly. It follows the format `numbers:letters`. You will need this in Step 3.

---

## Step 2: Get Your Chat ID

You can send data to a private chat or a group. Follow the path that suits you.

### Option A: Private chat (just you and the bot)

1. Search your bot's username in Telegram and open the conversation.
2. Send any message. Example: `hello`
3. Open this URL in your browser, replacing `YOUR_TOKEN` with the token from Step 1:
   ```
   https://api.telegram.org/botYOUR_TOKEN/getUpdates
   ```
4. The browser shows a JSON response. Look for this structure:
   ```json
   "chat": {
     "id": 987654321,
     "first_name": "Your Name",
     "type": "private"
   }
   ```
5. The number next to `"id"` is your chat ID. Copy it.

### Option B: Group chat

1. Create a new Telegram group.
2. Add your bot to the group as a member.
3. Send any message in the group.
4. Visit the same `getUpdates` URL above.
5. The chat ID for a group starts with a minus sign:
   ```json
   "chat": {
     "id": -100987654321,
     "title": "My Group",
     "type": "supergroup"
   }
   ```
6. Copy the full number including the minus sign.

---

## Step 3: Configure the Sketch

Open `digispark/telegram/r00t_b0t.ino` in Arduino IDE.

Find these two lines:

```cpp
DigiKeyboard.print("$env:TK='PASTE_TOKEN_HERE'");
DigiKeyboard.print("$env:CI='PASTE_CHAT_ID_HERE'");
```

Replace the placeholders:

| Placeholder | Replace with |
|-------------|-------------|
| `PASTE_TOKEN_HERE` | Your full bot token (e.g., `1234567890:ABCDef...`) |
| `PASTE_CHAT_ID_HERE` | Your chat ID (e.g., `987654321` or `-100987654321`) |

The result should look like:

```cpp
DigiKeyboard.print("$env:TK='1234567890:ABCDefghIJKLmnoPQRsTUVwxyz'");
DigiKeyboard.print("$env:CI='987654321'");
```

These values are typed as live keystrokes into PowerShell. They never touch disk, the script file or GitHub.

---

## Step 4: Flash and Test

1. Upload the sketch to your Digispark following the [main setup guide](../README.md#setup-guide).
2. Plug the flashed Digispark into a Windows machine that has saved WiFi networks.
3. Wait approximately 24 seconds.
4. Check your Telegram chat. A `.txt` file will arrive containing the WiFi credentials, computer name and username.

---

## Troubleshooting

**No message received**
- Make sure you sent a message to the bot before checking `getUpdates` — the bot only sees messages after you start the conversation.
- Double-check there are no extra spaces or quote characters in the token or chat ID.

**`{"ok":false}` in getUpdates**
- The token is incorrect. Regenerate it in BotFather using `/revoke`.

**File arrives but is empty**
- The target machine may have no saved WiFi profiles. Test with `netsh wlan show profiles` in a command prompt first.
