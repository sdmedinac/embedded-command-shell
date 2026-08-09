# Embedded Command Shell

A firmware-oriented command shell written in C designed to practice command parsing, command dispatch tables, function pointers, state machines, and modular software architecture.

---

## Overview

Embedded Command Shell is a modular command-line application developed in C that simulates the architecture commonly found in embedded systems and UART-based debugging consoles.

The project implements:

- Command parsing using strings
- Command dispatching through function pointers
- A shell state machine
- Modular peripheral abstraction
- Independent command handlers
- LED and ADC simulation modules

The main goal of the project is to learn software design concepts commonly used in Firmware Engineering.

---

## Features

- Command parsing with `strtok()`
- Input sanitization using `strcspn()`
- Command dispatch table
- Function pointers
- Shell state machine
- LED simulation module
- ADC simulation module
- Modular architecture
- Error handling
- Git version control

---

## Available Commands

### System Commands


help
status
version
state
reset
exit


### LED Commands


led on
led off


### ADC Commands

adc read

## Example Execution


Embedded Command Shell

> help

Available Commands:
help
status
version
state
reset
led on
led off
adc read
exit

> led on

LED ON

> status

SYSTEM OK
LED: ON

> adc read

ADC VALUE: 3210

> state

Current State: IDLE

> reset

System Reset

> exit

Goodbye


## Project Structure

embedded-command-shell/

├── include/
│   ├── adc.h
│   ├── commands.h
│   ├── led.h
│   └── shell.h
│
├── src/
│   ├── adc.c
│   ├── commands.c
│   ├── led.c
│   ├── main.c
│   └── shell.c
│
├── docs/
│
├── README.md
└── .gitignore
```

---

## Software Architecture

User
 |
 v
Shell
 |
 v
Command Parser
 |
 v
Command Dispatch Table
 |
 v
Command Handlers
 |------ LED Module
 |
 |------ ADC Module
```


## State Machine

The shell implements a simple state machine:

SHELL_IDLE
      |
      v
SHELL_PROCESSING
      |
      +------> SHELL_IDLE

SHELL_ERROR
      |
      v
SHELL_IDLE
```

### States

| State | Description |
|---------|-------------|
| SHELL_IDLE | Waiting for user input |
| SHELL_PROCESSING | Processing a command |
| SHELL_ERROR | Invalid command detected |

---

## Concepts Practiced

### C Programming

- Functions
- Arrays
- Strings
- Structures
- Enumerations
- Pointers
- Function Pointers
- Modular Programming

### Firmware Engineering

- Command Parsing
- Command Dispatch Tables
- State Machines
- Peripheral Abstraction
- Error Handling
- Modular Software Architecture

---

## Future Improvements

- UART integration using STM32
- Real GPIO LED control
- Real ADC interface
- Configuration commands
- Logging system
- Persistent configuration storage

---

## Author

**Samuel David Medina Contreras**

Electronic Engineering Student  
Universidad del Magdalena

---

## License

This project was developed for educational and portfolio purposes.