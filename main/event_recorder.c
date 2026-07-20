#include <stddef.h>

#include "event_recorder.h"

/*=========================================================
 * Private Variables
 *========================================================*/

static SystemState_t previousState = SYSTEM_STATE_NORMAL;

/*=========================================================
 * EventRecorder_Init
 *========================================================*/

void EventRecorder_Init(void)
{
    previousState = SYSTEM_STATE_NORMAL;
}

/*=========================================================
 * EventRecorder_Update
 *========================================================*/

void EventRecorder_Update(SystemState_t currentState,
                          const AlertStatus_t *alerts,
                          const SensorData_t *sensorData)
{
    (void)alerts;
    (void)sensorData;

    /*
     * Event logging logic will be implemented later.
     */

    previousState = currentState;
}