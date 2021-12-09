#pragma once
#ifndef AD_CONVERTER_HPP
#define AD_CONVERTER_HPP

#include <functional>
#include "simulation/components/peripheral.hpp"
#include "simulation/typedefs.hpp"

namespace uc {

class ad_converter : public uc::peripheral {
    private:
        std::function<void(uc::pin_state_t)> ad_complete_;
        uc::pin_state_t value_;

    public:
        ad_converter(const std::string& name, uc::pin& pin) :
            uc::peripheral{name}
        {
            add_pin("A/D", pin);
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
            // _value = ... SOMETHING ...;
            if (ad_complete_ != nullptr) {
                ad_complete_(value_);
            }
        }

};

}


#endif