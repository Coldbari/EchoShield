#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Define Serial Ports
HardwareSerial sim800l(1);  // SIM800L
HardwareSerial gpsSerial(2); // GPS Module

// GPS Module Setup
TinyGPSPlus gps;
#define GPS_RX 34
#define GPS_TX 12

// SIM800L Setup
#define SIM_TX 17
#define SIM_RX 16

// Define Multiple SOS Phone Numbers
const char* SOS_PHONE_NUMBERS[] = {"+918465215355", "+919545217559"};  // Add multiple numbers
const int NUM_CONTACTS = 2;  // Total contacts

// Button, LEDs, Buzzer, and Vibration Motor
#define SOS_BUTTON 4  // KAN-9A-L ON/OFF Switch
#define RED_LED 26
#define GREEN_LED 27
#define YELLOW_LED 25
#define BUZZER 32
#define VIBRATION_MOTOR 33

void setup() {
    Serial.begin(115200);
    sim800l.begin(9600, SERIAL_8N1, SIM_RX, SIM_TX);
    gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
    
    pinMode(SOS_BUTTON, INPUT_PULLUP);  // Read switch state
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(VIBRATION_MOTOR, OUTPUT);
    
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);  // Device Ready
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATION_MOTOR, LOW);
}

void loop() {
    bool sosState = digitalRead(SOS_BUTTON) == LOW;  // Switch ON (LOW) or OFF (HIGH)

    if (sosState) {
        Serial.println("🔴 SOS Activated!");
        triggerSOS();
    } else {
        Serial.println("🟢 SOS Deactivated!");
        stopSOS();
    }

    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read());
    }

    delay(500);  // Reduce CPU usage
}

void triggerSOS() {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(VIBRATION_MOTOR, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATION_MOTOR, LOW);

    String location = getGPSLocation();
    sendSMS(location);
    makeCall();
}

void stopSOS() {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATION_MOTOR, LOW);
    
    sim800l.println("ATH");  // Hang up the call
    Serial.println("📞 Call Ended.");
}

String getGPSLocation() {
    if (gps.location.isValid()) {
        String latitude = String(gps.location.lat(), 6);
        String longitude = String(gps.location.lng(), 6);
        return "SOS ALERT! Location: https://www.google.com/maps?q=" + latitude + "," + longitude;
    }
    return "SOS ALERT! Location not available.";
}

void sendSMS(String message) {
    sim800l.println("AT+CMGF=1");  // SMS mode
    delay(1000);
    for (int i = 0; i < NUM_CONTACTS; i++) {
        if (digitalRead(SOS_BUTTON) == HIGH) return; // Stop SMS if button is OFF
        sim800l.print("AT+CMGS=\"");
        sim800l.print(SOS_PHONE_NUMBERS[i]);
        sim800l.println("\"");
        delay(1000);
        sim800l.println(message);
        sim800l.write(26);
        delay(5000);
    }
}

void makeCall() {
    for (int i = 0; i < NUM_CONTACTS; i++) {
        if (digitalRead(SOS_BUTTON) == HIGH) return; // Stop calling if button is OFF
        sim800l.print("ATD");
        sim800l.print(SOS_PHONE_NUMBERS[i]);
        sim800l.println(";\r");
        delay(30000); // 30-second call duration
        sim800l.println("ATH"); // End call
        delay(2000);
    }
}
