/*
 * Weak Pointers
 * This is the last component of the smart pointer family. Its purpose is much more limited compared to the others.
 * std::weak_ptr is not a smart pointer. std::weak_ptr supports no transparent access to the resource because it only
 * borrows the resource from std::shared_ptr. std::weak_ptr does bot change the reference counter.
 *
 * Weak Pointer methods:
 *  - expired: Checks if the resource was deleted.
 *  - lock: Creates a std::shared_ptr on the resource.
 *  - reset: Resets the resource.
 *  - swap: Swaps the resource.
 *  - use_count: Returns the value of the resource counter.
 *
 * There is one reason of the existence of std::weak_ptr. It breaks cycle of std::shared_ptr.
 */
#include <iostream>
#include <memory>

int main(){
    auto sharedPtr = std::make_shared<int>(2011);
    std::weak_ptr<int> weakPtr{sharedPtr};

    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << "\n";
    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << "\n";

    std::cout << std::boolalpha;
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

    if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock())
        std::cout << *sharedPtr << "\n";
    else
        std::cout << "Don't get it!\n";

    weakPtr.reset();

    if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock())
        std::cout << *sharedPtr << "\n";
    else
        std::cout << "Don't get it!\n";

    return 0;
}