/*
 * pwm_pin.h
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#ifndef HAL_PWM_PIN_H_
#define HAL_PWM_PIN_H_

#include "stm32f4xx_ll_tim.h"

namespace hal {

class PwmPin {
public:
  PwmPin(TIM_TypeDef* tim, const uint32_t channel);
  void SetFrequency(float frequency);
  void SetDutyCycle(float duty_cycle);
private:
  TIM_TypeDef* tim_;
  uint32_t channel_;
};

} /* namespace hal */

#endif /* HAL_PWM_PIN_H_ */
