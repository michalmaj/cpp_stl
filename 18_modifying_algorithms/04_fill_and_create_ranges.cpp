/*
 * Fill and Create Ranges
 * We can fill a range with std::fill and std::fill_n, we can generate new elements with std::generate and
 * std::generate_n.
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main(){

    auto getNext = [val{0}]()mutable {
      return val++;
    };

    std::vector<int> vec(20);
    std::fill(vec.begin(), vec.end(), 2024);
    for (const auto& e : vec) std::cout << e << " ";
    std::cout << "\n";

    std::generate_n(vec.begin(), 15, getNext);
    for (const auto& e : vec) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}