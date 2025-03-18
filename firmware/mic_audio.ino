#include "config.h"
#include <Arduino.h>
#include <driver/i2s.h>

#define SAMPLE_RATE 16000  // Sample rate for audio recording
#define I2S_WS 15          // Word Select (L/R Clock)
#define I2S_SD 32          // Serial Data (Data In)
#define I2S_SCK 14         // Serial Clock (Bit Clock)
#define BUFFER_SIZE 1024   // Buffer size for audio data

void initMicrophone() {
    Serial.println("🎤 Initializing Microphone...");

    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = SAMPLE_RATE,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = BUFFER_SIZE,
        .use_apll = false
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_SCK,
        .ws_io_num = I2S_WS,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = I2S_SD
    };

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
    Serial.println("✅ Microphone Ready!");
}

void recordAudio(int duration) {
    Serial.println("🎤 Recording Audio...");
    uint8_t audioBuffer[BUFFER_SIZE];
    size_t bytesRead;
    unsigned long startTime = millis();

    while (millis() - startTime < duration * 1000) {
        i2s_read(I2S_NUM_0, &audioBuffer, BUFFER_SIZE, &bytesRead, portMAX_DELAY);
        Serial.write(audioBuffer, bytesRead); // Stream data via Serial
    }

    Serial.println("✅ Recording Complete.");
}

void playAudio() {
    Serial.println("🔊 Playing Audio...");
    // You need an external DAC or speaker module to process playback.
    // This function can send the recorded data to a speaker if required.
}
