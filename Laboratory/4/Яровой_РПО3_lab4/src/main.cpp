#include "../include/printToVect.hpp"
#include "../include/printToConsole.hpp"

#include <print>
#include <cstdlib>
#include <mutex>
#include <string>
#include <vector>
#include <thread>

auto main() -> int {
    // std::jthread вместо std::thread: автоматический join() в деструкторе.
    const std::jthread thread_1(printTC, "AA");
    const std::jthread thread_2(printTC, "BB");

    std::vector<std::string> vect;
    std::mutex mtx;

    const std::jthread t1(printToVector, std::ref(vect), "AA", std::ref(mtx));
    const std::jthread t2(printToVector, std::ref(vect), "BB", std::ref(mtx));

    // Явное соединение, чтобы печать шла уже после заполнения vect.
    t1.join();
    t2.join();

    std::println("{}", vect);

    return EXIT_SUCCESS;
}
