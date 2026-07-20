# AutoLink Driver Safety Monitoring System

An ESP32-based embedded driver safety monitoring system designed to improve road safety by continuously monitoring driver condition and vehicle environment, detecting hazardous situations, and transmitting safety data to the cloud using Supabase.

---

## Project Overview

The AutoLink Driver Safety Monitoring System is an intelligent embedded solution developed using the ESP32 and ESP-IDF framework.

The system continuously monitors multiple safety parameters including:

- Driver alcohol level
- Cabin temperature
- Driver fatigue
- Obstacle distance
- Vehicle vibration
- Impact detection

When unsafe conditions are detected, the system provides immediate visual and audible alerts while transmitting event information to a cloud database for remote monitoring and future analysis.

---

## Features

- Driver alcohol detection (MQ-3)
- Cabin temperature monitoring (DHT22)
- Obstacle detection (Ultrasonic Sensor)
- Vehicle vibration monitoring
- Driver fatigue monitoring
- Emergency impact detection
- LED status indication
- Audible buzzer warning
- OLED information display (SH1107)
- Wi-Fi connectivity
- Cloud data upload using Supabase REST API
- Modular software architecture
- Event recording system
- State machine based decision making

---

## Hardware Components

| Component | Purpose |
|-----------|----------|
| ESP32 DevKit | Main controller |
| MQ-3 Sensor | Alcohol detection |
| DHT22 | Temperature sensor |
| HC-SR04 | Obstacle detection |
| Push Button | Impact simulation |
| LEDs | Status indication |
| Buzzer | Audible alerts |
| SH1107 OLED | Information display |

---

## Software Stack

- ESP-IDF v6.0.2
- C Programming Language
- FreeRTOS
- ESP HTTP Client
- ESP Wi-Fi
- ESP Event Loop
- ESP-NETIF
- Supabase REST API

---

## Software Architecture

The project follows a modular architecture where every subsystem has a dedicated responsibility.

```
Application Layer
│
├── Driver Monitor
├── State Machine
├── Event Recorder
│
├── Sensor Manager
├── Display Manager
├── LED Manager
├── Buzzer Manager
│
├── WiFi Manager
├── WiFi Driver
│
└── Supabase Client
```

---

## Project Structure

```
main/
│
├── main.c
├── config.h
├── system_types.h
│
├── sensor_manager.c
├── sensor_manager.h
│
├── driver_monitor.c
├── driver_monitor.h
│
├── state_machine.c
├── state_machine.h
│
├── event_recorder.c
├── event_recorder.h
│
├── display_manager.c
├── display_manager.h
│
├── led_manager.c
├── led_manager.h
│
├── buzzer_manager.c
├── buzzer_manager.h
│
├── wifi_manager.c
├── wifi_manager.h
│
├── wifi_driver.c
├── wifi_driver.h
│
├── supabase_client.c
├── supabase_client.h
├── supabase_config.h
│
├── sh1107.c
├── sh1107.h
│
├── i2c_manager.c
└── i2c_manager.h
```

---

## Build Instructions

1. Install ESP-IDF v6.0.2
2. Clone this repository

```
git clone https://github.com/Akinlatauto19/autolink-driver-safety-monitoring-system.git
```

3. Open the project directory

```
cd autolink-driver-safety-monitoring-system
```

4. Build the project

```
idf.py build
```

5. Flash to ESP32

```
idf.py flash monitor
```

---

## Cloud Integration

The system uploads safety information to a Supabase database using the REST API.

Current uploaded data includes:

- Cabin Temperature
- Alcohol Level
- Obstacle Distance
- Vehicle Vibration
- Current System State

---

## Future Improvements

- GPS Tracking
- GSM Emergency Notifications
- Mobile Application
- Driver Face Monitoring
- Machine Learning Fatigue Detection
- Vehicle Speed Monitoring
- Real-time Dashboard
- OTA Firmware Updates

---

## Development Notes

This project was developed as part of an embedded systems learning journey focused on:

- Modular software architecture
- Embedded C programming
- ESP-IDF development
- Driver safety systems
- Automotive embedded applications
- Cloud-enabled IoT systems

---

## Author

**Akinkunmi Akindolapo**

B.Sc Physics

NCE Automobile Technology

Embedded Systems | Automotive Technology | Robotics

GitHub:
https://github.com/Akinlatauto19

---

## License

This project is intended for educational and research purposes.