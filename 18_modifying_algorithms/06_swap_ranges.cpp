/*
 * Swap Ranges
 * std::swap and std::swap_ranges can swap objects and ranges
 * The ranges must not overlap.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v) {
    for (const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> myVec2(10);
    std::cout << "myVec: " << myVec << "\n";
    std::cout << "myVec2: " << myVec2 << "\n";

    std::swap(myVec, myVec2);

    std::cout << "myVec: " << myVec << "\n";
    std::cout << "myVec2: " << myVec2 << "\n";

    std::cout << "=============================\n\n";

    std::string str{"abcdefghijklmnop"};
    std::string str2{"---------------------"};

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    std::swap_ranges(str.begin(), str.begin()+5, str2.begin()+5);

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    return 0;
}