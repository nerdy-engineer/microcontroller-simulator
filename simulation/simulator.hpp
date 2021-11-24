#pragma once
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <vector>
#include <chrono>
#include "simulation/microcontroller.hpp"
#include "simulation/task.hpp"
#include "simulation/typedefs.hpp"


namespace uc {

class simulator {
    private:
        std::vector<uc::microcontroller&> microcontrollers_;
        std::chrono::duration dt_;


    public:
        simulator(std::vector<uc::microcontroller>& microcontrollers, std::chrono::duration dt) :
            microcontrollers_{microcontrollers},
            dt_{dt}
        {

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

}


}

#endif