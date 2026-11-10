// Task_2
#include "../include/myInit.hpp"

#include <cstddef>
#include <random>
#include <vector>

// Современная замена C-стилю rand()/srand(): ГПСЧ из <random>.
// thread_local -- у каждого потока свой генератор, безопасно звать из потоков.
auto myInit(std::vector<short>& vectors) -> std::vector<short>& {
    static thread_local std::mt19937 rng{std::random_device{}()};
    const std::uniform_int_distribution<int> dist{0, 999};

    for (std::size_t i = 0; i < vectors.size(); ++i) {
        vectors.at(i) = static_cast<short>(dist(rng));
    }
    return vectors;
}
