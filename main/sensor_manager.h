#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <stdbool.h>

#include "system_types.h"

/*=========================================================
 * Public Functions
 *========================================================*/

void SensorManager_Init(void);

void SensorManager_Update(void);

void SensorManager_GetData(SensorData_t *data);

#endif /* SENSOR_MANAGER_H */