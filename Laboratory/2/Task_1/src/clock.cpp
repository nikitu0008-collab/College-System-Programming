#include "../include/clock.hpp"

#include <print>
#include <cstdint>
#include <ranges>
#include <vector>

auto printClock(const std::vector<int16_t>& clock_vector) -> void {
    if (clock_vector.empty()) {
        std::print(std::cerr, "Vector empty\n");
        return;
    }

    // Печатаем только первые 10 элементов, чтобы не засорять консоль.
    for (const int16_t element : clock_vector | std::views::take(10)) {
        std::print("{} ", element);
    }
    std::println("");

    std::println("Vector filled");
}
