#include <functional>
#include <print>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <thread>
#include <vector>

#include "../include/clock.hpp"
#include "../include/time_t.hpp"
#include "../include/myInit.hpp"

auto main() -> int {
    std::vector<int16_t> vectors(100'000);

    if (vectors.empty()) {
        std::print(std::cerr, "Vector empty\n");
        return EXIT_FAILURE;
    }

    const std::size_t mid_size_vector = vectors.size() / 2;

    const auto start_time = std::chrono::steady_clock::now();

    // Два потока, каждый заполняет свою половину вектора.
    // std::jthread сам делает join() в деструкторе -- поток не может остаться "брошенным".
    std::jthread thread_1(myInit, std::ref(vectors), 0, mid_size_vector);
    std::jthread thread_2(myInit, std::ref(vectors), mid_size_vector, vectors.size());

    // Явный join() оставлен, чтобы замер шёл после реального завершения потоков.
    thread_1.join();
    thread_2.join();

    const auto end_time = std::chrono::steady_clock::now();

    // Замер через std::chrono::steady_clock вместо C-стиля clock()/CLOCKS_PER_SEC.
    const double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

    std::println("Parallel init in 2 threads: {:.6f} seconds", elapsed_time);

    return EXIT_SUCCESS;
}
