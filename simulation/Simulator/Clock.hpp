#pragma once
#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <string>
#include "simulation/Simulator/types.hpp"
#include "simulation/Simulator/SimObject.hpp"

namespace simulator {

class Clock : public simulator::SimObject {
private:
    size_t ticker_;


public:
    Clock(std::string name, id_t id) :
        ticker_{0}
        {
            name_ = name;
            id_ = id;
        }


    void tick() {
        ticker_++;
    }

    size_t get() {
        return ticker_;
    }

    };


}

#endif