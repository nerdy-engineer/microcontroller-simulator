#pragma once
#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include "simulation/components/microcontroller.hpp"
#include "simulation/components/task.hpp"
#include "simulation/components/pin.hpp"
#include "simulation/components/gpio.hpp"
#include "simulation/components/pwm.hpp"
#include "simulation/components/ad_converter.hpp"
#include "simulation/components/timer.hpp"
#include "simulation/components/uart.hpp"

namespace uc {


void digitalWrite(uc::pin& pin, uc::pin_state_t state) {
    if (state) {
        pin.state_ = ~static_cast<uc::pin_state_t>(0);
    } else {
        pin.state_ = 0;
    }
}

uc::pin_state_t digitalRead(uc::pin& pin) {
    if (pin.state_ > ~static_cast<uc::pin_state_t>(0)/2) {
        return true;
    } else {
        return false;
    }
}







}


#endif