#pragma once
#ifndef PWM_HPP
#define PWM_HPP

#include "simulation/components/pin.hpp"
#include "simulation/components/peripheral.hpp"
#include "simulation/components/timer.hpp"
#include "simulation/typedefs.hpp"

namespace uc{

class pwm : public uc::peripheral {
    private:
        double duty_cycle_;
        uc::timer* timer_src_;

    public:
        pwm(const std::string& name, uc::timer& timer) :
            uc::peripheral{name},
            duty_cycle_{0},
            timer_src_{&timer}
        {
            
        }

};

    
}

#endif