#ifndef CONFIG_H
#define CONFIG_H

#include "driver/gpio.h"

/*==========================================================
 * GPIO Pin Assignments
 *==========================================================*/

#define DHT22_GPIO                 (4U)

#define MQ3_GPIO                   (34U)

#define ULTRASONIC_TRIGGER_GPIO    (18U)
#define ULTRASONIC_ECHO_GPIO       (19U)

#define IMPACT_BUTTON_GPIO         (27U)

/* Status LEDs */
#define GREEN_LED_GPIO             (12U)
#define YELLOW_LED_GPIO            (13U)
#define RED_LED_GPIO               (14U)

/* Audible Alert */
#define BUZZER_GPIO                (26U)

/* Reserved for future AutoLink hardware */
#define AUTOLINK_RESERVED_GPIO     (32U)

/*==========================================================
 * I2C Configuration (OLED)
 *==========================================================*/

#define I2C_SDA_GPIO               GPIO_NUM_21
#define I2C_SCL_GPIO               GPIO_NUM_22

/*==========================================================
 * Wi-Fi Configuration
 *==========================================================*/

#define WIFI_SSID                  "Infinix HOT 20i"
#define WIFI_PASSWORD              "lateef123"

/*==========================================================
 * Supabase Configuration
 *==========================================================*/

#define SUPABASE_URL               "https://xnqobxbwitloygezvkxw.supabase.co"

#define SUPABASE_API_KEY           "sb_publishable_fX-Qguo5jEFnbLjws7uQOg_ZQByExcV"

#define SUPABASE_TABLE             "driver_data"

/*==========================================================
 * Project Configuration Constants
 *==========================================================*/

/* Temperature thresholds (°C) */
#define TEMP_WARNING_THRESHOLD            (35U)
#define TEMP_CRITICAL_THRESHOLD           (45U)

/* Alcohol Sensor Thresholds */
#define ALCOHOL_WARNING_THRESHOLD         (300U)
#define ALCOHOL_CRITICAL_THRESHOLD        (600U)

/* Impact Thresholds */
#define VIBRATION_WARNING_THRESHOLD       (400U)
#define VIBRATION_CRITICAL_THRESHOLD      (700U)

/* Ultrasonic Distance Thresholds (cm) */
#define SAFE_DISTANCE_CM                  (100U)
#define WARNING_DISTANCE_CM               (50U)
#define CRITICAL_DISTANCE_CM              (20U)

/* Driver Fatigue Timer */
#define FATIGUE_WARNING_TIME_MIN          (120U)
#define FATIGUE_CRITICAL_TIME_MIN         (240U)

/* Task Periods */
#define SENSOR_UPDATE_PERIOD_MS           (1000U)
#define LOGGER_UPDATE_PERIOD_MS           (30000U)

/* Wi-Fi Upload Period */
#define WIFI_HEALTH_UPLOAD_PERIOD_MS      (600000U)

#endif /* CONFIG_H */