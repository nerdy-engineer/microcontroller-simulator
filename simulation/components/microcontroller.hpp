#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <thread>
#include <chrono>

#include "simulation/typedefs.hpp"
#include "simulation/components/pin.hpp"
#include "simulation/components/task.hpp"


namespace uc {


class microcontroller {
    private:
        std::map<std::string, uc::pin> pins_;
        std::map<std::string, uc::peripheral> peripherals_;
        std::vector<uc::task&> tasks_;
        uc::pulse_t uc_time_;

    public:
        microcontroller() :
            pins_{},
            peripherals_{},
            tasks_{},
            uc_time_{0}
        {

        }

        void add_pin(const std::string& name) {
            pins_.emplace(name, uc::pin(name));
        }

        uc::pin& pin(const std::string& name) {
            return pins_.at(name);
        }

        void add_task(uc::task& task) {
            tasks_.push_back(task);
        }

        void boot() {
            // launch each task in tasks in its own thread
            for (auto t : tasks_) {
                t.start();
            }
        }

        void shutdown() {
            // end each task
            for (auto t : tasks_) {
                t.stop();
            }
        }

        /*
        void pinMode(const std::string& name, uc::pin::pin_mode_t mode) {
            pin(name).mode(mode);
        }

        void digitalWrite(const std::string& name, bool state) {
            pin(name).digital_write(state);
        }

        bool digitalRead(const std::string& name) {
            return pin(name).digital_read();
        }
        */

        // replace this with the microcontroller clock link
        void simStep(uc::pulse_t dt) {
            uc_time_ += dt;
        }

};


}







#endif
