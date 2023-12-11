/*
 * Introduction
 * The type traits library helps us optimize our code.
 * The type traits library enables us to check, compare and modify types at compile time. So, there is no overhead on
 * the runtime of our program. There are two reasons for using the type traits library:
 *  1. Optimization, because the introspection capabilities of the type traits library make it possible to choose the
 *     faster code automatically.
 *  2. Correctness, because we can specify requirements for our code, which is checked at compile-time.
 *
 *  The type traits library and static_assert are powerful pair. On one side, the functions of the type traits library
 *  provide the type information at compile time. On the other side, the static_assert function checks the given
 *  information at compile time. All this happens transparently to the runtime of the program.
 */
#include <cmath>
#include <iostream>
#include <type_traits>

template <typename T>
T fac(T a){
    static_assert(std::is_integral_v<T>, "T not integral");
    return std::tgamma(a + 1);
}

int main(){
    auto res1 = fac(3); // Fine, value is integral type
    std::cout << res1 << "\n";

//    auto res2 = fac(3.5); // CE: with T = double, T not integral

    return 0;
}