/*
 * String Introduction
 * A string is a sequence of characters. C++ has many methods to analyze or to change a string. C++ strings are the safe
 * replacement for C Strings: const char*. Strings need the header <string>
 *
 * A string is very similar to a std::vector
 * A string feels like a std::vector containing characters. It supports a very similar interface. This means that in
 * addition to the methods of the string class, we have the algorithms of the STL to work with the string.
 */
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string name{"RainerGrimm"};
    std::string firstName;
    std::string lastName;
    auto strIt = std::find_if(name.begin()+1, name.end(),
                              [](char c){return std::isupper(c);});
    if (strIt != name.end()) {
        firstName = std::string(name.begin(), strIt);
        lastName = std::string(strIt, name.end());
    }
    std::cout << "First name: " << firstName << " last name: " << lastName << '\n';

}