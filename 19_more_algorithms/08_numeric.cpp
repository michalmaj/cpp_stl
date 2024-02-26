/*
 * Numeric
 * The numeric algorithms std::accumulate, std::adjacent_difference, std::partial_sum, std::inner_product and std::iota
 * and six additional C++17 algorithms std::exclusive_scan, std::inclusive_scan, std::transform_exclusive_scan,
 * std::transform_inclusive_scan, std::reduce and std::transform_reduce are special. All of them are defined in the
 * header <numeric>. They are widely applicable because they can be configured with callable.
 *
 * std::accumulate without a callable uses the following strategy:
 *  result = init;
 *  result += *(first+0);
 *  result += *(first+1);
 *
 * std::adjacent_difference without callable uses the following strategy:
 *  *(result) = *first;
 *  *(result+1) = *(first+1) - *(first);
 *  *(result+2) = *(first+2) - *(first+1);
 *
 * std::partial_sum without callable uses the following strategy:
 *  *(result) = *first;
 *  *(result+1) = *first + *(first+1);
 *  *(result+2) = *first + *(first+1) + *(first+2);
 */
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::array<int, 9> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "std::accumulate(arr.begin(), arr.end(), 0): "
              << std::accumulate(arr.begin(), arr.end(), 0) << '\n';
    std::cout << "std::accumulate(arr.begin(), arr.end(), 1, std::multiplies{}): "
              << std::accumulate(arr.begin(), arr.end(), 1, std::multiplies{}) << '\n';

    std::cout << "\n=======================================\n\n";

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> myVec;

    std::cout << "adjacent difference:\n";
    std::adjacent_difference(vec.begin(), vec.end(),
                             std::back_inserter(myVec), std::multiplies{});
    for (const auto& e : vec) std::cout << e << ' ';
    std::cout << '\n';
    for (const auto& e : myVec) std::cout << e << ' ';
    std::cout << '\n';

    std::cout << "\n=======================================\n\n";

    std::cout << "std::inner_product(vec.begin(), vec.end(), arr.begin(), 0): "
              << std::inner_product(vec.begin(), vec.end(), arr.begin(), 0) << '\n';

    std::cout << "\n=======================================\n\n";

    myVec={};
    std::partial_sum(vec.begin(), vec.end(), std::back_inserter(myVec));
    std::cout <<  "partial_sum:\n";
    for (const auto& e : vec) std::cout << e << ' ';
    std::cout << '\n';
    for ( auto v: myVec) std::cout << v << " ";
    std::cout << '\n';

    std::cout << "\n=======================================\n\n";

    std::cout << "iota:\n";
    std::vector<int> myLongVec(100);
    std::iota(myLongVec.begin(), myLongVec.end(),  2000);

    for ( auto v: myLongVec) std::cout << v << " ";


    return 0;
}