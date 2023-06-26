#pragma once
#ifndef COMPONENT_BASE
#define COMPONENT_BASE

#include "time.hpp"

namespace simulation {


class component_base {
public:
    virtual void tick(tstep_t dt) = 0;
};





}


#endif //COMPONENT_BASE