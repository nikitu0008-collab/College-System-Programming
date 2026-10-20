#include "../include/quicSort.hpp"
#include <utility>
#include <vector>
#include <cstddef>
auto funcQuicSort(std::vector<short>& vect, size_t start, size_t end) -> size_t{
    size_t i = start, j = start;
    for(; i < end - 1 ; i++){
        if(vect.at(i) <= vect.at(end - 1)){
            std::swap(vect.at(i), vect.at(j));
            j++;
        }
    }
    std::swap(vect.at(j), vect.at(end - 1));
    return j;
}
