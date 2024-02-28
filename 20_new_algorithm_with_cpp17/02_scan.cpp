/*
 * Scan
 * Scan operations are useful when working with prefix sums.
 *
 * exclusive_Scan: computes the exclusive prefix sum using a binary operation:
 *  - behaves similar to std::reduce, but provides a range of all prefix sums;
 *  - excludes the last element in each iteration.
 *
 * inclusive_scan: computes the inclusive prefix sum using a binary operation:
 *  - behaves similar to std::reduce, but provides a range of all prefix sums;
 *  - includes the last element in each iteration.
 *
 * transform_exclusive_scan: first transform each element and then computes the exclusive prefix sum.
 *
 * transform_inclusive_scan: first transform each element of the input range and then computes the inclusive prefix sums
 */
#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v) {
    for (const auto& e : v) {
        out << e << " ";
    }
    return out;
}

int main() {
    std::vector<int> intVec(10);
    std::iota(intVec.begin(), intVec.end(), 1);
    std::vector<int> resVec(intVec.begin(), intVec.end()-1);
    std::vector<int> resVec2(resVec);
    std::vector<int> resVec3(resVec);
    std::vector<int> resVec4(resVec3.size());
    std::cout << "intVec contains: " << intVec << '\n';

    std::cout << "for_each:\n";
    std::for_each_n(std::execution::par,
                    intVec.begin(), 5,
                    [](auto& arg){return arg *= arg;});
    std::cout << "After operation intVec contains: " << intVec << '\n';

    std::cout << "\nexclusive scan:\n";
    std::exclusive_scan(resVec.begin(), resVec.end(), resVec.begin(), 1,
                        [](auto fir, auto sec){return fir*sec;});
    std::cout << "resVec contains: " << resVec << '\n';

    std::cout << "\ninclusive scan:\n";
    std::inclusive_scan(resVec2.begin(), resVec2.end(), resVec2.begin(),
                        [](auto fir, auto sec){return fir*sec;}, 1);
    std::cout << "resVec2 contains: " << resVec2 << '\n';

    std::cout << "\ntransform exclusive scan:\n";
    std::transform_exclusive_scan(resVec3.begin(), resVec3.end(),
                                  resVec4.begin(), 0,
                                  [](auto fir, auto sec){return fir + sec;},
                                  [](auto arg){return arg*=arg;});
    std::cout << "resVec4 contains: " << resVec4 << '\n';

    std::cout << "\ntransform inclusive scan:\n";
    std::vector<std::string> strVec{"Only", "for", "testing", "purpose"};
    std::vector<int> resVec5(strVec.size());
    std::transform_inclusive_scan(strVec.begin(), strVec.end(),
                                  resVec5.begin(),
                                  [](int fir, int sec){return fir+sec;},
                                  [](auto s){return s.size();}, 1);
    std::cout << "resVec5 contains: " << resVec5 << '\n';

    // reduce and transform_reduce
    std::vector<std::string> strVec2{"Only", "for", "testing", "purpose"};

    std::string res = std::reduce(std::execution::par,
                                  strVec2.begin() + 1, strVec2.end(), strVec2[0],
                                  [](auto fir, auto sec){ return fir + ":" + sec; });

    std::cout << "reduce: " << res << std::endl;


    std::size_t res7 = std::transform_reduce(std::execution::par,
                                                       strVec2.begin(), strVec2.end(), 0,
                                                       [](std::size_t a, std::size_t b){ return a + b; },
                                                       [](std::string s){ return s.length(); });

    std::cout << "transform_reduce: " << res7 << std::endl;


    return 0;
}