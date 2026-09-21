#include "../include/clock.hpp"

#include <cstdint>
#include <print>
#include <iostream>
#include <vector>

auto Printclock(std::vector<int16_t>& clock_vector) -> void{
    for (auto& i : clock_vector) {
        std::println("{} ",clock_vector);
    }
    if(clock_vector.empty()){
        std::cerr << "Vector empty" << '\n';
    }
}
