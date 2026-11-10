#include "../include/funcPrintVector.hpp"
#include "../include/myInit.hpp"
#include "../include/bubbleSort.hpp"
#include "../include/timing.hpp"
#include "../include/quicSort.hpp"
#include "../include/separation.hpp"
#include "../include/startSort.hpp"
#include "../include/reconciliation.hpp"
#include "../include/Merging.hpp"
#include "../include/funcSuperCalculation.hpp"

#include <print>
#include <vector>
#include <cstdlib>

auto main() -> int {
    std::vector<short> vectors(50'000);

    myInit(vectors);

    std::vector<short> vect1 = vectors, vect2 = vectors, vect3 = vectors;

    // funcTiming теперь принимает std::function -- задание передаём лямбдой.
    funcTiming([&vect1] { funcSort(vect1); }, "\nBubble sort: ");
    funcTiming([&vect2] { quickSort(vect2); }, "\nQuick Sort: ");

    std::println(
            "BubbleSort and QuickSort: {}",
            checkVectors(vect1, vect2)
            );

    funcTiming([&vect3] { quickSortMultiThreads(vect3); }, "\nQuicSort MultiThreads: ");

    std::println(
            "\nQuicSort and QuicSortMultiThreads: {}",
            checkVectors(vect3, vect2)
            );

    return EXIT_SUCCESS;
}
