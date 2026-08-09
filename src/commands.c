#include <stdio.h>
#include "../include/commands.h"
#include "../include/led.h"

Command command_table[] = {
    
    {"help\n", cmd_help},
    {"status\n", cmd_status},
    {"version\n", cmd_version},
    {"reset\n", cmd_reset}
};

void cmd_help(void)
{
    printf("\nAvailable Commands: \n");
    printf("help\nstatus\nversion\nreset\n");
    printf("led on\nled off\nadc read\nexit\n");
}

void cmd_status(void)
{
    printf("SYSTEM OK\n");

    if(led_get_state()){
        
        printf("LED: ON\n");
    }
    else{

        printf("LED: OFF\n");
    }

}

void cmd_version(void)
{
    printf("\nFirmware Version 1.0.0\n");
}

void cmd_reset(void)
{
    led_off();
    printf("System Reset\n");
}
