#pragma once
#ifndef PIN_HPP
#define PIN_HPP

#include <functional>
#include <vector>
#include <type_traits>
#include "simulation/typedefs.hpp"
#include "simulation/components/microcontroller.hpp"
#include "simulation/components/peripheral.hpp"
#include "simulation/components/gpio.hpp"

namespace uc {

class pin {
    public:
    enum pin_mode_t {
        high_z,
        input,
        output
    };
    friend void digitalWrite(uc::pin&, uc::pin_state_t);
    friend uc::pin_state_t digitalRead(uc::pin&);

    private:
        const std::string name_;
        pin_state_t state_;
        pin_mode_t mode_;
        std::function<void(uc::pin_state_t)> ad_complete_;
        std::vector<uc::peripheral&> peripherals_;
        uc::microcontroller microcontroller_;

    public:
        // Needs to be non-copyable
        pin(const std::string& name) : 
        name_{name},
        state_{0},
        mode_{pin_mode_t::high_z}
        {
            add_peripheral(uc::gpio(name, *this));
        }

        pin(const pin&) = delete;

        const std::string& name() const noexcept {
            return name_;
        }

        pin& route(uc::peripheral* peripheral) {
            // Connect the pin to a peripheral
            peripherals_.push_back(*peripheral);
            return *this;
        }

        void route(uc::microcontroller& microcontroller) {
            microcontroller_ = microcontroller;
        }

        pin_mode_t mode() const noexcept {
            return mode_;
        }

        void mode(pin_mode_t pin_mode){
            mode_ = pin_mode;
        }

        template <class T, typename=std::enable_if_t<std::is_base_of_v<uc::peripheral, T>>>
        void add_peripheral(T& peripheral) {
            peripherals_.push_back(peripheral);
        }

    /*
        void digital_write(bool state) {
            // Set the pin state to full-on or full-off based on a boolean state
            if (state) {
                state_ = ~static_cast<uc::pin_state_t>(0);
            } else {
                state_ = 0;
            }
        }

        bool digital_read() {
            if (state_ > ~static_cast<uc::pin_state_t>(0)/2) {
                return true;
            } else {
                return false;
            }
        }

        void PWM_write(pin_state_t value) {
            state_ = value;
        }
    */
        
        

};

}

#endif