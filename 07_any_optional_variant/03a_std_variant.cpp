/*
 * std::variant
 * std::variant allows us to create a variable fromany of the types specified in the std::variant container.
 *
 * std::variant is a type-safe union. An instance of std::variant has a value from one of its types. The type must not
 * be a reference, array or void. A std::variant can have a type more than once. A default-initialised std::variant is
 * initialised with its first type; therefore, its first type must have a default constructor. By using var.index we get
 * the zero-based index of the alternative held by the std::variant var. var.valueless_by_exception returns false if the
 * variant holds a value. By using var.emplace we can create a new value in-place. There are a few global functions used
 * to access a std::variant. The function template var.holds_alternative lets us check if the std::variant holds a
 * specified alternative. We can use std::get with an index and with a type as argument. By using an index, we will get
 * the value. If we invoke std::get with a type, we will only get the value if it is unique. If we use an invalid index
 * or a non-unique type, we will get a std::bad_variant_access exception. In contrast to std::get which eventually
 * returns an exception, std::get_if returns a null pointer in the case of an error.
 */
#include <cassert>
#include <iostream>
#include <variant>

int main(){

    std::variant<int, float> v, w;
    v = 12; // v contains int
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v; // same effect as the previous line

//    std::get<double>(v); // CE: no double in [int, float]
//    std::get<3>(v); // CE: valid index values are 0 and 1

    try{
        std::get<float>(w); // w contains  int, not float: will throw an exception
    }
    catch (const std::bad_variant_access& bva){
        std::cout << bva.what() << "\n";
    }

    std::variant<std::string> x{"abc"}; // converting constructors work when unambiguous
    x = "def"; // converting assignment also works when unambiguous

    std::variant<std::string, bool> y{"abc"}; // vasts to bool when passed a char const*
//    assert(std::holds_alternative<bool>(y));
    y = std::string{"xyz"};
    assert(std::holds_alternative<std::string>(y));

    return 0;
}