/*
 * Rotate Ranges
 * We can rotate our data such that every element now lies at a different index, which is decided by the rotation offset
 * std::rotate and std::rotate_copy rotate their elements. Rotates the elements is such way that middle becomes the new
 * first element.
 */
#include <algorithm>
#include <iostream>
#include <string>

int main(){
    std::string str;
    std::generate_n(std::back_inserter(str), 9, [i=0]() mutable {
        i++;
        return static_cast<char>(i + '0');
    });
    std::cout << str << "\n";

    auto it = str.end();

    for (auto middleIt = str.begin(); middleIt != it; ++middleIt) {
        std::rotate(str.begin(), middleIt, str.end());
        std::cout << str << "\n";
    }

    return 0;
}