/*
 * Search Elements
 * We can search for elements in three different ways:
 *  1. Return an element in a range.
 *  2. Return the first element of a range is a range.
 *  3. Returns identical, adjacent elements in a range.
 * The algorithms require input or forward iterators as arguments and return an iterator on the element when
 * successfully found. If the search is not successful, they return an end iterator.
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <set>

bool isVowel(char c) {
    std::string myVowels{"aeiouäöü"};
    std::set<char> vowels(myVowels.begin(), myVowels.end());
    return (vowels.find(c) != vowels.end());
}

int main(){
    std::list<char> myCha;
    std::generate_n(std::back_inserter(myCha), 10, [c = 'a']() mutable {
       return c++;
    });
    std::cout << "myCha contains: ";
    for (const auto& e : myCha) std::cout << e << " ";
    std::cout << "\n";

    int cha[]{'A', 'B', 'C'};

    std::cout << *std::find(myCha.begin(), myCha.end(), 'g') << std::endl;
    std::cout << *std::find_if(myCha.begin(), myCha.end(), isVowel) << std::endl;
    std::cout << *std::find_if_not(myCha.begin(), myCha.end(), isVowel) << std::endl;

    auto iter = std::find_first_of(myCha.begin(), myCha.end(), cha, cha+3);
    if (iter == myCha.end()) std::cout << "None of A, B, C\n";

    auto iter2 = std::find_first_of(myCha.begin(), myCha.end(), cha, cha+3,
                                    [](char a, char b){return std::toupper(a) == toupper(b);});
    if (iter2 != myCha.end())
        std::cout << *iter2 << "\n";

    auto iter4= std::adjacent_find(myCha.begin(), myCha.end(),
                              [](char a, char b){ return isVowel(a) == isVowel(b); });
    if (iter4 != myCha.end()) std::cout << *iter4;

    return 0;
}