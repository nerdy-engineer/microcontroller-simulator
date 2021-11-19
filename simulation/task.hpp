#pragma once
#ifndef TASK_HPP
#define TASK_HPP


#include "simulation/microcontroller.hpp"
#include "simulation/typedefs.hpp"



namespace uc {

class task {
    // Note! Each task should be run in its own thread managed by the microcontroller!
    private:
        uc::microcontroller* uc_;
    
    public:
        task(uc::microcontroller* microcontroller) :
        uc_{microcontroller}
        {

        }

        void sleep(size_t microseconds) {
            // Do something here to handle threads and interrupts and use uc_ to sleep properly
        }



        virtual void execute() = 0;

};


class example_task : public task{
    private:
    void execute() override {
        
    }
};










}

#endif