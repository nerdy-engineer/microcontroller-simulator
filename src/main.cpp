#include <iostream>
#include <vector>
#include <memory>
#include "simulator.hpp"
#include "component_base.hpp"
#include "world.hpp"
#include "time.hpp"
#include "debug_component.hpp"

using namespace simulation;

int main() {

    // Build simulation world
    auto comp = debug();
    auto w = world();
    w.add(std::make_shared<debug>(comp));



    // Set up simulation parameters
    auto s = settings{0, 10000, 0.1, 0.05};
    auto sim = simulator(s, std::make_shared<world>(w));



    // Run simulation loop
    sim.run();

    std::cout << "Simulation complete." << std::endl;


}



