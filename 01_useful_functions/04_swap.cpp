/*
 * Swap
 * Swapping is made simple in C++ using std::swap.
 *
 * With the function std::swap defined in the header <utility>, we can easily swap two objects. The generic
 * implementation in the C++ standard library internally uses the function std::move.
 */
#include <iostream>
#include <utility>
// Simple implementation
template <typename T>
inline void my_swap(T& a, T& b){
    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}

int main(){
    int a{3};
    int b{99};
    std::cout << "Before swap:\n";
    std::cout << "a: " << a << ", b: " << b << "\n\n";

    my_swap(a, b);

    std::cout << "After swap:\n";
    std::cout << "a: " << a << ", b: " << b << "\n\n";

    return 0;
}