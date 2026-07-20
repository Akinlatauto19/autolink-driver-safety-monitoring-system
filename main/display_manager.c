#include "display_manager.h"

#include "sh1107.h"

#include <stddef.h>

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static void DrawDashboard(SystemState_t currentState,
                          const AlertStatus_t *alerts,
                          const SensorData_t *sensorData,
                          bool wifiConnected);

/*=========================================================
 * DisplayManager_Init
 *========================================================*/

void DisplayManager_Init(void)
{
    SH1107_Init();

    SH1107_Clear();
}

/*=========================================================
 * DisplayManager_Update
 *========================================================*/

void DisplayManager_Update(SystemState_t currentState,
                           const AlertStatus_t *alerts,
                           const SensorData_t *sensorData,
                           bool wifiConnected)
{
    if(sensorData == NULL)
    {
        return;
    }

    if(alerts == NULL)
    {
        return;
    }

    DrawDashboard(currentState,
                  alerts,
                  sensorData,
                  wifiConnected);
}

/*=========================================================
 * DrawDashboard
 *========================================================*/

static void DrawDashboard(SystemState_t currentState,
                          const AlertStatus_t *alerts,
                          const SensorData_t *sensorData,
                          bool wifiConnected)
{
    (void)currentState;
    (void)alerts;
    (void)sensorData;
    (void)wifiConnected;

    /*
     * Dashboard drawing implementation
     * will populate the OLED using the SH1107 driver.
     */
}