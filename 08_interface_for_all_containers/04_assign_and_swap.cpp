/*
 * Assign and Swap
 * We can assign new elements to existing containers or swap two containers. For the assignment of a container cont2 to
 * a container cont, there exists the copy assignment cont = cont2 and the move assignment cont = std::move(cont2). This
 * statement copies the value of cont2 to cont and the value of cont2 becomes empty after the move operation. A special
 * form of assignment is the one with an initializer list cont = {1, 2, 3, 4, 5}. That's not possible for std::array,
 * but we can instead use the aggregate initialization. The function swap exists in two forms. We have it as method
 * cont(swap(cont2)) or as a function template std::swap(cont, cont2).
 */
#include <iostream>
#include <set>

int main(){
    std::set<int> set1{0, 1, 2, 3, 4, 5};
    std::set<int> set2{6, 7, 8, 9};

    for (const auto& s : set1) std::cout << s << " ";
    std::cout << "\n";

    for (const auto& s : set2) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "==============================\n\n";

    set1 = set2;

    for (const auto& s : set1) std::cout << s << " ";
    std::cout << "\n";

    for (const auto& s : set2) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "==============================\n\n";

    set1 = std::move(set2);

    for (const auto& s : set1) std::cout << s << " ";
    std::cout << "\n";

    for (const auto& s : set2) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "==============================\n\n";

    set2 = {60, 70, 80, 90};

    for (const auto& s : set1) std::cout << s << " ";
    std::cout << "\n";

    for (const auto& s : set2) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "==============================\n\n";

    std::swap(set1, set2);

    for (const auto& s : set1) std::cout << s << " ";
    std::cout << "\n";

    for (const auto& s : set2) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "==============================\n\n";

    return 0;
}