#include <iostream>
#include <vector>
#include <memory>
#include "simulation\simulator.hpp"
#include "simulation\component_base.hpp"
#include "simulation\world.hpp"
#include "simulation\time.hpp"
#include "peripherals\debug_component.hpp"

using namespace simulation;

int main() {

    // Build simulation world
    auto comp = debug();
    auto w = world();
    w.add(std::make_shared<component_base>(comp));



    // Set up simulation parameters
    auto s = settings{0, 10000, 0.1, 0.05};
    auto sim = simulator(s, std::make_shared<world>(w));



    // Run simulation loop






}



