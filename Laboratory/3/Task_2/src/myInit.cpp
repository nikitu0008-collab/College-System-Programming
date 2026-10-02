// Task_2
#include "../include/myInit.hpp"

#include <cstdlib>
#include <vector>

auto myInit(std::vector<short>& vectors) -> std::vector<short>& {
    for (size_t i = 0 ; i < vectors.size() ; i++) {
        vectors.at(i) = static_cast<short>(rand() % 1001);
    }
    return vectors;
}
