#pragma once
#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include <vector>
#include <cstdint>
#include <chrono>

namespace uc {

typedef size_t timestep_t;
typedef double freq_t;
typedef int64_t pin_state_t;
typedef uint32_t baud_rate_t;
typedef size_t buffer_size_t;
typedef std::vector<uint8_t> buffer_t;
typedef std::chrono::duration<uc::timestep_t, std::chrono::nanoseconds::period> pulse_t;


};






#endif
