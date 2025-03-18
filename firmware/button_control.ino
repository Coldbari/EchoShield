#include "config.h"

bool sosTriggered = false;

void setupButton() {
    pinMode(SOS_BUTTON, INPUT_PULLUP);
    Serial.println("🛑 SOS Button Ready!");
}

void checkButton() {
    if (digitalRead(SOS_BUTTON) == LOW) {
        delay(100); // Debounce
        if (digitalRead(SOS_BUTTON) == LOW) {
            sosTriggered = !sosTriggered; // Toggle state
            
            if (sosTriggered) {
                Serial.println("🚨 SOS Activated!");
                triggerSOS();
            } else {
                Serial.println("🛑 SOS Deactivated!");
                stopSOS();
            }

            delay(1000); // Avoid multiple triggers
        }
    }
}

void triggerSOS() {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(VIBRATION_MOTOR, HIGH);
    
    sendSMS("🚨 SOS ALERT! Help Needed!");
    makeCall();
    
    delay(5000);
    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATION_MOTOR, LOW);
}

void stopSOS() {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);
    digitalWrite(VIBRATION_MOTOR, LOW);
    Serial.println("✅ SOS Stopped.");
}
