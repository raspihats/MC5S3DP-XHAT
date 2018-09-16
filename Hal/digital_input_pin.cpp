/*
 * digital_input_pin.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#include "digital_input_pin.h"

namespace hal {

DigitalInputPin::DigitalInputPin(GPIO_TypeDef* port, const uint32_t pin_mask, const bool inverted) :
    port_(port),
    pin_mask_(pin_mask),
    inverted_(inverted) {

}

bool DigitalInputPin::Read() {
  return (bool)LL_GPIO_IsInputPinSet(port_, pin_mask_) ^ inverted_;
}

} /* namespace hal */
