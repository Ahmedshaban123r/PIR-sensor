# PIR Motion Detection with ATmega32 and LCD

This project demonstrates how to interface a **PIR sensor** with an **ATmega32 microcontroller** and display motion detection status on a **16x2 LCD**.  

- When motion is detected → LCD shows **"Motion Detected"**  
- When no motion is detected → LCD shows **"Not Detected"**

---

## 📌 Features
- Reads motion from a PIR sensor (digital output).  
- Displays real-time status on 16x2 LCD.  
- Simple and lightweight code in **C (AVR-GCC)**.  
- Works with both hardware and Proteus simulation.  

---

## 🛠️ Components Used
- ATmega32 Microcontroller  
- PIR Sensor (HC-SR501 or equivalent)  
- 16x2 LCD Display (HD44780 compatible)  
- Resistors & Jumper wires  
- Power supply (5V)  

---

## ⚡ Circuit Connections
| Component | ATmega32 Pin |
|-----------|--------------|
| PIR OUT   | PD0          |
| LCD Data  | PORTC        |
| LCD RS    | PA0          |
| LCD RW    | PA1          |
| LCD EN    | PA2          |

---

## 📂 Project Structure
├── LCD.h # LCD function declarations
├── LCD.c # LCD driver implementation
├── main.c # PIR + LCD main logic
└── README.md # Project documentation


---

## ▶️ How It Works
1. The PIR sensor detects motion and outputs a **HIGH signal**.  
2. ATmega32 reads this signal on **PD0**.  
3. Depending on the signal:
   - **HIGH** → "Motion Detected"  
   - **LOW** → "Not Detected"  
4. Message is displayed on the **LCD**.  

---

## 🚀 Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/atmega32-pir-lcd.git
2. Open the project in Atmel Studio / Microchip Studio or use avr-gcc toolchain.

3. Compile and upload the hex file to ATmega32 using a programmer (e.g., USBasp).

4. Connect components as per the circuit table.
