#pragma once
#ifndef PERIPHERAL_HPP
#define PERIPHERAL_HPP

#include <map>
#include "simulation/pin.hpp"
#include "simulation/typedefs.hpp"


namespace uc {

class peripheral {
    private:
        std::string name_;
        std::map<std::string, uc::pin&> pins_;   // Stores any pins associated with the peripheral (not sure about the std::less<>, SO says it's necessary to be able to use std::string_view as a lookup)

        peripheral() :
            name_{},
            pins_{}
        {
            
        }

    public:

        virtual void sim_update(uc::timestep_t dt) = 0;
        
        void add_pin(const std::string& peripheral_pin_name, uc::pin& pin) {
            pins_[peripheral_pin_name] = pin.route(this);
        }


};


}

#endif