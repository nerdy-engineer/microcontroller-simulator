#pragma once
#ifndef MICROCONTROLLER_BASE_HPP
#define MICROCONTROLLER_BASE_HPP


#include <list>
#include "peripheral_base.hpp"
#include "clock.hpp"
#include "entity.hpp"


namespace simulator {

class MicrocontrollerBase : public Entity {
    private:
    std::list<peripherals::PeripheralBase&> peripherals_;
    std::list<State&> state_variables_;
    std::list<Clock&> clocks_;


    public:
    MicrocontrollerBase() :
        peripherals_{},
        state_variables_{}
    {

    }

    void add_peripheral(peripherals::PeripheralBase& p) {
        peripherals_.push_back(p);
        state_variables_.insert(state_variables_.end(), p.states_begin(), p.states_end());
    }

    virtual void run();         // This is the user's microcontroller code that will get run during the simulation

    void delay(time_t duration) const noexcept {
        // Implementation required
    }

    void update(double dt) {
        // Step through the loop once
        run();

        // There is no peripheral update loop because all peripherals require a clock
        // Updating the clock will update all peripherals attached to the clock.
        for (auto clock : clocks_) {
            clock.update(dt);
        }
    }

};

}

#endif