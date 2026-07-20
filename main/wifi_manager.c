#include "wifi_manager.h"

#include "config.h"

#include <stddef.h>

#include "esp_timer.h"

#include "supabase_client.h"

/*=========================================================
 * Private Variables
 *========================================================*/

static bool wifiConnected = false;

static int64_t lastHealthUploadTime = 0;

static SystemState_t previousState = SYSTEM_STATE_NORMAL;

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static void CheckConnection(void);

static bool DetectImportantEvent(SystemState_t currentState,
                                 const AlertStatus_t *alerts);

static void UploadHealthReport(SystemState_t currentState,
                               const SensorData_t *sensorData);

static void SendPacket(SystemState_t currentState,
                       const AlertStatus_t *alerts,
                       const SensorData_t *sensorData);

/*=========================================================
 * WiFiManager_Init
 *========================================================*/

void WiFiManager_Init(void)
{
    wifiConnected = false;

    lastHealthUploadTime = esp_timer_get_time() / 1000;

    previousState = SYSTEM_STATE_NORMAL;

    SupabaseClient_Init();
}

/*=========================================================
 * WiFiManager_Update
 *========================================================*/

void WiFiManager_Update(SystemState_t currentState,
                        const AlertStatus_t *alerts,
                        const SensorData_t *sensorData)
{
    if ((alerts == NULL) || (sensorData == NULL))
    {
        return;
    }

    CheckConnection();

    if (!wifiConnected)
    {
        return;
    }

    if (DetectImportantEvent(currentState, alerts))
    {
        SendPacket(currentState,
                   alerts,
                   sensorData);

        previousState = currentState;

        return;
    }

    int64_t currentTime = esp_timer_get_time() / 1000;

    if ((currentTime - lastHealthUploadTime) >= WIFI_HEALTH_UPLOAD_PERIOD_MS)
    {
        UploadHealthReport(currentState,
                           sensorData);

        lastHealthUploadTime = currentTime;
    }
}

/*=========================================================
 * WiFiManager_IsConnected
 *========================================================*/

bool WiFiManager_IsConnected(void)
{
    return wifiConnected;
}

/*=========================================================
 * CheckConnection
 *========================================================*/

static void CheckConnection(void)
{
    /*
     * Actual Wi-Fi connection handling
     * will be implemented later.
     */

    wifiConnected = true;
}

/*=========================================================
 * DetectImportantEvent
 *========================================================*/

static bool DetectImportantEvent(SystemState_t currentState,
                                 const AlertStatus_t *alerts)
{
    if (currentState != previousState)
    {
        return true;
    }

    if (alerts->faultDetected)
    {
        return true;
    }

    if (alerts->highTemperatureAlert)
    {
        return true;
    }

    if (alerts->alcoholAlert)
    {
        return true;
    }

    if (alerts->obstacleAlert)
    {
        return true;
    }

    if (alerts->vibrationAlert)
    {
        return true;
    }

    if (alerts->fatigueAlert)
    {
        return true;
    }

    return false;
}

/*=========================================================
 * UploadHealthReport
 *========================================================*/

static void UploadHealthReport(SystemState_t currentState,
                               const SensorData_t *sensorData)
{
    (void)currentState;
    (void)sensorData;

    /*
     * Send periodic vehicle health report.
     */
}

/*=========================================================
 * SendPacket
 *========================================================*/

static void SendPacket(SystemState_t currentState,
                       const AlertStatus_t *alerts,
                       const SensorData_t *sensorData)
{
    (void)currentState;
    (void)alerts;
    (void)sensorData;

   SupabaseClient_SendData(
    currentState,
    alerts,
    sensorData
  );
}