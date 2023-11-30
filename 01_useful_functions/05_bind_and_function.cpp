/*
 * std::bind and std::function
 * Thw two functions std::bind and std::function fit very well together. While std::bind enables us to create new
 * function objects on the fly, std::function takes these temporary function objects and binds them to a variable. Both
 * functions are powerful tools from functional programming and need the header <functional>.
 *
 * std::bind and std::function, which where part of TR1, are mostly not necessary any more with C++11. We can use
 * lambda functions instead of std::bind and most often we can use the automatic type deduction instead of std::function.
 */
#include <functional>
#include <iostream>

double divMe(double a, double b){ return a / b; }

int main(){
    std::cout << std::boolalpha;
    std::function<double(double, double)> myDiv1 = std::bind(divMe, std::placeholders::_1, std::placeholders::_2);
    std::function<double(double)> myDiv2 = std::bind(divMe, 2000, std::placeholders::_1);

    std::cout << (divMe(2000, 10) == divMe(2000, 10)) << "\n";
    std::cout << (myDiv1(2000, 10) == myDiv2(10)) << "\n";

    return 0;
}