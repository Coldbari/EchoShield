#ifndef CONFIG_H
#define CONFIG_H

// **SIM800L Configuration**
#define SIM_TX 17  // ESP32 TX to SIM800L RX
#define SIM_RX 16  // ESP32 RX to SIM800L TX

// **GPS Module Configuration**
#define GPS_RX 34  // ESP32 RX to GPS TX
#define GPS_TX 12  // ESP32 TX to GPS RX

// **SOS Button & Indicators**
#define SOS_BUTTON 4          // SOS Button Pin
#define RED_LED 26            // Emergency Indicator LED
#define GREEN_LED 27          // Device Ready LED
#define YELLOW_LED 25         // Status LED
#define BUZZER 32             // Buzzer Pin
#define VIBRATION_MOTOR 33    // Vibration Motor Pin

// **Microphone & Speaker (PAM8403)**
#define MIC_PIN 35            // Microphone Input
#define SPEAKER_L 22          // Speaker Left Channel
#define SPEAKER_R 23          // Speaker Right Channel

// **Battery Monitoring**
#define BATTERY_VOLTAGE_PIN 36  // Battery Voltage Measurement

// **SOS Contacts (Multiple Numbers)**
const char* SOS_PHONE_NUMBERS[] = {"+918169783494", "+917900177209"};
const int NUM_CONTACTS = sizeof(SOS_PHONE_NUMBERS) / sizeof(SOS_PHONE_NUMBERS[0]);

// **Other Settings**
#define CALL_DURATION 30000  // Max call duration in milliseconds (30 sec)
#define GPS_TIMEOUT 10000    // GPS signal timeout (10 sec)

// **Debugging Options**
#define DEBUG true  // Set to 'false' to disable Serial prints

#endif  // CONFIG_H
