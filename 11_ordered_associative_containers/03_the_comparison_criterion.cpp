/*
 * The Comparison Criterion
 * The default comparison criterion of the ordered associative containers is std::less. If we want to use a user-defined
 * type as the key, we have to overload the operator <. It's sufficient to overload the operator< for our data type
 * because the C++ runtime compares, with the help of the relation (! (elem1 < elem2 || elem2 < elem1), two elements for
 * equality.
 * We can specify the sorting criterion as a template argument. This sorting criterion must implement a strict weak
 * ordering.
 * Strict weak ordering for a sorting criterion on a set s is given if the following requirements are met:
 *  - For s from s has hold, that s < s is not possible.
 *  - For all s1 and s2 from s must hold: If s1 < s2, then s2 < s1 is not possible.
 *  - For all s1, s2, and s3 with s1 < s2 and s2 < s3 must hold: s1 < s3.
 *  - For all s1, s2, and s3 with s1 not comparable with s2 and s2 not comparable with s3 must hold: s1 is not
 *  comparable with s3.
 */
#include <iostream>
#include <map>

int main(){
    std::map<int, std::string, std::greater<>> int2str {
            {5, "five"},
            {1, "one"},
            {4, "four"},
            {3, "three"},
            {2, "two"},
            {7, "seven"},
            {6, "six"}
    };

    for (const auto& [k, v]: int2str)
        std::cout << "{" << k << ": " << v << "} ";
    std::cout << "\n";

    return 0;
}