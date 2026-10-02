#pragma once
#include "../include/myInit.hpp"
#include <vector>
#include <string>
auto funcTiming(std::vector<short>&(*myInit)(std::vector<short>&), std::vector<short>& vect, std::string message) -> void;
