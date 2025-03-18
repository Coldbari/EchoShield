## Troubleshooting

### **GSM Issues**
- **No network connection**: Check SIM card placement and ensure it has an active plan.
- **SIM800L not responding**: Verify power supply (SIM800L requires stable 4.2V-4.7V).
- **Cannot send SMS**: Check if the number format is correct and ensure the SMS service is active.
- **Device not making calls**: Verify that voice calling is enabled on the SIM card.

### **GPS Issues**
- **No GPS signal**: Move outdoors or near a window for better reception.
- **GPS module not initializing**: Check wiring and power connections.
- **Incorrect coordinates**: Wait for the GPS to stabilize after power-on (can take up to 60 seconds).

### **Button Not Responding**
- Ensure the button is properly wired to the correct GPIO pin.
- Check for loose connections and replace if necessary.
- Verify in Serial Monitor if button presses are detected.

### **Audio Issues**
- **No sound from speaker**: Check speaker wiring and power.
- **Microphone not recording**: Ensure correct wiring and test with another microphone module.
- **Poor audio quality**: Adjust gain or use a noise-filtering microphone.

### **Power & Battery Issues**
- **Device not turning on**: Ensure the battery is charged and properly connected.
- **Frequent restarts**: Check for unstable power supply or insufficient battery capacity.
- **Overheating issues**: Verify that voltage regulators are not overheating and use heat sinks if needed.

### **Indicator & Alerts Not Working**
- **LED not blinking**: Ensure it is connected to the correct GPIO pin and not damaged.
- **Buzzer not sounding**: Check wiring and replace the buzzer if necessary.
- **Vibration motor not working**: Verify power connections and try a different GPIO pin.

---

Your SOS device is now ready for deployment! 🚀 Let me know if you need further refinements.

