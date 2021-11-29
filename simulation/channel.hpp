#pragma once
#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "simulation/typedefs.hpp"


namespace uc {

class channel {
    private:
        uc::freq_t carrier_;

    public:
        channel(uc::freq_t carrier_frequency) :
            carrier_{carrier_frequency}
        {

        }
};



}

#endif