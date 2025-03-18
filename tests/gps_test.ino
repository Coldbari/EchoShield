Here’s a **GPS test code (`gps_test.ino`)** to check if your GPS module (like **Neo-6M, Ublox, or any other UART-based GPS module**) is working properly with **Arduino** or **ESP32**.  

---

### **📌 Features of This Code**  
✅ Reads GPS data (Latitude, Longitude, Altitude, Speed, etc.)  
✅ Parses data using **TinyGPS++** library  
✅ Displays GPS info on the **Serial Monitor**  

---

### **🚀 Step 1: Install Required Library**  
Before using the code, install the **TinyGPS++** library:  
1. Open **Arduino IDE**  
2. Go to **Sketch > Include Library > Manage Libraries**  
3. Search for **TinyGPS++** and install it  

---

### **📟 GPS Test Code (`gps_test.ino`)**
```cpp
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define GPS module TX/RX pins (Change these if needed)
#define RXPin 4  // GPS TX to Arduino D4
#define TXPin 3  // GPS RX to Arduino D3
#define GPSBaud 9600

// Create GPS and Serial connection
SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSPlus gps;

void setup() {
    Serial.begin(9600);
    gpsSerial.begin(GPSBaud);
    
    Serial.println("GPS Module Test...");
    Serial.println("Waiting for GPS signal...");
}

void loop() {
    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read());

        if (gps.location.isUpdated()) {
            Serial.print("Latitude: ");
            Serial.println(gps.location.lat(), 6);
            Serial.print("Longitude: ");
            Serial.println(gps.location.lng(), 6);
            Serial.print("Altitude: ");
            Serial.println(gps.altitude.meters());
            Serial.print("Speed: ");
            Serial.println(gps.speed.kmph());
            Serial.println("-------------------------");
        }
    }
}
```
---

### **🔌 Wiring Diagram (For Arduino UNO)**
| GPS Module Pin | Arduino Pin |
|--------------|-------------|
| **VCC**      | **5V / 3.3V** |
| **GND**      | **GND** |
| **TX**       | **D4** (RX) |
| **RX**       | **D3** (TX) (Use a voltage divider for 5V logic) |

⚠️ **If using ESP32 or ESP8266, use HardwareSerial instead of SoftwareSerial.**  

---

### **📌 Expected Serial Monitor Output (When GPS Signal is Available)**  
```
GPS Module Test...
Waiting for GPS signal...
Latitude: 19.0760
Longitude: 72.8777
Altitude: 14.5 m
Speed: 0.0 km/h
-------------------------
```
If **no data appears**, try moving **outdoors** to get a signal. 🚀  