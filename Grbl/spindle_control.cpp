/*
 * spindle_control.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: fcos
 */

#include "spindle_control.h"

namespace grbl {

SpindleControl::SpindleControl(
    hal::DigitalOutputPin& enable_pin,
    hal::DigitalOutputPin& direction_pin,
    hal::PwmPin& speed_pin,
    const uint32_t max_speed,
    const uint32_t min_speed) {

}


void SpindleControl::Start(const float speed, const SpindleControl::Direction direction) {

}

void SpindleControl::SetSpeed(const float speed) {

}

float SpindleControl::GetSpeed() {

}

void SpindleControl::SetDirection(const SpindleControl::Direction direction) {

}

float SpindleControl::GetDirection() {

}

void SpindleControl::Stop() {

}


} /* namespace grbl */
