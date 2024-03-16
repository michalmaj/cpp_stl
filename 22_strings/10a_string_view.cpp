/*
 * Modifying operations
 * There are a few modifying operations that a string view can perform. Some of these are unique to string view only.
 *
 * The call stringView.swap(stringView2) swaps the content of the 2 strings views. The method remove_prefix and
 * remove_suffix are unique to a string view because a string supports neither. remove_prefix shrinks its start forward
 * remove_suffix shrinks its end backward.
 */
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string str{"   A lot of space"};
    std::string_view strView{str};
    strView.remove_prefix(std::min(strView.find_first_not_of(' '), strView.size()));

    std::cout << str << '\n';
    std::cout << strView << '\n';

    std::cout << "\n=======================================\n\n";

    char arr[]{'A', ' ', 'l', 'o', 't', ' ', 'o', 'f', ' ', 's', 'p', 'a', 'c', 'e', '\0',  '\0',  '\0'};
    std::string_view strView2(arr, sizeof arr);
    auto trimPos = strView2.find('\0');

    if (trimPos != strView2.npos) {
        strView2.remove_suffix(strView2.size() - trimPos);
    }

    std::cout << sizeof arr << '\n';
    std::cout << strView2.size() << '\n';

    return 0;
}