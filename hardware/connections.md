Here’s the **detailed wiring connection** for your SOS device project.  

---

## **ESP32 SOS Device – Complete Wiring Guide**  

### **1. ESP32 Pin Mapping**  
| **Component**         | **ESP32 Pin** | **Remarks** |
|----------------------|------------|------------|
| **SIM800L GSM Module** | TX → 17, RX → 16 | Communication with SIM800L |
| **GPS Module (NEO-6M)** | TX → 34, RX → 12 | Serial communication with GPS |
| **Microphone (MAX9814 / Electret Mic)** | OUT → A0 (Analog Pin) | Audio input for recording |
| **Speaker (8Ω, 1W)** | Connected to PAM8403 module | For audio output |
| **SOS Button (KAN 9A-L)** | GPIO 4 (INPUT_PULLUP) | Press to activate SOS |
| **Red LED (SOS Status)** | GPIO 26 | Turns ON when SOS activated |
| **Green LED (Power Indicator)** | GPIO 27 | Stays ON when device is ready |
| **Yellow LED (Notification LED)** | GPIO 25 | Blinks for alerts |
| **Buzzer (Active 5V)** | GPIO 32 | Sound alerts for SOS |
| **Vibration Motor (3.7V – 5V)** | GPIO 33 (via Transistor) | Vibrates on SOS activation |
| **Li-Ion Battery (3.7V)** | Connected to TP4056 | Main power source |
| **Boost Converter (MT3608)** | Output to 5V | Steps up voltage if needed |

---

## **2. GSM Module (SIM800L) Wiring**
| **SIM800L Pin** | **ESP32 / Power** | **Remarks** |
|----------------|-----------------|-------------|
| **VCC**       | 4.2V (Battery) | Direct battery connection |
| **GND**       | GND (ESP32) | Common ground |
| **TX**        | GPIO 17 (RX1) | Serial communication |
| **RX**        | GPIO 16 (TX1) | Serial communication |
| **RST**       | NC (Not Connected) | Optional reset pin |
| **DTR**       | GND (if required) | Sleep mode control |

> **Note:** Use **level shifter or resistor divider** to step down TX voltage.

---

## **3. GPS Module (NEO-6M) Wiring**
| **GPS Pin** | **ESP32** | **Remarks** |
|------------|---------|------------|
| **VCC**    | 3.3V | GPS Power |
| **GND**    | GND | Common ground |
| **TX**     | GPIO 34 (RX2) | Serial Communication |
| **RX**     | GPIO 12 (TX2) | Serial Communication |

---

## **4. Microphone Module (MAX9814 / Electret Mic) Wiring**
| **Mic Pin** | **ESP32 / Power** | **Remarks** |
|------------|-----------------|-------------|
| **VCC**    | 3.3V / 5V | Power supply |
| **GND**    | GND | Common ground |
| **OUT**    | A0 (Analog Pin) | Audio input for recording |

> **Note:** Use **AnalogRead** on ESP32 to capture audio data.

---

## **5. Speaker & Audio Amplifier (PAM8403) Wiring**
| **PAM8403 Pin** | **ESP32 / Power** | **Remarks** |
|----------------|-----------------|-------------|
| **VCC**       | 5V | Power supply |
| **GND**       | GND | Common ground |
| **L-IN**      | ESP32 DAC1 (GPIO 25) | Left audio input |
| **R-IN**      | ESP32 DAC2 (GPIO 26) | Right audio input |
| **L-OUT**     | Speaker + | Left channel output |
| **R-OUT**     | Speaker - | Right channel output |

> **Note:** Use **I2S** for better audio transmission.

---

## **6. LED Indicators Wiring**
| **LED** | **ESP32 Pin** | **Resistor (Ω)** | **Remarks** |
|--------|-------------|---------------|------------|
| **Red LED (SOS Active)** | GPIO 26 | 220Ω | Turns ON during SOS |
| **Green LED (Power)** | GPIO 27 | 220Ω | Indicates device is ON |
| **Yellow LED (Alert)** | GPIO 25 | 220Ω | Notification alert |

---

## **7. Buzzer & Vibration Motor Wiring**
| **Component** | **ESP32 Pin** | **Via Transistor?** | **Remarks** |
|-------------|------------|---------------|------------|
| **Buzzer (Active)** | GPIO 32 | No | Turns ON for alerts |
| **Vibration Motor (5V)** | GPIO 33 | Yes (BC547 / 2N2222) | Needs transistor to drive |

> **Note:**  
> - Use **PWM (tone function)** for buzzer control.  
> - **Transistor needed** for vibration motor since ESP32 cannot drive it directly.

---

## **8. Power Supply (Battery + Charging) Wiring**
| **Component** | **Connection** | **Remarks** |
|-------------|-------------|------------|
| **Li-Ion Battery (3.7V)** | TP4056 BAT+ / BAT- | Main power source |
| **TP4056 Output** | Boost Converter Input | Charges battery |
| **Boost Converter (MT3608)** | Output to 5V | Steps up voltage if needed |

---

## **9. SOS Button (KAN 9A-L) Wiring**
| **Button Pin** | **ESP32 Pin** | **Mode** |
|--------------|-------------|--------|
| **One Side** | GPIO 4 | INPUT_PULLUP |
| **Other Side** | GND | Ground |

> **Logic:** When pressed, **GPIO 4 LOW** → Trigger SOS.

---

## **10. Capacitors & Protection Components**
| **Component** | **Placement** | **Function** |
|-------------|-------------|------------|
| **100µF Capacitor** | Across Battery & TP4056 | Power stabilization |
| **10µF Capacitor** | Across Boost Converter Output | Reduces voltage noise |
| **Schottky Diode (1N5819)** | Between Battery & Load | Prevents reverse current |
| **1KΩ Resistor** | Transistor Base | Limits base current |

---

## **Final Notes**
- **Common GND:** All components should share a **common ground (GND)** with ESP32.
- **Use Logic Level Shifter** for **SIM800L TX** to prevent **3.3V-5V mismatch**.
- **Check Power Consumption:** ESP32, GSM, and GPS require **good power supply**.
- **Use External Antennas** for better **GPS & GSM signal**.

---
