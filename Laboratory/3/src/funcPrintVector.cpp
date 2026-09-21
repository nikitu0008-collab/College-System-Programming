#include "../include/funcPrintVector.hpp"

#include <cstddef>
#include <vector>
#include <print>

auto printVector(std::vector<short>& vectors, size_t  /*start*/, size_t  /*end*/) -> void {
    for(short& vector : vectors){
        std::println("{} ",vector);
    }
}
