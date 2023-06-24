#include <iostream>
#include <vector>
#include <memory>
#include "settings.hpp"
#include "world.hpp"
#include "debug_component.hpp"
#include "time.hpp"

using namespace simulation;

int main() {

    // Build simulation world
    auto comp = debug();
    auto w = world();
    w.add(std::make_shared<simulation::component_base>(comp));



    // Set up simulation parameters
    auto s = settings{0, 10000, 0.1, 0.05};
    



    // Run simulation loop






}



