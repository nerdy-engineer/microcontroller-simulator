#pragma once
#ifndef PERIPHERAL_HPP
#define PERIPHERAL_HPP

#include <map>
#include "simulation/pin.hpp"
#include "simulation/typedefs.hpp"


namespace uc {

class peripheral {
    private:
        std::map<std::string, uc::pin> pins_;   // Stores any pins associated with the peripheral


    public:
    peripheral() :
        pins_{}
    {

    }

    virtual void sim_update(uc::timestep_t dt) = 0;

    // Make sure to create a factory function to create a given
    // peripheral that will add the appropriate pins

};


}

#endif