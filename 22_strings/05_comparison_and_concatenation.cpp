/*
 * Comparison and Concatenation
 *
 * Comparison
 * Strings support the well-known comparison operators ==, !=, <, >, >=. THe comparison of two strings takes palce on
 * their elements.
 *
 * String Concatenation
 * The + operator is overloaded for strings, so we can add strings.
 * The + operator is only overloaded for C++ strings. The C++ type system permits it to concatenate C++ and C strings
 * to C++ string, but no to concatenate C++ and C strings to C strings. The reason is that the + operator is overloaded
 * for C++ strings. Therefore only the second line is valid C++, because the C is implicitly converted to a C++ string:
 *  std::string wrong = "1" + "1"; // ERROR
 *  std::string right = std::string("1") + "1"; // 11
 */
#include <iostream>
#include <string>

int main() {

    std::cout << std::boolalpha << std::endl;

    std::string first{"aaa"};
    std::string second{"aaaa"};

    std::cout << "first <  first: " << (first < first) << std::endl;
    std::cout << "first <=  first: " << (first <= first) << std::endl;
    std::cout << "first <  second: " << (first < second) << std::endl;

    std::cout << std::endl;

    std::string one{"1"};
    std::string oneOneOne= one+ std::string("1") +"1";

    std::cout << "1 + 1 + 1: " << oneOneOne << std::endl;

    return 0;
}