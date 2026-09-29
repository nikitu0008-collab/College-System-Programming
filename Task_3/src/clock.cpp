#include "../include/clock.hpp"

#include <cstddef>
#include <iostream>
#include <vector>
#include <cstdint>
#include <print>

auto Printclock(std::vector<int16_t>& clock_vector) -> void {
    if (clock_vector.empty()) {
        std::cerr << "Vector empty" << '\n';
        return;
    }

    for (size_t i = 0; i < clock_vector.size() ; i++) {
        std::println("{} ", clock_vector.at(i));
    }

    std::println("Vector filled");
}
