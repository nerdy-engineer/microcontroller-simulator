#pragma once
#ifndef GPIO_HPP
#define GPIO_HPP

#include "simulation/components/peripheral.hpp"
#include "simulation/typedefs.hpp"
#include "simulation/components/pin.hpp"


namespace uc {

class gpio : uc::peripheral {
    private:


    public:
        gpio(const std::string& name, uc::pin& pin) :
            uc::peripheral{name}
        {
            pins_.emplace(name, pin);
        }

};




}

#endif