#ifndef DRIVER_MONITOR_H
#define DRIVER_MONITOR_H

#include "system_types.h"

/*=========================================================
 * Public Functions
 *========================================================*/

void DriverMonitor_Init(void);

void DriverMonitor_Update(const SensorData_t *sensorData);

SystemState_t DriverMonitor_GetSystemState(void);

void DriverMonitor_GetAlerts(AlertStatus_t *alerts);



#endif /* DRIVER_MONITOR_H */