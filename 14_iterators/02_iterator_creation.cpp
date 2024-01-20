/*
 * Iterator Creation
 * Each container generates its suitable iterator on request. For example, a std::unordered_map generates constant and
 * non-constant iterators.
 *  std::unordered_map<std::string, int>::iterator umIt = um.begin();
 *  std::unordered_map<std::string, int>::iterator umIt = um.end();
 *
 *  std::unordered_map<std::string, int>::const_iterator umIt = um.cbegin();
 *  std::unordered_map<std::string, int>::const_iterator umIt = um.cend();
 * In addition, std::map supports the backward iterators:
 *  std::map<std::string, int>::reverse_iterator mIt = m.rbegin();
 *  std::map<std::string, int>::reverse_iterator mIt = m.rend();
 *
 *  std::map<std::string, int>::const_reverse_iterator mIt = m.rcbegin();
 *  std::map<std::string, int>::const_reverse_iterator mIt = m.rcend();
 *
 * Use auto for iterator definition
 * Iterator definition is very labour intensive. The automatic type deduction with auto reduces the writing to the bare
 * minimum:
 *  std::map<std::string, int>::const_reverse_iterator mIt = m.rcbegin();
 *  auto mIt = m.rcbegin();
 */
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

int main(){
    std::unordered_map<std::string, int> unorderedMap{
            {"Rainer", 1966},
            {"Beatrix", 1966},
            {"Juliette", 1997},
            {"Marius", 1999}
    };

    std::unordered_map<std::string, int>::const_iterator endMapIt = unorderedMap.end();
    std::unordered_map<std::string, int>::iterator mapIt;

    for (mapIt = unorderedMap.begin(); mapIt != endMapIt; ++mapIt)
        std::cout << "{" << mapIt->first << ": " << mapIt->second << "}\n";

    std::cout << "====================================\n\n";

    std::vector<int> myVec(9);
    std::iota(myVec.begin(), myVec.end(), 1);

    std::vector<int>::const_iterator vecEndIt = myVec.cend();
    std::vector<int>::iterator vecIt;

    for (vecIt = myVec.begin(); vecIt != vecEndIt; ++vecIt)
        std::cout << *vecIt << " ";
    std::cout << "\n";

    for (const auto& e : myVec) std::cout << e << " ";
    std::cout << "\n";

    std::vector<int>::const_reverse_iterator vecEndRevIt = myVec.crend();
    std::vector<int>::reverse_iterator vecRevIt;
    for (vecRevIt = myVec.rbegin(); vecRevIt != vecEndRevIt; ++vecRevIt)
        std::cout << *vecRevIt << " ";

    return 0;
}