/*
 * Conversion Between C++ and C Strings
 * There are several ways to convert C++ strings to C strings.
 * While the conversion of a C string in a C++ string is done implicitly, we must explicitly request the conversion from
 * C++ string into a C string. str.copy() copies the content of a C++ string without the terminating \0 character.
 * str.data() and str.c_str() includes the terminating null character.
 *
 * Be careful with str.data() and str.c_str()
 * The return value of the two methods str.data() and str.c_str() is invalid, if we modify the str.
 */
#include <iostream>
#include <string>

int main() {
    std::string str{"C++-String"};
    std::cout << str << std::endl;
    str += "C-String";
    std::cout << str << std::endl;

    const char* cString = str.c_str();
    char buffer[10];
    str.copy(buffer, 10);

    str += "works";
    const char* cString2 = cString;

    std::string str2(buffer, buffer+10);
    std::cout << str2 << '\n';

    return 0;
}