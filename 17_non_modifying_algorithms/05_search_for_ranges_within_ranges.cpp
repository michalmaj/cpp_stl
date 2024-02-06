/*
 * Search for Ranges within Ranges
 * std::search searches for a range in another range from the beginning, std::find_end from the end. std::search_n
 * searches for n consecutive elements in the range.
 * All algorithms take a forward iterator, can be parametrized by a binary predicate, and return an end iterator for the
 * first range if the search was unsuccessful.
 * Searches the second range in the first one and returns the position.
 */
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>


int main(){
    std::array<int, 10> arr1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 5> arr2{3, 4, -5, 6, 7};

    auto fwdIt = std::search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());
    if (fwdIt == arr1.end()){
        std::cout << "arr2 not in arr1\n";
    }
    else {
        std::cout << "arr2 at position: " << std::distance(arr1.begin(), fwdIt) << " in arr1.\n";
    }

    auto fwdIt2 = std::search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), [](int a, int b){
       return std::abs(a) == std::abs(b);
    });
    if (fwdIt2 == arr1.end()){
        std::cout << "arr2 not in arr1\n";
    }
    else {
        std::cout << "arr2 at position: " << std::distance(arr1.begin(), fwdIt2) << " in arr1.\n";
    }

    return 0;
}