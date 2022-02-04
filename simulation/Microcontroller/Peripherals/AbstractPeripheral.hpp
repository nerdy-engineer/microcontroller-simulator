#pragma once
#ifndef ABSTRACTPERIPHERAL_HPP
#define ABSTRACTPERIPHERAL_HPP

#include "simulation/Simulator/types.hpp"
#include "simulation/Simulator/SimObject.hpp"

namespace simulator::microcontroller {

class AbstractPeripheral : public simulator::SimObject {
private:
    std::map<std::string, simulator::microcontroller::Pin> pins_;



public:


    const std::map<std::string, simulator::microcontroller::Pin>& pins() const {
        return pins_;
    }


};

}

#endif