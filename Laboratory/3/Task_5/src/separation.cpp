#include "../include/separation.hpp"
#include "../include/quicSort.hpp"
#include <vector>
#include <cstddef>

auto funcSeparation(std::vector<short>& vect, size_t start, size_t end) -> std::vector<short>& {
    if(start < end){
        size_t pivot = funcQuicSort(vect, start, end);
        funcSeparation(vect, start, pivot);
        funcSeparation(vect, pivot + 1, end);
        return vect;
    }
    return vect;
}
