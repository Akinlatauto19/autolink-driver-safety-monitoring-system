#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "system_types.h"

/*=========================================================
 * Public Functions
 *========================================================*/

void StateMachine_Init(void);

void StateMachine_Update(const AlertStatus_t *alerts);

SystemState_t StateMachine_GetState(void);

#endif /* STATE_MACHINE_H */