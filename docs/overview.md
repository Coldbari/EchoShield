# Overview

## Project Overview
This project is an **audio recording and playback system** that allows users to record sound using a microphone, store the audio as a **WAV file** on an SD card, and play it back. It is designed for various applications such as:

- **Voice logging** (meetings, lectures, personal notes)
- **IoT-based audio monitoring**
- **DIY sound recorders**
- **Remote surveillance & security recording**
- **Environmental sound analysis**
- **Offline voice data collection**

### Key Features:
✅ **Supports both Analog & I2S microphones**  
✅ **Saves recordings as WAV files** (16-bit PCM, 16kHz default)  
✅ **Works with SD card storage** for flexible file management  
✅ **Real-time recording with playback option**  
✅ **Low-power mode for battery-powered applications**  
✅ **Easy customization for different sample rates & durations**  
✅ **Potential for Wi-Fi/Bluetooth integration** for live streaming  

## Technical Details

### 1. Hardware Compatibility
This project supports two types of hardware setups:

#### **Option 1: Arduino (Analog Mic Setup)**
- **Microcontroller:** Arduino Uno, Nano, Mega
- **Microphone:** MAX9814 (or any analog mic with preamp)
- **Storage:** SD Card Module (SPI-based)
- **Power Supply:** 5V (USB or battery)

#### **Option 2: ESP32 (I2S Mic Setup)**
- **Microcontroller:** ESP32 (with I2S support)
- **Microphone:** INMP441 or SPH0645 (I2S-based)
- **Storage:** SD Card Module
- **Power Supply:** 3.3V (Battery or USB)

### 2. Software & Firmware
The firmware consists of:
- **Recording Module** – Captures microphone input and saves as a WAV file.
- **Playback Module** – Reads the WAV file from the SD card and plays audio.
- **File Management** – Handles SD card operations, file creation, and deletion.
- **User Interaction** – Button-based control for recording, stopping, and playback.

### 3. File Format & Storage
- **Default File Format:** `.wav` (16-bit PCM, 16kHz sample rate)
- **Customizable Settings:** Sample rate, bit depth, recording duration
- **Storage Format:** FAT32 (supports 16GB - 64GB SD cards)

### 4. Control Mechanism
- **Single Button Control:** Press to start/stop recording, playback mode.
- **Status LED:** Indicates recording, standby, or error states.
- **OLED Display (Optional):** Shows recording status, file info, SD card space.

## Future Enhancements
This system can be expanded with:
- **Wi-Fi or Bluetooth audio streaming** for real-time playback.
- **Voice activation** to start recording automatically on sound detection.
- **Multiple file storage & deletion options** for better management.
- **Integration with mobile apps** for wireless control.
- **Noise filtering algorithms** for improved audio quality.

## Conclusion
This project serves as a versatile and efficient **audio recording system** that can be modified for various real-world applications. It is beginner-friendly yet powerful enough for advanced customizations. Whether you need a simple **DIY voice recorder** or a more complex **IoT-based audio monitoring system**, this setup provides a strong foundation to build upon.

