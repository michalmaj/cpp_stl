/*
 * Special Search Functions
 * Ordered associative containers are optimized for searching. So they offer unique search functions:
 *  - ordAssCont.count(key) - Returns the number of values with key.
 *  - ordAssCont.find(key) - Returns the iterator of key in ordAssCont. If there is no key it returns end().
 *  - ordAssCont.lower_bound() - Returns the iterator to the first key in ordAssCont in which key would be inserted.
 *  - ordAssCont.upper_bound() - Returns the last position of key in ordAssCont in which key would be inserted.
 *  - ordAssCont.equal_range() - Returns the range ordAssCont.lower_bound(key) and ordAssCont.upper_bound(key) in a
 *                               std::pair.
 */
#include <iostream>
#include <set>

int main() {
    std::multiset<int> mySet{3, 1, 5, 3, 4, 5, 1, 4, 4, 3, 2, 2, 7, 6, 4, 3, 6};

    std::cout << "mySet contains: ";
    for (const auto& e : mySet) std::cout << e << " ";
    std::cout << "\n";

    std::cout << "================================\n\n";

    mySet.erase(mySet.lower_bound(4), mySet.upper_bound(4));
    std::cout << "mySet after deletion all 4 contains: ";
    for (const auto& e : mySet) std::cout << e << " ";
    std::cout << "\n";

    std::cout << "================================\n\n";

    std::cout << "mySet.count(3): " << mySet.count(3) << "\n";
    std::cout << "Index of first 3 is: " << *mySet.find(3) << "\n";
    std::cout << "Pointer at first 3 is: " << *mySet.lower_bound(3) << "\n";
    std::cout << "Pointer after last 3 is: " << *mySet.upper_bound(3) << "\n";

    auto pair = mySet.equal_range(3);
    auto idxFirst = std::distance(mySet.begin(), pair.first);
    auto idxLast = std::distance(mySet.begin(), pair.second);
    std::cout << "Indexes of first and after last occurrence of value 3: " << idxFirst << ", " << idxLast << "\n";

    return 0;
}
