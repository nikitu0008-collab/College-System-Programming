#pragma once
#include <vector>
#include <string>
#include <mutex>
auto printToVector(std::vector<std::string>& vect, const std::string& str, std::mutex& mtx) -> void;
