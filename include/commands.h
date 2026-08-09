#ifndef COMMANDS_H
#define COMMANDS_H


typedef struct 
{
    char name[20];
    void (*handler)(void);

} Command;

extern Command command_table[];
extern const int command_count;

void cmd_help(void);
void cmd_status(void);
void cmd_version(void);
void cmd_reset(void);

#endif 