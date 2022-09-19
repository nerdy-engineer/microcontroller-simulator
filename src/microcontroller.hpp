#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP

#include "microcontroller_base.hpp"
#include "pin.hpp"

using namespace simulator;
using namespace simulator::peripherals;

class Microcontroller : public simulator::MicrocontrollerBase{
    DigitalPin test_pin;

    Microcontroller() :
        MicrocontrollerBase(),
        test_pin{pin_state_t::OFF}
    {

    }

    void run() {
        
    }



};


#endif