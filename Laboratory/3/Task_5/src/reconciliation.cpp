#include "../include/reconciliation.hpp"
#include <vector>
#include <cstddef>
#include <print>
auto checkVectors(const std::vector<short>& vect1, const std::vector<short>& vect2) -> bool{
    bool same = true;
    for(size_t i = 0 ; i < vect1.size() ; i++){
        if(vect1.at(i) != vect2.at(i)){
            same = false;
            //std::println("{}\t!=\t{}", vect1.at(i), vect2.at(i));
        }
    }
    if(!same){ std::println("\t\tFALSE\n"); }
    else{ std::println("\t\tSAME\n");}
    return same;
}
