#include "../include/printToConsole.hpp"

#include <cstdlib>
#include <thread>

auto main() -> int {
    std::thread threads_1(printTC, "AA");
    std::thread threads_2(printTC, "AA-2");

    threads_1.join(); 
    threads_2.join();

    return EXIT_SUCCESS;
}
