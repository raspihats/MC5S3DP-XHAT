/*
 * coolant_control.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#include "coolant_control.h"

namespace grbl {

CoolantControl::CoolantControl(
    hal::DigitalOutputPin& flood_pin,
    hal::DigitalOutputPin& mist_pin) :
      flood_pin_(flood_pin),
      mist_pin_(mist_pin) {

}

void CoolantControl::StartFlood() {
  flood_pin_.Set();
}

void CoolantControl::StartMist() {
  mist_pin_.Set();
}

void CoolantControl::Stop() {
  flood_pin_.Reset();
  flood_pin_.Set();
}

} /* namespace grbl */
