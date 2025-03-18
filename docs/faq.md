# FAQ

## Frequently Asked Questions

### 1. What is this project about?
This project allows users to record audio using a microphone, save it as a `.wav` file on an SD card, and play it back. It can be used for:
- Voice logging
- Audio analysis
- DIY sound recorders
- Remote audio surveillance
- IoT-based audio monitoring

### 2. What hardware is required?
#### For Analog Recording (Arduino):
- **Microcontroller**: Arduino Uno/Nano
- **Microphone**: MAX9814 (or any analog mic)
- **Storage**: SD Card Module (SPI-based)
- **Power**: 5V supply (USB or battery)

#### For I2S Recording (ESP32):
- **Microcontroller**: ESP32 (with I2S support)
- **Microphone**: INMP441 or SPH0645 (I2S-based)
- **Storage**: SD Card Module
- **Power**: 3.3V supply

### 3. How long can I record?
Recording time depends on the SD card size. Approximate storage capacity:
- **16GB SD Card** → **20+ hours** at 16kHz sample rate
- **32GB SD Card** → **40+ hours** at 16kHz sample rate
- **64GB SD Card** → **80+ hours** at 16kHz sample rate

### 4. What is the recording format?
The recorded audio is saved in **16-bit PCM WAV format** with a sample rate of **16kHz (default, can be changed in code)**.

### 5. Why is my audio quality poor?
Possible reasons and solutions:
- **Low volume** → Increase microphone gain (MAX9814 auto-gain may need adjustment)
- **Noise** → Use shielded cables and move away from electrical interference
- **Distortion** → Reduce sampling rate or check mic placement
- **Weak signal** → Use a preamp for better signal amplification

### 6. Can I play the recorded file on my computer?
Yes, follow these steps:
1. Remove the SD card from the module.
2. Insert it into a PC, laptop, or smartphone using an SD card reader.
3. Locate the file `sample_audio.wav`.
4. Open it using **VLC Media Player, Audacity, or any WAV-supported player**.

### 7. How do I change the recording duration?
Modify this line in `main.ino`:
```cpp
#define RECORD_TIME 5  // Change 5 to the desired duration in seconds
```

### 8. Can I use a different microphone?
Yes, but ensure:
- **Analog microphones** are connected to **A0 (Arduino) or ADC (ESP32)**.
- **I2S microphones** are connected correctly (I2S WS, SD, SCK pins).

### 9. How do I troubleshoot issues?
Refer to the `troubleshooting.md` document for common problems and solutions.

### 10. Can I record stereo audio?
No, the current setup supports **mono recording**. For stereo, you need a dual-channel microphone setup and modifications in the code.

### 11. Can I add live audio streaming?
Yes, but it requires additional coding. You can:
- Use **ESP32 with Wi-Fi** to stream audio over the network.
- Implement **Bluetooth audio streaming** for real-time playback.

### 12. Can I set up auto-deletion of old recordings?
Yes, modify the code to check SD card space and delete the oldest files when storage is low.

### 13. Can I add an OLED display for status updates?
Yes, add an OLED screen (SSD1306 or SH1106) and modify the code to display:
- **Recording status**
- **File name & duration**
- **Available SD card space**

### 14. What are some possible future enhancements?
- **Real-time audio visualization (via OLED or TFT display)**
- **Voice-activated recording (using sound level detection)**
- **Automatic file compression to save space**

### 15. Where can I get help?
- Check `troubleshooting.md` for common issues.
- Visit Arduino & ESP32 forums.
- Join online maker communities for support.

