#pragma once
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP


#include <memory>
#include <vector>
#include "settings.hpp"
#include "world.hpp"
#include "node.hpp"
#include "component_base.hpp"
#include "time.hpp"


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

    void run() {
        tstamp_t t = tstart;
        while (t < tend) {
            update(sim_dt);
            t++;
        }
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