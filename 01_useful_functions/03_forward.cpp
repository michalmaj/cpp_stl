/*
 * Forward
 * The function std::forward, defined in hte header <utility>, empowers us to write function templates, which can
 * identically forward their arguments. Typical use cases for std::forward are factory functions or constructors.
 * Factory functions are functions which create an object and must therefore identically pass the arguments.
 * Constructors often use their arguments to initialize their base class with identical arguments. So std::forward is
 * the perfect tool for authors of generic libraries.
 *
 * std::forward in combination with variadic templates allows completely generic functions. If we use std::forward
 * together with variadic templates, we can define completely generic function templates. Our function template can
 * accept an arbitrary number of arguments and forward them unchanged.
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct MyData{
    MyData(int i, double d, char c): i(i), d(d), c(c) {}

    void print() const{
        std::cout << "i: " << i << ", d: " << d << ", c: " << c << "\n";
    }

    int i;
    double d;
    char c;
};

// The function template createT has to take their arguments as a universal reference: Args&&... args. A universal
// reference or also called forwarding reference is an rvalue reference in a type deduction context.
template <typename T, typename... Args>
T createT(Args&&... args){
    return T(std::forward<Args>(args)...);
}

int main(){
    int a = createT<int>();
    std::cout << "a: " << a << "\n";
    int b = createT<int>(1);
    std::cout << "b: " << b << "\n";

    std::string s = createT<std::string>("Only for testing");
    std::cout << "s: " << s << "\n";

    MyData myData = createT<MyData>(1, 3.14, 'z');
    myData.print();

    typedef std::vector<int> IntVec;
    IntVec intVec = createT<IntVec>(std::initializer_list<int>({1, 2, 3}));
    std::cout << "intVec contains: ";
    for(const auto& e : intVec)
        std::cout << e << " ";
    std::cout << "\n";


    return 0;
}