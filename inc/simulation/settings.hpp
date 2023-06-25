#pragma once
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <cinttypes>
#include "simulation\time.hpp"

namespace simulation {

struct settings {
    tstamp_t t_start;   // Time to start saving the simulation
    tstamp_t t_end;     // Time to exit the simulation
    // Think of the sim_dt as a game-tick
    tstep_t sim_dt;     // Update rate of the simulation (as stored in the output file)
    // Think of the proc_dt as a redstone-tick
    tstep_t proc_dt;    // Update rate of the processor
    
};

}


#endif // SETTINGS_HPP