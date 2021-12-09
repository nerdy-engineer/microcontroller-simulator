#pragma once
#ifndef TIMER_HPP
#define TIMER_HPP

#include "simulation/simulator/clock.hpp"



namespace uc {

class timer : public uc::peripheral{
    private:
    uc::clock* clock_src_;



    public:
    timer(const std::string& name, uc::clock& clock_source) :
        uc::peripheral{name},
        clock_src_{&clock_source}
    {

    }


};


}

#endif