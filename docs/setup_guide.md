# SOS Device Setup Guide

## 1. Hardware Requirements
Ensure you have the following components before starting:

- **Microcontroller**: ESP32 or Arduino with GSM support
- **GSM Module**: SIM800L / SIM900 for SMS and calls
- **GPS Module**: NEO-6M or equivalent for location tracking
- **Microphone & Speaker**: For voice recording and two-way communication
- **Push Button**: To trigger SOS alert
- **LED Indicator**: To show device status
- **Buzzer**: For emergency alert tones
- **Vibration Motor**: For haptic feedback when SOS is activated
- **Battery**: Rechargeable Li-ion battery (3.7V, 2000mAh recommended)
- **Voltage Regulator**: If needed for stable power supply
- **Waterproof Casing**: For durability and protection

## 2. Hardware Connections

### **ESP32 + SIM800L + GPS Setup**
| Component       | ESP32 Pin |
|----------------|-----------|
| SIM800L TX     | GPIO17    |
| SIM800L RX     | GPIO16    |
| SIM800L VCC    | 4.2V      |
| SIM800L GND    | GND       |
| GPS TX         | GPIO34    |
| GPS RX         | GPIO35    |
| GPS VCC        | 3.3V      |
| GPS GND        | GND       |
| Button         | GPIO4     |
| LED Indicator  | GPIO2     |
| Buzzer         | GPIO27    |
| Vibration Motor| GPIO26    |

## 3. Software Setup
### **Step 1: Install Required Libraries**
Open **Arduino IDE**, go to **Sketch** → **Include Library** → **Manage Libraries**, and install:
- `TinyGSM` (for GSM communication)
- `Adafruit_GPS` (for GPS functionality)
- `ArduinoJson` (for SMS formatting)
- `DFRobotDFPlayerMini` (for audio playback if needed)

### **Step 2: Upload Firmware**
1. Connect ESP32/Arduino to your PC via USB.
2. Open `sos_device.ino` in Arduino IDE.
3. Select the correct **board** and **port**.
4. Click **Upload**.
5. Open **Serial Monitor** (Baud rate: `115200`) to verify initialization.

### **Step 3: Insert SIM Card & Test GSM**
- Insert a valid SIM card into the GSM module.
- Check for network connectivity by sending an AT command in Serial Monitor (`AT+CSQ`).
- If connected, proceed to GPS testing.

### **Step 4: Test GPS Module**
- Open Serial Monitor and check for GPS coordinates.
- Ensure it receives a proper signal outdoors.

## 4. Usage Instructions

### **Triggering SOS Alert**
1. Press the **SOS button** for 3 seconds.
2. The **buzzer will beep**, and **LED will blink**.
3. The device sends an SMS with location and a voice recording.
4. If the first contact does not respond, it auto-dials the secondary contact.
5. The device continues sending periodic location updates until deactivated.

### **Receiving a Location Request**
- Send an SMS with `LOCATE` to the device number.
- The device responds with the current GPS location.

### **Two-Way Communication**
- The device auto-answers calls from the parent number.
- The microphone and speaker allow real-time conversation.

## 5. Troubleshooting
- **GSM Not Connecting**: Ensure SIM card has an active plan and check power supply.
- **GPS Not Working**: Move outdoors for better signal reception.
- **SOS Not Triggering**: Check button wiring and Serial Monitor logs.

---

Your SOS device is now ready for deployment! 🚀 Let me know if you need further refinements.

