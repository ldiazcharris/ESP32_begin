/*
    Objetivo:
    Realizar el blink de un led.

    El DevKitC tiene un led el pin 1.
    El pin 1 es usado por la comunicación serial.
    No se pueden usar como led indicador y serial al tiempo.
*/

#include <stdio.h>             // Biblioteca estándar de C para entrada/salida
#include "driver/gpio.h"       // Biblioteca de funciones para interactuar con los pines GPIO
#include "freertos/FreeRTOS.h" // Biblioteca para programación multitarea en ESP32
#include "freertos/task.h"     // Biblioteca para crear tareas en ESP32

// Definir LED
#define led 1

void app_main(void)
{
    // Config led
    gpio_reset_pin(led);
    gpio_set_direction(led, GPIO_MODE_OUTPUT);

    while(1){
        gpio_set_level(led, 0);                 // led on
        vTaskDelay( 1000 / portTICK_PERIOD_MS); // delay
        gpio_set_level(led, 1);                 // led off
        vTaskDelay( 1000 / portTICK_PERIOD_MS); // delay
    }
}
