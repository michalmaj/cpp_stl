/*
 * Transform Ranges
 * The std::transform algorithm applies a unary or binary callable to a range and copies the modified elements to the
 * destination range.
 *  - Applies the unary callable fun to the elements of the input range and copies the results to result.
 *  - Applies the binary callable fun to both input ranges and copies the result to result.
 * The difference between the two versions is that the first version applies the callable to each element of the range;
 * the second version applies the callable to pairs of both ranges in parallel. The returned iterator points to one
 * position after the last transformed element.
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string str;
    std::generate_n(std::back_inserter(str), 26, [c{'a'}]() mutable {
        return c++;
    });
    std::cout << str << "\n";

    std::transform(str.begin(), str.end(), str.begin(), [](char c){
        return std::toupper(c);
    });
    std::cout << str << "\n";

    std::cout << "==============================\n\n";

    std::vector<std::string> vecStr{"Only", "for", "testing", "purpose", "."};
    std::vector<std::string> vecStr2(5, "-");
    std::vector<std::string> vecRes;

    std::transform(vecStr.begin(), vecStr.end(),
                   vecStr2.begin(),
                   std::back_inserter(vecRes),
                   [](const std::string& a, const std::string& b){return std::string(b) + a + b;});
    for (const auto& e : vecRes) std::cout << e << "\n";

    return 0;
}