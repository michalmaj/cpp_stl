/*
 * Access
 * To access the elements of a container, we can use an iterator. If we use a begin and end iterator, we have a range,
 * which we can further process. For a container cont, we get with cont.begin() the begin iterator and with cont.end()
 * the end iterator, which defines a half-open range. It is half-open because the begin iterator belongs to the range,
 * the end iterator refers to a position past the range. With the iterator pair cont.begin() and cont.end() we can
 * modify the elements
 *
 * Four types of iterators:
 *  1. cont.begin() and cont.end() - Pair of iterators to iterate forward.
 *  2. cont.cbegin() and cont.cend() - Pair of iterators to iterate const forward.
 *  3. cont.rbegin() and cont.rend() - Pair of iterators to iterate backward.
 *  4. cont.crbegin() and cont.crend() - Pair of iterators to iterate const backward.
 */
#include <iostream>
#include <vector>

struct MyInt{
    MyInt(int i): myInt(i) {}
    int myInt;
};

int main(){
    std::vector<MyInt> myIntVec;
    myIntVec.push_back(MyInt(5));
    myIntVec.emplace_back(1);
    std::cout << myIntVec.size() << "\n";

    std::cout << "\n";

    std::vector<int> intVec;
    intVec.assign({1, 2, 3});
    for (const auto& v : intVec) std::cout << v << " ";
    std::cout << "\n";

    intVec.insert(intVec.begin(), 0);
    for (const auto& v : intVec) std::cout << v << " ";
    std::cout << "\n";

    auto it = intVec.begin();
    std::advance(it, 4);
    intVec.insert(it, 4);
    for (const auto& v : intVec) std::cout << v << " ";
    std::cout << "\n";

    intVec.insert(intVec.end(), {5, 6, 7, 8, 9, 10, 11});
    for (const auto& v : intVec) std::cout << v << " ";
    std::cout << "\n";

    for (auto b{intVec.rbegin()}; b != intVec.rend(); ++b)
        std::cout << *b << " ";
    std::cout << "\n";

    intVec.pop_back();
    for (const auto& v : intVec) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}