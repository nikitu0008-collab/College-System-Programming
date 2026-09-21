#include "../include/clock.hpp"

#include <print>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>

auto printClock(std::vector<int16_t>& clock_vector) -> void{
    srand(1000);//Нач-ное значение генератора

    for (size_t i = 0 ; clock_vector.size() ; i++) {
        clock_vector.at(i) = std::rand() % 1000;//Заполнение
    }
    if(clock_vector.empty()){
        std::cerr << "Vector empty" << '\n';
    }
    std::println("Vector filed");
}
