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

    // Почему не uint16_t? т.к hardware_concurrency возвращает unsigned int, у меня было бы предупреждение
    const unsigned int n_threads = std::thread::hardware_concurrency();
    std::println("hardware concurrency: {}", n_threads);

    // number of element per thread
    const std::size_t mid_size_vector = vectors.size() / n_threads;

    const auto start_time = std::chrono::steady_clock::now();

    std::vector<std::jthread> threads;
    threads.reserve(n_threads);

    // Обработка хвоста
    for (unsigned int i = 0; i < n_threads; ++i) {
        const std::size_t start_index = i * mid_size_vector;
        // Проверка на хвост
        const std::size_t end_index =
            (i == n_threads - 1) ? vectors.size() : start_index + mid_size_vector;

        threads.emplace_back(myInit, std::ref(vectors), start_index, end_index);
    }

    // Явный join() оставлен, чтобы замер шёл после реального завершения потоков.
    // (std::jthread в деструкторе и так закрывает их, даже если вылетит исключение.)
    for (std::jthread& thread : threads) {
        thread.join();
    }

    const auto end_time = std::chrono::steady_clock::now();

    // Замер через std::chrono::steady_clock вместо C-стиля clock()/CLOCKS_PER_SEC.
    const double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

    std::println("Init all cores: {} threads, {:.6f} seconds", n_threads, elapsed_time);

    return EXIT_SUCCESS;
}
