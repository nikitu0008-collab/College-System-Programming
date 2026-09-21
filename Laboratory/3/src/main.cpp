#include "../include/funcPrintVector.hpp"
#include "../include/myInit.hpp"

#include <stdexcept>
#include <vector>
#include <print>
#include <iostream>
#include <cstdlib>

auto main() -> int{
    const std::vector<short> vectors(10);
    if(vectors.empty()){ 
        throw std::invalid_argument("Error size vector");
    }

    myInit(vectors);
    printVector(vectors);
    
    return EXIT_SUCCESS;
}
