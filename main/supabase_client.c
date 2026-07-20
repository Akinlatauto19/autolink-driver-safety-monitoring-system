#include "supabase_client.h"
#include "supabase_config.h"

#include "esp_log.h"
#include "esp_http_client.h"

#include <stdio.h>
#include <string.h>

static const char *TAG = "SUPABASE";

/*=========================================================
 * SupabaseClient_Init
 *========================================================*/

esp_err_t SupabaseClient_Init(void)
{
    ESP_LOGI(TAG, "Supabase Client Initialized");
    ESP_LOGI(TAG, "URL: %s", SUPABASE_URL);

    return ESP_OK;
}

/*=========================================================
 * SupabaseClient_SendData
 *========================================================*/

esp_err_t SupabaseClient_SendData(
    SystemState_t state,
    const AlertStatus_t *alerts,
    const SensorData_t *sensorData)
{
    if ((alerts == NULL) || (sensorData == NULL))
    {
        return ESP_ERR_INVALID_ARG;
    }

    char json[512];

    snprintf(json,
             sizeof(json),
             "{"
             "\"temperature\":%.2f,"
             "\"alcohol\":%u,"
             "\"vibration\":%u,"
             "\"obstacle\":%.2f,"
             "\"system_state\":%d"
             "}",
             sensorData->cabinTemperature,
             sensorData->alcoholLevel,
             sensorData->vibrationMagnitude,
             sensorData->obstacleDistance,
             state);

    esp_http_client_config_t config =
    {
        .url = SUPABASE_URL
              "/rest/v1/driver_data"
    };

    esp_http_client_handle_t client =
        esp_http_client_init(&config);

    esp_http_client_set_method(client,
                               HTTP_METHOD_POST);

    esp_http_client_set_header(client,
                               "apikey",
                               SUPABASE_API_KEY);

    esp_http_client_set_header(client,
                               "Authorization",
                               "Bearer " SUPABASE_API_KEY);

    esp_http_client_set_header(client,
                               "Content-Type",
                               "application/json");

    esp_http_client_set_header(client,
                               "Prefer",
                               "return=minimal");

    esp_http_client_set_post_field(client,
                                   json,
                                   strlen(json));

    esp_err_t err =
        esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG,
                 "Upload Successful. Status = %d",
                 esp_http_client_get_status_code(client));
    }
    else
    {
        ESP_LOGE(TAG,
                 "Upload Failed: %s",
                 esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);

    return err;
}