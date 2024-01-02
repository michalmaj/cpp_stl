/*
 * Introduction
 * C++ has eight different associative containers. Four of them are associative containers with sorted keys: std::set,
 * std::map, std::multiset, std::multimap. The other four are associative containers with unsorted keys
 * std::unsorted_set, std::unsorted_map, std::unsorted_multiset, std::unsorted_multimap. The associative containers are
 * special containers.
 *
 * Overview
 * All eight ordered and unordered containers have in common that they associate a key with a value. We can use the key
 * to get the value. To get classification of the associative containers, three simple questions need to be answered:
 *  1. Are the keys sorted?
 *  2. Does the key have an associated value?
 *  3. Can a key appear more than once?
 *
 * Characteristic for associative containers
 * Since C++98, C++ has ordered associative containers; with C++11, C++ has in addition unordered associative
 * containers. Both classes have a very similar interface.
 * We can initialize the containers with an initializer list and add new elements with the index operator. To access the
 * first element of the key/value pair p, we have p.first, and for the second element, we have p.second.
 */
#include <iostream>
#include <map>
#include <unordered_map>

int main(){
    std::map<std::string, int> m {
            {"Dijkstra", 1972},
            {"Scott", 1976}
    };
    m["Ritchie"] = 1983;
    std::cout << "m[\"Ritchie\"]: " << m["Ritchie"] << "\n";

    for (const auto& p : m)
        std::cout << "{" << p.first << ", " << p.second << "} ";
    std::cout << "\n";

    m.erase("Scott");
    for (const auto& [k, v]: m)
        std::cout << "{" << k << ", " << v << "} ";
    std::cout << "\n";

    m.clear();
    std::cout << m.size() << "\n";

    std::unordered_map<std::string, int> um {
            {"Dijkstra", 1972},
            {"Scott", 1976}
    };
    um["Ritchie"] = 1983;
    std::cout << "um[\"Ritchie\"]: " << um["Ritchie"] << "\n";

    for (const auto& p : um)
        std::cout << "{" << p.first << ", " << p.second << "} ";
    std::cout << "\n";

    um.erase("Scott");
    for (const auto& [k, v]: um)
        std::cout << "{" << k << ", " << v << "} ";
    std::cout << "\n";

    um.clear();
    std::cout << um.size() << "\n";

    return 0;
}