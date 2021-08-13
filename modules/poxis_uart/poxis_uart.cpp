#include "poxis_uart.h"

static unsigned char file_buffer[0x100]  = { 0x00 };
static unsigned char read_buffer[0x100]  = { 0x00 };
static unsigned char user_buffer[0x100]  = { 0x00 };

static uint32_t read_buffer_index = 0;

static BufferedSerial serial_port(USBTX, USBRX);

bool in_poxisUART(uint32_t bytes)
{
    if(uint32_t num = serial_port.read(file_buffer, sizeof(file_buffer))) {
        for(uint32_t i = 0; i < num; ++i, ++read_buffer_index)
        {
            if(read_buffer_index > sizeof(read_buffer)) {
                read_buffer_index = 0;    
            }
            read_buffer[read_buffer_index] = file_buffer[i];
        }
        return read_buffer_index >= bytes;
    }
    return false;
}

unsigned char* read_poxisUART(uint32_t bytes)
{
    if(bytes > sizeof(read_buffer)) {
        bytes = sizeof(read_buffer);
    }
    uint32_t i, j = 0;
    
    for(i = 0; i < bytes; ++i)
    {
        user_buffer[i] = read_buffer[i];
    }

    for(i = 0, j = bytes; j < sizeof(read_buffer); ++i, ++j)
    {
        read_buffer[i] = read_buffer[j];
    }
    read_buffer_index = read_buffer_index - bytes;

    return user_buffer;
}

bool write_poxisUART(unsigned char* data, uint32_t bytes)
{
    if(bytes > sizeof(file_buffer)) {
        return false;
    }
    serial_port.write(data, bytes);
    return true;
}