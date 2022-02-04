#pragma once
#ifndef SIMOBJECT_HPP
#define SIMOBJECT_HPP

#include <string>

namespace simulator {

class SimObject {
private:
    std::string name_;
    id_t id_;

public:
    
    // std::string_view name() const noexcept {
    //     return {name_};
    // }

    const std::string& name() const noexcept{
        return {name_};
    }

    id_t id() {
        return id_;
    }
};

}

#endif