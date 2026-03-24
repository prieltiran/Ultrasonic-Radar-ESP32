פ
# Ultrasonic Radar System (ESP32)

A real-time proximity alert system based on an ESP32 and HC-SR04 ultrasonic sensor.  
The system operates similarly to a parking radar, providing visual feedback through an LED whose blinking rate changes according to distance.

## Features
- Real-time distance measurement using ultrasonic sensing  
- Adaptive LED alert system based on proximity  
- Multiple alert levels  
- Serial output for debugging  

## Distance-Based Behavior

| Distance Range | LED Behavior        |
|----------------|--------------------|
| 80–100 cm      | Slow blink (2 Hz)  |
| 50–80 cm       | Medium blink (4 Hz)|
| 20–50 cm       | Fast blink (8 Hz)  |
| < 20 cm        | Solid ON           |
| > 100 cm / 0   | OFF                |

## Hardware Components
- ESP32 Development Board  
- HC-SR04 Ultrasonic Sensor  
- LED  
- Resistor (220Ω–1kΩ)  
- Breadboard and jumper wires  

## Wiring

| Component        | ESP32 Pin |
|------------------|----------|
| VCC              | 5V / VIN |
| GND              | GND      |
| Trig             | GPIO 5   |
| Echo             | GPIO 18  |
| LED (+ via R)    | GPIO 13  |
| LED (-)          | GND      |

## How It Works
1. The ESP32 sends a trigger pulse to the ultrasonic sensor  
2. The sensor measures echo return time  
3. Distance is calculated based on sound velocity  
4. LED behavior is adjusted according to distance  

## Serial Monitor
Baud rate: 115200  

## How to Run
1. Open the project in Arduino IDE  
2. Select ESP32 board  
3. Choose the correct COM port  
4. Upload the code  
5. Open Serial Monitor  

## Author
Priel Tiran
