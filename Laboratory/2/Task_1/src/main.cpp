#include <print>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <random>
#include <vector>

#include "../include/clock.hpp"
#include "../include/time_t.hpp"

// Современная замена C-стилю time()/srand()/rand(): ГПСЧ из <random>.
// thread_local -- у каждого потока свой генератор, одной загрузкой от std::random_device.
static thread_local std::mt19937 rng{std::random_device{}()};

auto main() -> int {
    std::vector<int16_t> vectors(100'000);

    const auto start_time = std::chrono::steady_clock::now(); // Точка старта замера.

    const std::uniform_int_distribution<int> dist(0, 999);

    for (int16_t& element : vectors) {
        element = static_cast<int16_t>(dist(rng)); // Заполнение.
    }

    if (vectors.empty()) {
        std::print(std::cerr, "Vector empty\n");
    }

    std::println("Print difference: ");

    // Монохронные часы C-стиля (clock()/CLOCKS_PER_SEC) заменены на std::chrono::steady_clock.
    const double elapsed_time =
        std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();

    std::println("difference: {}", elapsed_time);

    vectors.resize(1'000'000'000); // Увеличили размер.

    const double new_elapsed_time =
        std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();

    std::println("New difference: {}", new_elapsed_time);

    return EXIT_SUCCESS;
}
