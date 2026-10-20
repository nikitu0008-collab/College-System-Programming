#include "../include/funcSuperCalculation.hpp"
#include "../include/quicSort.hpp"
#include "../include/Merging.hpp"
#include "../include/separation.hpp"

#include <functional>
#include <vector>
#include <thread>

auto quickSortMultiThreads(std::vector<short>& vect) -> std::vector<short>&{
    if(vect.size() < 2){ return vect; }

    constexpr const int num_threads = 2;
    
    int low = 0, hight = vect.size() - 1, mid = vect.size() / 2;

    std::vector<std::thread> threads;

    threads.emplace_back(funcSeparation, std::ref(vect), 0, mid);
    threads.emplace_back(funcSeparation, std::ref(vect), mid, vect.size());

    for (std::thread& i : threads) {
        i.join();
    }
    myMerging(vect, 0, vect.size());
    return vect;
}
