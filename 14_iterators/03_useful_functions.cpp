/*
 * Useful Functions
 * The global functions: std::begin, std::end, std::prev, std::next, std::distance, std::advance make our handling of
 * the iterators a lot easier. Only the function std::prev requires a bidirectional iterator. All function need the
 * header <iterator>:
 *  - std::begin(cont) - Returns a begin iterator of the container cont.
 *  - std::end(cont) - Returns an end iterator to the container cont.
 *  - std::rbegin(cont) - Returns a reverse begin iterator of the container cont.
 *  - std::rend(cont) - Returns a revers end iterator of the container cont.
 *  - std::cbegin(cont) - Returns a constant begin iterator of the container cont.
 *  - std::cend(cont) - Returns a constant end iterator of the container cont.
 *  - std::crbegin(cont) - Returns a reverse constant begin iterator of the container cont.
 *  - std::crend(cont) - Returns a revers constant end iterator of the container cont.
 *  - std::prev(it) - Returns an iterator, which points to a point before it.
 *  - std::next(it) - Returns an iterator, which points to a position after it.
 *  - std::distance(fir, sec) - Returns the number of elements between fir and sec.
 *  - std::advance(it, n) - Puts the iterator it n position further.
 */
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>

int main(){
    std::unordered_map<std::string, int> myMap{
            {"Rainer", 1966},
            {"Beatrix", 1966},
            {"Juliette", 1997},
            {"Marius", 1999}
    };
    for (const auto& [k, v] : myMap) std::cout << "{" << k << ": " << v << "} ";
    std::cout << "\n";

    auto mapItBegin = std::begin(myMap);
    std::cout << "{" << mapItBegin->first << ": " << mapItBegin->second << "}\n";
    auto mapIt = std::next(mapItBegin);
    std::cout << "{" << mapIt->first << ": " << mapIt->second << "}\n";

    auto distance = std::distance(mapItBegin, mapIt);
    std::cout << "std::distance(mapItBegin, mapIt): " << distance << "\n";

    std::cout << "========================================\n";

    std::array<int, 10> myArr;
    std::iota(myArr.begin(), myArr.end(), 0);
    for (const auto& e : myArr) std::cout << e << " ";
    std::cout << "\n";

    auto arrItEnd = std::end(myArr);
    auto arrIt = std::prev(arrItEnd);
    std::cout << "*arrIt: " << *arrIt << "\n";

    std::advance(arrIt, -5);
    std::cout << "*arrIt: " << *arrIt << "\n";

    return 0;
}