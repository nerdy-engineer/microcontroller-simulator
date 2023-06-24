#pragma once
#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <string_view>

namespace simulation {

class node {
public:
    node() { }

    inline std::string_view name() const { return name_; }

private:
    std::string name_;

};

}


#endif // NODE_HPP