/*
 * digital_output_pin.h
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#ifndef HAL_DIGITAL_OUTPUT_PIN_H_
#define HAL_DIGITAL_OUTPUT_PIN_H_

#include "stm32f4xx_ll_gpio.h"

namespace hal {

class DigitalOutputPin {
public:
  DigitalOutputPin(GPIO_TypeDef* port, const uint32_t pin_mask, const bool inverted=false);
  bool Read();
  void Write(const bool state);
  void Set();
  void Reset();
private:
  GPIO_TypeDef *port_;
  uint32_t pin_mask_;
  bool inverted_;
};

} /* namespace hal */

#endif /* HAL_DIGITAL_OUTPUT_PIN_H_ */
