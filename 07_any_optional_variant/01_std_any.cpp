/*
 * std::any
 * C++ allows us to put our value in a safe container which can be accessed only when its type is specified.
 *
 * std::any is a type-safe container for single values of any type which is copy-constructible. There are a few ways to
 * create a std::any container. We can use the various constructors or the factory function contained object. If we want
 * to know whether the container std::any has a value, use the method std::any_has_value. We can get the typeid of the
 * container object via std::any.type. Thanks to the generic function std::any_cast we have access to the contained
 * object. If we specify the wrong type, we will get a std::bad_any_cast exception.
 */
#include <any>
#include <iostream>
#include <vector>

struct MyCLass{};

int main(){
    std::vector<std::any> anyVector{true, 2017, std::string("test"), 3.14, MyCLass()};

    std::cout << std::any_cast<bool>(anyVector.at(0)) << "\n";
    int myInt = std::any_cast<int>(anyVector.at(1));
    std::cout << myInt << "\n";

    for (const auto& e : anyVector)
        std::cout << e.type().name() << "\n";


    return 0;
}