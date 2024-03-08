/*
 * Element Access
 * The access to the element of a string str is very convenient, because the string supports random access iterators. We
 * can access with str.front() the first character and with str.back() the last character of the string. With str[n] and
 * str.at(n) we get the n-th element by index.
 */
#include <algorithm>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {

    std::string str;
    std::generate_n(std::back_inserter(str), 10, [c = '0']()mutable{
        return c++;
    });
    std::cout << "str: " << str << '\n';
    std::cout << "str.front(): " << str.front() << '\n';
    std::cout << "str.back(): " << str.back() << '\n';

    std::cout << "\n======================================\n\n";

    for (size_t i{0}; const auto& e : str) {
        std::cout << std::format("str[{}]: ", i++) << e << '\n';
    }

    std::cout << "\n======================================\n\n";

    try {
        str.at(10);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n======================================\n\n";

    std::cout << "*(&str[0]+5): " << *(&str[0]+5) << '\n';
    std::cout << "*(&str[5]): " << *(&str[5]) << '\n';
    std::cout << "str[5]: " << str[5] << '\n';

    return 0;
}