#include "../include/printToConsole.hpp"

#include <cstdlib>
#include <thread>

auto main() -> int {
    // std::jthread вместо std::thread: join() вызывается в деструкторе,
    // потоки не останутся "брошенными" даже при исключении.
    const std::jthread threads_1(printTC, "AA");
    const std::jthread threads_2(printTC, "AA-2");

    return EXIT_SUCCESS;
}
