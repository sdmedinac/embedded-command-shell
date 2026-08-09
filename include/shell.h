#ifndef SHELL_H
#define SHELL_H

typedef enum
{
    SHELL_IDLE,
    SHELL_PROCESSING,
    SHELL_ERROR

} ShellState;


void run_shell(void);
ShellState get_shell_state(void);

#endif