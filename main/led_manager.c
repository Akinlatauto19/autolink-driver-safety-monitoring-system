#include "led_manager.h"

#include "config.h"

#include "driver/gpio.h"

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static void TurnOffAllLeds(void);

/*=========================================================
 * LedManager_Init
 *========================================================*/

void LedManager_Init(void)
{
    gpio_reset_pin(GREEN_LED_GPIO);
    gpio_reset_pin(YELLOW_LED_GPIO);
    gpio_reset_pin(RED_LED_GPIO);

    gpio_set_direction(GREEN_LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(YELLOW_LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(RED_LED_GPIO, GPIO_MODE_OUTPUT);

    TurnOffAllLeds();
}

/*=========================================================
 * LedManager_Update
 *========================================================*/

void LedManager_Update(SystemState_t state)
{
    TurnOffAllLeds();

    switch(state)
    {
        case SYSTEM_STATE_NORMAL:

            gpio_set_level(GREEN_LED_GPIO, 1);

        break;

        case SYSTEM_STATE_WARNING:

            /*
             * Temporary:
             * Yellow ON.
             * Later this becomes NON-BLOCKING BLINK.
             */
            gpio_set_level(YELLOW_LED_GPIO, 1);

        break;

        case SYSTEM_STATE_CRITICAL:

            /*
             * Temporary:
             * Red ON.
             * Later this becomes FAST BLINK.
             */
            gpio_set_level(RED_LED_GPIO, 1);

        break;

        case SYSTEM_STATE_FAULT:

            /*
             * Fault remains solid RED.
             */
            gpio_set_level(RED_LED_GPIO, 1);

        break;

        default:

        break;
    }
}

/*=========================================================
 * TurnOffAllLeds
 *========================================================*/

static void TurnOffAllLeds(void)
{
    gpio_set_level(GREEN_LED_GPIO, 0);

    gpio_set_level(YELLOW_LED_GPIO, 0);

    gpio_set_level(RED_LED_GPIO, 0);
}