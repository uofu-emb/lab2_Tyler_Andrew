
//here is the chickens
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"
#include "function.c"

int count = 0;
bool on = false;

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void blink_task(__unused void *params) {
    //this code checks to see if the pico is there
    hard_assert(cyw43_arch_init() == PICO_OK);
    //code executes forever on one thread of the processor
    while (true) {
        //turns on the LED
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
        //counts 11 seconds turns of led
        if (count++ % 11) on = !on;
        //delays the command so there is some time off.
        vTaskDelay(500);
    }
}


void main_task(__unused void *params) {
    //this creates the task of flashing the led.
    xTaskCreate(blink_task, "BlinkThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    
    //declares the char value for c
    char c;
    printf("look mum!");
    //assigns c value to what getchar value is
    while(c = getchar()) {
        //sees if the value is less then z or a and puts it so that there is
        if (c <= 'z' && c >= 'a') putchar(c - 32);
        else if (c >= 'A' && c <= 'Z') putchar(c + 32);
        else putchar(c);
    }
}

int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}
