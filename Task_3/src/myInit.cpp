// Task_2
#include "../include/myInit.hpp"

#include <cstdlib>
#include <vector>
#include <cstdint>

auto myInit(std::vector<int16_t>& vectors, size_t start, size_t end) -> void {
    for (size_t i = start ; i < end ; i++) {
        //vectors.at(i) = static_cast<int16_t>(rand() % 1001);
        vectors.at(i) = 1;
    }
}
