/*
 * Lists
 * C++ supports the linked list data structure and provides additional methods to improve the list's functionality.
 *
 * std::list is a double linked list. std::list needs the header <list>.
 * Although it has a similar interface to std::vector or std::deque, std::list is quite different to both of them.
 * That's due to its structure.
 * std::list makes the following points unique:
 *  - It supports no random access.
 *  - The access of an arbitrary element is slow, because we have to iterate in the worst case through the whole list.
 *  - To add or remove an element is fast, if the iterator points to the right place.
 *  - If we add or remove an element, the iterator adjust accordingly and stays valid (doesn't go out of bounds).
 *
 * std::list has also a few special methods:
 *  - l.merge(c) - Merges the sorted list c into the sorted list l, so that l keeps sorted.
 *  - l.merge(c, op) - Merges the sorted list c into the sorted list l, so that l keeps sorted. Uses op as sorting
 *                     criteria.
 *  - l.remove(val) - Removes all elements from list with value val.
 *  - l.remove_if(pre) - Removes all elements from list, fulfilling the predicate pre.
 *  - l.splice(pos, ...) - Splits the elements in l before pos. The elements can be single elements, range or list.
 *  - l.unique() - Removes adjacent element with the same value.
 *  - l.unique(pre) - Removes adjacent elements, fulfilling the predicate pre.
 */
#include <algorithm>
#include <iostream>
#include <list>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& l){
    for (const auto& e : l)
        out << e << " ";
    return out;
}

int main(){
    std::list<int> l1{15, 2, 18, 19, 4, 15, 1, 3, 18, 5, 4, 7, 17, 9, 16, 8, 6, 17, 1, 2};
    std::cout << "List: " << l1 << "\n";

    l1.sort();
    std::cout << "List after sorting: " << l1 << "\n";

    l1.unique();
    std::cout << "List after removing duplicates: " << l1 << "\n";

    std::list<int> l2{10, 11, 12, 13, 14};
    l1.splice(std::find(l1.begin(), l1.end(), 15), l2);
    std::cout << "List after adding another list before value 15: " << l1 << "\n";

    return 0;
}