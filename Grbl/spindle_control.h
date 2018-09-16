/*
 * spindle_control.h
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#ifndef SPINDLE_CONTROL_H_
#define SPINDLE_CONTROL_H_

#include "hal.h"

namespace grbl {

class SpindleControl {
public:
  enum Direction {
    CW = 0,
    CCW = 1
  };

  SpindleControl(
      hal::DigitalOutputPin& enable_pin,
      hal::DigitalOutputPin& direction_pin,
      hal::PwmPin& speed_pin,
      const uint32_t max_speed,
      const uint32_t min_speed);

  void Start(const float speed, const SpindleControl::Direction direction);
  void SetSpeed(const float speed);
  float GetSpeed();
  void SetDirection(const SpindleControl::Direction direction);
  float GetDirection();
  void Stop();
};


} /* namespace grbl */

#endif /* SPINDLE_CONTROL_H_ */
