// Task_4
#include "../include/myInit.hpp"

#include <cstdint>
#include <random>
#include <vector>

// Современная замена C-стилю rand()/srand(): ГПСЧ из <random>.
// thread_local -- у каждого потока свой генератор, можно безопасно звать из потоков.
auto myInit(std::vector<int16_t>& vectors, const std::size_t start_index, const std::size_t end_index) -> void {
    static thread_local std::mt19937 rng{std::random_device{}()};
    const std::uniform_int_distribution<int> dist{0, 999};

    for (std::size_t i = start_index; i < end_index; ++i) {
        vectors.at(i) = static_cast<int16_t>(dist(rng));
    }
}
