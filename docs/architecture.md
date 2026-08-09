# Embedded Command Shell Architecture

## Overview

Embedded Command Shell follows a modular firmware-oriented architecture.

## Software Structure


main.c
 |
 v
shell.c
 |
 v
commands.c
 |------ led.c
 |
 |------ adc.c


## Module Responsibilities

### shell.c

- User input
- Command parsing
- State machine
- Command dispatching

### commands.c

- Command table
- Command handlers

### led.c

- LED state management
- LED control functions

### adc.c

- ADC simulation
- ADC readings

## Implemented Concepts

- Command Parsing
- Function Pointers
- Command Dispatch Table
- State Machine
- Modular Architecture
```