/*
 * Behavior of std::bind and std::function
 * std::bind
 * Because of std::bind, we can create function objects in a variety of ways:
 *  - bind the arguments to an arbitrary position;
 *  - change the order of the arguments;
 *  - introduce placeholders for arguments;
 *  - invoke the newely created function objects, use them in the algorithm of the STL or store them in std::function.
 *
 * std::function
 * std::function can store arbitrary callables in variable. It's kind of polymorphic function wrapper. A callable may be
 * a lambda function, a function object, or a function. std::function is always necessary and can't be replaced by auto,
 * if we have to specify the type of the callable explicitly.
 */
#include <functional>
#include <iostream>
#include <map>

int main(){
    std::map<const char, std::function<double(double, double)>> tab;
    tab.insert({'+', [](double a, double b){return a + b;}});
    tab.insert({'-', [](double a, double b){return a - b;}});
    tab.insert({'*', [](double a, double b){return a * b;}});
    tab.insert({'/', [](double a, double b){return a / b;}});

    std::cout << "3.5 + 4.5 = " << tab['+'](3.5, 4.5) << "\n";
    std::cout << "3.5 - 4.5 = " << tab['-'](3.5, 4.5) << "\n";
    std::cout << "3.5 * 4.5 = " << tab['*'](3.5, 4.5) << "\n";
    std::cout << "3.5 / 4.5 = " << tab['/'](3.5, 4.5) << "\n";

    return 0;
}