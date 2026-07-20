#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "sensor_manager.h"
#include "driver_monitor.h"
#include "state_machine.h"
#include "event_recorder.h"

#include "led_manager.h"
#include "buzzer_manager.h"
#include "display_manager.h"
#include "wifi_manager.h"
#include "wifi_driver.h"

/*=========================================================
 * Application Entry Point
 *========================================================*/

void app_main(void)
{
    SensorData_t sensorData;

    AlertStatus_t alertStatus;

    SystemState_t currentState;

    /*=========================================
     * Initialize System Modules
     *========================================*/

    SensorManager_Init();

    DriverMonitor_Init();

    StateMachine_Init();

    LedManager_Init();

    BuzzerManager_Init();

    DisplayManager_Init();

   /*-----------------------------------------
    * Initialize Wi-Fi Driver
    *----------------------------------------*/

    WiFiDriver_Init();

    WiFiManager_Init();

    EventRecorder_Init();

    /*=========================================
     * Main Application Loop
     *========================================*/

    while (1)
    {
        /*--------------------------------------
         * Read Sensors
         *-------------------------------------*/

        SensorManager_Update();

        SensorManager_GetData(&sensorData);

        /*--------------------------------------
         * Analyze Driver
         *-------------------------------------*/

        DriverMonitor_Update(&sensorData);

        DriverMonitor_GetAlerts(&alertStatus);

        /*--------------------------------------
         * Determine Vehicle State
         *-------------------------------------*/

        StateMachine_Update(&alertStatus);

        currentState = StateMachine_GetState();

        /*--------------------------------------
         * LED Indicators
         *-------------------------------------*/

        LedManager_Update(currentState);

        /*--------------------------------------
         * Buzzer
         *-------------------------------------*/

        BuzzerManager_Update(currentState);

        /*--------------------------------------
         * OLED Dashboard
         *-------------------------------------*/

        DisplayManager_Update(currentState,
                              &alertStatus,
                              &sensorData,
                              WiFiManager_IsConnected());

        /*--------------------------------------
         * Wi-Fi
         *-------------------------------------*/

        WiFiManager_Update(currentState,
                           &alertStatus,
                           &sensorData);

        /*--------------------------------------
         * Event Recorder
         *-------------------------------------*/

        EventRecorder_Update(currentState,
                             &alertStatus,
                             &sensorData);

        /*--------------------------------------
         * Scheduler Tick
         *-------------------------------------*/

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

