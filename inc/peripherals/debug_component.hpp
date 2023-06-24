#pragma once
#ifndef DEBUG_COMPONENT_HPP
#define DEBUG_COMPONENT_HPP

#include <iostream>
#include "time.hpp"
#include "component_base.hpp"

namespace simulation {

class debug : component_base {
public:
    debug() {

    }

    virtual void tick(tstep_t dt) override {
        acc += dt;
        if (acc-dt < floor(acc) && acc > floor(acc)) {
            std::cout << "Time: " << acc << " seconds";
        }
    }

private:
    double acc;

};

}


#endif // DEBUG_COMPONENT_HPP