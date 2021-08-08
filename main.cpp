#include "PinNames.h"
#include "mbed.h"
#include "modules/crc8/crc8.h"

Serial pc(USBTX, USBRX);

int main()
{
    struct Sarwate crc;
    unsigned char polynomial = 0x1C;
    unsigned char table[256];
    init_sarwate(&crc, polynomial, table);
    
    pc.printf("\n\n");

    pc.printf("Polynomial: %X\n", crc.polynomial);

    pc.printf("Generated table:\n");
    for(int i = 0; i < 256; i++)
    {
        pc.printf("%X | ", crc.table[i]);
    }
    pc.printf("\n");

    char buffer[11];
    while (true) {
        pc.gets(buffer, 11);
        pc.printf("msg: %s\n",buffer);
        pc.printf("msg crc: 0x%X\n", (unsigned int)buffer[9]);
        unsigned int payload[9];
        for(int i = 0; i < 9; i++)
        {
            payload[i] = (unsigned int)buffer[i];
        }
        unsigned char computedCRC = buildCRC8(&crc, payload,9);
        pc.printf("computed crc: 0x%X\n", computedCRC);
    }
}

