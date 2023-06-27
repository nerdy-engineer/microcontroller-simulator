#pragma once
#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "time.hpp"
#include "component_base.hpp"
#include "processor_base.hpp"
#include "node.hpp"

namespace simulation {

class world : component_base {
public:
    world() {}
    
    void add (std::shared_ptr<component_base> e) {
        entities_.push_back(e);
    }

    void add (std::shared_ptr<processor_base> p) {
        smart_entities_.push_back(p);
    }

    void add (std::shared_ptr<node> n) {
        nodes_.emplace(n->name(), n);
    }


    virtual void tick(tstep_t dt) override {
        for (auto e : entities_) {
            // std::cout << "Entity tick...\t";
            e->tick(dt);
        }
        for (auto p : smart_entities_) {
            p->tick(dt);
        }
    }

private:

    std::vector<std::shared_ptr<component_base>> entities_;
    std::vector<std::shared_ptr<processor_base>> smart_entities_;
    std::map<std::string, std::shared_ptr<node>> nodes_;



};

}



#endif // WORLD_HPP