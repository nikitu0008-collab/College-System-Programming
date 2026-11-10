#pragma once

#include <functional>
#include <string>

// Замеряет время выполнения task и печатает результат в консоль.
// Было: C-стиль указателя на функцию + <ctime>. Стало: std::function<void()>.
auto funcTiming(const std::function<void()>& task, std::string message) -> void;
