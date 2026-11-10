#include "../include/funcPrintVector.hpp"
#include "../include/myInit.hpp"
#include "../include/bubbleSort.hpp"
#include "../include/timing.hpp"
#include "../include/quicSort.hpp"
#include "../include/separation.hpp"
#include "../include/startSort.hpp"

#include <print>
#include <stdexcept>
#include <vector>
#include <cstdlib>

auto main() -> int {
    std::vector<short> vectors(50'000);
    if (vectors.empty()) {
        throw std::invalid_argument("Vector empty");
    }
    myInit(vectors);
    const std::vector<short> vect1 = vectors, vect2 = vectors;
    //printVector(vect);

    // funcTiming теперь принимает std::function -- задание передаём лямбдой.
    funcTiming([&vect1] { funcSort(vect1); }, "\nBubble sort: ");
    //printVector(vect1);
    funcTiming([&vect2] { quickSort(vect2); }, "\nQuick Sort: ");
    //printVector(vect2);

    return EXIT_SUCCESS;
}
