#pragma once
#ifndef STATE_HPP
#define STATE_HPP

#include <stdint.h>
#include <variant>
#include <type_traits>

namespace simulator {

#define IS_TYPE(DTYPE) std::is_same_v<T, DTYPE>
#define VALID_STATE_TYPE IS_TYPE(double) || IS_TYPE(uint32_t) || IS_TYPE(uint16_t) || IS_TYPE(uint8_t) || IS_TYPE(bool) || IS_TYPE(char)
typedef std::variant<double, uint32_t, uint16_t, uint8_t, bool, pin_state_t, char> state_t;

enum pin_state_t : bool {
    ON = true,
    HIGH = true,
    OFF = false,
    LOW = false
};

class State {
    private:
    // Probably have to replace this with a union
    state_t value_;

    public:
    State() :
        value_{}
    {

    }

    template <typename T>
        requires VALID_STATE_TYPE
    State(T initial_value) :
        value_{initial_value}
    {

    }


    template <typename T>
        requires VALID_STATE_TYPE
    void set(T value) {
        value_ = value;
    }

    
    template <typename T>
        requires VALID_STATE_TYPE
    T get() const noexcept {
        return std::get<T>(value_);
    }

};


}

#endif