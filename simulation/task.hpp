#pragma once
#ifndef TASK_HPP
#define TASK_HPP

#include <thread>
#include "simulation/microcontroller.hpp"
#include "simulation/typedefs.hpp"



namespace uc {

class task {    
    private:
        std::string_view name_;
        uc::microcontroller* uc_;
        bool run_;
        std::thread thread_;
    
    protected:
        void sleep(size_t microseconds) {
            // Do something here to handle threads and interrupts and use uc_ to sleep properly
        }
    

    public:
        task(const std::string_view name, uc::microcontroller* microcontroller) :
        name_{name},
        uc_{microcontroller},
        run_{false},
        thread_{}
        {
            
        }

        void start() {
            run_ = true;
            thread_ = std::thread(execute);
        }

        void stop() {
            run_ = false;
        }

        bool run_signal() {
            return run_;
        }

        virtual void execute() = 0;

};


/*
class example_task : public task{
    private:
    
    public:
    void execute() override {
        while (run_signal()) {
            uc_->pin("A1").digital_write(true);
            sleep(500);
            uc_->pin("A1").digital_write(false);
            sleep(500);
        }
    }
};
*/









}

#endif