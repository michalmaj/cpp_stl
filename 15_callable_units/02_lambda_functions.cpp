/*
 * Lambda Functions
 * Lambda functions provide us all the functionality we need, on the go. They are faster than usual functions.
 *
 * Lambda functions provide in-place functionality. The compiler gets a lots of insights and has therefore great
 * optimization potential. Lambda functions can receive their arguments by value or by reference. They can capture
 * their environment by value, by reference, and with C++14 by move.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main(){
    std::vector<int> myVec(10);
    std::iota(myVec.begin(), myVec.end(), 1);
    std::cout << "myVec contains: ";
    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    std::cout << "myVec contains: ";
    std::for_each(myVec.begin(), myVec.end(), [](auto& i){
        i *= i;
        std::cout << i << " ";
    });
    std::cout << "\n";

    return 0;
}