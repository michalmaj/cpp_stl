/*
 * Permutations
 * std::prev_permutation and std::next_permutation return the previous smaller or next bigger permutation of the newly
 * ordered range. If a smaller or bigger permutation is not available, the algorithms return false. Both algorithms
 * need bidirectional iterators. Per default, the predefined sorting criterion std::less is used. If we use our sorting
 * criterion, it has to obey the strict weak ordering. If not, the program is undefined.
 */
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> myInts{1, 2, 3};
    std::cout << "All 3! permutations\n\n";
    std::cout << "forwards:\n";

    do {
        for (const auto& i : myInts) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    } while (std::next_permutation(myInts.begin(), myInts.end()));

    std::cout << "\n=======================================\n\n";

    std::ranges::reverse(myInts);
    std::cout << "All 3! permutations\n\n";
    std::cout << "backwards:\n";

    do {
        for (const auto& i : myInts) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    } while (std::prev_permutation(myInts.begin(), myInts.end()));



    return 0;
}