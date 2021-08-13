#include "mbed.h"
#include "modules/crc8/crc8.h"
#include "modules/poxis_uart/poxis_uart.h"

static DigitalOut GREEN(LED1);
static DigitalOut RED(LED3);

int main() {
    Sarwate crc;
    unsigned char polynomial = 0x1C;
    unsigned char table[256]; 
    init_sarwate(&crc, polynomial, table);

    unsigned char crc_byte = 0x00;

    unsigned char* reader;

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
