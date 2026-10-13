#include "../include/printToConsole.hpp"

#include <string>
#include <print>
#include <cstddef>
#include <mutex>

std::mutex count_mutex;

auto printTC(const std::string& str) -> void {
    for(size_t i = 0 ; i < 10 ; i++){
        if(count_mutex.try_lock()){
        std::println("Выполняется поток {}, попытка {}", str, i);
        count_mutex.unlock();
        } else {
            //Данный else просто навсякий
            std::println("Вызвался else в функции условия");
        }
    }
}
