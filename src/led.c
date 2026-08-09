#include "../include/led.h"

static int led_state;

void led_on(void)
{
    led_state = 1;
}

void led_off(void)
{
    led_state = 0;
}

int led_get_state(void)
{
    return led_state;
}