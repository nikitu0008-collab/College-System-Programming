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

    //Почему не uint16_t? т.к hardware_concurrency возвращает unsigned int, у меня было бы предупреждение
    const unsigned int n_threads = std::thread::hardware_concurrency();
    std::println("hardware concurrency: {}", n_threads);

    //number of element per thread
    const size_t mid_size_vector = vectors.size() / n_threads;

    const clock_t start_time = clock();

    std::vector<std::thread> threads;
    threads.reserve(n_threads);

    //Обработка хвоста
    for(unsigned int i = 0 ; i < n_threads ; i++){
        size_t start_index = i * mid_size_vector, end_index = 0;
        //Проверка на хвост
        if(i == n_threads - 1){
            end_index = vectors.size();
        } else {
            end_index = start_index + mid_size_vector;
        }

        threads.emplace_back(myInit, std::ref(vectors), start_index, end_index);
    }

    for(std::thread& i : threads){
        i.join();
    }

    const clock_t end_time = clock();

    const double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    std::println("Init all cores: {} threads, {} second", n_threads, elapsed_time);

    return EXIT_SUCCESS;
}
