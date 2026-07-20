#ifndef SYSTEM_TYPES_H
#define SYSTEM_TYPES_H

#include <stdint.h>
#include <stdbool.h>

/*==========================================================
 * Vehicle Monitoring States
 *==========================================================*/
typedef enum
{
    SYSTEM_STATE_NORMAL = 0,
    SYSTEM_STATE_WARNING,
    SYSTEM_STATE_CRITICAL,
    SYSTEM_STATE_FAULT
} SystemState_t;

/*==========================================================
 * Sensor Data Structure
 *==========================================================*/
typedef struct
{
    float cabinTemperature;
    uint16_t alcoholLevel;
    uint16_t vibrationMagnitude;
    float obstacleDistance;

} SensorData_t;

/*==========================================================
 * Alert Status Structure
 *==========================================================*/
typedef struct
{
    bool highTemperatureAlert;
    bool alcoholAlert;
    bool vibrationAlert;
    bool obstacleAlert;
    bool fatigueAlert;
    bool faultDetected;

} AlertStatus_t;

#endif /* SYSTEM_TYPES_H */