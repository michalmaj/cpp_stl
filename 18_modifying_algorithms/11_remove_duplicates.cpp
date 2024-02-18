/*
 * Remove Duplicates
 * With the algorithms std::unique and std::unique_copy we have more opportunities to remove adjacent duplicates. This
 * can be done with and without a binary predicate.
 *
 * The unique algorithms return the new logical end iterator
 * The unique algorithms return the logical end iterator of the range. The elements have to be removed with the
 * erase-remove idiom.
 */
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    for (const auto& e : vec) {
        out << e << " ";
    }
    return out;
}

int main() {
    std::vector<int> myVec{0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 3, 6, 7, 8, 1, 3, 3, 8, 8, 9};
    std::cout << "myVec contains: " << myVec << "\n";

    myVec.erase(std::unique(myVec.begin(), myVec.end()), myVec.end());
    std::cout << "After erase myVec contains: " << myVec << "\n";

    std::cout << "\n====================================\n\n";

    std::vector<int> myVec2{1, 4, 3, 3, 3, 5, 7, 9, 2, 4, 1, 6, 8, 0, 3, 5, 7, 8, 7, 3, 9, 2, 4, 2, 5, 7, 3};
    std::vector<int> resVec;

    resVec.reserve(myVec2.size());
    std::unique_copy(myVec2.begin(), myVec2.end(), std::back_inserter(resVec),
                     [](auto a, auto b){return (a % 2) == (b % 2);});
    std::cout << "myVec2 contains: " << myVec2 << "\n";
    std::cout << "resVec contains: " << resVec << "\n";


    return 0;
}