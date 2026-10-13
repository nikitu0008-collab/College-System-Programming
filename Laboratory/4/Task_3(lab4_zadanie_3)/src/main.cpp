/*
 * НОВЫЙ CPP ФАЙЛ
 * */

#include "../include/printToVect.hpp"

#include <cstdlib>
#include <functional>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <print>

auto main() -> int {
    std::vector<std::string> vect;
    std::mutex mtx;

    std::thread thread_1(printToVector, std::ref(vect),"AA", std::ref(mtx));
    std::thread thread_2(printToVector, std::ref(vect),"BB", std::ref(mtx));

    thread_1.join();
    thread_2.join();

    std::println("{}",vect);

    return EXIT_SUCCESS;
}
