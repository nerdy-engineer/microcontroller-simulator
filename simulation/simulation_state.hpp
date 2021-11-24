#pragma once
#ifndef SIMULATION_STATE_HPP
#define SIMULATION_STATE_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <format>
#include "simulation/typedefs.hpp"
#include "simulation/pin.hpp"



namespace uc {

class simulation_state {
    private:
        uc::timestep_t t_;
        std::map<std::string_view, uc::pin_state_t> states_;
    

    public:
        simulation_state(uc::timestep_t timestamp) : 
            t_{timestamp},
            states_{}
        {
            // simulation state constructor
        }

        void add_field(const std::string_view name, const uc::pin& pin) {
            // Not sure if this is optimal
            states_.insert(name, pin);
        }

        uc::pin& get(const std::string_view name) {
            return states_.at(name);
        }

        uc::timestep_t timestep(){
            return t_;
        }

        void timestep(uc::timestep_t timestamp) {
            t_ = timestamp;
        }

};


}

#endif