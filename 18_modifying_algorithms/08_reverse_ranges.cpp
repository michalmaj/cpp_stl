/*
 * Reverse Ranges
 * std::reverse and std::reverse_copy invert the order of the elements in their range.
 * Both algorithms require bidirectional iterators. The returned iterator points to the position of the output range
 * result before the elements were copied.
 */
#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <list>
#include <string>
#include <vector>

template <typename Cont, typename T>
void doTheSame(Cont cont, T t){
    for (auto c : cont) std::cout << c << " ";
    std::cout << "\n";

    std::reverse(cont.begin(), cont.end());
    for (auto c : cont) std::cout << c << " ";
    std::cout << "\n";

    std::reverse(cont.begin(), cont.end());
    for (auto c : cont) std::cout << c << " ";
    std::cout << "\n";

    auto it = std::find(cont.begin(), cont.end(), t);
    std::reverse(it, cont.end());
    for (auto c : cont) std::cout << c << " ";
    std::cout << "\n\n";
}

int main(){
    std::vector<int> myVec(10);
    std::iota(myVec.begin(), myVec.end(), 1);

    std::deque<std::string> myDeque;
    std::generate_n(std::back_inserter(myDeque), 9, [c='A']() mutable {
        return std::string(1, c++);
    });

    std::list<char> myList;
    std::transform(myDeque.begin(), myDeque.end()-1, std::back_inserter(myList), [](auto s){
        return tolower(s.at(0));
    });

    doTheSame(myVec, 5);
    doTheSame(myDeque, "D");
    doTheSame(myList, 'd');

    return 0;
}