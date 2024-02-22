/*
 * Merge Operations
 * Merge operations empower us to merge sorted ranges in a new sorted range. The algorithm requires that the ranges and
 * the algorithm use the same sorting criterion. If not, the program is undefined. Per default, the predefined sorting
 * criterion std::less is used. If we use our sorting criterion, it has to obey the strict weak ordering. If not, the
 * program is undefined.
 * We can merge two sorted ranges with std::inplace_merge and std::merge. We can check with std::includes if one sorted
 * range is in another sorted range. We can merge with std::set_difference, std::set_intersection,
 * std::set_symmetric_difference and std::set_union two sorted ranges in a new sorted range.
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec) {
    for (const auto& e : vec) {
        out << e << " ";
    }
    return out;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> vec1{1, 1, 4, 3, 5, 8, 6, 7, 9, 2};
    std::vector<int> vec2{1, 2, 3};

    std::cout << "vec1 contains: " << vec1 << "\n";
    std::cout << "vec2 contains: " << vec2 << "\n";

    std::ranges::sort(vec1);
    std::vector<int> vec(vec1);

    std::cout << "\n==================================\n";

    std::cout << "std::ranges::includes(vec1, vec2): " << std::ranges::includes(vec1, vec2) << "\n";

    std::cout << "\n==================================\n";

    vec1.reserve(vec1.size() + vec2.size());
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    std::cout << "vec1 after inserting vec2 contains: " << vec1 << "\n";

    std::cout << "\n==================================\n";

    std::inplace_merge(vec1.begin(), vec1.end() - vec2.size(), vec1.end());
    std::cout << "vec1 after inplace_merge contains: " << vec1 << "\n";

    std::cout << "\n==================================\n";

    vec2.push_back(10);
    std::cout << "vec contains: " << vec << '\n';
    std::cout << "vec2 contains: " << vec2 << '\n';

    std::vector<int> res;
    std::set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
                   std::back_inserter(res));
    std::cout << "set_union of vec and vec2: " << res << '\n';

    res = {};
    std::ranges::set_intersection(vec, vec2, std::back_inserter(res));
    std::cout << "set_intersection of vec and vec2: " << res << '\n';

    res = {};
    std::ranges::set_difference(vec, vec2, std::back_inserter(res));
    std::cout << "set_difference of vec and vec2: " << res << '\n';

    res = {};
    std::ranges::set_symmetric_difference(vec, vec2, std::back_inserter(res));
    std::cout << "set_symmetric_difference of vec and vec2: " << res << '\n';


    return 0;
}