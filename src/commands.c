#include <stdio.h>
#include <string.h>
#include "../include/commands.h"
#include "../include/led.h"
#include "../include/adc.h"
#include "../include/shell.h"

Command command_table[] = {
    
    {"help", cmd_help},
    {"status", cmd_status},
    {"version", cmd_version},
    {"reset", cmd_reset},
    {"led", cmd_led},
    {"adc", cmd_adc},
    {"state", cmd_state}
};

const int command_count = sizeof(command_table) / sizeof(command_table[0]);

void cmd_help(char *argument)
{
    printf("\nAvailable Commands: \n");
    printf("help\nstatus\nversion\nreset\n");
    printf("led on\nled off\nadc read\nexit\n");
}

void cmd_status(char *argument)
{
    printf("\nSYSTEM OK\n");

    if(led_get_state()){
        
        printf("LED: ON\n");
    }
    else{

        printf("LED: OFF\n");
    }

}

void cmd_version(char *argument)
{
    printf("\nFirmware Version 1.0.0\n");
}

void cmd_reset(char *argument)
{
    led_off();
    printf("System Reset\n");
}

void cmd_led(char *argument)
{
    if(argument == NULL){

        printf("Missing Argument\n");
    }
    else if(strcmp(argument, "on") == 0){

        led_on();
        printf("LED ON\n");
    }
    else if(strcmp(argument, "off") == 0){
        
        led_off();
        printf("LED OFF\n");
    }
    else{

        printf("Invalid Argument\n");
    }

}

void cmd_adc(char *argument)
{
    if(argument == NULL){
        
        printf("Missing Argument\n");
    }
    else if(strcmp(argument, "read") == 0){
    
        printf("ADC VALUE: %d\n", adc_read());    
    }
    else{

        printf("Invalid Argument\n");
    }
    
}

void cmd_state(char *argument)
{   
    printf("Current State: ");

    if(get_shell_state() == SHELL_IDLE){

        printf("IDLE\n");
    }
    else if(get_shell_state() == SHELL_PROCESSING){

        printf("PROCESSING\n");
    }
    else if(get_shell_state() == SHELL_ERROR){

        printf("ERROR\n");
    }
}
