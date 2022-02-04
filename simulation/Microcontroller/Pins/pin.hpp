#pragma once
#ifndef PIN_HPP
#define PIN_HPP

#include <string>
#include "simulation/Simulator/types.hpp"
#include "simulation/Simulator/SimObject.hpp"

namespace simulator::microcontroller {
// Not sure how to make this work with ADC and DAC configurations...
enum PinState_t {
    LOW=0,
    HIGH=1
};

enum PinMode_t {
    INPUT,
    INPUT_PULLUP,
    INPUT_PULLDOWN,
    OUTPUT,
    OUTPUT_PUSH_PULL,
    OPEN_DRAIN,
    ADC,
    DAC
};

class Pin : public simulator::SimObject {
private:
    std::string name_;
    PinState_t pin_state_;
    PinMode_t pin_mode_;

public:
    Pin(std::string name) :
        name_{name},
        pin_mode_{PinMode_t::OPEN_DRAIN},
        pin_state_{PinState_t::LOW} 
    {
        
    }
    
    PinState_t state(PinState_t s) {
        switch (pin_mode_) {
            case PinMode_t::INPUT:
            case PinMode_t::INPUT_PULLUP:
            case PinMode_t::INPUT_PULLDOWN:
            case PinMode_t::ADC:
            case PinMode_t::DAC:
                return pin_state_;
            case PinMode_t::OPEN_DRAIN:
                if (s == PinState_t::HIGH) {
                    return pin_state_;
                }
                break;
        }
        pin_state_ = s;
        return s;
    }
    
    PinState_t state() {
        return pin_state_;
    }

    PinMode_t mode() {
        return pin_mode_;
    }

};


}

#endif