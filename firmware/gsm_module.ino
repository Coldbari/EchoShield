#include "config.h"

HardwareSerial sim800l(1); // Use UART1 for SIM800L

void initGSM() {
    sim800l.begin(9600, SERIAL_8N1, SIM_RX, SIM_TX);
    Serial.println("📶 Initializing GSM Module...");
    delay(3000);
    
    sim800l.println("AT");  // Check module response
    delay(1000);
    sim800l.println("AT+CMGF=1");  // Set SMS text mode
    delay(1000);
    sim800l.println("AT+CNMI=1,2,0,0,0");  // Configure new message indications
    delay(1000);
    
    Serial.println("✅ GSM Module Ready!");
}

void sendSMS(String message) {
    Serial.println("📩 Sending SMS...");
    for (int i = 0; i < NUM_CONTACTS; i++) {
        sim800l.print("AT+CMGS=\"");
        sim800l.print(SOS_PHONE_NUMBERS[i]);
        sim800l.println("\"");
        delay(1000);
        sim800l.println(message);
        sim800l.write(26); // Send SMS (CTRL+Z)
        delay(5000);
        Serial.println("✅ SMS Sent to: " + String(SOS_PHONE_NUMBERS[i]));
    }
}

void makeCall() {
    Serial.println("📞 Making SOS Call...");
    for (int i = 0; i < NUM_CONTACTS; i++) {
        sim800l.print("ATD");
        sim800l.print(SOS_PHONE_NUMBERS[i]);
        sim800l.println(";");
        delay(30000); // 30 seconds call duration
        sim800l.println("ATH"); // Hang up
        delay(2000);
        Serial.println("📴 Call Ended.");
    }
}
