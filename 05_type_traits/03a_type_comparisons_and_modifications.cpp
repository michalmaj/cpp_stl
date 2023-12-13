/*
 * Type Comparisons and Modifications
 * Sometimes we need to manipulate or compare different types. We can use the type traits library for that.
 *
 * Type Comparisons
 * The library supports three kinds of type comparisons:
 *  1. template <class Base, class Derived> struct is_base_of - checks if Derived is derived from Base.
 *  2. template <class From, class To> struct is_convertible - Checks if From can be converted to To.
 *  3. template <class T, class U> struct is_same - checks if the types T and U are the same.
 *
 * Type Modifications
 * The type traits library enables us to modify types during compile time. So we can modify the constness of a type.
 * The function std::add_const adds the constness to a type, while std::remove_const removes it.
 * There are a lot more functions available in the type traits library. So we can modify the const-volatile properties
 * of a type.
 *  template <class T> struct remove_const;
 *  template <class T> struct remove_volatile;
 *  template <class T> struct remove_cv;
 *  template <class T> struct add_const;
 *  template <class T> struct add_volatile;
 *  template <class T> struct add_cv;
 *
 * We can also change at compile time the signs:
 *  template <class T> struct make_signed;
 *  template <class T> struct make_unsigned;
 *
 * Or the reference or pointer properties of a type:
 *  template <class T> struct remove_reference;
 *  template <class T> struct add_lvalue_reference;
 *  template <class T> struct add_rvalue_reference;\
 *  template <class T> struct remove_pointer;
 *  template <class T> struct add_pointer;
 */
#include <iostream>
#include <type_traits>

int main(){
    std::cout << std::boolalpha;

    std::cout << "std::is_const<int>::value: " << std::is_const<int>::value << "\n";
    std::cout << "std::is_const<const int>::value: " << std::is_const<const int>::value << "\n";
    std::cout << "std::is_const<std::add_const<int>::type>::value: " << std::is_const<std::add_const<int>::type>::value << "\n";

    using myConstInt = std::add_const<int>::type;
    std::cout << "std::is_const<myConstInt>::value: " << std::is_const<myConstInt>::value << "\n";

    using myConstInt2 = const int;
    std::cout << "std::is_same<myConstInt, myConstInt2>::value: " << std::is_same<myConstInt, myConstInt2>::value << "\n";

    std::cout << "std::is_same<int, std::remove_const<std::add_const<int>::type>::type>::value: " << std::is_same<int, std::remove_const<std::add_const<int>::type>::type>::value << "\n";
    std::cout << "std::is_same<const int, std::add_const<int>::type>::value: " << std::is_same<const int, std::add_const<int>::type>::value << "\n";

    return 0;
}