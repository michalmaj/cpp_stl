/*
 * Introduction
 * On the one hand, iterators are generalization of pointers which represents positions in a container. On the other
 * hand, they provide powerful iteration and random access in a container.
 * Iterators are the glue between the generic containers and the generic algorithms of the Standard Template Library.
 * Iterators support the following operations:
 *  * - Returns the element at current position.
 *  ==, != - Compares two positions.
 *  = - Assigns a new value to an iterator.
 * The range-based for-loop uses the iterators implicitly.
 * Because iterators are not checked, they have the same issues as pointers.
 */
#include <iostream>
#include <queue>
#include <vector>

int main(){
    std::vector<int> vec{1, 23, 3, 3, 3, 4, 5};
    std::deque<int> deq;

    std::copy(vec.begin() + 2, vec.begin(), deq.begin());
    for (const auto& e : deq) std::cout << e << " ";
    std::cout << "\n";

    std::copy(vec.begin(), vec.end(), std::back_inserter(deq));
    for (const auto& e : deq) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}