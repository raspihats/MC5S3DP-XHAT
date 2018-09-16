/*
 * serial_port.h
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#ifndef SERIAL_PORT_H_
#define SERIAL_PORT_H_

#include "stm32f4xx_ll_usart.h"

namespace hal {

class SerialPort {
public:
  SerialPort(const uint32_t baudrate);
  bool Read(uint8_t& byte);
  bool Write(uint8_t byte);
};

} /* namespace hal */

#endif /* SERIAL_PORT_H_ */
