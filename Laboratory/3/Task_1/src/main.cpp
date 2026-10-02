#include "../include/funcPrintVector.hpp"
#include "../include/myInit.hpp"

#include <stdexcept>
#include <vector>
#include <cstdlib>

auto main() -> int{
    std::vector<short> vectors(10);
    if(vectors.empty()){ 
        throw std::invalid_argument("Error size vector");
    }

    myInit(vectors, 0, vectors.size());
    printVector(vectors);

    return EXIT_SUCCESS;
}
