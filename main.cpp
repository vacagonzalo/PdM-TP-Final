#include "mbed.h"
#include "modules/crc8/crc8.h"

#define BUFFER_SIZE 0x100
#define MINIMUM_FRAME_SIZE 9

static BufferedSerial serial_port(USBTX, USBRX);
static DigitalOut GREEN(LED1);
static DigitalOut RED(LED3);

int main() {
  unsigned char serial_buffer[BUFFER_SIZE] = {0};
  unsigned char frame[BUFFER_SIZE] = {0};
  uint32_t frame_index = 0;

  Sarwate crc;
  unsigned char polynomial = 0x1C;
  unsigned char table[256];
  init_sarwate(&crc, polynomial, table);

  while (true) {
    if (uint32_t num = serial_port.read(serial_buffer, sizeof(serial_buffer))) {
      GREEN = !GREEN;
      for (uint32_t i = 0; i < num; ++i) {
        frame[frame_index] = serial_buffer[i];
        ++frame_index;
      }
      if (frame_index > MINIMUM_FRAME_SIZE) {
        unsigned char computedCRC = buildCRC8(&crc, frame, (frame_index - 1));
        //printf("frame CRC: %X\n", frame[frame_index - 1]);
        //printf("computedCRC: %X\n", computedCRC);
        if (computedCRC != frame[frame_index - 1]) {
          RED.write(1);
        } else {
          RED.write(0);
        }
        serial_port.write(frame, frame_index);
        frame_index = 0;
      }
    }
  }
}
