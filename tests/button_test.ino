Here’s a simple **button test code (`button_test.ino`)** for **Arduino** to check if a button is working correctly.  

---

### **📌 Features of This Code**  
✅ Reads button state (pressed/released)  
✅ Prints the status on **Serial Monitor**  
✅ Uses **internal pull-up resistor** to avoid external resistors  

---

### **🚀 Button Test Code (`button_test.ino`)**
```cpp
#define BUTTON_PIN 2  // Change to the pin where your button is connected

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Enable internal pull-up resistor
    Serial.begin(9600);
    Serial.println("Button Test Started...");
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {  // Button pressed
        Serial.println("Button Pressed!");
        delay(200);  // Debounce delay
    } else {
        Serial.println("Button Released");
    }
    delay(500);  // Slow down serial printing
}
```

---

### **🔌 Wiring (For Arduino UNO)**
| Button Pin | Arduino Pin |
|------------|------------|
| **One Leg** | **GND** |
| **Other Leg** | **D2 (BUTTON_PIN)** |

⚠️ **No external resistor is needed** because we're using `INPUT_PULLUP`. The button will read **HIGH** when not pressed and **LOW** when pressed.

---

### **📟 Expected Serial Monitor Output**
```
Button Test Started...
Button Released
Button Released
Button Pressed!
Button Released
```
