/*
 * Numeric Conversions
 * We can convert with std::to_string(val) and std::to_wstring(val) numbers or floating point numbers to the
 * corresponding std::string or std::wstring. For opposite direction for the numbers or floating point numbers, we have
 * the function family of the sto* functions. ALl functions need the header <string>.
 *
 * Read sto* as string to
 * The seven ways to convert a string into a natural or floating point number follow a simple pattern. All functions
 * start with sto and add further characters, denoting the type to which the strings should be converted to. E.g., stol
 * stands for string to long or stod for string to double.
 *
 * The sto functions all have the same interface The example shows it for the type long:
 *  std::stol(str, idx=nullptr, base=10)
 * The function takes a string and determines the long representation to the base. stol ignores leading spaces and
 * optionally returns the index of the first invalid character in idx. By default, the base is 10. Valid values for the
 * base are 0 and 2 until 36. If we use base 0 the compiler automatically determines the type based on the format of
 * the string. If the base is bigger than 10 the compiler encodes them in the characters a until z. The representation
 * is analogues to the representation of hexadecimal numbers.
 *
 * Overview of all functions:
 *  - std::to_string(val): Converts val into a std::string.
 *  - std::to_wstring(val): Converts val into a std::wstring.
 *  - std::stoi(str): Returns an int value.
 *  - std::stol(str): Returns a long value.
 *  - std::stoll(str): Returns a long long value.
 *  - std::stoul(str): Returns an unsigned long value.
 *  - std::stoull(str): Returns an unsigned long long value.
 *  - std::stof(str): Returns a float value.
 *  - std::stod(str): Returns a double value.
 *  - std::stold(str): Returns a long double value.
 * The functions throw a std::invalid_argument exception if the conversion is not possible. If the determined value is
 * too big for the destination type, we get a std::out_of_range exception.
 *
 * Where is the stou function?
 * In case we're curious, the C++ sto functions are thin wrappers around the C strto* functions, but there is nn strtou
 * function in C. Therefore C++ has no stou function.
 */
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::cout << "to_string, to_wstring\n";

    std::string maxLongLongString = std::to_string(std::numeric_limits<long long>::max());
    std::wstring maxLongLongWstring = std::to_wstring(std::numeric_limits<long long>::max());

    std::cout << std::numeric_limits<long long>::max() << '\n';
    std::cout << maxLongLongString << '\n';
    std::wcout << maxLongLongWstring << '\n';

    std::cout << "\n============================================\n\n";

    std::cout << "ato*\n";

    std::string str("10010101");

    std::cout << std::stoi(str) << '\n';
    std::cout << std::stoi(str, nullptr, 16) << '\n';
    std::cout << std::stoi(str, nullptr, 8) << '\n';
    std::cout << std::stoi(str, nullptr, 2) << '\n';

    std::cout << "\n============================================\n\n";

    std::size_t idx;
    std::cout << std::stod("        3.5 km", &idx) << '\n';
    std::cout << "Not numeric char at position: " << idx << ".\n";

    std::cout << "\n============================================\n\n";

    try {
        std::cout << std::stoi("        3.5 km") << '\n';
        std::cout << std::stoi("        3.5 km", nullptr, 2) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }


    return 0;
}