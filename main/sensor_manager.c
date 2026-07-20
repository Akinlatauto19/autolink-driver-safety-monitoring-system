#include "sensor_manager.h"

static SensorData_t sensorData;

#include <stddef.h>
#include "config.h"

/*=========================================================
 * SensorManager_Init
 *========================================================*/
void SensorManager_Init(void)
{
    sensorData.cabinTemperature = 0.0f;
    sensorData.alcoholLevel = 0U;
    sensorData.vibrationMagnitude = 0U;
    sensorData.obstacleDistance = SAFE_DISTANCE_CM;
}

/*=========================================================
 * SensorManager_Update
 *========================================================*/
void SensorManager_Update(void)
{
    /* Sensor reading will be implemented later */
}

/*=========================================================
 * SensorManager_GetData
 *========================================================*/
void SensorManager_GetData(SensorData_t *data)
{
    if (data != NULL)
    {
        *data = sensorData;
    }
}