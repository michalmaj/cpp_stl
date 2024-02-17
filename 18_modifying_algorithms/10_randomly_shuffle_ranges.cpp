/*
 * Randomly Shuffle Ranges
 * We can randomly shuffle with std::random_shuffle and std::shuffle.
 *
 * Prefer std::shuffle
 * Use std:: shuffle instead os std::random_shuffle. std::random_shuffle has been deprecated since C++14 and removed
 * in C++17, because it uses the C function rand internally.
 */
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <ranges>
#include <vector>

template <typename T>
void printVec(const std::vector<T>& vec){
    for (const auto& e : vec)
        std::cout << e << " ";
    std::cout << "\n";
}

int main(){
    std::vector<int> vec1(10);
    std::ranges::iota(vec1, 0);

    std::vector<int> vec2(vec1);

    printVec(vec1);
    std::cout << "\n";

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(vec1.begin(), vec1.end(), std::default_random_engine(seed));
    printVec(vec1);

    return 0;
}