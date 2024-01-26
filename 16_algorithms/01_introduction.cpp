/*
 * Introduction
 * The Standard Template Library has a large number of algorithms to work with containers and their elements. As the
 * algorithms are function templates, they are independent of the type of container elements. The glue between the
 * containers and algorithms are the iterators. If your container supports the interface of an STL container, we can
 * apply the algorithms to your container.
 */
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

template <typename Cont, typename T>
void doTheSame(Cont cont, T t){
    std::cout << "Cont contains: ";
    for (const auto& c : cont) std::cout << c << " ";
    std::cout << "\n";
    std::cout << "cont.size(): " << cont.size() << "\n";

    std::reverse(cont.begin(), cont.end());
    std::cout << "Cont after reversing contains: ";
    for (const auto& c : cont) std::cout << c << " ";
    std::cout << "\n";

    std::reverse(cont.begin(), cont.end());
    std::cout << "Cont after reversing again contains: ";
    for (const auto& c : cont) std::cout << c << " ";
    std::cout << "\n";

    auto it = std::find(cont.begin(), cont.end(), t);
    if (it == cont.end())
        return;
    std::reverse(it, cont.end());
    std::cout << "Cont after reversing contains: ";
    for (const auto& c : cont) std::cout << c << " ";
    std::cout << "\n";
}

int main(){
    std::vector<int> myVec(10);
    std::iota(myVec.begin(), myVec.end(), 1);

    std::deque<std::string> myDeq(9);
    std::generate(myDeq.begin(), myDeq.end(), [c='A'-1]() mutable {
        c++;
        return std::string(1, c);
    });

    std::list<char> myList(8);
    std::generate(myList.begin(), myList.end(), [c='a']() mutable {
       return c++;
    });

    doTheSame(myVec, 5);
    std::cout << "\n\n";
    doTheSame(myDeq, "D");
    std::cout << "\n\n";
    doTheSame(myList, 'c');

    return 0;
}