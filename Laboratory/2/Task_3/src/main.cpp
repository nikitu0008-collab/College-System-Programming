#include <functional>
#include <print>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <cstdint>
#include <vector>
#include <ctime>

#include "../include/clock.hpp"
#include "../include/time_t.hpp"
#include "../include/myInit.hpp"

auto main() -> int {
    std::vector<int16_t> vectors(100000);

    if (vectors.empty()) {
        std::cerr << "Vector empty" << '\n';
        return EXIT_FAILURE;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    const size_t mid_size_vector = vectors.size() / 2;

    const clock_t start_time = clock();

    //two streams, and each fills its own half
    std::thread thread_1(myInit, std::ref(vectors), 0, mid_size_vector);
    std::thread thread_2(myInit, std::ref(vectors), mid_size_vector, vectors.size());

    //waiting completed streams
    thread_1.join();
    thread_2.join();

    const clock_t end_time = clock();

    const double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    std::println("Parallel init in 2 threads: {} second", elapsed_time);

    return EXIT_SUCCESS;
}
