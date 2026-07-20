#include "sh1107.h"

#include "i2c_manager.h"

#include <string.h>
#include "esp_check.h"

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static esp_err_t SH1107_SendCommand(uint8_t command);

static esp_err_t SH1107_SendData(const uint8_t *data,
                                  size_t length);

/*=========================================================
 * SH1107_SendCommand
 *========================================================*/

static esp_err_t SH1107_SendCommand(uint8_t command)
{
    uint8_t buffer[2];

    buffer[0] = SH1107_COMMAND;

    buffer[1] = command;

    return I2CManager_Write(SH1107_I2C_ADDRESS,
                            buffer,
                            sizeof(buffer));
}

/*=========================================================
 * SH1107_SendData
 *========================================================*/

static esp_err_t SH1107_SendData(const uint8_t *data,
                                 size_t length)
{
    uint8_t buffer[129];

    buffer[0] = SH1107_DATA;

    memcpy(&buffer[1],
           data,
           length);

    return I2CManager_Write(SH1107_I2C_ADDRESS,
                            buffer,
                            length + 1);
}

/*=========================================================
 * SH1107_Init
 *========================================================*/

esp_err_t SH1107_Init(void)
{
    ESP_ERROR_CHECK(SH1107_SendCommand(0xAE));   // Display OFF

    ESP_ERROR_CHECK(SH1107_SendCommand(0xDC));   // Display Start Line
    ESP_ERROR_CHECK(SH1107_SendCommand(0x00));

    ESP_ERROR_CHECK(SH1107_SendCommand(0x81));   // Contrast
    ESP_ERROR_CHECK(SH1107_SendCommand(0x7F));

    ESP_ERROR_CHECK(SH1107_SendCommand(0x20));   // Memory Address Mode
    ESP_ERROR_CHECK(SH1107_SendCommand(0x00));

    ESP_ERROR_CHECK(SH1107_SendCommand(0xA0));   // Segment Remap

    ESP_ERROR_CHECK(SH1107_SendCommand(0xC0));   // Scan Direction

    ESP_ERROR_CHECK(SH1107_SendCommand(0xA6));   // Normal Display

    ESP_ERROR_CHECK(SH1107_SendCommand(0xAF));   // Display ON

    return ESP_OK;
}
/*=========================================================
 * SH1107_Clear
 *========================================================*/

esp_err_t SH1107_Clear(void)
{
    uint8_t buffer[128] = {0};

    for(int page = 0; page < 16; page++)
    {
        SH1107_SendCommand(0xB0 + page);

        SH1107_SendCommand(0x00);

        SH1107_SendCommand(0x10);

        SH1107_SendData(buffer,
                        sizeof(buffer));
    }

    return ESP_OK;
}
/*=========================================================
 * SH1107_Update
 *========================================================*/

esp_err_t SH1107_Update(void)
{
    return ESP_OK;
}

/*=========================================================
 * SH1107_DrawString
 *========================================================*/

esp_err_t SH1107_DrawString(uint8_t x,
                            uint8_t y,
                            const char *text)
{
    (void)x;
    (void)y;
    (void)text;

    return ESP_OK;
}