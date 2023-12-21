/*
 * std::variant has an interesting non-member function std::visit that allows us to execute a callable on list of
 * variants. A callable is something which we can invoke. Typically, this can be a function, a function object, or a
 * lambda expression.
 */
#include <iostream>
#include <variant>
#include <vector>

int main(){
    std::vector<std::variant<char, long, float, int, double, long long>> vecVariant{
        5, '2', 5.4, 100ll, 2011l, 3.5f, 2023
    };

    for (const auto& v: vecVariant)
        std::visit([](const auto& arg){std::cout << arg << " ";}, v);
    std::cout << "\n";

    for (const auto& v : vecVariant)
        std::visit([](const auto& arg){std::cout << typeid(arg).name() << " ";}, v);
    std::cout << "\n";

    // get the sum
    std::common_type<char, long, float, int, double, long long>::type res{};
    std::cout << typeid(res).name() << "\n";

    for (const auto& v : vecVariant)
        std::visit([&res](const auto& arg){res += arg;}, v);
    std::cout << "res: " << res << "\n";

    // double each value
    for (auto& v : vecVariant){
        std::visit([](auto&& arg){arg *= 2;}, v);
        std::visit([](auto&& arg){std::cout << arg << " ";}, v);
    }

    return 0;
}