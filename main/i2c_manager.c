#include "i2c_manager.h"

#include "config.h"

static i2c_master_bus_handle_t i2cBus = NULL;

/*=========================================================
 * I2CManager_Init
 *========================================================*/

esp_err_t I2CManager_Init(void)
{
    i2c_master_bus_config_t config =
    {
        .clk_source = I2C_CLK_SRC_DEFAULT,

        .i2c_port = I2C_NUM_0,

        .scl_io_num = I2C_SCL_GPIO,

        .sda_io_num = I2C_SDA_GPIO,

        .glitch_ignore_cnt = 7,

        .flags.enable_internal_pullup = true
    };

    return i2c_new_master_bus(&config,
                              &i2cBus);
}

/*=========================================================
 * I2CManager_GetBus
 *========================================================*/

i2c_master_bus_handle_t I2CManager_GetBus(void)
{
    return i2cBus;
}

/*=========================================================
 * I2CManager_Write
 *========================================================*/

esp_err_t I2CManager_Write(uint8_t deviceAddress,
                           const uint8_t *data,
                           size_t length)
{
    if (i2cBus == NULL)
    {
        return ESP_FAIL;
    }

    i2c_device_config_t deviceConfig =
    {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = deviceAddress,
        .scl_speed_hz = 400000
    };

    i2c_master_dev_handle_t device;

    ESP_ERROR_CHECK(i2c_master_bus_add_device(i2cBus,
                                              &deviceConfig,
                                              &device));

    esp_err_t ret = i2c_master_transmit(device,
                                        data,
                                        length,
                                        -1);

    i2c_master_bus_rm_device(device);

    return ret;
}