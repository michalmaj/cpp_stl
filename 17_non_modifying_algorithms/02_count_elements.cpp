/*
 * Count Elements
 * Count algorithms assist us in counting the number of elements in range which satisfy a certain predicate.
 * We can count elements with STL with and without a predicate.
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main(){
    std::string str{"abcdabAAAaefaBqeaBCQEaadsfdewAAQAaafbd"};
    std::cout << "count: " << std::count(str.begin(), str.end(), 'a') << std::endl;
    std::cout << "count_if: " << std::count_if(str.begin(), str.end(), [](char a){
        return std::isupper(a);}) << std::endl;


    return 0;
}