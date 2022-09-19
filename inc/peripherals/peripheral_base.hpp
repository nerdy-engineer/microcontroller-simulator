#pragma once
#ifndef PERIPHERAL_BASE_HPP
#define PERIPHERAL_BASE_HPP

#include <list>
#include "clock.hpp"
#include "entity.hpp"
#include "state.hpp"


namespace simulator {
    namespace peripherals {

class PeripheralBase : public Entity {
    private:
    std::list<simulator::State&> state_variables_;
    // Clock& clock_source_;

    protected:
    PeripheralBase(Clock& clock_source) :
        state_variables_{}
        // clock_source_{clock_source}
    {
        clock_source.subscribe(*this);
    }



    public:
    
    std::list<simulator::State&>::const_iterator states_begin() const noexcept {
        return state_variables_.begin();
    }

    std::list<simulator::State&>::const_iterator states_end() const noexcept {
        return state_variables_.end();
    }

    void add_state_variable(simulator::State& variable) {
        state_variables_.push_back(variable);
    }

};

    }
}


#endif