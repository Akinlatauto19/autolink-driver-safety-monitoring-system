# Software Architecture

## Why I Designed the Project This Way

When I started this project, I knew putting everything inside one `main.c` file would work for a small project, but it would become difficult to manage as more sensors and features were added.

For that reason, I decided to separate the project into different modules, where each module performs one specific responsibility.

This makes the code easier to understand, maintain, and improve later.

---

## Overall System Flow

The system starts by initializing all peripherals.

After initialization, the ESP32 continuously reads sensor values.

The sensor data is then analysed to determine whether the driver is safe or if any dangerous condition exists.

Depending on the result, the state machine changes the system state, which controls the LEDs, buzzer, OLED display, and cloud communication.

The Wi-Fi manager is responsible for uploading important information to Supabase whenever necessary.

---

## Module Responsibilities

### sensor_manager

This module reads all hardware sensors.

It collects values from:

- DHT22
- MQ-3
- Ultrasonic Sensor

Instead of allowing every file to read sensors directly, this module keeps all sensor handling in one place.

---

### driver_monitor

This module interprets the raw sensor values.

Instead of checking temperatures or alcohol levels throughout the project, all safety decisions are made here.

This keeps the project organized.

---

### state_machine

I decided to use a state machine because the vehicle should only be in one operating state at a time.

The states are:

- Normal
- Warning
- Critical
- Fault

This makes system behaviour predictable and easier to debug.

---

### display_manager

Handles everything shown on the OLED display.

This keeps display code separate from sensor logic.

---

### led_manager

Controls the system LEDs according to the current state.

---

### buzzer_manager

Handles all audible alerts.

This allows alarm behaviour to be changed without affecting the rest of the project.

---

### wifi_manager

Responsible for cloud communication.

It decides when data should be uploaded instead of allowing every module to communicate with the cloud directly.

---

### supabase_client

This module prepares and sends data to Supabase.

Separating cloud communication from Wi-Fi management makes the code cleaner.

---

## Why I Used Structures

I grouped related information together using structures.

For example:

SensorData_t contains all sensor readings.

AlertStatus_t contains all alert conditions.

This makes it easier to pass one variable instead of many different parameters.

It also keeps related information together.

---

## Why I Chose ESP-IDF

Although Arduino is easier to start with, I wanted to learn professional embedded software development.

ESP-IDF provides better control over:

- memory
- peripherals
- FreeRTOS
- networking
- project organization

Since my goal is Embedded Systems Engineering, ESP-IDF was the better choice.

---

## Design Decisions

Some decisions I made during development include:

- separating code into modules
- using a state machine
- keeping hardware drivers independent
- preparing cloud communication through Supabase
- writing the project so additional sensors can easily be added later

These choices make the project more scalable than putting everything into one source file.