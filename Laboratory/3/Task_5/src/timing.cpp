#include "../include/timing.hpp"

#include <print>
#include <chrono>

auto funcTiming(const std::function<void()>& task, std::string message) -> void {
    const auto start = std::chrono::steady_clock::now();
    task();
    const auto stop = std::chrono::steady_clock::now();

    // C-стиль clock()/time_t из <ctime> заменён на std::chrono::steady_clock.
    // Заодно исправлен баг: (finish - start) / CLOCKS_PER_SEC был целочисленным
    // делением двух time_t и почти всегда выдавал 0.
    std::println("{}: {:.6f} second", message,
                 std::chrono::duration<double>(stop - start).count());
}
