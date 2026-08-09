#ifndef COMMANDS_H
#define COMMANDS_H


typedef struct 
{
    char name[20];
    void (*handler)(void);

} Command;

extern Command command_table[];

void cmd_help(void);
void cmd_status(void);
void cmd_version(void);
void cmd_reset(void);

#endif 