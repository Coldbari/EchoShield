#include <TinyGPS++.h>
#include "config.h"

// Create GPS object
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);  // Use UART2 for GPS

// Function to initialize GPS module
void initGPS() {
    gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
    Serial.println("📡 GPS Module Initialized...");
}

// Function to get GPS location
String getGPSLocation() {
    unsigned long startTime = millis();
    while (millis() - startTime < GPS_TIMEOUT) {
        while (gpsSerial.available()) {
            gps.encode(gpsSerial.read());
            if (gps.location.isValid()) {
                String latitude = String(gps.location.lat(), 6);
                String longitude = String(gps.location.lng(), 6);
                Serial.println("✅ GPS Location Acquired!");
                return "SOS ALERT! Location: https://www.google.com/maps?q=" + latitude + "," + longitude;
            }
        }
    }
    Serial.println("⚠ GPS Signal Not Found!");
    return "SOS ALERT! Location Not Available!";
}
