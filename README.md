# LPC2129 Temperature & Industrial Safety Monitoring System

An Embedded C project based on the LPC2129 ARM7 microcontroller for real-time temperature monitoring and industrial safety monitoring.

## 📌 Overview

This project is designed to monitor temperature and safety conditions in an industrial environment using the LPC2129 microcontroller.

The system reads temperature using an ADC-connected temperature sensor and monitors fire and worker/motion conditions using digital sensors. The monitored information is displayed on a 16x2 LCD and transmitted through UART.

The system also provides visual safety indication using Red and Green LEDs.

## ✨ Features

- Real-time temperature monitoring
- ADC interfacing with LPC2129
- Temperature sensor interfacing
- 16x2 LCD interfacing
- UART serial communication
- Fire detection
- PIR-based worker/motion detection
- SAFE and DANGER status indication
- Red and Green LED indication
- Modular Embedded C driver implementation

## 🛠️ Hardware Components

- LPC2129 ARM7TDMI-S Microcontroller
- Temperature Sensor
- Fire Sensor
- PIR Sensor
- 16x2 LCD
- Red LED
- Green LED
- UART interface

## 💻 Software & Tools

- Embedded C
- Keil µVision
- LPC2129
- ARM7
- ADC
- UART
- GPIO
- LCD 4-bit Interface

## 🔌 Pin Configuration

| LPC2129 Pin | Connected Device | Function |
|-------------|------------------|----------|
| P0.14 | Fire Sensor | Fire detection |
| P0.15 | PIR Sensor | Worker/motion detection |
| P0.17 | Green LED | Safe indication |
| P0.18 | Red LED | Danger indication |
| ADC Channel 1 | Temperature Sensor | Temperature measurement |

## ⚙️ Working Principle

### 1. Temperature Monitoring

The temperature sensor is connected to an ADC channel of the LPC2129.

The microcontroller:

1. Reads the analog value from the temperature sensor.
2. Converts the ADC value into voltage.
3. Calculates the temperature.
4. Displays the temperature on the LCD.
5. Transmits the temperature through UART.

### 2. Fire Detection

The fire sensor is connected to P0.14.

The sensor is treated as an active-low input:

- `0` → Fire detected
- `1` → No fire

### 3. Worker/Motion Detection

The PIR sensor is connected to P0.15.

- `1` → Worker/motion detected
- `0` → No worker/motion detected

### 4. Safety Status

The system checks the fire and PIR sensor conditions continuously.

If fire is detected or worker/motion is detected:

**DANGER → Red LED**

If neither condition is detected:

**SAFE → Green LED**

## 📺 Output

### LCD Display

The LCD displays the temperature and safety status.

Example:

```text
Temp:25.40
Status:SAFE

