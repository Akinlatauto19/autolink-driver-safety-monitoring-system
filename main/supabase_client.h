#ifndef SUPABASE_CLIENT_H
#define SUPABASE_CLIENT_H

#include "esp_err.h"
#include "sensor_manager.h"
#include "system_types.h"

esp_err_t SupabaseClient_Init(void);

esp_err_t SupabaseClient_SendData(
    SystemState_t state,
    const AlertStatus_t *alerts,
    const SensorData_t *sensorData
);

#endif