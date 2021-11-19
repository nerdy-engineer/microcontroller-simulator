#pragma once
#ifndef PERIPHERALS_HPP
#define PERIPHERALS_HPP





namespace uc {

class peripheral {
    private:



    public:
    peripheral()
    {

    }

    virtual void sim_update(timestep_t dt) = 0;

};


}

#endif