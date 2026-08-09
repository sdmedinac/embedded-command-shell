#include <stdio.h>
#include <string.h>
#include "../include/shell.h"
#include "../include/led.h"
#include "../include/adc.h"
#include <stdlib.h>
#include <time.h>


void run_shell(void)
{
    srand(time(NULL));

    char buffer[50], *command, *argument;

    printf("Embedded Command Shell\n");

    while(1){
        
        printf("\n> ");
        fgets(buffer, sizeof(buffer), stdin);
        
        command = strtok(buffer, " ");
        argument = strtok(NULL, " ");
 
        if(strcmp(command, "help\n") == 0){
        
            printf("\nAvailable Commands:\n");
            printf("help\n");
            printf("status\n");
            printf("version\n");
            printf("led on\n");
            printf("led off\n");
            printf("adc read\n");
            printf("reset\n");
            printf("exit\n");

        }
        else if(strcmp(command, "status\n") == 0){
        
            printf("System OK\n");
            
            if(led_get_state()){

                printf("LED: ON\n");
            }
            else{

                printf("LED: OFF\n");
            }
        }
        else if(strcmp(command, "exit\n") == 0){
        
            printf("Goodbye\n");
            break;
        }
        else if(strcmp(command, "led") == 0){
            
            if(strcmp(argument, "off\n") == 0){

                led_off();
                printf("\nLED OFF\n");
            }
            else if(strcmp(argument, "on\n") == 0){
                
                led_on();
                printf("\nLED ON\n");
            }
            else{
                
                printf("\nInvalid argument\n");
            }
        }
        else if(strcmp(command, "led\n") == 0){
            
            printf("\nMissing argument\n");
        }
        else if(strcmp(command, "adc") == 0){
        
            if(strcmp(argument, "read\n") == 0){
                
                printf("ADC VALUE: %d\n", adc_read());
            }
            else{
                
                printf("Invalid argument\n");
            }
        }
        else if(strcmp(command, "adc\n") == 0){

            printf("\nMissing argument\n");
        }
        else if(strcmp(command, "version\n") == 0){
            
            printf("Firmware Version 1.0.0\n");
        }
        else if(strcmp(command, "reset\n") == 0){
            
            led_off();
            printf("System Reset\n");
        }
        else{

            printf("Unknown Command\n");
        }
    }
    
}