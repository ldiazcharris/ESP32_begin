#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/touch_pad.h"
#include "driver/gpio.h"

#define led 26  // Usar led (interno: 1, externo, 26 por ejemplo)

void led_config(void){
    if (led == 1 ) gpio_reset_pin(led);
    gpio_set_direction(led, GPIO_MODE_OUTPUT);
}

void app_main()
{
    led_config();                   // Config led
    // Inicializar el subsistema de pines táctiles
    touch_pad_init();
    // Configurar los pines táctiles que se van a utilizar
    touch_pad_config(TOUCH_PAD_NUM0, 0);
    while(1)
    {
        // Leer el estado de los pines táctiles
        uint16_t touch_value;
        touch_pad_read(TOUCH_PAD_NUM0, &touch_value);
        printf("Touch pad 0: %d\n", touch_value);
        // Encender led de acuerdo al tactil
        if (touch_value > 400){
            gpio_set_level(led, 1);
        }else{
            gpio_set_level(led, 0);
        }
        // Esperar 100 ms antes de leer de nuevo
        //vTaskDelay(pdMS_TO_TICKS(100));
        vTaskDelay( 100 / portTICK_PERIOD_MS);
    }
}
