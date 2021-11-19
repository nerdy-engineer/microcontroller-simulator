#pragma once
#ifndef PIN_HPP
#define PIN_HPP

#include <functional>
#include "typedefs.hpp"


namespace uc {

class pin {
    public:
    enum pin_mode_t {
        high_z,
        input,
        output
    };


    private:
        pin_state_t _state;
        pin_mode_t _mode;
        std::function<void(uc::pin_state_t)> _ad_complete;

    public:
        pin( ) : 
        _state{0},
        _mode{pin_mode_t::high_z},
        _ad_complete{nullptr}
        {
            
        }


        pin_mode_t mode() {
            return _mode;
        }

        void mode(pin_mode_t pin_mode){
            _mode = pin_mode;
        }

        void digital_write(bool state) {
            // Set the pin state to full-on or full-off based on a boolean state
            if (state) {
                _state = ~static_cast<uc::pin_state_t>(0);
            } else {
                _state = 0;
            }
        }

        bool digital_read() {
            if (_state > ~static_cast<uc::pin_state_t>(0)/2) {
                return true;
            } else {
                return false;
            }
        }

        void PWM_write(pin_state_t value) {
            _state = value;
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
            _ad_complete = callback;
        }
    
    private:
        void ad_complete() {
            // Get the state of the A/D pin
            // _state = ... SOMETHING ...;
            if (_ad_complete != nullptr) {
                _ad_complete(_state);
            }
        }



};

}

#endif