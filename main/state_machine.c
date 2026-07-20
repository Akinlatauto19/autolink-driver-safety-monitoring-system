#include "state_machine.h"

#include <stddef.h>
static SystemState_t currentState = SYSTEM_STATE_NORMAL;

/*=========================================================
 * StateMachine_Init
 *========================================================*/
void StateMachine_Init(void)
{
    currentState = SYSTEM_STATE_NORMAL;
}

/*=========================================================
 * StateMachine_Update
 *========================================================*/
void StateMachine_Update(const AlertStatus_t *alerts)
{
    if (alerts == NULL)
    {
        currentState = SYSTEM_STATE_FAULT;
        return;
    }

    /*==============================
     * Fault Detection
     *==============================*/
    if (alerts->faultDetected)
    {
        currentState = SYSTEM_STATE_FAULT;
    }

    /*==============================
     * Critical Conditions
     *==============================*/
    else if
    (
        (alerts->highTemperatureAlert &&
         alerts->obstacleAlert)

        ||

        (alerts->alcoholAlert &&
         alerts->obstacleAlert)

        ||

        alerts->vibrationAlert
    )
    {
        currentState = SYSTEM_STATE_CRITICAL;
    }

    /*==============================
     * Warning Conditions
     *==============================*/
    else if
    (
        alerts->highTemperatureAlert ||

        alerts->alcoholAlert ||

        alerts->obstacleAlert ||

        alerts->fatigueAlert
    )
    {
        currentState = SYSTEM_STATE_WARNING;
    }

    /*==============================
     * Normal
     *==============================*/
    else
    {
        currentState = SYSTEM_STATE_NORMAL;
    }
}

/*=========================================================
 * StateMachine_GetState
 *========================================================*/
SystemState_t StateMachine_GetState(void)
{
    return currentState;
}