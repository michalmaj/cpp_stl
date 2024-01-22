/*
 * Adaptors
 * Iterator adaptors enable the use of iterators in insert mode or with streams. They need the header <iterator>.
 *
 * Insert iterators
 * With the three insert iterators std::front_inserter, std::back_inserter and std::inserter we can insert an element
 * into a container at the beginning, at the end, or an arbitrary position respectively. The memory for the elements
 * will automatically be provided. The three map their functionality on the underlying methods of the container cont.
 *  - Name: std::front_inserter(val), Internally-used Method: cont.push_front(val), Container: std::deque, std::list
 *  - Name: std::back_inserter(val), Internally-used Method: cont.push_back(val), Container: std::deque, std::list,
 *    std::vector, std::string
 *  - Name: std::inserter(val), Internally-used Method: cont.insert(pos, val), Container: std::deque, std::list,
 *    std::vector, std::string, std::map, std::set.
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <vector>
#include <unordered_map>

template <typename C>
void printCont(const C& c){
    for (const auto& e : c)
        std::cout << e << " ";
    std::cout << "\n";
}

int main(){
    std::deque<int> deq{5, 6, 7, 10, 11, 12};
    std::cout << "deq contains: ";
    printCont(deq);

    std::vector<int> vec(15);
    std::iota(vec.begin(), vec.end(), 1);
    std::cout << "vec contains: ";
    printCont(vec);

    std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq));
    std::cout << "deq contains: ";
    printCont(deq);

    std::copy(std::find(vec.begin(), vec.end(), 8),
              std::find(vec.begin(), vec.end(), 10),
              std::inserter(deq, std::find(deq.begin(), deq.end(), 10)));
    std::cout << "deq contains: ";
    printCont(deq);

    std::copy(vec.rbegin()+11, vec.rend(),
              std::front_inserter(deq));
    std::cout << "deq contains: ";
    printCont(deq);


    return 0;
}