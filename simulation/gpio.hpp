#pragma once
#ifndef GPIO_HPP
#define GPIO_HPP

#include "simulation/peripheral.hpp"
#include "simulation/typedefs.hpp"
#include "simulation/pin.hpp"


namespace uc {

class gpio : uc::peripheral {
    private:


    public:
        gpio(const std::string& name, uc::pin& pin) :
            name_{name}
        {
            pins_[name] = pin;
        }

};




}

#endif