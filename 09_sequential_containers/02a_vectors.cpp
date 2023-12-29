/*
 * Vectors
 * std::vector is a homogeneous container, for which its length can be adjusted at runtime. std::vector needs the header
 * <vector>. As it stores its elements contiguously in memory, std::vector supports pointer arithmetic.
 *
 * Distinguish the round and curly braces by the creation of a std::vector
 * If we construct a std::vector, we have to keep a few specialities in mind. The constructor with round braces in the
 * following example creates a std::vector with 10 elements, the constructor with curly braces a std::vector with the
 * element 10.
 *  std::vector<int> vec(10);
 *  std::vector<int> vec{10};
 *
 * The same rules hold for the expression std::vector<int>(10, 2023) or std::vector<int>{10, 2023}. In the first case,
 * we get a std::vector with 10 elements, initialised to 2023. In the second case, we get a std::vector with elements 10
 * and 2023. The reason for the behaviour is, that curly braces are interpreted as initializer lists and so, the
 * sequence constructor is used.
 *
 * Size versus Capacity
 * The number of elements a std::vector has is usually smaller than the number of elements for which is space is
 * already reserved. That is for a simple reason. The size of the std::vector can increase without an expensive
 * allocation of new memory.
 * There are a few methods for the smart handling of memory:
 *  - vec.size() - Number of elements of vec.
 *  - vec.capacity() - Number of elements, which vec can have without reallocation.
 *  - vec.resize(n) - vec will be increased to n elements.
 *  - vec.reserve(n) - Reserve memory for at least n elements.
 *  - vec.shrink_to_fit() - Reduces capacity of vec to the size.
 *
 * Note: the call vec.shrink_to_fit() is not binding. That means the runtime can ignore it.
 */
#include <iostream>
#include <vector>

int main(){
    std::vector<int> intVec1(5, 2023);
    intVec1.reserve(10);
    std::cout << "intVec1.size(): " << intVec1.size() << "\n";
    std::cout << "intVec1.capacity(): " << intVec1.capacity() << "\n";

    intVec1.shrink_to_fit();
    std::cout << "intVec1.capacity(): " << intVec1.capacity() << "\n";

    std::vector<int> intVec2(10);
    std::cout << "intVec2.size(): " << intVec2.size() << "\n";

    std::vector<int> intVec3{10};
    std::cout << "intVec3.size(): " << intVec3.size() << "\n";

    std::vector<int> intVec4{5, 2023};
    std::cout << "intVec4.size(): " << intVec4.size() << "\n";

    return 0;
}