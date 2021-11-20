#pragma once
#ifndef PIN_HPP
#define PIN_HPP

#include <functional>
#include "simulation/typedefs.hpp"


namespace uc {

class pin {
    public:
    enum pin_mode_t {
        high_z,
        input,
        output
    };


    private:
        pin_state_t state_;
        pin_mode_t mode_;
        std::function<void(uc::pin_state_t)> ad_complete_;

    public:
        pin( ) : 
        state_{0},
        mode_{pin_mode_t::high_z},
        ad_complete_{nullptr}
        {
            
        }


        pin_mode_t mode() {
            return mode_;
        }

        void mode(pin_mode_t pin_mode){
            mode_ = pin_mode;
        }

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
        


};

}

#endif