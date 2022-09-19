#pragma once
#ifndef TIMER_HPP
#define TIMER_HPP

#include "peripheral_base.hpp"
#include "clock.hpp"

namespace simulator::peripherals {


template <typename T>
class Timer : public PeripheralBase {
    private:
    T count_;
    T max_;




    public:
    Timer(Clock& clock_source) :
        count_{0},
        max_{!0x00}
    {
        clock_source.subscribe(*this);
    }

    void update(double dt) {
        if (count_ == max_) {
            count_ = 0;
        }
        if (count_ < max_) {
            count_++;
        }
    }


};


}

#endif