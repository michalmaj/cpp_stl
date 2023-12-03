/*
 * Tuples
 * Tuples extend the principles of a pair to a broader perspective.
 *
 * We can create tuples of arbitrary length and types with std::tuple. The class template need the header <tuple>.
 * std::tuple is a generalization of std::pair. We can convert between tuples with two elements and pairs. The tuple
 * has, like std::pair, a default, a copy, and a move constructor. We can swap tuples with the function std::swap.
 *
 * The i-th element of a tuple can be referenced by the function template std::get<i-1>(t). By std::get<type>(t) we can
 * directly refer to the element of the type type.
 *
 * Tuples support the comparison operators ==, !=, <, >, <=, >=. If we compare two tuples, the elements of the tuples
 * will be compared lexicographically. The comparison starts at index 0.
 *
 * std::make_tuple
 * THe helper function std::make_tuple is quite convenient for the creation of tuples. We don't have to provide the
 * types. The compiler automatically deduces them.
 */
#include <iostream>
#include <tuple>

int main(){
    std::tuple<std::string, int, float> tup1("first", 3, 4.17f);
    auto tup2 = std::make_tuple("second", 4, 1.1);

    std::cout << std::get<0>(tup1) << ", " << std::get<1>(tup1) << ", " <<
            std::get<2>(tup1) << "\n";

    std::cout << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " <<
              std::get<2>(tup2) << "\n";

    std::get<0>(tup2) = "Second";
    std::cout << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " <<
              std::get<2>(tup2) << "\n";

    std::cout << std::boolalpha;
    std::cout << (tup1 < tup2) << "\n";

    auto pair = std::make_pair(1, true);
    std::tuple<int, bool> tup = pair;


    return 0;
}