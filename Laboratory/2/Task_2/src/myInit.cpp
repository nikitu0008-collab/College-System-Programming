//Task_2
#include "../include/myInit.hpp"

#include <vector>
#include <cstdint>
#include <cstdlib>

auto myInitFunc(std::vector<int16_t>& vectors, size_t start_time, size_t end_time) -> void{
    for(size_t i = start_time ; i < end_time ; i++){
        vectors.at(i) = rand() % 1001;
    }
}
