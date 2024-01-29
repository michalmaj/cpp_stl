/*
 * Sequential, parallel, or parallel execution with vectorization
 * By using an execution policy in C++17, we can specify whether the algorithm should run sequentially, in parallel, or
 * in parallel with vectorization.
 *
 * Execution Policies
 * The policy tag specifies whether an algorithm should run sequentially, in parallel, or in parallel with vectorization
 *  - std::execution::seq - runs the algorithm sequentially;
 *  - std::execution::par - runs the algorithm in parallel on multiple threads;
 *  - std::execution::par_unseq - runs the algorithm in parallel on multiple threads and allows the interleaving of
 *                                individual loops; permits a vectorised version with SMID (Single instruction Multiple
 *                                Data) extensions.
 */
#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v){
    for (const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> v(999);
    std::iota(v.begin(), v.end(), 1);
    std::random_device rd;
    std::mt19937 f(rd());
    std::shuffle(v.begin(), v.end(), f);
    std::cout << "Vector contains: " << v << "\n";

    std::cout << "\n\n";

    // Standard sequential algorithm
    std::sort(v.begin(), v.end());
    std::cout << "Vector after sorting contains: " << v << "\n";

    std::shuffle(v.begin(), v.end(), f);
    std::cout << "\n\n";

    // Sequential execution
    std::sort(std::execution::seq, v.begin(), v.end());
    std::cout << "Vector after sorting contains: " << v << "\n";

    std::shuffle(v.begin(), v.end(), f);
    std::cout << "\n\n";

    // Parallel execution
    std::sort(std::execution::par, v.begin(), v.end());
    std::cout << "Vector after sorting contains: " << v << "\n";

    std::shuffle(v.begin(), v.end(), f);
    std::cout << "\n\n";

    // Permitting parallel and vectorized execution
    std::sort(std::execution::par_unseq, v.begin(), v.end());
    std::cout << "Vector after sorting contains: " << v << "\n";

    return 0;
}