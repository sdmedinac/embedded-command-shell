#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/shell.h"
#include "../include/led.h"
#include "../include/adc.h"
#include "../include/commands.h"

static ShellState shell_state = SHELL_IDLE;

void run_shell(void)
{
    srand(time(NULL));

    char buffer[50], *command, *argument;
    int index;

    printf("Embedded Command Shell\n");

    while(1){
        
        shell_state = SHELL_IDLE;
        index = -1;

        printf("\n> ");
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        buffer[strcspn(buffer, "\n")] = '\0';

        
        command = strtok(buffer, " ");
        argument = strtok(NULL, " ");

        if(command == NULL){
            
            shell_state = SHELL_IDLE;
            continue;
        }

        for(int i = 0; i < command_count; i++){

            if(strcmp(command, command_table[i].name) == 0){

                index = i;
                break;
            }
        }

        if(index != -1){
            
            command_table[index].handler(argument);
            shell_state = SHELL_IDLE;
            continue;
        }

        if(strcmp(command, "exit") == 0){
        
            printf("Goodbye\n");
            break;
        }
        else{

            shell_state = SHELL_ERROR;
            printf("Unknown Command\n");
            shell_state = SHELL_IDLE;
        }
    }   

}

ShellState get_shell_state(void)
{
    return shell_state;
}
