#include <print>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdint>

#include "../include/clock.hpp"
#include "../include/time_t.hpp"

auto main() -> int {
    std::vector<int16_t> vectors(100000);
    time_t start_time = clock();

    srand(static_cast<unsigned int>(time(0))); //Обьявление srand.

    for(size_t i = 0 ; i < vectors.size() ; i++){
        vectors.at(i) = std::rand() % 1000; //Заполнение.
    }

    if(vectors.empty()){
        std::cerr << "Vector empty" << '\n';
    }

    std::println("Print difference: ");

    double elapsed_time = static_cast<double>(std::clock() - start_time) / 1000;

    std::println("difference: {}",elapsed_time);

    vectors.resize(1000000000); //Увеличили размер.

    elapsed_time = static_cast<double>(std::clock() - start_time) / 1000;

    std::println("New difference: {}",elapsed_time);

    return EXIT_SUCCESS;
}   
