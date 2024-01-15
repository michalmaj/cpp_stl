/*
 * Stack
 * The std::stack follows the LIFO principle (Last In First Out). The stack sta, which needs the header <stack> has
 * three spacial methods.
 * With sta.push(e) we can insert a new element e at the top of the stack, remove it from the top with sta.pop() and
 * reference it with sta.pop(). The stack supports the comparison operators and knows its size. The operations of the
 * stack have constant complexity.
 */
#include <iostream>
#include <stack>

int main(){
    std::stack<int> myStack;

    std::cout << std::boolalpha;
    std::cout << "myStack.empty(): " << myStack.empty() << std::endl;
    std::cout << "myStack.size(): " << myStack.size() << std::endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    std::cout << "myStack.top(): " << myStack.top() << std::endl;

    while (!myStack.empty()){
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << "\n";

    std::cout << "myStack.empty(): " << myStack.empty() << std::endl;
    std::cout << "myStack.size(): " << myStack.size() << std::endl;

    return 0;
}