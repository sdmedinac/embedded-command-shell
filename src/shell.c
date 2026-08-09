#include <stdio.h>
#include <string.h>
#include "../include/shell.h"
#include "../include/led.h"
#include "../include/adc.h"
#include "../include/commands.h"
#include <stdlib.h>
#include <time.h>


void run_shell(void)
{
    srand(time(NULL));

    char buffer[50], *command, *argument;
    int index;

    printf("Embedded Command Shell\n");

    while(1){
        
        index = -1;

        printf("\n> ");
        fgets(buffer, sizeof(buffer), stdin);
        
        command = strtok(buffer, " ");
        argument = strtok(NULL, " ");

        for(int i = 0; i < 4; i++){

            if(strcmp(command, command_table[i].name) == 0){

                index = i;
                break;
            }
        }

        if(index != -1){
            
            command_table[index].handler();
            continue;
        }

        if(strcmp(command, "exit\n") == 0){
        
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
        else{

            printf("Unknown Command\n");
        }
    }
    
}