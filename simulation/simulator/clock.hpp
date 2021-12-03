#pragma once
#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <mutex>
#include <chrono>
#include <cmath>
#include "simulation/typedefs.hpp"


namespace uc {

class clock {
    private:
        uc::freq_t frequency_;
        uc::timestep_t counts_;
        std::mutex m_;

    public:
    clock(uc::freq_t frequency) :
        frequency_{frequency},
        counts_{0}
    {

    }

    uc::timestep_t time() {
        uc::timestep_t r;
        while(!m_.try_lock()) {
            // Wait until you can acquire the lock
        }
        r = counts_;
        m_.unlock();
        return r;
    }

    void step(uc::pulse_t dt) {
        while (!m_.try_lock()) {
            // Wait until you can acquire the lock
        }
        // increment counts_ by the appropriate number of counts equivalent to dt
        counts_ += static_cast<uc::timestep_t>(std::ceil((dt/static_cast<double>(frequency_))));
        m_.unlock();
    }

};


}


#endif