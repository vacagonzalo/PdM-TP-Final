/**
 * @file poxis_uart.h
 * @author Gonzalo Nahuel Vaca
 * @date 2021
 * @brief File containing the interface of a non-blocking UART library.
 *
 */

#ifndef poxis_uart_h
#define poxis_uart_h

#include "mbed.h"

/**
 * @brief It reports if the UART has the desired number of bytes to be read.
 *
 * @param[in] bytes The amount of bytes requested for reading.
 * @return True if the UART has at least the amount of bytes requested.
 */
bool in_poxisUART(uint32_t bytes);

/**
 * @brief It will read the desired amount of bytes from the UART.
 *
 * @param[in] bytes The amount of bytes to be read.
 * @return An array address with the readed value.
 * \warning{The reading operation is destructive, the value will no longer be in the UART.}
 * \warning{You can read an amount of bytes that surpass the last valid value, this library gives you this option in order to be able to implement a circular buffer.}
 * \warning{If you try to read an amount of bytes that surpass the file size, you will recive data until the EOF.}
 */
unsigned char* read_poxisUART(uint32_t bytes);

/**
 * @brief Sends data using the UART.
 *
 * @param[in] data The memory holding the data to be send.
 * @param[in] bytes The amount of bytes to be send.
 * @return True if the operation was successful.
 */
bool write_poxisUART(unsigned char* data, uint32_t bytes);

#endif