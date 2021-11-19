#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <format>
#include <vector>

#include "typedefs.hpp"



namespace uc {


class microcontroller {
    private:
        uc::freq_t _core_clock;
        std::map<std::string, uc::pin_state_t> _pins;


};






}







#endif
