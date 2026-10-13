#include "../include/printToVect.hpp"

#include <string>
#include <vector>
#include <cstddef>
#include <mutex>
#include <print>

auto printToVector(std::vector<std::string>& vect, const std::string& name, std::mutex& mtx) -> void {
    for(size_t i = 0 ; i < 10 ; i++){
        std::string line = "Я строка студента Ярового в потоке "
            + name
            + ", это моя"
            + std::to_string(i)
            + " итерация";
        std::lock_guard<std::mutex> lock(mtx);
        vect.push_back(line);
    }
}
