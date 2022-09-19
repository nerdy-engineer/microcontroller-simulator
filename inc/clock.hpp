#pragma once
#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <stdint.h>
#include <list>
#include "entity.hpp"

namespace simulator {

class Clock : public Entity {
    private:
    uint32_t frequency_;
    double dt_;
    bool run_;
    std::list<Entity&> driving_;
    uint16_t divider_;
    uint16_t ticks_;

    public:
    Clock(uint32_t frequency, Clock& clock) :
        Clock(frequency)
    {
        clock.subscribe(*this);
    }

    Clock(uint32_t frequency) :
        frequency_{frequency},
        dt_{1/frequency},
        run_{true},
        driving_{},
        divider_{1}
    {

    }

    inline void clock_divider(uint16_t divider) noexcept {
        divider_ = divider;
    }

    inline uint16_t clock_divider() const noexcept {
        return divider_;
    }


    void drive () {
        update(dt_);
    }

    void update (double dt) {
        if (ticks_++ < divider_) {
            if (run_) {
                // If the clock is active, do the update thing
                for (auto driven : driving_) {
                    driven.update(dt);
                }

            } else {
                // If the clock is not active, do not do the update thing

            }
        }
    }


    inline void frequency(uint32_t frequency) noexcept {
        frequency_ = frequency;
    }

    inline uint32_t frequency() const noexcept {
        return frequency_;
    }

    inline void stop() {
        run_ = false;
    }

    inline void run() {
        run_ = true;
    }

    inline void subscribe(Entity& driven) {
        driving_.push_back(driven);
    }


};


}

#endif