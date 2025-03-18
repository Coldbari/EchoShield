If you want to create **`recording_test.ino`** to test audio recording, you’ll need a **microphone module** (like MAX9814, INMP441, or an SD card module to store the audio). Here’s a basic test setup:  

---

### **🚀 Features of This Code**  
✅ Records audio using an **electret microphone (MAX9814) or I2S mic (INMP441)**  
✅ Saves recorded data to an **SD card**  
✅ Uses **ADC** (for analog mic) or **I2S** (for digital mic)  

---

### **1️⃣ If Using an Analog Microphone (MAX9814, KY-038, or LM393)**
This method uses the **Arduino ADC** to sample the microphone input.

#### **📟 Code for Analog Microphone Recording (`recording_test.ino`)**
```cpp
#define MIC_PIN A0  // Microphone connected to A0

void setup() {
    Serial.begin(115200);
    pinMode(MIC_PIN, INPUT);
    Serial.println("Recording Test: Analog Mic...");
}

void loop() {
    int micValue = analogRead(MIC_PIN);  // Read microphone input
    Serial.println(micValue);  // Print raw audio data
    delay(10);  // Small delay to avoid flooding Serial Monitor
}
```
✅ **This will display the microphone signal in real time.**  
🔹 **To store recordings, add an SD card module**.

---

### **2️⃣ If Using a Digital Microphone (I2S INMP441, SPH0645)**
ESP32 supports **I2S** for high-quality audio recording.  

#### **📟 Code for I2S Microphone (ESP32 Only)**
```cpp
#include <driver/i2s.h>

#define I2S_WS   15  // Word Select (LRC)
#define I2S_SD   32  // Serial Data (DOUT)
#define I2S_SCK  14  // Serial Clock (BCLK)

void setup() {
    Serial.begin(115200);
    
    i2s_config_t i2s_config = {
        .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = 0,
        .dma_buf_count = 8,
        .dma_buf_len = 64
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_SCK,
        .ws_io_num = I2S_WS,
        .data_in_num = I2S_SD,
        .data_out_num = I2S_PIN_NO_CHANGE
    };

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
}

void loop() {
    int16_t sampleBuffer[64];
    size_t bytesRead;
    i2s_read(I2S_NUM_0, sampleBuffer, sizeof(sampleBuffer), &bytesRead, portMAX_DELAY);

    Serial.print("Audio Sample: ");
    Serial.println(sampleBuffer[0]);  // Print first sample value
}
```
✅ **This reads raw PCM data from an I2S mic**.  
🔹 **To store recordings, add an SD card module**.

---

### **3️⃣ If You Want to Save the Recording (SD Card Required)**
**Add an SD card module to store recorded data** and modify the code.

## **🔹 Code for I2S Microphone (ESP32 Only)**
This records **high-quality I2S audio** to an **SD card**.

```cpp
#include <SD.h>
#include <SPI.h>
#include <driver/i2s.h>

#define I2S_WS   15  // LRC
#define I2S_SD   32  // DOUT
#define I2S_SCK  14  // BCLK
#define SD_CS    5   // SD Card CS Pin

File audioFile;
#define SAMPLE_RATE 16000
#define RECORD_TIME 5

void setupI2S() {
    i2s_config_t i2s_config = {
        .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = SAMPLE_RATE,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = 0,
        .dma_buf_count = 8,
        .dma_buf_len = 64
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_SCK,
        .ws_io_num = I2S_WS,
        .data_in_num = I2S_SD,
        .data_out_num = I2S_PIN_NO_CHANGE
    };

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
}

void setup() {
    Serial.begin(115200);
    if (!SD.begin(SD_CS)) {
        Serial.println("SD Card failed!");
        return;
    }

    Serial.println("SD Card Initialized.");
    setupI2S();
    audioFile = SD.open("/record_i2s.wav", FILE_WRITE);
    if (!audioFile) {
        Serial.println("Failed to open file!");
        return;
    }

    Serial.println("Recording...");
    uint32_t totalSamples = SAMPLE_RATE * RECORD_TIME;
    int16_t sampleBuffer[64];

    for (uint32_t i = 0; i < totalSamples / 64; i++) {
        size_t bytesRead;
        i2s_read(I2S_NUM_0, sampleBuffer, sizeof(sampleBuffer), &bytesRead, portMAX_DELAY);
        audioFile.write((byte*)sampleBuffer, bytesRead);
    }

    Serial.println("Recording finished.");
    audioFile.close();
}

void loop() {
}
```

---

### **📌 Expected Behavior**
- The **Analog version** samples the microphone via ADC and saves it as a **16-bit WAV file**.  
- The **I2S version** (ESP32) records **high-quality 16-bit WAV audio**.  
- The recorded **`record.wav`** file is saved on the **SD card**.

---

### **🛠 Hardware Setup**
| **Component** | **Analog (Arduino)** | **I2S (ESP32)** |
|--------------|---------------------|----------------|
| **Microphone** | MAX9814 (A0) | INMP441 (I2S Pins) |
| **SD Card Module** | SPI Pins (CS = 10) | SPI Pins (CS = 5) |
| **Power** | 5V | 3.3V |

---

### **🎧 How to Listen to the Recording?**
1. Remove the SD card from the module.  
2. Insert it into your **PC or phone**.  
3. Locate the file `record.wav`.  
4. Play it using **VLC Media Player** or **Audacity**.

---