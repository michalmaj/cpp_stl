/*
 * Arrays
 * std::array is a homogeneous container of fixed length. It needs the header <array>. The std::array combines the
 * memory and runtime characteristic of a C-array with the interface of std::vector. This means is particular, the
 * std::array knows its size. We can use std::array in the algorithms of the STL.
 *
 * We have to keep a few special rules in our minds to initialise a std::array:
 *  - std::array<int, 10> arr: The 10 elements are not initialised.
 *  - std::array<int, 10> arr{}: The 10 elements are default initialised.
 *  - std::array<int, 10> arr{1, 2, 3, 4, 5}: The remaining elements are default initialised.
 *
 * std::array supports three types of index access:
 *  1. arr[n];
 *  2. arr.at(n);
 *  3. std::get<n>(arr);
 * The most often used first type form with square brackets doesn't check boundaries of the arr. This is in opposition
 * to arr.at(n). We will get eventually a std::range-error exception. The last type shows the relationship of std::array
 * with the std::tuple, because both are containers of fixed length.
 */
#include <algorithm>
#include <iostream>
#include <array>
#include <numeric>

int main(){
    std::array<int, 10> arr;
    std::iota(arr.begin(), arr.end(), 1);
    std::cout << "arr contains: ";
    for (const auto& a : arr) std::cout << a << " ";
    std::cout << "\n";

    double sum = std::accumulate(arr.begin(), arr.end(), 0.0);
    double mean = sum / arr.size();
    std::cout << "Mean of arr: " << mean << "\n";

    return 0;
}