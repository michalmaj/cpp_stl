/*
 * Move Ranges
 * std::move moves the ranges forward; std::move_backward moves ranges backwards
 * Both algorithms need a destination iterator result, to which the range is moved. In the case of the std::move
 * algorithm, this is an output iterator, and in the case of the std::move_backward algorithm, this is a bidirectional
 * iterator. The algorithms return output or a bidirectional iterator, pointing to the initial position in the
 * destination range.
 *
 * The source range may be changed
 * std::move and std::move_backward apply move semantics. Therefore, the source range is valid but does have not
 * necessarily the same elements afterward.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

int main(){
    std::vector<int> myVec(10);
    std::ranges::iota(myVec, 0);

    std::vector<int> myVec2(myVec.size());

    std::ranges::move(myVec, myVec2.begin());
    for (const auto& e : myVec2) std::cout << e << " ";


    return 0;
}