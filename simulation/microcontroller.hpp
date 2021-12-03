#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP

#include <map>
#include <string>
#include <format>
#include <stdexcept>
#include <vector>
#include <thread>
#include <chrono>

#include "simulation/typedefs.hpp"
#include "simulation/pin.hpp"
#include "simulation/task.hpp"


namespace uc {


class microcontroller {
    private:
        uc::freq_t core_clock_;
        std::map<std::string, uc::pin> pins_;
        std::map<std::string, uc::peripheral> peripherals_;
        std::vector<uc::task&> tasks_;
        std::chrono::time_point uc_time_;

    public:
        microcontroller(uc::freq_t core_clock) :
            core_clock_{core_clock},
            pins_{},
            peripherals_{},
            tasks_{},
            uc_time_{0}
        {

        }

        void add_pin(const std::string& name) {
            pins_.emplace(name, uc::pin(name));
        }

        uc::pin& pin(const std::string_view name) {
            return pins_.at(name);
        }

        void add_task(const uc::task& task) {
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

        void pinMode(const std::string_view name, uc::pin::pin_mode_t mode) {
            pin(name).mode(mode);
        }

        void digitalWrite(const std::string_view name, bool state) {
            pin(name).digital_write(state);
        }

        bool digitalRead(const std::string_view name) {
            return pin(name).digital_read();
        }

        void simStep(std::chrono::duration dt) {
            uc_time_ += dt;
        }

};






}







#endif
