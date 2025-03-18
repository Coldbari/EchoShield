Here’s a **detailed components list** for your SOS device project:  

### **1. Microcontroller & Modules**  
- **ESP32** – Main microcontroller  
- **SIM800L GSM Module** – For SMS, calls, and communication  
- **GPS Module (NEO-6M / Ublox)** – For location tracking  
- **Microphone Module (MAX9814 or similar)** – For voice recording & live audio  
- **Speaker (8Ω, 1W or similar)** – For two-way communication  

### **2. Power Supply & Battery Management**  
- **Li-Ion / Li-Po Battery (3.7V, 2000mAh or more)** – Power source  
- **TP4056 Battery Charging Module with Protection** – Battery charging & protection  
- **Boost Converter (MT3608 or similar)** – Step-up voltage to 5V if needed  
- **100µF & 10µF Capacitors** – For power stabilization  

### **3. Buttons & Switches**  
- **KAN 9A-L Flashlight Push Button Switch (ON/OFF)** – SOS activation  
- **Additional Push Buttons** – For manual controls if needed  

### **4. Indicators & Feedback Components**  
- **Red LED** – SOS status indicator  
- **Green LED** – Power / device ready indicator  
- **Yellow LED** – Notification indicator  
- **Buzzer (Active/Passive, 5V)** – Alarm sound for alerts  
- **Vibration Motor (3.7V – 5V)** – Haptic feedback for SOS activation  

### **5. Connectivity & Wiring**  
- **Jumper Wires (Male & Female)** – For connections  
- **PCB or Breadboard** – Prototyping platform  
- **Screw Terminals / JST Connectors** – For secure connections  

### **6. Additional Components**  
- **Transistors (BC547 / 2N2222)** – Switching components  
- **Resistors (1kΩ, 10kΩ, etc.)** – For circuit stability  
- **Diodes (1N4007 or Schottky Diodes)** – For power protection  
- **Voltage Regulator (AMS1117-3.3V / 7805)** – Voltage conversion  
