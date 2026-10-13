#include "../include/printToConsole.hpp"

#include <string>
#include <print>
#include <cstddef>

auto printTC(const std::string& str) -> void {
    for(size_t i = 0 ; i < 10 ; i++){
        std::println("Выполняется поток {}, попытка {}", str, i);
    }
}
