#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP


#include <map>
#include "simulation/Simulator/types.hpp"
#include "simulation/Simulator/SimObject.hpp"
#include "simulation/Simulator/Clock.hpp"
#include "simulation/Microcontroller/Peripherals/AbstractPeripheral.hpp"
#include "simulation/Microcontroller/Pins/pin.hpp"

namespace simulator::microcontroller {

class Microcontroller : public simulator::SimObject {
private:
    simulator::Clock clock_;
    std::map<std::string, simulator::microcontroller::AbstractPeripheral> peripherals_; // According to SO, this should work and I should be able to store and use any peripheral (use references) 
    std::map<std::string, simulator::microcontroller::Pin&> pins_;

public:
    Microcontroller(std::string name, id_t id, simulator::Clock& clock) : 
        clock_{clock}
    {
        name_ = name;
        id_ = id;
    }

    void register_peripheral(simulator::microcontroller::AbstractPeripheral& p) {
        peripherals_.insert({p.name(), p});
        for (auto pin : p.pins()) {
            pins_.insert({p.name() + std::string(":") + pin.first, pin.second}); 
        }
    }



};


}

#endif