/*
 * Shared Pointers
 * Next, we have the shared pointer. It follows the principle of keeping a reference count to maintain the count of its
 * copies.
 * std::shared_ptr shares the ownership of the resource. They have two handles. One for resource and one for the
 * reference counter. By copying a std::shared_ptr, the reference count is increased by one. It is decreased by one if
 * the std::shared_ptr goes out of scope. If the reference counter becomes the value 0 and therefore there is no
 * std::shared_ptr referencing the resource, the C++ runtime automatically releases the resource. The release of the
 * resource takes place at exactly the time at which the last std::shared_ptr goes out of scope. The C++ runtime
 * guarantees that the call of the reference counter is an atomic operations. Because of this management,
 * std::shared_ptr uses more time and memory than a raw pointer ot std::unique_ptr.
 *
 * List of the methods of std::shared_ptr:
 *  - get: Returns a pointer to the resource.
 *  - get_deleter: Returns the delete function.
 *  - reset: Resets the resource.
 *  - swap: Swaps the resources.
 *  - unique: Checks if the std::shared_ptr is the exclusive owner of the resource.
 *  - use_count: Returns the value of the reference counter.
 *
 * std::make_shared
 * The helper function std::make_shared creates the resource and returns it in a std::shared_ptr. We should use
 * std:make_shared instead of the direct creation of a std::shared_ptr, because std::make_shared is a lot faster.
 */
#include <iostream>
#include <memory>

class MyInt{
public:
    MyInt(int v): val(v) {
        std::cout << "Hello: " << val << "\n";
    }

    ~MyInt(){
        std::cout << "Goodbye: " << val << "\n";
    }

private:
    int val;
};

int main(){
    auto sharPtr = std::make_shared<MyInt>(1998);
    std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << "\n";

    {
        std::shared_ptr<MyInt> locSharPtr(sharPtr);
        std::cout << "sharPtr.use_count(): " << locSharPtr.use_count() << "\n";
    }

    std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << "\n";

    std::shared_ptr<MyInt> globSHarPtr(sharPtr);
    std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << "\n";

    globSHarPtr.reset();
    std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << "\n";

    sharPtr = std::shared_ptr<MyInt>(new MyInt{2023});

    std::cout << "Done!\n";

    return 0;
}