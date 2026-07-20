#ifndef SH1107_H
#define SH1107_H

#include "esp_err.h"

#include <stdint.h>

/*=========================================================
 * SH1107 Definitions
 *========================================================*/

#define SH1107_I2C_ADDRESS      0x3C

#define SH1107_COMMAND          0x00

#define SH1107_DATA             0x40

/*=========================================================
 * Public Functions
 *========================================================*/

esp_err_t SH1107_Init(void);

esp_err_t SH1107_Clear(void);

esp_err_t SH1107_Update(void);

esp_err_t SH1107_DrawString(uint8_t x,
                            uint8_t y,
                            const char *text);

#endif /* SH1107_H */