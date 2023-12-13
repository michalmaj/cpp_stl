/*
 * The three following functions are especially valuable for the writing of generic libraries:
 *  template <class B> struct enable_if;
 *  template <class B, class T, class F> struct conditional;
 *  template <class... T> common_type;
 *
 * We can conditionally hide with std::enable_if a function overload or template specialization from overload
 * resolution. std::conditional provides un with the ternary operator at compiler time and std::common_type gives us the
 * type, to which all type parameters can be implicitly converted to. std::common_type is a variadic template, therefore
 * the number on type parameters can be arbitrary.
 *
 * Let's say we want to write code for the euclid algorithm to calculate the greatest common divisor of wto numbers. We
 * can incorporate enable_if and conditional in our code.
 *
 * C++14 has a shorthand for ::type
 * If we want to get a const int from int we have to ask for the type: std::add_const<int>::type. With C++14 standard
 * use simply std::add_const_t<int> instead of the verbose form: std::add_const<int>::type. This rule works for all
 * type traits functions.
 */
#include <iostream>
#include <type_traits>

// The expression std::is_integral determines whether the type parameter T1 and T2 are integrals. If T1 and T2 are not
// integrals, and therefore they return false, we will not get a template instantiation.
// If std::enable_if returns true as the first parameter, std::enable_if will have a public member typedef type. If
// std::enable_if returns false as first parameter, std::enable_if will have on member type. This is not en error but a
// common technique in C++: SFINAE. SFINAE stands for Substitution Failure In Not An Error. Only the template for
// exactly this type will not be instantiated and the compiler tries to instantiate the template in another way.
template <typename T1, typename T2,
        typename std::enable_if<std::is_integral<T1>::value, T1>::type = 0,
        typename std::enable_if<std::is_integral<T2>::value, T2>::type = 0,
        typename R = typename std::conditional<(sizeof(T1) < sizeof(T2)), T1, T2>::type>
R gcd(T1 a, T2 b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    std::cout << "gcd(100, 10) = " << gcd(100, 10) << "\n";
    std::cout << "gcd(100, 33) = " << gcd(100, 33) << "\n";
//    std::cout << "gcd(3.5, 4.0) = " << gcd(3.5, 4.0) << "\n"; // CE: values aren't integers

    return 0;
}