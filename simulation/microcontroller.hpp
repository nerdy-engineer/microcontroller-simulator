#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP

#include <map>
#include <string>
#include <format>
#include <stdexcept>
#include <vector>
#include <thread>

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

    public:
        microcontroller(uc::freq_t core_clock) :
            core_clock_{core_clock},
            pins_{},
            peripherals_{},
            tasks_{}
        {

        }

        void add_pin(const std::string& name) {
            pins_[name] = uc::pin(name);
        }

        uc::pin& pin(const std::string& name) {
            auto pin_it = pins_.find(name);
            if (pin_it == pins_.end()) {
                throw std::out_of_range(std::format("Simulation state does not contain key {}", name));
            }
            return pin_it->second;
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

        void pinMode(const std::string& name, uc::pin::pin_mode_t mode) {
            pin(name).mode(mode);
        }

        void digitalWrite(const std::string& name, bool state) {
            pin(name).digital_write(state);
        }

        bool digitalRead(const std::string& name) {
            return pin(name).digital_read();
        }



};






}







#endif
