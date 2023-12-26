/*
 * Compare
 * All the general comparison operators work on containers.
 *
 * Containers support the comparison operators ==, !=, <, >, <=, >=. The comparison of two containers happens on the
 * elements of the containers. If we compare associative containers, their elements and sizes are compared. Unordered
 * associative containers support only the comparison operator == and !=.
 */
#include <array>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

int main(){
    std::cout << std::boolalpha;

    std::vector vec1{1, 2, 3, 4};
    std::vector vec2{1, 2, 3, 4};
    std::cout << "(vec1 == vec2): " << (vec1 == vec2) << "\n";

    std::cout << "=========================\n\n";

    std::array arr1{1, 2, 3, 4};
    std::array arr2{1, 2, 3, 4};
    std::cout << "(arr1 == arr2): " << (arr1 == arr2) << "\n";

    std::cout << "=========================\n\n";

    std::set set1{1, 2, 3, 4};
    std::set set2{4, 3, 2, 1};
    std::cout << "(set1 == set2): " << (set1 == set2) << "\n";

    std::cout << "=========================\n\n";

    std::set set3{1, 2, 3, 4, 5};
    std::cout << "(set1 < set3): " << (set1 < set3) << "\n";

    std::cout << "=========================\n\n";

    std::set set4{1, 2, 3, -3};
    std::cout << "(set1 > set4): " << (set1 > set4) << "\n";

    std::cout << "=========================\n\n";

    std::unordered_map<int, std::string> um1{{1, "one"}, {2, "two"}};
    std::unordered_map<int, std::string> um2{{1, "one"}, {2, "Two"}};
    std::cout << "(um1 == um2): " << (um1 == um2) << "\n";


    return 0;
}