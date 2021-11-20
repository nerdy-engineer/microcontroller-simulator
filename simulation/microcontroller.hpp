#pragma once
#ifndef MICROCONTROLLER_HPP
#define MICROCONTROLLER_HPP

#include <map>
#include <string>
#include <format>
#include <stdexcept>
#include <vector>

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
            // launch each task in tasks in it's own thread
        }
};






}







#endif
