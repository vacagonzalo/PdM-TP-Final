#ifndef poxis_uart_h
#define poxis_uart_h

#include "mbed.h"

bool in_poxisUART(uint32_t bytes);

unsigned char* read_poxisUART(uint32_t bytes);

bool write_poxisUART(unsigned char* data, uint32_t bytes);

#endif