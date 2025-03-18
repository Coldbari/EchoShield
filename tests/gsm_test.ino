// ### **Features of This Code:**  
// ✅ Connects to the GSM module  
// ✅ Sends an SMS to a specified number  
// ✅ Displays responses from the module in the Serial Monitor  
// ### **GSM Test Code (`gsm_test.ino`)**

#include <SoftwareSerial.h>

// Define RX and TX pins for GSM module
SoftwareSerial gsm(7, 8);  // RX, TX (Change if needed)

void setup() {
    Serial.begin(9600);
    gsm.begin(9600);

    Serial.println("Initializing GSM Module...");
    delay(1000);

    // Test AT communication
    gsm.println("AT");
    delay(1000);
    printResponse();

    // Set SMS mode to text
    gsm.println("AT+CMGF=1");
    delay(1000);
    printResponse();

    // Send an SMS
    gsm.println("AT+CMGS=\"+911234567890\"");  // Change to recipient number
    delay(1000);
    gsm.println("Hello from Arduino GSM!");
    delay(1000);
    gsm.write(26);  // ASCII code for CTRL+Z to send SMS
    delay(5000);
    printResponse();
}

void loop() {
    // Nothing in loop (one-time test)
}

void printResponse() {
    while (gsm.available()) {
        Serial.write(gsm.read());
    }
}

// ### **How to Use This Code:**  
// 1. **Connect the GSM Module:**  
//    - **VCC** → 5V (use a separate power source if needed)  
//    - **GND** → GND  
//    - **TX** → Arduino **Pin 7**  
//    - **RX** → Arduino **Pin 8** (use a voltage divider to step down from 5V to 3.3V)  

// 2. **Insert a SIM card into the module**  
// 3. **Upload the code to Arduino**  
// 4. **Open Serial Monitor** (`9600 baud`)  
// 5. **Check the AT responses** and SMS delivery  


// If you're getting the error "cannot open source file 'SoftwareSerial.h'", here are possible reasons and solutions:

// 1. Install the SoftwareSerial Library (For Arduino Boards)
// Open Arduino IDE.
// Go to Sketch > Include Library > Manage Libraries.
// Search for SoftwareSerial and install it.
// Restart the IDE and try compiling again.

