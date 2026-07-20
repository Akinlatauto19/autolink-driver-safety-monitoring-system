#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#include "esp_err.h"
#include "driver/i2c_master.h"

#include <stddef.h>
#include <stdint.h>

/*=========================================================
 * Public Functions
 *========================================================*/

esp_err_t I2CManager_Init(void);

i2c_master_bus_handle_t I2CManager_GetBus(void);

esp_err_t I2CManager_Write(uint8_t deviceAddress,
                           const uint8_t *data,
                           size_t length);

#endif /* I2C_MANAGER_H */