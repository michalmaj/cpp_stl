/*
 * Create and Delete
 * We can construct each container by a multitude of constructors. To delete all elements of a container cont, we can
 * use cont.clear(). It makes no difference if we create a container, if we delete them or if we add or remove elements.
 * Each time the container takes care of the memory management.
 * Example using std::vector:
 *  - default: std::vector<int> vec1;
 *  - range: std::vector<int> vec2(vec1.begin(), vec1.end());
 *  - copy: std::vector<int> vec3(vec1);
 *  - copy: std::vector<int> vec4 = vec2;
 *  - move: std::vector<int> vec5(std::move(vec4));
 *  - move:std::vector<int> vec6 = std::move(vec3);
 *  - sequence: std::vector<int> vec7 {1, 2, 3, 4, 5};
 *  - sequence: std::vector<int> vec8 = {1, 2, 3, 4, 5};
 *  - destructor: vec5.~vector();
 *  - delete elements: vec8.clear();
 *
 * Note
 * Because std::array is generated at compile-time, there are a few things are special. std::array has no move
 * constructor and can neither be created with a range nor with an initializer list. However, we can initialize a
 * std::array with an aggregate initialization. Also, std::array has no method for removing its elements.
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::map<std::string , int> m{
            {"bart", 12345},
            {"jenne", 34920},
            {"huber", 840284}
    };
    std::unordered_map<std::string, int> um{m.begin(), m.end()};

    for (const auto& v : vec) std::cout << v << " ";
    std::cout << "\n";

    for (const auto& [k, v]: m) std::cout << k << ": " << v << " ";
    std::cout << "\n";

    for (const auto& [k, v]: um) std::cout << k << ": " << v << " ";
    std::cout << "\n";

    std::vector<int> vec2 = vec;
    std::cout << vec.size() << "\n";
    std::cout << vec2.size() << "\n";

    std::vector<int> vec3 = std::move(vec);
    std::cout << vec.size() << "\n";
    std::cout << vec3.size() << "\n";

    vec3.clear();
    std::cout << vec3.size() << "\n";

    return 0;
}