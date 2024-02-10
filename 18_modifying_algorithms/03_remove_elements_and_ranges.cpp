/*
 * Remove Elements and Ranges
 * The four variations std::remove, std::remove_if, std::remove_copy, std::remove_copy_if support two kinds of
 * operations. On one hand, remove elements with and without a predicate from a range. On the other hand, copy the
 * result of our modification to a new range.
 *
 * Apply the erase-remove idiom
 * The remove variations don't remove an element from the range. They return the new logical end of the range. We have
 * to adjust the size of the container with the erase-remove idiom.
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for (const auto& e : v){
        out << e << " ";
    }
    return out;
}

int main(){
    std::vector<int> myVec(10);
    std::ranges::iota(myVec, 0);
    std::cout << myVec << "\n";

    auto newIt = std::remove_if(myVec.begin(), myVec.end(), [](int a){
        return a % 2;
    });
    std::cout << myVec << "\n";

    myVec.erase(newIt, myVec.end());
    std::cout << myVec << "\n";

    std::cout << "\n\n";

    std::string str{"Only for Testing Purpose."};
    std::cout << str << std::endl;

    str.erase(std::remove_if(str.begin(), str.end(), [](char c){
        return std::isupper(c);
    }), str.end());
    std::cout << str << std::endl;

    return 0;
}