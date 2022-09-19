#pragma once
#ifndef PIN_HPP
#define PIN_HPP

#include "state.hpp"
#include "peripherals/peripheral_base.hpp"
#include <vector>




namespace simulator {
    namespace peripherals {

template <typename T>
    requires VALID_STATE_TYPE
class PinBase : public PeripheralBase {
    protected:
    State pin_state_;

    public:
    PinBase(T initial_state) :
        PeripheralBase(),
        pin_state_{initial_state}
    {
        add_state_variable(pin_state_);
    }

    void write(T state) {
        pin_state_.set(state);
    }

    T read() const noexcept {
        return pin_state_.get<T>();
    }
};

class DigitalPin : public PinBase<bool> {
    private:

    public:
    DigitalPin(bool initial_state) :
        PinBase(initial_state)
    {

    }

    DigitalPin() : 
        DigitalPin(pin_state_t::OFF)
    {
        
    }

};

class AnalogPin : public PinBase<double> {
    private:


    public:
    AnalogPin(double initial_state) :
        PinBase(initial_state)
    {
        
    }

    AnalogPin() :
        PinBase(0.0)
    {

    }

};

    }
}

#endif