/*
 * std::vector vac has a few methods to access its elements. With vec.front() we get the first element, with vec.back()
 * we get the last element of vec. To read or write the (n+1)-th element of vec, we can use the index operator vec[n] or
 * the method vec.at(n). The second one checks the boundaries of vec, so that we eventually get a std::range_error
 * exception.
 * Besides the index operator, std::vector offers additional methods to assign, insert, create or remove elements:
 *  - vec.assign(...) - Assigns one or more elements, a range or an initializer list.
 *  - vec.clear() - Removes all elements from vec.
 *  - vec.emplace(pos, args, ...) - Creates a new element before pos with the args in vec and returns the new position
 *                                  of the element.
 *  - vec.emplace_back(args ...) - Creates a new element in vec with args ... .
 *  - vec.erase(...) - Removes one or more elements, or a range and return the next position.
 *  - vec.insert(pos, ...) - Inserts one or more elements, a range or an initializer list and returns the new position
 *                           of the element.
 *  - vec.pop_back() - Removes the last element.
 *  - vec.push_back(elem) - Add a copy of elem at the end of vec.
 */
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for (const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> intVec1;
    intVec1.push_back(10);
    std::cout << intVec1 << "\n";

    intVec1.push_back(20);
    intVec1.push_back(40);
    std::cout << intVec1 << "\n";

    intVec1.insert(intVec1.begin() + 2, 30);
    intVec1.insert(intVec1.begin(), 0);
    std::cout << intVec1 << "\n";

    intVec1.erase(intVec1.begin() + 1);
    std::cout << intVec1 << "\n";

    intVec1.pop_back();
    std::cout << intVec1 << "\n";

    intVec1.assign(4, 100);
    std::cout << intVec1 << "\n";

    intVec1.clear();
    std::cout << intVec1 << "\n";

    return 0;
}