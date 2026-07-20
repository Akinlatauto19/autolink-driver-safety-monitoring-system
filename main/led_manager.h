#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include "system_types.h"

void LedManager_Init(void);

void LedManager_Update(SystemState_t state);

#endif