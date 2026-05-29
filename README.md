# Project 3 — Automated Temperature Control System

## Overview
A fully automatic temperature monitoring and control system built 
on Arduino Uno. Demonstrates closed loop control system architecture:

**Sense → Control → Actuate**

A BMP180 sensor continuously measures temperature and pressure. 
The Arduino controller compares live temperature against a 
programmed setpoint and automatically activates a relay output 
when the threshold is exceeded. Live readings are displayed on 
an I2C LCD panel. No human intervention required — the environment 
drives the system automatically.

This mirrors the same principle used in industrial thermal 
protection systems, greenhouse controllers, and process temperature 
regulation systems.

## Components Used
- Arduino Uno
- BMP180 Temperature and Pressure Sensor (GY-68)
- 5V Relay Module
- I2C LCD Display (16x2)
- LED
- 220Ω Resistor
- Breadboard and Jumper Wires

## Pin Configuration
| Component | Arduino Pin |
|---|---|
| BMP180 VIN | 5V |
| BMP180 GND | GND |
| BMP180 SCL | Analog Pin A5 |
| BMP180 SDA | Analog Pin A4 |
| LCD VCC | 5V |
| LCD GND | GND |
| LCD SCL | Analog Pin A5 |
| LCD SDA | Analog Pin A4 |
| Relay IN | Digital Pin 8 |

## How It Works
1. BMP180 sensor reads temperature and pressure every second
2. Live readings displayed on I2C LCD panel in real time
3. Arduino compares temperature against programmed setpoint (27°C)
4. Temperature exceeds setpoint → Relay activates on Pin 8
5. Relay closes → LED switches ON → Alarm state indicated
6. Temperature returns to normal → Relay deactivates → System resets
7. All data logged continuously via Serial Monitor

## Setpoint Configuration
```cpp
const float tempSetpoint = 27.0; // Adjust to suit environment
```
Change this value to tune the system to your specific application —
exactly like commissioning a temperature transmitter on an 
industrial plant.

## Skills Demonstrated
- I2C protocol communication (multiple devices on shared bus)
- Analog sensor integration and data processing
- Threshold based automatic relay control
- Live data display on LCD HMI panel
- Serial Monitor data logging (SCADA historian equivalent)
- Embedded C programming
- Systematic fault finding and component isolation
- Industrial control loop implementation

## Industrial Equivalent
| Breadboard Component | Industrial Equivalent |
|---|---|
| BMP180 Sensor | PT100 / Thermocouple temperature transmitter |
| I2C LCD Display | Local HMI operator panel |
| Arduino Uno | PLC / DCS Controller |
| Relay Module | Industrial contactor / solenoid valve |
| LED | Motor / pump / cooling system |
| Serial Monitor | SCADA data historian |
| Setpoint value | Controller setpoint register |

## Key Concept — I2C Communication
Both the BMP180 sensor and LCD display share the same two wires
(SDA and SDA) simultaneously using the I2C protocol. Each device
has a unique address:
- BMP180 → Address 0x77
- LCD Display → Address 0x27

This mirrors industrial fieldbus protocols like HART, Modbus and 
Profibus where multiple instruments share one communication cable.

## Circuit Simulation
[▶️ Click to run live simulation on Wokwi](https://wokwi.com/projects/464091661653294081)

## Video Demo
[📹 Watch on LinkedIn](https://www.linkedin.com/posts/adekunle-francis-adeniyi-miet-mnse-86a196198_controlengineering-automation-arduino-ugcPost-7466240239737667584-Znmk/?utm_source=share&utm_medium=member_desktop&rcm=ACoAAC5NElIBAzSFx3J1_C64gAVYtNlgFTGYhGU)

## Author
**Adekunle Francis Adeniyi**
MIET | MNSE | BS 7671
Pursuing CEng & COREN
[LinkedIn Profile](www.linkedin.com/in/adekunle-francis-adeniyi-miet-mnse-86a196198)
