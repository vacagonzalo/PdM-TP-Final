#include "crc8.h"

void generate_table(Sarwate *crc);

void init_sarwate(Sarwate *crc, unsigned char polynomial,
                  unsigned char *table) {
  crc->polynomial = polynomial;
  crc->table = table;
  generate_table(crc);
}

unsigned char buildCRC8(Sarwate *crc, unsigned char *bufferPtr,
                        unsigned int bufferLenght) {
  unsigned int i;
  unsigned char crcValue = 0x00;
  unsigned int tableIndex;

  for (i = 0; i < bufferLenght; i++) {
    tableIndex = crcValue ^ (bufferPtr[i] & 0xFF);
    crcValue = crc->table[tableIndex];
  }
  return crcValue;
}

void generate_table(Sarwate *crc) {
  const unsigned int TABLE_LENGTH = 0X100;
  const unsigned int OCTET_MASK = 0x000000FF;

  unsigned char crcValue;
  unsigned int i, j;

  for (i = 0; i < TABLE_LENGTH; i++) {
    crcValue = i;
    for (j = 0; j < 8; j++) {
      if (crcValue & 0x80) {
        crcValue = (crcValue << 1);
        crcValue = crcValue ^ crc->polynomial;
      } else {
        crcValue = crcValue << 1;
      }
    }
    crc->table[i] = crcValue & OCTET_MASK;
  }
}