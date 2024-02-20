/*
 * Sort
 * We can sort a range with std::sort or std::stable_sort or sort until a position with std::stable_sort. In addition,
 * std::partial_sort_copy copies sorted range. With std::nth_element we can assign an element the sorted position in
 * the range. We can check with std::is_sorted if a range is sorted. If we want to know until which position a range
 * is sorted, we use std::is_sorted_until.
 * Per default, the predefined function object std::less is used a as sorting criterion. However, we can use our sorting
 * criterion.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << std::boolalpha;

    std::string str{"RUdAjdDkaACsdfjwldXmnEiVSEZTiepfgOIkue"};
    std::cout << str << '\n';
    std::cout << "std::is_sorted(str.begin(), str.end()): "
              << std::is_sorted(str.begin(), str.end()) << '\n';

    std::cout << '\n';

    std::partial_sort(str.begin(), str.begin() + 30, str.end());
    std::cout << str << '\n';

    auto sortUntil = std::is_sorted_until(str.begin(), str.end());
    std::cout << "Sorted until: " << *sortUntil << " at index: "
                                  << std::distance(str.begin(), sortUntil) << '\n';
    for (auto it = str.begin(); it != sortUntil; ++it) {
        std::cout << *it;
    }
    std::cout << "\n\n";

    std::vector<int> vec{1, 0, 4, 3, 5};
    auto vecIt = vec.begin() + 2;
    std::nth_element(vec.begin(), vecIt, vec.end());
    std::cout << "Sorted element at 2nd index: " << *vecIt << "\n";


    return 0;
}