/*
 * coolant_control.h
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#ifndef COOLANT_CONTROL_H_
#define COOLANT_CONTROL_H_

#include "hal.h"

namespace grbl {

class CoolantControl {
public:
  CoolantControl(
      hal::DigitalOutputPin& flood_pin,
      hal::DigitalOutputPin& mist_pin);

  void StartFlood();
  void StartMist();
  void Stop();
private:
  hal::DigitalOutputPin& flood_pin_;
  hal::DigitalOutputPin& mist_pin_;
};

} /* namespace grbl */

#endif /* COOLANT_CONTROL_H_ */
