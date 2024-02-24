/*
 * Min and Max
 * We can determine the minimum, the maximum and the minimum and maximum pair of a range with the algorithms
 * std::min_element, std::max_element and std::minmax_element. Each algorithm can be configured with a binary predicate.
 * If the range has more than one minimum or maximum element, the first one is returned.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string toString(int i) {
    std::stringstream buff;
    buff.str("");
    buff << i;
    std::string val = buff.str();
    return val;
}

int toInt(const std::string& s) {
    std::stringstream buff;
    buff.str("");
    buff << s;
    int value;
    buff >> value;
    return value;
}

int main() {
    std::vector<int> myInts;
    std::vector<std::string> myStrings{
        "94", "5", "39", "-4", "-49", "1001", "-77", "23", "0", "84", "59", "96", "6", "-94", "87"
    };
    std::transform(myStrings.begin(), myStrings.end(), std::back_inserter(myInts), toInt);
    for (const auto& e : myInts) {
        std::cout << e << " ";
    }
    std::cout << "\n";

    auto paInt = std::minmax_element(myInts.begin(), myInts.end());
    std::cout << "std::minmax_element(myInts.begin(), myInts.end()): " << "("
              << *paInt.first << "," << *paInt.second << ")\n";

    auto paStr = std::minmax_element(myStrings.begin(), myStrings.end());
    std::cout << "std::minmax_element(myStrings.begin(), myStrings.end()): " << "("
              << *paStr.first << "," << *paStr.second << ")\n";

    auto paStrAsInt = std::minmax_element(myStrings.begin(), myStrings.end(),
                                          [](auto& a, auto& b){
                                              return toInt(a) < toInt(b);
    });
    std::cout << "std::minmax_element(myStrings.begin(), myStrings.end()): " << "("
              << *paStrAsInt.first << "," << *paStrAsInt.second << ")\n";

    return 0;
}