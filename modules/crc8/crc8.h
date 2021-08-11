#pragma once

typedef struct {
  unsigned char polynomial;
  unsigned char *table;
} Sarwate;

void init_sarwate(Sarwate *crc, unsigned char polynomial, unsigned char *table);

unsigned char buildCRC8(Sarwate *crc, unsigned char *bufferPtr,
                        unsigned int bufferLenght);