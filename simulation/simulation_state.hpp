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
        uc::timestep_t _t;
        std::map<std::string, uc::reporting_state_t> _states;
    

    public:
        simulation_state(uc::timestep_t timestamp) : 
            _t{timestamp}
        {
            // simulation state constructor
        }

        void add_field(const std::string& name, const uc::pin& pin) {
            // Not sure if this is optimal
            _states[name] = pin;
        }

        uc::pin& get(const std::string& name) {
            auto value = _states.find(name);
            if (value == _states.end()) {
                throw std::out_of_range(std::format("Simulation state does not contain key {}", name));
            }
            return value->second;
        }

        uc::timestep_t timestep(){
            return _t;
        }

        void timestep(uc::timestep_t timestamp) {
            _t = timestamp;
        }

};


}

#endif