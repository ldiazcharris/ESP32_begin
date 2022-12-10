#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdbool.h>

bool state = false;


void app_main(void)
{

    gpio_reset_pin(2);
    gpio_set_direction(2, GPIO_MODE_OUTPUT);

    while(1)
    {
        vTaskDelay(250 / portTICK_PERIOD_MS);
        state = !state;
        gpio_set_level(2, state);
    }

}

