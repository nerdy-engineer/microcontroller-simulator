#pragma once
#ifndef SIMULATION_STATE_HPP
#define SIMULATION_STATE_HPP

#include <map>
#include <string>
#include <stdexcept>
#include "simulation/typedefs.hpp"
#include "simulation/components/pin.hpp"


namespace uc {

class simulation_state {
    private:
        uc::timestep_t t_;
        std::map<std::string, uc::pin&> states_;
    

    public:
        simulation_state(uc::timestep_t timestamp) : 
            t_{timestamp},
            states_{}
        {
            // simulation state constructor
        }

        void add_field(std::string_view name, uc::pin& pin) {
            // Not sure if this is optimal
            states_.emplace(name, pin);
        }

        uc::pin& get(const std::string& name) const noexcept {
            return states_.at(name);
        }

        uc::timestep_t timestep() const noexcept {
            return t_;
        }

        void timestep(uc::timestep_t timestamp) {
            t_ = timestamp;
        }

};

}

#endif