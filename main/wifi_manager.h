#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <stdbool.h>

#include "system_types.h"

void WiFiManager_Init(void);

void WiFiManager_Update(SystemState_t currentState,
                        const AlertStatus_t *alerts,
                        const SensorData_t *sensorData);

bool WiFiManager_IsConnected(void);

#endif /* WIFI_MANAGER_H */