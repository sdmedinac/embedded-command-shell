#ifndef COMMANDS_H
#define COMMANDS_H


typedef struct 
{
    char name[20];
    void (*handler)(char *argument);

} Command;

extern Command command_table[];
extern const int command_count;

void cmd_help(char *argument);
void cmd_status(char *argument);
void cmd_version(char *argument);
void cmd_reset(char *argument);
void cmd_led(char *argument);
void cmd_adc(char *argument);
void cmd_state(char *argument);

#endif 