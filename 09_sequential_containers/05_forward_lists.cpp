/*
 * Forward Lists
 * A forward list is the primitive form of the list structure, but forward lists are still useful.
 *
 * std::forward_list is a singly linked list, which needs the header <forward_list>. std::forward_list has a drastically
 * reduced interface and is optimized for minimal memory requirements.
 * std::forward_list has a lot in common with std::list:
 *  - It supports no random access.
 *  - The access of an arbitrary element is slow because in the worst cas we have to iterate forward through the whole
 *    list.
 *  - To add or remove an element is fast, if the iterator points to the right place.
 *  - If we add or remove an element, the iterator stays valid.
 *  - Operations always refer to the beginning of the std::forward_list or the position past the current element.
 *
 * The characteristic that we can iterate a std::forward_list forward has a great impact. So the iterators cannot be
 * decremented and therefore, operations like It-- on iterators are not supported. For the same reason,
 * std::forward_list has no backward iterator. std::forward_list is the only sequential container that doesn't know
 * its size.
 *
 * std::forward_list has a very special domain
 * std::forward_list is the replacement for single linked list. It's optimized for minimal memory management and
 * performance if the insertion, extraction or movement of elements only affect adjacent elements. This is typical for
 * a sort algorithm.
 *
 * List of the special methods of std::forward_list:
 *  - fl.before_begin() - Returns an iterator before the first element.
 *  - fl.emplace_after(pos, args...) - Creates an element after pos with the arguments args... .
 *  - fl.emplace_front(args...) - Creates an element at the beginning of fl with the arguments args... .
 *  - fl.erase_after(pos, ...) - Removes from fl the element pos or a range of elements, starting with pos.
 *  - fl.insert_after(pos, ...) - Inserts after pos new elements. These elements can be single element, ranges or
 *    initializer lists.
 *  - fl.merge(c) - Merges the forward sorted list c into the sorted forward list fl, so that fl keeps sorted.
 *  - fl.merge(c, op) - Merges the forward sorted list c into the forward sorted list fl, so that fl keeps sorted. Uses
 *    op as sorting criteria.
 *  - fl.splice_after(pos, ...) - Splits the elements in fl before pos. The elements can be single elements, ranges or
 *    lists.
 *  - fl.unique() - Removes adjacent element with the same value.
 *  - fl.unique(pre) - Removes adjacent elements, fulfilling the predicate pre.
 */
#include <algorithm>
#include <forward_list>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::forward_list<T>& fl){
    for (const auto& e : fl)
        out << e << " ";
    return out;
}

int main(){
    std::cout << std::boolalpha;
    std::forward_list<int> fl1;
    std::cout << "Is fl1 empty: " << fl1.empty() << "\n";

    fl1.push_front(7);
    fl1.push_front(6);
    fl1.push_front(5);
    fl1.push_front(4);
    fl1.push_front(3);
    fl1.push_front(2);
    fl1.push_front(1);
    std::cout << "fl1 contains: " << fl1 << "\n";

    fl1.erase_after(fl1.before_begin());
    std::cout << "fl1 after removing first element contains: " << fl1 << "\n";

    std::forward_list<int> fl2;
    fl2.insert_after(fl2.before_begin(), 1);
    fl2.insert_after(++fl2.before_begin(), 2);
    fl2.insert_after(++(++fl2.before_begin()), 3);
    fl2.push_front(1000);
    std::cout << "fl2 contains: " << fl2 << "\n";


    auto itTo5 = std::find(fl1.begin(), fl1.end(), 5);
    fl1.splice_after(itTo5, std::move(fl2));
    std::cout << "fl1 after splice: " << fl1 << "\n";

    fl1.sort();
    std::cout << "fl1 after sorting: " << fl1 << "\n";

    fl1.reverse();
    std::cout << "fl1 after reversing: " << fl1 << "\n";

    fl1.unique();
    std::cout << "fl1 after delete adjacent: " << fl1 << "\n";

    return 0;
}