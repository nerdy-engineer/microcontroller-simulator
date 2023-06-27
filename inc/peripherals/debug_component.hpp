#pragma once
#ifndef DEBUG_COMPONENT_HPP
#define DEBUG_COMPONENT_HPP

#include <iostream>
#include <cmath>
#include "time.hpp"
#include "component_base.hpp"

namespace simulation {

class debug : public component_base {
public:
    debug(tstep_t print_freq) :
        acc{0},
        delta{print_freq},
        last_print{0}
    {

    }

    virtual void tick(tstep_t dt) override {
        if ((acc - floor(acc))>=dt) {
            if (acc - last_print > delta) {
                std::cout << "Time: " << acc << " seconds\n";
                last_print = acc;
            }
        }
        acc += dt;
    }

private:
    tstep_t acc;
    tstep_t delta;
    tstep_t last_print;

};

}


#endif // DEBUG_COMPONENT_HPP