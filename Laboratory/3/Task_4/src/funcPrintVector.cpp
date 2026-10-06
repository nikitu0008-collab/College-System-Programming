#include "../include/funcPrintVector.hpp"

#include <vector>
#include <print>

auto printVector(std::vector<short>& vectors) -> const std::vector<short>& {
    for(short& vector : vectors){
        std::println("{} ",vectors);
    }
    return vectors;
}
