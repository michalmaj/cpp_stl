/*
 * Functions and Function Objects
 *
 * Functions
 * Functions are the simplest callables. They can have - apart from static variables - no state. Because the definition
 * of a function is often widely separated from its use or even is a different translation unit, the compiler has fewer
 * opportunities to optimize the resulting code.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void square(int& i) {
    i *= i;
}

int main(){
    std::vector<int> myVec(10);
    std::iota(myVec.begin(), myVec.end(), 1);

    std::cout << "myVec before square each element: ";
    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    std::for_each(myVec.begin(), myVec.end(), square);
    std::cout << "myVec after square each element: ";
    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}