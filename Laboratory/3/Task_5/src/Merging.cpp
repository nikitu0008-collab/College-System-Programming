#include "../include/Merging.hpp"

#include <vector>
#include <cstddef>

auto myMerging(std::vector<short>& vect, size_t start, size_t finish) -> void{
    if (finish - start < 2) {
        return;
    }

    std::size_t mid = start + (finish - start) / 2;

    std::vector<short> buffer(vect.begin() + start, vect.begin() + mid);

    std::size_t left_idx = 0, right_idx = mid, write_idx = start;

    while (left_idx < buffer.size() && right_idx < finish) {
        if (buffer[left_idx] <= vect[right_idx]) {
            vect.at(write_idx++) = buffer.at(left_idx++);
        }
        else {
            vect.at(write_idx++) = vect.at(right_idx++);
        }
    }
    while (left_idx < buffer.size()) {
        vect.at(write_idx++) = buffer.at(left_idx++);
    }
}
