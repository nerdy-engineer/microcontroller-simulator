#pragma once
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <vector>
#include <chrono>
#include "simulation/rf/carrier.hpp"
#include "simulation/components/microcontroller.hpp"
#include "simulation/components/task.hpp"
#include "simulation/typedefs.hpp"


namespace uc {

class simulator {
    private:
        std::vector<uc::microcontroller&> microcontrollers_;
        std::vector<uc::rf::carrier&> carrier_frequencies_;
        uc::pulse_t dt_;


    public:
        simulator(std::vector<uc::microcontroller&> microcontrollers, uc::pulse_t dt) :
            carrier_frequencies_{},
            dt_{dt}
        {
            microcontrollers_ = microcontrollers;
        }

        void add_microcontroller(uc::microcontroller& uc) {
            microcontrollers_.push_back(uc);
        }

        void simStep() {
            // Record the state


            // Increase the step counter
            for (auto uc : microcontrollers_) {
                uc->simStep();
            }
        }

};


}

#endif