#include "mbed.h"
#include "modules/crc8/crc8.h"
#include "modules/poxis_uart/poxis_uart.h"

static DigitalOut GREEN(LED1);
static DigitalOut RED(LED3);

int main() {
    unsigned char polynomial = 0x1C;
    Sarwate crc;
    init_sarwate(&crc, polynomial);

    unsigned char crc_byte = 0x00;

    unsigned char* reader = NULL;

    // msg for academic purposes
    printf("polynomial: %X\n", polynomial);
    printf("TABLE\n");
    for(uint32_t i = 0; i < sizeof(crc.table); ++i)
    {
        printf("%X ", crc.table[i]);
    }
    printf("\n");
    // end of msg
    
    while (true) {
        if(in_poxisUART(10)) {
            GREEN = !GREEN;
            reader = read_poxisUART(10);
            crc_byte = buildCRC8(&crc, reader, 10);
            RED.write(crc_byte != reader[10]);
            write_poxisUART(reader, 10);
        }
    }
}
