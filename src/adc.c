#include <stdlib.h>
#include "../include/adc.h"

int adc_read(void)
{
    return rand() % 4096;
}