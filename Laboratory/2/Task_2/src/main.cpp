#include <cstdlib>
#include <cstdint>
#include <vector>
#include <ctime>
#include <print>

#include "../include/clock.hpp"
#include "../include/time_t.hpp"
#include "../include/myInit.hpp"

auto main() -> int {
    std::vector<int16_t> vectors(100000);

    srand(static_cast<unsigned int>(time(0))); //Обьявление srand.

    std::println("Print difference");
    
    const time_t start_time = clock();

    myInitFunc(vectors, 0, vectors.size()); //Заполнение
 
    const time_t end_time = clock();

    double elapsed_time = static_cast<double>(end_time - start_time) / 1000.0;

    std::println("difference: {}",elapsed_time);

    vectors.resize(1000000000); //Увеличили размер.

    elapsed_time = static_cast<double>(clock() - start_time) / 1000.0;

    std::println("New difference: {}",elapsed_time);

    return EXIT_SUCCESS;
}   
//thread.join() -- ждём пока завершится поток
