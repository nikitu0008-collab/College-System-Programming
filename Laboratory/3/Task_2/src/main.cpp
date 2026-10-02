#include "../include/funcPrintVector.hpp"
#include "../include/myInit.hpp"
#include "../include/bubbleSort.hpp"
#include "../include/timing.hpp"

#include <stdexcept>
#include <vector>
#include <cstdlib>

auto main() -> int{
    std::vector<short> vectors(50000);
    if(vectors.empty()){ 
        throw std::invalid_argument("Error size vector");
    }
    myInit(vectors);
    //printVector(vectors);
    funcTiming(funcSort, vectors, "\nBubble sort: ");
    return EXIT_SUCCESS;
}
