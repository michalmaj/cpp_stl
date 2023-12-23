/*
 * Size
 * For a container cont, we can check with cont.empty() if the container is empty. cont.size() returns the current
 * number of elements, and cont.max_size() returns the maximum number of elements cont can have. The maximum number
 * of elements is implementation defined.
 *
 * Use cont.empty() instead of cont.size()
 * For a container count, use the method cont.empty() instead of (cont.size() == 0) to determine if the container is
 * empty. First cont.empty() is in general faster than (cont.size() == 0); second, std::forward_list has no method
 * size().
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main(){
    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::map<std::string, int> str2Int{
            {"bar", 12345},
            {"jenne", 34929},
            {"huber", 840284}
    };
    std::set<double> doubleSet{3.14, 2.5};

    std::cout << std::boolalpha;
    std::cout << intVec.empty() << "\n";
    std::cout << str2Int.empty() << "\n";
    std::cout << doubleSet.empty() << "\n";

    std::cout << intVec.size() << "\n";
    std::cout << str2Int.size() << "\n";
    std::cout << doubleSet.size() << "\n";

    std::cout << intVec.max_size() << "\n";
    std::cout << str2Int.max_size() << "\n";
    std::cout << doubleSet.max_size() << "\n";

    return 0;
}