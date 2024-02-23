/*
 * Heaps
 * What is a heap?
 * A heap is a binary search tree in which paren elements are always bigger than its child elements. Heap trees are
 * optimized for the efficient sorting of elements.
 *
 * We can create with std::make_heap a heap. We can push with std::push_heap a new element on the heap. On the contrary,
 * we can pop the largest element with std::pop_heap. Both operations respect the heap characteristics. std::push_heap
 * moves the last element on the range on the heap; std::pop_heap moves the biggest element of the heap to the last
 * position in the range. We can check with std::is_heap if a range is a heap. We can determine with std::is_heap_until
 * unit which positions the range is a heap. std::sort_heap sorts the heap.
 *
 * The heap algorithms require that the range and the algorithm use the same sorting criterion. If not, the program is
 * undefined. Per default, the predefined sorting criterion std::less is used. If we use our sorting criterion, it has
 * to obey the strict weak ordering. If not, the program is undefined.
 *
 * With std::pop_heap we can remove the biggest element from the heap. Afterward, the biggest element is the last
 * element of the range. To remove it from the heap h, use h.pop_back().
 */
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec) {
    for (const auto& e : vec) {
        out << e << " ";
    }
    return out;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> vec{4, 3, 2, 1, 5, 6, 7, 9, 10};
    std::cout << "vec contains: " << vec << '\n';

    std::make_heap(vec.begin(), vec.end());
    std::cout << "vector after make_heap contains: " << vec << '\n';
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << '\n';

    vec.push_back(100);
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << '\n';
    std::cout << "*std::is_heap_until(vec.begin(), vec.end()): "
              << *std::is_heap_until(vec.begin(), vec.end()) << '\n';

    std::cout << "vec contains: " << vec << '\n';
    std::push_heap(vec.begin(), vec.end());
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << '\n';
    std::cout << "vec contains: " << vec << '\n';

    std::pop_heap(vec.begin(), vec.end());
    std::cout << "vec after pop_heap contains: " << vec << '\n';
    std::cout << "*std::is_heap_until(vec.begin(), vec.end()): "
              << *std::is_heap_until(vec.begin(), vec.end()) << '\n';
    vec.resize(vec.size() - 1);
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << '\n';

    std::cout << "vec.front(): " << vec.front() << '\n';

    return 0;
}