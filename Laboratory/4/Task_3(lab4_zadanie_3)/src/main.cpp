#include "../include/printToVect.hpp"

#include <print>
#include <cstdlib>
#include <functional>
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

    // Явный join перед печатью: читаем vect только после того,
    // как оба потока гарантированно дописали свои строки (иначе -- гонка данных).
    thread_1.join();
    thread_2.join();

    // Диапазонное форматирование vector через std::println пока тянется не всеми
    // компиляторами (GCC 15+), поэтому печатаем элементы честным циклом.
    for (const std::string& line : vect) {
        std::println("{}", line);
    }

    return EXIT_SUCCESS;
}
