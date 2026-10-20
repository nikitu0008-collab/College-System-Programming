#include "../include/bubbleSort.hpp"

#include <cstddef>
#include <utility>
#include <vector>
#include <print>

auto funcSort(std::vector<short>& vectors) -> std::vector<short>& {
    bool swap = false;
    for(size_t i = 0 ; i < vectors.size() ; i++){
        for(size_t j = 0 ; j < vectors.size() - 1 ; j++){
            if(vectors.at(j) > vectors.at(j + 1)){
                std::swap(vectors.at(j), vectors.at(j + 1));
                swap = true;
            }
        }
/*        if(!swap){
            std::println("Not sorted");
            break;
            } */
    }
    return vectors;
}
