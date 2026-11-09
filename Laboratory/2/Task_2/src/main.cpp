#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <print>
#include <vector>

#include "../include/clock.hpp"
#include "../include/time_t.hpp"
#include "../include/myInit.hpp"

auto main() -> int {
    std::vector<int16_t> vectors(100'000);

    std::println("Print difference");

    const auto start_time = std::chrono::steady_clock::now();

    myInitFunc(vectors, 0, vectors.size()); // Заполнение.

    // Замер через std::chrono::steady_clock вместо C-стиля clock()/CLOCKS_PER_SEC.
    const double elapsed_time =
        std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();

    std::println("difference: {}", elapsed_time);

    vectors.resize(1'000'000'000); // Увеличили размер.

    const double new_elapsed_time =
        std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count();

    std::println("New difference: {}", new_elapsed_time);

    // thread.join() -- ждём пока завершится поток
    return EXIT_SUCCESS;
}
