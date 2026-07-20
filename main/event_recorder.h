#ifndef EVENT_RECORDER_H
#define EVENT_RECORDER_H

#include "system_types.h"

/*=========================================================
 * Public Functions
 *========================================================*/

void EventRecorder_Init(void);

void EventRecorder_Update(SystemState_t currentState,
                          const AlertStatus_t *alerts,
                          const SensorData_t *sensorData);

#endif /* EVENT_RECORDER_H */