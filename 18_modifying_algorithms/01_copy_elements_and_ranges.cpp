/*
 * Copy Elements and Ranges
 * We can copy ranges forward with std::copy, backward with std::copy_backward and conditionally with std::copy_if. If
 * we want to copy n elements, we can use std::copy_n:
 *  - copy: copies the range.
 *  - copy_n: copies n elements.
 *  - copy_if: copies the elements dependent on the predicate pre.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

int main(){
    std::vector<int> myVec(10);
    std::ranges::iota(myVec, 0);
    std::vector<int> myVec2(10);

    std::copy_if(myVec.begin(), myVec.end(), myVec2.begin()+3, [](int a){
        return a % 2;
    });
    for (const auto& e : myVec2) std::cout << e << " ";
    std::cout << "\n";

    std::cout << "===========================\n\n";

    std::string str{"Iamstring1"};
    std::string str2{"Hellostring---------------------2"};
    std::cout << str2 << "\n";
    std::copy_backward(str.begin(), str.end(), str2.end());
    std::cout << str2 << "\n";

    std::cout << "\n";

    std::cout << str << "\n";
    std::copy_backward(str.begin(), str.begin()+5, str.end());
    std::cout << str << "\n";

    return 0;
}