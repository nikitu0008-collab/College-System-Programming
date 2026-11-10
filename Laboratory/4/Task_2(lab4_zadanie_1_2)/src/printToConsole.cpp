#include "../include/printToConsole.hpp"

#include <mutex>
#include <print>
#include <string>

std::mutex count_mutex;

auto printTC(const std::string& str) -> void {
    for (size_t i = 0; i < 10; ++i) {
        // Захват мьютекса через RAII: unique_lock(std::try_to_lock) сам
        // разлочится при выходе из блока, забыть unlock() больше невозможно.
        if (std::unique_lock lock(count_mutex, std::try_to_lock); lock.owns_lock()) {
            std::println("Выполняется поток {}, попытка {}", str, i);
        } else {
            // Захват не получился -- мьютекс занят другим потоком.
            std::println("Вызвался else в функции условия");
        }
    }
}
