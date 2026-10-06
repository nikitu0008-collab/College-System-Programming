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

#include <vector>
#include <cstdlib>
#include <print>

auto main() -> int{
    std::vector<short> vectors(50000);
    
    myInit(vectors);
    
    std::vector<short>vect1 = vectors, vect2 = vectors, vect3 = vectors;
    
    funcTiming(funcSort, vect1, "\nBubble sort: ");
    funcTiming(quickSort, vect2, "\nQuick Sort: ");
    
    std::println(
            "BubbleSort and QuickSort: {}",
            checkVectors(vect1, vect2)
            );
    
    funcTiming(quickSortMultiThreads, vect3, "\nQuicSort MultiThreads: ");
    
    std::println(
            "\nQuicSort and QuicSortMultiThreads: {}",
            checkVectors(vect3, vect2)
            );
    
    return EXIT_SUCCESS;
}
