/*
 * Priority Queue
 * The std::priority_queue is a reduced std::queue. It needs the header <queue>.
 * The difference to the std::queue is, that their biggest element is always at the top of the priority queue.
 * std::priority_queue pq uses by default the comparison operator std::less. Similar to std::queue, pq.push(e) inserts
 * a new element e int the priority queue. pq.pop() removes the first element of the pq, but does that with logarithmic
 * complexity. With pq.top() we can reference the first element in the priority queue, which is the greatest one. The
 * std::priority_queue knows its size, but didn't support the comparison operator on their instances.
 */
#include <iostream>
#include <queue>
#include <vector>

int main(){
    std::priority_queue<int> pq;

    std::cout << std::boolalpha;

    std::cout << "pq.empty(): " << pq.empty() << "\n";
    std::cout << "pq.size(): " << pq.size() << "\n";

    pq.push(3);
    pq.push(2);
    pq.push(1);

    std::cout << "pq.top(): " << pq.top() << "\n";

    std::cout << "Data: ";
    while (!pq.empty()){
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
    std::cout << "pq.empty(): " << pq.empty() << "\n";
    std::cout << "pq.size(): " << pq.size() << "\n";

    std::cout << "==================================\n\n";

    std::priority_queue<std::string, std::vector<std::string>, std::greater<>> pq2;
    pq2.push("Only");
    pq2.push("for");
    pq2.push("testing");
    pq2.push("purpose");
    pq2.push(".");

    while (!pq2.empty()){
        std::cout << pq2.top() << " ";
        pq2.pop();
    }
    std::cout << "\n";

    return 0;
}