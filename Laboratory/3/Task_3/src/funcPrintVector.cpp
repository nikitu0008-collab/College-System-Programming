#include "../include/funcPrintVector.hpp"

#include <cstddef>
#include <vector>
#include <print>

auto printVector(std::vector<short>& vectors) -> void {
    for(short& vector : vectors){
        std::println("{} ",vector);
    }
}
