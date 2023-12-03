/*
 * std::tie and std::ignore
 * std::tie enables us to create tuples, whose elements reference variables. With std::ignore we can explicitly ignore
 * elements of the tuple.
 */
#include <iostream>
#include <tuple>

int main(){
    int first{1};
    int second{2};
    int third{3};
    int fourth{4};

    std::cout << first << " " << second << " " << third << " " << fourth << "\n";
    // Bind the tuple and create the tuple and assign to it
    auto tup = std::tie(first, second, third, fourth) = std::make_tuple(101, 102, 103, 104);

    std::cout << "Tuple contains: ";
    std::cout << std::get<0>(tup) << " " << std::get<1>(tup) << " " << std::get<2>(tup) <<
            " " << std::get<3>(tup) << "\n";
    std::cout << "first, second, third, fourth are equal to: ";
    std::cout << first << " " << second << " " << third << " " << fourth << "\n";

    std::cout << "\n";

    first = 201;
    std::get<1>(tup) = 202;

    std::cout << "Tuple contains: ";
    std::cout << std::get<0>(tup) << " " << std::get<1>(tup) << " " << std::get<2>(tup) <<
              " " << std::get<3>(tup) << "\n";
    std::cout << "first, second, third, fourth are equal to: ";
    std::cout << first << " " << second << " " << third << " " << fourth << "\n";

    std::cout << "\n";

    int a, b;
    std::tie(std::ignore, a, std::ignore, b) = tup;
    std::cout << "a and b contain: ";
    std::cout << a << " " << b << "\n";

    return 0;
}