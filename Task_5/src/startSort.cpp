#include "../include/startSort.hpp"
#include "../include/separation.hpp"
#include <vector>

auto quickSort(std::vector<short>& vect) -> std::vector<short>& {
    funcSeparation(vect, 0, vect.size());
    return vect;
}
