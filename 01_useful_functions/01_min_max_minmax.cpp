/*
 * The min, max, and minmax functions
 * This family of functions allows us to find the minimum and maximum is a set of data.
 *
 * Required Headers
 * The many variations of the min, max, and minmax function apply to values and initializer lists. These functions need
 * the header <algorithm>. Nearly the same holds for the functions std::move, std::forward, and std::swap. We can apply
 * them to arbitrary values. These three functions are defined in the header <utility>.
 *
 * std::min, std::max, and std::minmax
 * The functions std::min, std::max, and std::minmax, defined in header <algorithm>, act on values and initializer lists
 * and give us the requested value back as result. In the case of std::minmax, we get an std::pair. THe first element
 * of this pair is the minimum, the second is the maximum of these values. By default, less operator (<) is used, be we
 * can specify our comparison operator. This function needs two arguments and return a boolean. Functions that either
 * return true or false are called predicates.
 */
#include <algorithm>
#include <iostream>

int main(){
    // Return the minimal value of two
    std::cout << "std::min(2017, 2023): " << std::min(2017, 2023) << "\n";

    // Return the minimal value of the initializer list
    std::cout << "std::min({3, 1, 2017, 2023, -5}): " << std::min({3, 1, 2017, 2023, -5}) << "\n";

    // Return the minimal value of the initializer list according to the predicate.
    std::cout << "std::min(-10, -5, [](const auto& a, const auto& b){return std::abs(a) < std::abs(b);}): " <<
    std::min(-10, -5, [](const auto& a, const auto& b){return std::abs(a) < std::abs(b);}) << "\n";

    // Return the minimal and maximal value of thwo
    std::pair<int, int> pairInt = std::minmax(2017, 2023);
    std::cout << "pairInt contains: " << pairInt.first << ", " << pairInt.second << "\n";

    // Return the minimal and maximal value of the initializer list
    auto pairSeq = std::minmax({3, 1, 2011, 2014, -5});
    std::cout << "pairSeq contains: " << pairSeq.first << ", " << pairSeq.second << "\n";

    // Return the minimal and maximal value of the initializer list according to the predicate
    auto [first, second] = std::minmax({3, 1, 2011, 2014, -5}, [](const auto& f, const auto& s){
        return std::abs(f) < std::abs(s);
    });
    std::cout << "first, second: " << first << ", " << second << "\n";


    return 0;
}