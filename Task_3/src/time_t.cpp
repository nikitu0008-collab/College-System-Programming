#include "../include/time_t.hpp"

#include <iostream>

timeT::timeT() {
    std::cout << "Started constructor" << '\n';
}

timeT::~timeT() {
    std::cout << "Started destructor" << '\n';
}
