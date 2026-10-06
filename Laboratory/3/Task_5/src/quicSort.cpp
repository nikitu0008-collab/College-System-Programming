#include "../include/quicSort.hpp"
#include <utility>
#include <vector>
#include <cstddef>
auto funcQuicSort(std::vector<short>& vect, size_t start, size_t end) -> size_t{
    size_t i = start, j = start - 1;
    for(; i < end ; i++){
        if(vect.at(i) <= vect.at(end - 1)){
            j++;
            std::swap(vect.at(i), vect.at(j));
        }
    }
    return j;
}
