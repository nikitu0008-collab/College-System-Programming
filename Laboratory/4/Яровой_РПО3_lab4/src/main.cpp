#include "../include/printToVect.hpp"
#include "../include/printToConsole.hpp"

#include <functional>
#include <mutex>
#include <print>
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>

auto main() -> int {
    std::thread thread_1(printTC, "AA");
    std::thread thread_2(printTC, "BB");

    thread_1.join();
    thread_2.join();

    std::vector<std::string> vect;
    std::mutex mtx;

    std::thread t1(printToVector, std::ref(vect), "AA", std::ref(mtx));
    std::thread t2(printToVector, std::ref(vect), "BB", std::ref(mtx));

    t1.join();
    t2.join();

    std::println("{}",vect);

    return EXIT_SUCCESS;
}
