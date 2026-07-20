#include "buzzer_manager.h"

#include "config.h"

#include "driver/gpio.h"

/*=========================================================
 * Private Function Prototypes
 *========================================================*/

static void BuzzerOff(void);

/*=========================================================
 * BuzzerManager_Init
 *========================================================*/

void BuzzerManager_Init(void)
{
    gpio_reset_pin(BUZZER_GPIO);

    gpio_set_direction(BUZZER_GPIO,
                       GPIO_MODE_OUTPUT);

    BuzzerOff();
}

/*=========================================================
 * BuzzerManager_Update
 *========================================================*/

void BuzzerManager_Update(SystemState_t state)
{
    BuzzerOff();

    switch(state)
    {
        case SYSTEM_STATE_NORMAL:

            /*
             * Silent
             */

        break;

        case SYSTEM_STATE_WARNING:

            /*
             * Temporary:
             * Continuous ON
             *
             * Later becomes slow beep.
             */
            gpio_set_level(BUZZER_GPIO,1);

        break;

        case SYSTEM_STATE_CRITICAL:

            /*
             * Temporary:
             * Continuous ON
             *
             * Later becomes rapid beeps.
             */
            gpio_set_level(BUZZER_GPIO,1);

        break;

        case SYSTEM_STATE_FAULT:

            /*
             * Temporary:
             * Continuous ON
             */
            gpio_set_level(BUZZER_GPIO,1);

        break;

        default:

        break;
    }
}

/*=========================================================
 * BuzzerOff
 *========================================================*/

static void BuzzerOff(void)
{
    gpio_set_level(BUZZER_GPIO,0);
}