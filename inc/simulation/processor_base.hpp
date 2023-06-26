#pragma once
#ifndef PROCESSOR_BASE_HPP
#define PROCESSOR_BASE_HPP

#include "time.hpp"
#include "component_base.hpp"

namespace simulation {

class processor_base : public component_base {
public:

    virtual void tick(tstep_t dt) override = 0;

};

}


#endif // PROCESSOR_BASE_HPP