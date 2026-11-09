#include "../include/printToVect.hpp"

#include <print>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <string>
#include <vector>

auto main() -> int {
    std::vector<std::string> vect;
    std::mutex mtx;

    // std::jthread вместо std::thread: join() вызывается в деструкторе.
    const std::jthread thread_1(printToVector, std::ref(vect), "AA", std::ref(mtx));
    const std::jthread thread_2(printToVector, std::ref(vect), "BB", std::ref(mtx));

    // Соединение сработает в деструкорах jthread при выходе из main,
    // к этому моменту vect гарантированно заполнен.
    std::println("{}", vect);

    return EXIT_SUCCESS;
}
