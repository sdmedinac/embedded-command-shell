#include <stdio.h>
#include <string.h>

typedef struct {

    char name[20];
    void (*handler)(void);

} Command;

void cmd_status(void);
void cmd_help(void);
void cmd_version(void);
void cmd_reset(void);

int main(void)
{
    Command commands[] = {
        {"help\n", cmd_help},
        {"status\n", cmd_status},
        {"version\n", cmd_version},
        {"reset\n", cmd_reset}
    };
    
    char user_input[20];
    int index = -1;

    printf("Enter a command: ");
    fgets(user_input, sizeof(user_input), stdin);

    for(int i = 0; i < 4; i++){

        if(strcmp(user_input, commands[i].name) == 0){

            index = i;
            break;
        }
    }

    if(index == -1){

        printf("Command not found\n");
    }
    else{

        printf("Command found\n");
        commands[index].handler();
    }


    return 0;
}

void cmd_status(void)
{
    printf("SYSTEM OK\n");
}

void cmd_help(void)
{
    printf("help\n");
}

void cmd_version(void)
{
    printf("version\n");
}


void cmd_reset(void)
{
    printf("restarting\n");
}