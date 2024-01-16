/*
 * Queue
 * A queue follows the opposite principle of stack.
 *
 * The std::queue follows the FIFO principle (First In First Out). The queue que, which needs the header <queue>, has
 * four special methods.
 * With que.push(e) we can insert ane element e at the end of the queue and remove the first element from the queue with
 * que.pop(). que.back() enables us to refer to the last element in the que, que.front() to the first element in que.
 * std::queue has similar characteristics as std::stack. So we can compare std::queue instances and get their sizes.
 * The operations of the queue have constant complexity.
 */
#include <iostream>
#include <queue>

int main(){
    std::queue<int> myQueue;

    std::cout << std::boolalpha;
    std::cout << "myQueue.empty(): " << myQueue.empty() << "\n";
    std::cout << "myQueue.size(): " << myQueue.size() << "\n";

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "myQueue.front(): " << myQueue.front() << "\n";
    std::cout << "myQueue.back(): " << myQueue.back() << "\n";

    while (!myQueue.empty()){
        std::cout << myQueue.back() << " ";
        std::cout <<myQueue.front() << " : ";
        myQueue.pop();
    }

    std::cout << "\n";

    std::cout << "myQueue.empty(): " << myQueue.empty() << "\n";
    std::cout << "myQueue.size(): " << myQueue.size() << "\n";

    return 0;
}