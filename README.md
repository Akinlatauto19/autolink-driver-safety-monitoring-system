# AutoLink Driver Safety Monitoring System

## Overview

The AutoLink Driver Safety Monitoring System is an embedded software project developed using the ESP32 and ESP-IDF framework.

The purpose of this project is to improve driver safety by continuously monitoring different conditions inside and around a vehicle. The system collects data from multiple sensors, processes the information, determines the current safety state, and sends important events to a cloud database for remote monitoring.

Instead of focusing on only one type of hazard, the system combines several safety features into a single monitoring platform.

---

## Features

The system currently monitors:

- Driver alcohol level using the MQ-3 alcohol sensor
- Cabin temperature using the DHT22 sensor
- Obstacle distance using an ultrasonic sensor
- Vehicle vibration
- Driver fatigue alerts
- System fault detection

When abnormal conditions are detected, the system can:

- Change LED status indicators
- Activate the buzzer
- Display information on the OLED display
- Record important events
- Upload data to Supabase over Wi-Fi

---

## Hardware Used

- ESP32 Development Board
- MQ-3 Alcohol Sensor
- DHT22 Temperature Sensor
- HC-SR04 Ultrasonic Sensor
- SH1107 OLED Display
- Status LEDs
- Buzzer

---

## Software Architecture

While building this project, I decided to divide the software into different modules instead of putting everything inside `main.c`.

Each module has one responsibility only.

```
main
│
├── Sensor Manager
├── Driver Monitor
├── State Machine
├── Event Recorder
├── LED Manager
├── Buzzer Manager
├── Display Manager
├── Wi-Fi Manager
├── Wi-Fi Driver
├── I2C Manager
├── Supabase Client
└── Configuration Files
```

This made the project much easier to understand and debug.

For example, if I want to modify the OLED display, I only need to work inside the display module without affecting the rest of the project.

---

## Software Modules

### Sensor Manager

Responsible for reading all sensors and storing their values inside a common data structure.

It does not decide whether the driver is in danger.

---

### Driver Monitor

Processes sensor readings and determines whether different alerts should be triggered.

Examples include:

- High temperature
- Alcohol detected
- Obstacle too close
- Excessive vibration

---

### State Machine

I chose to use a state machine because multiple alerts can occur at the same time.

Instead of allowing different modules to make independent decisions, the state machine keeps the entire system operating in one clear state.

The available states are:

- Normal
- Warning
- Critical
- Fault

This makes the behaviour of the system more predictable and easier to maintain.

---

### Event Recorder

Stores important safety events for future logging and cloud upload.

---

### LED Manager

Controls the system status LEDs.

Green indicates normal operation, while yellow and red indicate increasing levels of danger.

---

### Buzzer Manager

Activates the audible alarm whenever the system enters dangerous operating conditions.

---

### Display Manager

Responsible for updating the SH1107 OLED display with useful information for the driver.

---

### Wi-Fi Manager

Maintains the Wi-Fi connection and decides when information should be uploaded to the cloud.

---

### Supabase Client

Handles communication between the ESP32 and the Supabase REST API.

Sensor information is converted into JSON before being transmitted.

---

## Data Flow

```
Sensors
   │
   ▼
Sensor Manager
   │
   ▼
Driver Monitor
   │
   ▼
State Machine
   │
   ├────────► LED Manager
   │
   ├────────► Buzzer Manager
   │
   ├────────► Display Manager
   │
   ├────────► Event Recorder
   │
   └────────► Wi-Fi Manager
                    │
                    ▼
             Supabase Cloud
```

---

## Why I Chose This Design

One thing I learned while building this project is that writing code that works is only the beginning.

As the project became larger, I realized that keeping everything in one file would make it difficult to debug and maintain.

By separating the software into modules, I can:

- Test one part of the system independently
- Easily fix bugs
- Improve readability
- Add new features later without rewriting existing code

For example, if I decide to add GPS tracking or GSM communication in the future, I can simply create another module without changing the rest of the project.

---

## Programming Practices Used

During development, I intentionally tried to follow good embedded software practices.

Some of these include:

- Modular programming
- Separation of responsibilities
- Meaningful function names
- Use of structures to organize sensor data
- Header/source file separation
- Configuration values stored in dedicated configuration files
- Defensive programming using NULL pointer checks
- Fixed-width integer types where appropriate

---

## Cloud Integration

The system uploads important information to Supabase using the REST API.

The current cloud data includes:

- Cabin temperature
- Alcohol level
- Vibration level
- Obstacle distance
- Current system state

This allows safety information to be monitored remotely.

---

## Development Environment

- ESP-IDF v6.0.2
- Visual Studio Code
- ESP32
- Git
- GitHub
- Supabase

---

## Future Improvements

Some features planned for future versions include:

- GPS location tracking
- GSM emergency notification
- Driver identity management
- Mobile application
- Historical trip analysis
- Machine learning for driver behaviour prediction

---

## Author

**Akinkunmi Akindolapo**

B.Sc. Physics

NCE Automobile Technology

Embedded Systems | Robotics | Automotive Technology