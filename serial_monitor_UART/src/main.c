/*
    Título: Srial_monitor_2
    Objetivo:
    Imprimir por serial un mensaje.
    Se usa la fución UART_Transmit.
    Entre cada impresión, se debe tener un tiempo de espera.
*/

#include <stdio.h>              // Biblioteca estándar de C para entrada/salida
#include <string.h>             // Biblioteca estándar de C para manejo de strings
#include "driver/gpio.h"        // Biblioteca de funciones para interactuar con los pines GPIO
#include "freertos/FreeRTOS.h"  // Biblioteca para programación multitarea en ESP32
#include "freertos/task.h"      // Biblioteca para crear tareas en ESP32
#include "driver/uart.h"        // Biblioteca para usar las funciones del UART del ESP32

#define tiempo      500
#define BUF_SIZE    1024

static void uart_init();

void app_main(void)
{
    char* string_test = "Hello World\n";
    uart_init();

    while(1){
        uart_write_bytes(UART_NUM_0, (const char*)string_test, strlen(string_test));
        vTaskDelay( tiempo / portTICK_PERIOD_MS);
    }
}

static void uart_init(){
    
    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_0, BUF_SIZE * 2, 0, 0, NULL, ESP_INTR_FLAG_IRAM));
    ESP_ERROR_CHECK(uart_param_config(UART_NUM_0, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_0, 1, 3, 22, 19));


}