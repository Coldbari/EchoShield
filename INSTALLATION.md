# **Installation Guide**  

## **1. Prerequisites**  
Before setting up the device, ensure you have the following:  

### **Hardware Requirements**  
- ESP32 Development Board  
- SIM800L GSM Module  
- GPS Module  
- Microphone  
- Speaker with PAM8403 Amplifier  
- SOS Button  
- LEDs (Red, Green, Yellow)  
- Buzzer  
- Vibration Motor  
- Power Supply (Li-ion Battery + BMS)  
- Jumper Wires  
- PCB (if applicable)  

### **Software Requirements**  
- Arduino IDE ([Download Here](https://www.arduino.cc/en/software))  
- ESP32 Board Manager ([Installation Guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html))  
- Required Libraries:  
  - `TinyGPS++`  
  - `Adafruit_GFX` (for OLED, if used)  
  - `SoftwareSerial`  
  - `DFRobotDFPlayerMini` (for audio, if used)  

## **2. Setting Up the Hardware**  
- Connect each component as per the **circuit diagram** (`circuit_diagram.png`).  
- Ensure correct power supply (3.7V Li-ion battery for SIM800L, 5V for ESP32).  
- Insert a **2G SIM Card** (5G SIM may not work with SIM800L).  

## **3. Setting Up the Software**  
### **Step 1: Install ESP32 Board in Arduino IDE**  
1. Open **Arduino IDE**  
2. Go to **File > Preferences**  
3. Add the following URL in **Additional Board Manager URLs**:  
   ```
   https://dl.espressif.com/dl/package_esp32_index.json
   ```
4. Go to **Tools > Board > Board Manager** and install **ESP32** by Espressif Systems.  

### **Step 2: Install Required Libraries**  
1. Open **Arduino IDE**  
2. Go to **Sketch > Include Library > Manage Libraries**  
3. Search for and install the following:  
   - TinyGPS++  
   - Adafruit GFX  
   - SoftwareSerial  
   - DFRobotDFPlayerMini  

### **Step 3: Upload the Code**  
1. Open the `main.ino` file.  
2. Select **ESP32 Board** from **Tools > Board**.  
3. Select the correct **COM Port** under **Tools > Port**.  
4. Click **Upload** (→).  

## **4. Testing the Device**  
- Press the **SOS Button** to trigger an alert.  
- Check the **LEDs, Buzzer, and Vibration Motor** functionality.  
- Verify **GPS location in SMS**.  
- Ensure the **microphone and speaker** work during calls.  

## **5. Troubleshooting**  
- **No GPS Signal?** Try moving to an open space.  
- **SIM Not Detecting?** Ensure the SIM supports **2G** and is activated.  
- **No Sound in Calls?** Check microphone and speaker wiring.  

---
