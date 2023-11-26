/*
 * Move vs. Copy
 * The function std::move, defined in the header <utility>, empowers the compiler to move its resource. In the so-called
 * move semantic, the values from the source object are moved to the new object. Afterward, the source is in well-defined
 * but not specified state. Most of the time that is the default state of the source. By using std::move, the compiler
 * converts the source arg to a rvalue reference:
 *  static_cast<std::remove_reference<decltype(arg)>::type&&> (arg);
 * The subtle difference is that if we create a new object based on an existing one, the copy semantic will copy the
 * elements of the existing resource, whereas the move semantic will move the elements of the resource. So, copying is
 * expensive and moving is cheap. But there are additional serious consequences:
 *  1. With the copy semantic, it is possible that a std::bad_alloc will be thrown because our program is out of memory.
 *  2. The source of the move operation is in a "valid but unspecified state" afterward.
 * The second point can be explained well by std::string example below.
 * Note: If the compiler can not apply the move semantic, it falls back to the copy semantic.
 */
#include <iostream>
#include <utility>

int main(){
    std::string str1{"abcd"};
    std::string str2{"efgh"};
    std::cout << "str1: " << str1 << "\n";
    std::cout << "str2: " << str2 << "\n\n";

    // Copying (copy semantic)
    str2 = str1;
    std::cout << "After copying: " << "\n";
    std::cout << "str1: " << str1 << "\n";
    std::cout << "str2: " << str2 << "\n\n";

    str1 = "abcd";
    str2 = "efgh";

    // Moving
    str2 = std::move(str1);
    std::cout << "After moving: " << "\n";
    std::cout << "str1: " << str1 << "\n"; // str1 is empty after the move operation (it is not guaranteed)
    std::cout << "str2: " << str2 << "\n\n";

    return 0;
}