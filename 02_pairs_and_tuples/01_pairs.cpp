/*
 * Pairs
 * With std::pair, we can build pairs of arbitrary types. The class template std::pair needs the header <utility>.
 * std::pair has a default, copy and move constructor. Pair objects can be swapped: std::swap(pair1, pair2).
 *
 * Pairs will often be used in the C++ library. For example, the function std::minmax returns its result as a pair,
 * the associative container std::map, std::unordered_map, std::multimap and std::unordered_multimap manage their
 * key/value association in pairs.
 *
 * To get the element of a pair, we can either access it directly or via an index. So, with p.first or std::get<0>(p)
 * we get the first, with p.second or std::get<1>(p) we get the second element of the pair.
 *
 * Pairs support the comparison operators ==, !=, <, >, <= and >=. If we compare two pairs for identity, at first the
 * members pair1.first and pair2.first will be compared and then pair1.second and pair2.second. The same strategy holds
 * for the other comparison operators.
 *
 * std::make_pair
 * C++ has the practical help function std::make_pair to generate pairs, without specifying their types. std::make_pair
 * automatically deduces their types.
 */
#include <iostream>
#include <utility>

int main(){
    std::pair<const char*, double> charDouble1("str", 3.14);
    std::pair<const char*, double> charDouble2 = std::make_pair("str", 3.14);

    std::cout << charDouble1.first << " " << charDouble2.second << "\n";
    charDouble1.first = "Str";
    std::get<1>(charDouble1) = 9.99;
    std::cout << charDouble1.first << " " << charDouble1.second << "\n";


    return 0;
}