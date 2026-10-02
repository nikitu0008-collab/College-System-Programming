#include "../include/timing.hpp"
#include <ctime>
#include <print>
#include <string>
#include <vector>
auto funcTiming(std::vector<short>& (*myInit)(std::vector<short>&), std::vector<short>& vect, std::string message) -> void {
    time_t start = clock(), finish = clock();
    myInit(vect);
    finish = clock();
    std::println("{}: {} second", message, ((finish - start) / CLOCKS_PER_SEC));
}
