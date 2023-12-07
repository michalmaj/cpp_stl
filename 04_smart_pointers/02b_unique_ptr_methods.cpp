/*
 * Methods of std::unique_ptr
 *  - get: Returns a pointer to the resource.
 *  - get_deleter: Return the delete function.
 *  - release: Returns a pointer to the resource and release it.
 *  - reset: Reset the resource.
 *  - swap: Swaps the resources.
 */
#include <iostream>
#include <memory>
#include <utility>

struct MyInt{
    MyInt(int i): i_(i) {}
    ~MyInt() { std::cout << "Good bye from: " << i_ << "\n"; }

    int i_;
};

int main(){
    std::unique_ptr<MyInt> uniquePtr1{new MyInt{2023}};
    std::cout << "Memory address of uniquePtr1: " << uniquePtr1.get() << "\n";

    std::unique_ptr<MyInt> uniquePtr2 = std::move(uniquePtr1);
    std::cout << "Memory address of uniquePtr1: " << uniquePtr1.get() << "\n";
    std::cout << "Memory address of uniquePtr2: " << uniquePtr2.get() << "\n";

    {
        std::unique_ptr<MyInt> localPtr{new MyInt{1998}};
    }

    uniquePtr2.reset(new MyInt{2002});
    MyInt* myInt = uniquePtr2.release();
    delete myInt;

    std::unique_ptr<MyInt> uniquePtr3{new MyInt{2014}};
    std::unique_ptr<MyInt> uniquePtr4{new MyInt{2017}};
    std::cout << "Memory address of uniquePtr3: " << uniquePtr3.get() << "\n";
    std::cout << "Memory address of uniquePtr4: " << uniquePtr4.get() << "\n";

    std::swap(uniquePtr3, uniquePtr4);
    std::cout << "Memory address of uniquePtr3: " << uniquePtr3.get() << "\n";
    std::cout << "Memory address of uniquePtr4: " << uniquePtr4.get() << "\n";


    return 0;
}