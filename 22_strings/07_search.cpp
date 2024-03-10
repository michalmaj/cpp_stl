/*
 * Search
 * C++ offers the ability to search in a string in many variations. Each variation exists in various overloaded forms.
 *
 * Search is called find
 * Odd enough the algorithms for search in a string start with the name find. If the search was successful, we get the
 * index of type std::string::size_type, if not, we get the constant std::string::npos. The first character has an
 * index 0.
 *
 * The find algorithms support to:
 *  - search for a character, a C String or a C++ string;
 *  - search for a character from a C or C++ string;
 *  - search forward and backward;
 *  - search positive (does contain) or negative (does not contain) for character from a C or C++ string;
 *  - start the search at an arbitrary position in the string.
 * The arguments of all six variations of the find functions follow a similar pattern. The first argument is the text we
 * are searching for. The second argument holds the start position of the search, and the third is the number of
 * characters' string from the second argument.
 *
 * The siz variations:
 *  - str.find(...): Returns the first position of a character;
 *  - str.rfind(...): Returns the last position of a character;
 *  - str.find_first_of(...): Returns the first position of a character;
 *  - str.find_last_of(...): Returns the last position of a character;
 *  - str.find_first_not_of(...): Returns the first position of a character in str, which is not;
 *  - str.find_last_not_of(...): Returns the last position of a character in str, which is not;
 */
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string str;

    auto idx = str.find("no");
    if (idx == std::string::npos) {
        std::cout << "not found\n";
    }

    str= {"dkeu84kf8k48kdj39kdj74945du942"};
    std::string str2{"84"};

    std::cout << str.find('8') << '\n';
    std::cout << str.rfind('8') << '\n';
    std::cout << str.find('8', 10) << '\n';
    std::cout << str.find(str2) << '\n';
    std::cout << str.rfind(str2) << '\n';
    std::cout << str.find(str2, 10) << '\n';

    str2 = "";
    std::generate_n(std::back_inserter(str2), 10, [c='0']() mutable {
       return c++;
    });

    std::cout << str.find_first_of("678") << std::endl;                    // 4
    std::cout << str.find_last_of("678") << std::endl;                     // 20
    std::cout << str.find_first_of("678", 10) << std::endl;                // 11
    std::cout << str.find_first_of(str2) << std::endl;                     // 4
    std::cout << str.find_last_of(str2) << std::endl;                      // 29
    std::cout << str.find_first_of(str2, 10) << std::endl;                 // 10
    std::cout << str.find_first_not_of("678") << std::endl;                // 0
    std::cout << str.find_last_not_of("678") << std::endl;                 // 29
    std::cout << str.find_first_not_of("678", 10) << std::endl;            // 10
    std::cout << str.find_first_not_of(str2) << std::endl;                 // 0
    std::cout << str.find_last_not_of(str2) << std::endl;                  // 26
    std::cout << str.find_first_not_of(str2, 10) << std::endl;             // 12

    return 0;
}