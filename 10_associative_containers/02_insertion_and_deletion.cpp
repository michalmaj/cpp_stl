/*
 * Insertion and Deletion
 * In associative containers, value are inserted and deleted based on the keys they have.
 *
 * Rhe insertion (insert and emplace) and deletion (erase) of elements in associative containers are similar to the
 * rules of a std::vector. For associative container which can have a key only once, the insertion fails if the key is
 * already in the container. Additionally, ordered associative containers support a special function erase(key), which
 * removes all pairs with the key and returns their number.
 */
#include <array>
#include <iostream>
#include <set>

int main() {
    std::multiset<int> mySet{3, 1, 5, 3, 4, 5, 1, 4, 4, 3, 2, 2, 7, 6, 4, 3, 6};

    std::cout << "mySet contains: ";
    for (const auto& e : mySet) std::cout << e << " ";
    std::cout << "\n";

    mySet.insert(8);
    std::array<int, 5> myArr{10, 11, 12, 13, 14};
    mySet.insert(myArr.begin(), myArr.end());
    mySet.insert({21, 22, 20});
    std::cout << "mySet after insertion contains: ";
    for (const auto& e : mySet) std::cout << e << " ";
    std::cout << "\n";

    std::cout << "mySet.erase(4): " << mySet.erase(4) << "\n";
    mySet.erase(mySet.lower_bound(5), mySet.upper_bound(15));
    std::cout << "mySet after insertion erase: ";
    for (const auto& e : mySet) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}