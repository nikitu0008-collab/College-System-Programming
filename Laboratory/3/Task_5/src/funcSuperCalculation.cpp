#include "../include/funcSuperCalculation.hpp"
#include "../include/quicSort.hpp"
#include "../include/Merging.hpp"

#include <functional>
#include <vector>
#include <thread>

auto quickSortMultiThreads(std::vector<short>& vect) -> std::vector<short>&{
    constexpr const int num_threads = 2;
    
    int low = 0, hight = vect.size() - 1, mid = low + (hight - low) / 2;

    std::vector<std::thread> threads;

    threads.emplace_back(funcQuicSort, std::ref(vect), low, mid);
    threads.emplace_back(funcQuicSort, std::ref(vect), mid + 1, hight);

    for (std::thread& i : threads) {
        i.join();
    }
    myMerging(vect, 0, vect.size());
    return vect;
}
