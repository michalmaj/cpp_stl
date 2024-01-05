/*
 * Keys and Values
 * There are special rules for the key and the value of an ordered associative container.
 * The key has to be:
 *  - sortable;
 *  - copyable and moveable.
 * The value has to be:
 *  - default constructible;
 *  - copyable and moveable.
 *
 * The associated with the value build a pair p. The key and value can then be retrieved by p.first and p.second.
 */
#include <iostream>
#include <map>

int main(){
    std::multimap<char, int> multiMap = {
            {'a', 10},
            {'a', 20},
            {'b', 30}
    };

    for (const auto& p : multiMap)
        std::cout << "{" << p.first << ": " << p.second << "} ";
    std::cout << "\n";

    return 0;
}