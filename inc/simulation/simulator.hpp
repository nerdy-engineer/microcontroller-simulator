#pragma once
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP


#include <memory>
#include <vector>
#include "simulation\settings.hpp"
#include "simulation\world.hpp"
#include "simulation\node.hpp"
#include "simulation\component_base.hpp"
#include "simulation\time.hpp"


namespace simulation {

class simulator {
public:
    simulator(settings& s, std::shared_ptr<world> w) :
        tstart{s.t_start},
        tend{s.t_end},
        sim_dt{s.sim_dt},
        proc_dt{s.proc_dt},
        w_{w}
    {

    }

    void update(tstep_t dt) {
        w_->tick(dt);
    }

private:
    tstamp_t tstart, tend;
    tstep_t sim_dt, proc_dt;
    std::shared_ptr<world> w_;



};

}






#endif // SIMULATOR_HPP