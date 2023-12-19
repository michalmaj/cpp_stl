/*
 * std::optional
 * std::optional is very convenient when the value of our object can be null or empty.
 * std::optional is quite comfortable for calculations such as database queries that may have a result.
 *
 * Don;t use non-results
 * Before C++17 it was common practice to use a special value such as a null-pointer, an empty string, or a unique
 * integer to denote the absence of a result. These special values or no-results are very error-prone because we have
 * to misuse the type system to check the return value. This means that for the type system that we have to use a
 * regular value such as empty string to define an irregular value.
 *
 * The various constructors and the convenience function std::make_optional let us define an optional object opt with
 * or without value. We can explicitly ask a std::optional container if it has a value, or we can check it in a logical
 * expression. opt.value returns the value and opt.value_or returns the value or a default value. If opt has no
 * contained value, the call opt.value will throw a std::bad_optional_access exception.
 */
#include <iostream>
#include <optional>
#include <vector>

// We use std::optional in the function getFirst. This function returns the first element if it exists. If not, we will
// get a std::optional<int> object.
std::optional<int> getFirst(const std::vector<int>& vec){
    if (!vec.empty())
        return std::optional<int>(vec.at(0));
    return std::optional<int>();
}

int main(){
    // Here, we have two vectors. Both invoke getFirst and return a std::optional object.
    std::vector<int> myVec{1, 2, 3};
    std::vector<int> emptyVec;

    auto myInt = getFirst(myVec);

    if (myInt){
        std::cout << *myInt << "\n"; // 1
        std::cout << myInt.value() << "\n"; // 1
        std::cout << myInt.value_or(2023) << "\n"; // 1
    }

    auto myEmptyInt = getFirst(emptyVec);

    if (myEmptyInt){
        std::cout << *myEmptyInt << "\n";
        std::cout << myEmptyInt.value() << "\n";
        std::cout << myEmptyInt.value_or(2023) << "\n";
    }
    else{
     std::cout << myEmptyInt.value_or(2023) << "\n";  // 2023
    }

    return 0;
}