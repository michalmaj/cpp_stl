/*
 * Reduce
 * The six new algorithms that are typically used for parallel execution are also known under the name prefix sum. If
 * the given binary callables are not associative and commutative, the behavior of the algorithms is undefined.
 *
 * reduce
 * This reduces the elements of the range. init is the start value.
 * Behaves the same sa std::accumulate but the range may be rearranged.
 *
 * transform_reduce
 * This transforms and reduces the elements of one or two ranges. init is the start value.
 * Behaves similarly to std::inner_product but the range may be rearranged.
 * If applied to two ranges:
 *  - if not provided, multiplication is used for transforming the ranges into one range, and addition is used to reduce
 *    the intermediate-range into the result
 *  - if provided, fun1 is used for transforming step and fun2 is used for the reducing step.
 * If applied to a single range:
 *  - fun2 is used for transforming the given range.
 *
 * MapReduce in C++17
 * The Haskell function map is called std::transform in C++. When we substitute transform with map in the name
 * std::transform_reduce, we will get std::map_reduce. MapReduce is the well-known parallel framework that first maps
 * each value to a new value, then reduces in the second phase all values to the result.
 * The algorithm is directly applicable in C++17. In the following example, in the map phase, each word is mapped to
 * its length, and the lengths of all words are then reduced to their sum during the reduce phase. The result is the
 * sum of the length of all words.
 */
#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>


int main() {

    std::vector<std::string> str{"Only", "for", "testing", "purpose"};

    std::size_t result = std::transform_reduce(std::execution::par, str.begin(), str.end(), 0,
                                               [](auto a, auto b){return a + b;},
                                               [](auto s){return s.size();});
    std::cout << result << '\n';


    return 0;
}