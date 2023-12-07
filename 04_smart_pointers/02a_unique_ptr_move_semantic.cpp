/*
 * Unique Pointers
 * std::unique_pre exclusively takes care of its resource. It automatically releases the resource if it goes out of
 * scope. If there is no copy semantic required, it can be used in containers and algorithms of the Standard Template
 * Library. std::unique{ptr is cheap and fast as a raw pointer, if we use no special deleter.
 */
#include <iostream>
#include <memory>

int main(){
    std::auto_ptr<int> ap1(new int{2023}); // Only for education purpose, this pointer is deprecated.
    std::auto_ptr<int> ap2 = ap1; // Possible with auto_ptr.

    std::unique_ptr<int> up1(new int{2023});
//    std::unique_ptr<int> up2 = up1; // Compiler Error
    std::unique_ptr<int> up3 = std::move(up1); // OK, we can move
    
    return 0;
}