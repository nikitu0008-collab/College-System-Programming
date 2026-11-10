#include "../include/funcPrintVector.hpp"
#include "../include/myInit.hpp"
#include "../include/bubbleSort.hpp"
#include "../include/timing.hpp"

#include <print>
#include <stdexcept>
#include <vector>
#include <cstdlib>

auto main() -> int {
    std::vector<short> vectors(50'000);
    if (vectors.empty()) {
        throw std::invalid_argument("Error size vector");
    }
    myInit(vectors);
    //printVector(vectors);

    // funcTiming теперь принимает std::function -- задание передаём лямбдой.
    funcTiming([&vectors] { funcSort(vectors); }, "\nBubble sort: ");

    return EXIT_SUCCESS;
}
