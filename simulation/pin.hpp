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

        uc::pin_state_t analog_read() {
            // This one needs to include some kind of processing delay before returning the _state value
            
            // Kick off a/d conversion
            start_ad_convert();

            // Wait for a/d conversion

            // Return a/d value when conversion has completed
        }

        void start_ad_convert() {
            // Start the A/D conversion
        }


        void attach_ad_complete_callback(std::function<void(uc::pin_state_t)> callback) {
            // Attach the "interrupt" callback
            ad_complete_ = callback;
        }
    
    private:
        void ad_complete() {
            // Get the state of the A/D pin
            // _state = ... SOMETHING ...;
            if (ad_complete_ != nullptr) {
                ad_complete_(state_);
            }
        }



};

}

#endif