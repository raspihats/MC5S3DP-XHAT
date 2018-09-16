/*
 * pwm_pin.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#include "pwm_pin.h"

namespace hal {

PwmPin::PwmPin(TIM_TypeDef* tim, const uint32_t channel) :
  tim_(tim),
  channel_(channel){

}

void PwmPin::SetFrequency(float frequency) {

}

void PwmPin::SetDutyCycle(float duty_cycle) {

}

} /* namespace hal */
