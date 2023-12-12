/*
 * Check Type Information
 * Type traits allow us to access and verify the type categories for all our variables.
 * With the type library, we can check primary and composite type categories. The attribute value gives us the result.
 *
 * Primary Type Categories
 * There are 14 different type categories. They are complete and don't overlap. So each type is only a member of one
 * type category. If we check a type category for our type, the request is independent of the const or volatile
 * qualifiers.
 *  template <class T> struct is_void;
 *  template <class T> struct is_null_pointer;
 *  template <class T> struct is_integral;
 *  template <class T> struct is_floating_point;
 *  template <class T> struct is_array;
 *  template <class T> struct is_pointer;
 *  template <class T> struct is_member_object_pointer;
 *  template <class T> struct is_member_function_pointer;
 *  template <class T> struct is_enum;
 *  template <class T> struct is_union;
 *  template <class T> struct is_class;
 *  template <class T> struct is_function;
 *  template <class T> struct is_lvalue_reference;
 *  template <class T> struct is_rvalue_reference;
 *
 * Composite Type categories
 * Based on the 14 primary type categories, there are 6 composite type categories.
 *  - is_arithmetic: is_floating_point or is_integral;
 *  - is_fundamental: is_arithmetic or is_void;
 *  - is_object: is_arithmetic or is_enum or _is_pointer or is_member_pointer;
 *  - is_reference: is_lvalue_reference or is_rvalue_reference;
 *  - is_compound: complement of is_fundamental;
 *  - is_member_pointer: is_member_object_pointer or is_member_function_pointer
 */
#include <iostream>
#include <type_traits>

struct A{
    int a;
    int f(int){return 2023;}
};

enum E{
    e = 1,
};

union U{
    int u;
};

int main(){
    std::cout << std::boolalpha;
    std::cout << "is_void: " << std::is_void<void>::value << "\n";
    std::cout << "is_integral: " << std::is_integral<short>::value << "\n";
    std::cout << "is_floating_point: " << std::is_floating_point<double>::value << "\n";
    std::cout << "is_array: " << std::is_array<int []>::value << "\n";
    std::cout << "is_pointer: " << std::is_pointer<int*>::value << "\n";
    std::cout << "is_reference: " << std::is_reference<int&>::value << "\n";

    std::cout << "is_member_object_pointer: " << std::is_member_object_pointer<int A::*>::value << "\n";
    std::cout << "is_member_function_pointer: " << std::is_member_function_pointer<int (A::*)(int)>::value << "\n";

    std::cout << "is_enum: " << std::is_enum<E>::value << "\n";

    std::cout << "is_union: " << std::is_union<U>::value << "\n";

    std::cout << "is_class: " << std::is_class<std::string>::value << "\n";
    std::cout << "is_function: " << std::is_function<int* (double)>::value << "\n";
    std::cout << "is_lvalue_reference: " << std::is_lvalue_reference<int&>::value << "\n";
    std::cout << "is_rvalue_reference: " << std::is_rvalue_reference<int&&>::value << "\n";

    return 0;
}