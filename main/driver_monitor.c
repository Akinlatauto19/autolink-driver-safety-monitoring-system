#include "driver_monitor.h"

#include "config.h"

#include <stddef.h>

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static void ClearAlerts(void);

static void CheckTemperature(const SensorData_t *sensorData);

static void CheckAlcohol(const SensorData_t *sensorData);

static void CheckVibration(const SensorData_t *sensorData);

static void CheckObstacle(const SensorData_t *sensorData);

static void CheckDriverFatigue(void);

static SystemState_t currentState = SYSTEM_STATE_NORMAL;

static AlertStatus_t alertStatus;


/*=========================================================
 * DriverMonitor_Init
 *========================================================*/
void DriverMonitor_Init(void)
{
    currentState = SYSTEM_STATE_NORMAL;

    alertStatus.highTemperatureAlert = false;
    alertStatus.alcoholAlert = false;
    alertStatus.vibrationAlert = false;
    alertStatus.obstacleAlert = false;
    alertStatus.fatigueAlert = false;
    alertStatus.faultDetected = false;
}

/*=========================================================
 * DriverMonitor_Update
 *========================================================*/
void DriverMonitor_Update(const SensorData_t *sensorData)
{
    ClearAlerts();

    CheckTemperature(sensorData);

    CheckAlcohol(sensorData);

    CheckVibration(sensorData);

    CheckObstacle(sensorData);

    CheckDriverFatigue();
}

/*=========================================================
 * DriverMonitor_GetSystemState
 *========================================================*/
SystemState_t DriverMonitor_GetSystemState(void)
{
    return currentState;
}

/*=========================================================
 * DriverMonitor_GetAlerts
 *========================================================*/
void DriverMonitor_GetAlerts(AlertStatus_t *alerts)
{
    if (alerts != NULL)
    {
        *alerts = alertStatus;
    }
}

/*=========================================================
 * ClearAlerts
 *========================================================*/
static void ClearAlerts(void)
{
    alertStatus.highTemperatureAlert = false;
    alertStatus.alcoholAlert = false;
    alertStatus.vibrationAlert = false;
    alertStatus.obstacleAlert = false;
    alertStatus.fatigueAlert = false;
    alertStatus.faultDetected = false;
}

/*=========================================================
 * CheckTemperature
 *========================================================*/
static void CheckTemperature(const SensorData_t *sensorData)
{
    if (sensorData->cabinTemperature >= TEMP_WARNING_THRESHOLD)
    {
        alertStatus.highTemperatureAlert = true;
    }
}

/*=========================================================
 * CheckAlcohol
 *========================================================*/
static void CheckAlcohol(const SensorData_t *sensorData)
{
    if (sensorData->alcoholLevel >= ALCOHOL_WARNING_THRESHOLD)
    {
        alertStatus.alcoholAlert = true;
    }
}

/*=========================================================
 * CheckVibration
 *========================================================*/
static void CheckVibration(const SensorData_t *sensorData)
{
    if (sensorData->vibrationMagnitude >= VIBRATION_WARNING_THRESHOLD)
    {
        alertStatus.vibrationAlert = true;
    }
}

/*=========================================================
 * CheckObstacle
 *========================================================*/
static void CheckObstacle(const SensorData_t *sensorData)
{
    if (sensorData->obstacleDistance <= WARNING_DISTANCE_CM)
    {
        alertStatus.obstacleAlert = true;
    }
}

/*=========================================================
 * CheckDriverFatigue
 *========================================================*/
static void CheckDriverFatigue(void)
{
    /*
     * Driver fatigue timer will be implemented later.
     */
}