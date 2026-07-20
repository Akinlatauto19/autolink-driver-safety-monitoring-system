#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <stdbool.h>

#include "system_types.h"

/*=========================================================
 * Public Functions
 *========================================================*/

void DisplayManager_Init(void);

void DisplayManager_Update(
    SystemState_t currentState,
    const AlertStatus_t *alerts,
    const SensorData_t *sensorData,
    bool wifiConnected);

#endif /* DISPLAY_MANAGER_H */
