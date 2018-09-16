/*
 * digital_output_pin.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#include "digital_output_pin.h"

namespace hal {

DigitalOutputPin::DigitalOutputPin(GPIO_TypeDef* port, uint32_t const pin_mask, const bool inverted) :
  port_(port),
  pin_mask_(pin_mask),
  inverted_(inverted) {

}

bool DigitalOutputPin::Read() {
  return (bool)LL_GPIO_IsOutputPinSet(port_, pin_mask_) ^ inverted_;
}

void DigitalOutputPin::Write(const bool state) {
  if(state ^ inverted_) {
    LL_GPIO_SetOutputPin(port_, pin_mask_);
  }
  else {
    LL_GPIO_ResetOutputPin(port_, pin_mask_);
  }
}

void DigitalOutputPin::Set() {
  Write(true);
}

void DigitalOutputPin::Reset() {
  Write(false);
}

} /* namespace hal */
