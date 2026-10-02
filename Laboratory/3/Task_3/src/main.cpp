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
    std::vector<short>vect1 = vect, vect2 = vect;
    printVector(vect);
    funcTiming(funcSort, vectors, "\nBubble sort: ");
    printVector(vect1);
    funcTiming(funcQuicSort, vect2, "Quick Sort: ");
    printVector(vect2);
    return EXIT_SUCCESS;
}
