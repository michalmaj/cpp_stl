/*
 * Modifying Operations
 * Strings have many operations to modify them. str.assign assigns a new string to the string str. With str.swap we can
 * swap two strings. To remove a character from a string use str.pop_back or str.erase. In contrary str.clean or
 * str.erase deletes the whole string. To append new characters to a string use +=, std.append or str.push_back. We can
 * use str.insert to insert new characters or str.replace to replace characters:
 *  - str = str2: Assigns str2 to str.
 *  - str.assign(...): Assigns to str a new string.
 *  - str.swap(str2): Swaps str and str2.
 *  - str.pop_back(): Removes the last character from str.
 *  - str.erase(...): Removes characters from str.
 *  - str.clear(): Clears the str.
 *  - str.append(...): Appends characters to str.
 *  - str.push_back(s): Appends the character s to str.
 *  - str.insert(pos, ...): Inserts characters in str starting at pos.
 *  - str.replace(pos, len, ...): Replaces the len characters from str starting at pos.
 *
 * The operations are available in many overloaded versions. The methods str.assign, str.append, str.insert and
 * str.replace are very similar. All four can be invoked with C++ strings and substrings, but also characters, C
 * strings, C string arrays, ranges, and initializer lists. str.erase can erase a single character, ranges, but also
 * many characters starting at a given position.
 */
#include <algorithm>
#include <iostream>
#include <string>

int main() {

    std::cout << "ASSIGN:\n";

    std::string str{"New String"};
    std::string str2{"Other string"};

    std::cout << "str: " << str << '\n';
    std::cout << "str2: " << str2 << '\n';

    str.assign(str2, 4, std::string::npos);
    std::cout << "str: " << str << '\n';

    str.assign(5, '-');
    std::cout << "str: " << str << '\n';

    std::cout << "DELETE:\n";

    str = "";
    std::generate_n(std::back_inserter(str), 10, [c='0']() mutable {
        return c++;
    });
    std::cout << "str: " << str << '\n';

    str.erase(7, 2);
    std::cout << "str: " << str << '\n';

    str.erase(str.begin()+2, str.end()-2);
    std::cout << "str: " << str << '\n';

    str.erase(str.begin()+2, str.end());
    std::cout << "str: " << str << '\n';

    str.pop_back();
    std::cout << "str: " << str << '\n';

    str.erase();
    std::cout << "str: " << str << '\n';

    std::cout << "APPEND:\n";
    std::generate_n(std::back_inserter(str), 5, [c='0']() mutable {
        return c++;
    });
    std::cout << "str: " << str << '\n';

    str += "56";
    std::cout << "str: " << str << '\n';

    str += '7';
    std::cout << "str: " << str << '\n';

    str += {'8', '9'};
    std::cout << "str: " << str << '\n';

    str.append(str);
    std::cout << "str: " << str << '\n';

    str.append(str, 2, 4);
    std::cout << "str: " << str << '\n';

    str.append(10, '0');
    std::cout << "str: " << str << '\n';

    str.append(str, 10, 10);
    std::cout << "str: " << str << '\n';

    str.push_back('9');
    std::cout << "str: " << str << '\n';

    std::cout << "INSERT\n";
    str = "345";
    std::cout << "str: " << str << '\n';

    str.insert(3, "6789");
    std::cout << "str: " << str << '\n';

    str.insert(0, "012");
    std::cout << "str: " << str << '\n';

    std::cout << "REPLACE:\n";
    str = "only for testing purpose.";
    std::cout << "str: " << str << '\n';

    str.replace(0, 0, "O");
    std::cout << "str: " << str << '\n';

    str.replace(0, 5, "Only", 0, 4);
    std::cout << "str: " << str << '\n';

    str.replace(16, 8, "");
    std::cout << "str: " << str << '\n';

    str.replace(4, 0, 5, 'y');
    std::cout << "str: " << str << '\n';

    str.replace(str.begin(), str.end(), "Only for testing purpose.");
    std::cout << "str: " << str << '\n';

    str.replace(str.begin()+4, str.end()-8, 10, '#');
    std::cout << "str: " << str << '\n';

    return 0;
}