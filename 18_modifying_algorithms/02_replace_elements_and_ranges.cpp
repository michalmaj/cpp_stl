/*
 * Replace Elements and Ranges
 * We have with std::replace, std::replace_if, std::replace_copy and std::replace_copy_if four variations to replace
 * elements in a range. The algorithms differ in two aspects. First, does the algorithm need a predicate? Second, does
 * the algorithm copy the elements in the destination range?
 *  - replace: Replaces the old elements in the range with newValue, if the old element has the value old.
 *  - replace_if: Replaces the old elements of the range with newValue, if the old element fulfils the predicate pred.
 *  - replace_copy: Replaces the old elements in the range with newVale (copies), if the old element has the value old.
 *  - replace_copy_if: Replaces the old elements of the range with newValue (copies), if the old element fulfils the
 *    predicate pred.
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main(){
    std::string str{"Only for testing purpose."};
    std::cout << str << "\n";

    std::replace(str.begin(), str.end(), ' ', '1');
    std::cout << str << "\n";

    std::replace_if(str.begin(), str.end(), [](char c){
        return c == '1';
    }, '2');
    std::cout << str << "\n";

    std::string str2;
    std::replace_copy(str.begin(), str.end(), std::back_inserter(str2), '2', '3');
    std::cout << str2 << "\n";

    std::string str3;
    std::replace_copy_if(str2.begin(), str2.end(), std::back_inserter(str3), [](char c){
        return c == '3';
    }, '4');
    std::cout << str3 << "\n";


    return 0;
}