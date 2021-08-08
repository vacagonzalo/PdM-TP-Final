#pragma once

struct Sarwate {
  unsigned char polynomial;
  unsigned char *table;
};

void init_sarwate(struct Sarwate *crc, unsigned char polynomial, unsigned char *table);
unsigned char buildCRC8(struct Sarwate *crc, unsigned int *bufferPtr,
                        unsigned int bufferLenght);