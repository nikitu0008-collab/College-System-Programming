#include "../include/Merging.hpp"

#include <vector>
#include <cstddef>

auto myMerging(std::vector<short>& vect, size_t start, size_t finish) -> void{
	std::vector<short>buffer;
	size_t left_index = start, right_index = start + ((finish - start) / 2);
	for (size_t i = 0; i < finish; i++) {
		if (i < ((finish - start) / 2)) { buffer.push_back(vect.at(i)); }
		if (!buffer.empty()) {
			if (vect.at(right_index) <= buffer.at(0)) {
				vect.at(i) = vect.at(right_index);
				if (right_index < vect.size() - 1) { right_index++; }
				else { vect.at(right_index) = buffer.back(); }
			}
			else {
				vect.at(i) = buffer.front();
				buffer.erase(buffer.begin());
			}
		}
	}
}
