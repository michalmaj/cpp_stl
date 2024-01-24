/*
 * Function Objects
 * At first, don't call them functors. That's a well-defined term from the category theory.
 * Function objects are objects that behave like functions. They achieve this due to their call operator being
 * implemented. As functions objects are objects, they can have attributes and therefore states.
 *
 * Instantiate function objects to use them
 * It's a common error that only the name of the function object (Square) and not the instance of function object
 * (Square()) is used in an algorithm std::for_each(myVEc.begin(), myVec.end(), Square). That's of course an error. We
 * have to use the instance std::for_each(myVEc.begin(), myVec.end(), Square())
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct Square{
    void operator()(int& i){
        i *= i;
    }
};

int main(){
    std::vector<int> myVec(10);
    std::iota(myVec.begin(), myVec.end(), 1);
    std::cout << "myVec contains before square: ";
    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    std::for_each(myVec.begin(), myVec.end(), Square());
    std::cout << "myVec contains after square: ";
    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}