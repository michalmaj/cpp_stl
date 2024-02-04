/*
 * Check Conditions on Ranges
 * C++17 contains several algorithms to check whether a value or values in range fulfill our given condition.
 * The three functions std::all_of, std::any_of, std::none_of answer the question, if all, at least one or no element of
 * a range satisfies the condition. The functions need as argument input iterators and a unary predicate and return a
 * boolean.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main(){
    auto even = [](int i) -> bool {return i % 2;};
    std::vector<int> myVec(9);
    std::ranges::iota(myVec, 1);
    std::cout << "myVec contains: ";
    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    std::cout << std::boolalpha;
    std::cout << "std::ranges::any_of(myVec, even): " << std::ranges::any_of(myVec, even) << std::endl;
    std::cout << "std::ranges::all_of(myVec, even): " << std::ranges::all_of(myVec, even) << std::endl;
    std::cout << "std::ranges::none_of(myVec, even): " << std::ranges::none_of(myVec, even) << std::endl;


    return 0;
}