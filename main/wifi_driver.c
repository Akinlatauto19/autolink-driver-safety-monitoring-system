#include "wifi_driver.h"

#include "config.h"

#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"

#include "nvs_flash.h"

#include "esp_wifi.h"
#include "esp_event.h"

/*=========================================================
 * Private Variables
 *========================================================*/

static const char *TAG = "WiFiDriver";

static bool wifiConnected = false;

/*=========================================================
 * Wi-Fi Event Group
 *========================================================*/

static EventGroupHandle_t wifiEventGroup;

#define WIFI_CONNECTED_BIT BIT0

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static void WiFiEventHandler(void *arg,
                             esp_event_base_t eventBase,
                             int32_t eventId,
                             void *eventData);

/*=========================================================
 * WiFiDriver_Init
 *========================================================*/

void WiFiDriver_Init(void)
{
    wifiEventGroup = xEventGroupCreate();

    ESP_ERROR_CHECK(
        nvs_flash_init());

    ESP_ERROR_CHECK(
        esp_netif_init());

    ESP_ERROR_CHECK(
        esp_event_loop_create_default());

    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg =
        WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(
        esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(
        esp_event_handler_register(
            WIFI_EVENT,
            ESP_EVENT_ANY_ID,
            &WiFiEventHandler,
            NULL));

    ESP_ERROR_CHECK(
        esp_event_handler_register(
            IP_EVENT,
            IP_EVENT_STA_GOT_IP,
            &WiFiEventHandler,
            NULL));

    wifi_config_t wifiConfig = {0};

     strncpy((char *)wifiConfig.sta.ssid,
        WIFI_SSID,
        sizeof(wifiConfig.sta.ssid));

     strncpy((char *)wifiConfig.sta.password,
        WIFI_PASSWORD,
        sizeof(wifiConfig.sta.password));

     wifiConfig.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;

    ESP_ERROR_CHECK(
        esp_wifi_set_mode(
            WIFI_MODE_STA));

    ESP_ERROR_CHECK(
        esp_wifi_set_config(
            WIFI_IF_STA,
            &wifiConfig));

    ESP_ERROR_CHECK(
        esp_wifi_start());

        ESP_LOGI(TAG, "Connecting to %s...", WIFI_SSID);

      EventBits_t bits =
         xEventGroupWaitBits(
          wifiEventGroup,
          WIFI_CONNECTED_BIT,
          pdFALSE,
          pdTRUE,
          pdMS_TO_TICKS(15000));

     if (bits & WIFI_CONNECTED_BIT)
     {
       ESP_LOGI(TAG, "Wi-Fi Connected Successfully.");
     }
     else
     {
      ESP_LOGE(TAG, "Connection Timeout.");
     }

     ESP_LOGI(TAG,
             "Connecting to %s...",
             WIFI_SSID);
}

/*=========================================================
 * WiFiDriver_IsConnected
 *========================================================*/

bool WiFiDriver_IsConnected(void)
{
    return wifiConnected;
}

/*=========================================================
 * WiFiEventHandler
 *========================================================*/

static void WiFiEventHandler(void *arg,
                             esp_event_base_t eventBase,
                             int32_t eventId,
                             void *eventData)
{
    if (eventBase == WIFI_EVENT &&
        eventId == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
    }

    else if (eventBase == WIFI_EVENT &&
             eventId == WIFI_EVENT_STA_DISCONNECTED)
    {
        wifiConnected = false;

        xEventGroupClearBits(
            wifiEventGroup,
            WIFI_CONNECTED_BIT);

        ESP_LOGI(TAG,
                 "WiFi Disconnected. Reconnecting...");

        esp_wifi_connect();
    }

    else if (eventBase == IP_EVENT &&
             eventId == IP_EVENT_STA_GOT_IP)
    {
        wifiConnected = true;

        xEventGroupSetBits(
            wifiEventGroup,
            WIFI_CONNECTED_BIT);

        ip_event_got_ip_t *event =
        (ip_event_got_ip_t *)eventData;

        ESP_LOGI(TAG,
                  "Connected.");

        ESP_LOGI(TAG,
                 "IP Address: " IPSTR,
        IP2STR(&event->ip_info.ip));
    }
}