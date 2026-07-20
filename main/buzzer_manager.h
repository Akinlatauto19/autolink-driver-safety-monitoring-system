#ifndef BUZZER_MANAGER_H
#define BUZZER_MANAGER_H

#include "system_types.h"

/*=========================================================
 * Public Functions
 *========================================================*/

void BuzzerManager_Init(void);

void BuzzerManager_Update(SystemState_t state);

#endif /* BUZZER_MANAGER_H */