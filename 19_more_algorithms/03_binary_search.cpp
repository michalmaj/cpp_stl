/*
 * Binary Search
 * The binary search algorithms use the fact that the ranges are already sorted. To search for an element, use
 * std::binary_search. With std::lower_bound we get an iterator for the first element, being no smaller than the given
 * value. With std::upper_bound we get an iterator back for the first element, which is bigger than the given value.
 * std::equal_range combines both algorithms.
 * If the container has n elements, we need on average log2(n) comparisons for the container. Per default comparison
 * criterion is std::less, but we can adjust it. Our sorting criterion has to obey the strict weak ordering. If not,
 * the program is undefined.
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>

bool isLessAbs(int a, int b) {
    return std::abs(a) < std::abs(b);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    for (const auto& e : v) {
        out << e << " ";
    }
    return out;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> vec{-3, 0, -3, 2, -3, 5, -3, 7, -0, 6, -3, 5, -6, 8, 9, 0, 8, 7, -7, 8, 9, -6, 3, -3, 2};
    std::cout << "vec contains: " << vec << "\n";

    std::ranges::sort(vec, isLessAbs);
    std::cout << "vec after sorting: " << vec << "\n";

    std::cout << "std::ranges::binary_search(vec, -5, isLessAbs): "
              << std::ranges::binary_search(vec, -5, isLessAbs) << "\n";
    std::cout << "std::ranges::binary_search(vec, 5, isLessAbs): "
              << std::ranges::binary_search(vec, 5, isLessAbs) << "\n";

    auto subrange = std::ranges::equal_range(vec, 3, isLessAbs);
    std::cout << "Position of first value of 3: " << std::distance(vec.begin(), subrange.begin()) << "\n";
    std::cout << "Position of first last of 3: " << std::distance(vec.begin(), subrange.end() - 1) << "\n";

    for (const auto& e : subrange)
        std::cout << e << " ";


    return 0;
}