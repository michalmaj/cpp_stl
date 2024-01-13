/*
 * The Details
 * The unordered associative containers store their indices in buckets. In which bucket the index goes is due to the
 * hash function, which maps the key to the index. If different keys are mapped to the same index, it's called a
 * collision. The hash function tries to avoid this.
 *
 * Indices are typically be stored in the bucket as a linked list. Since the access to the bucket is constant, the
 * access in the bucket is linear. The number of buckets is called capacity, the average number of elements for each
 * bucket is called the load factor. In general, the C++ runtime generates new buckets if the load factor is greater
 * than 1. This process called rehashing and can also explicitly be triggered.
 */
#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_set>


void getInfo(const std::unordered_set<int>& hash){
    std::cout << "hash.bucket_count(): " << hash.bucket_count() << "\n";
    std::cout << "hash.load_factor(): " << hash.load_factor() << "\n";
}

int main(){
    std::random_device device;
    std::mt19937 engine{device()};
    std::uniform_int_distribution<int> distribution(1, 100);

    std::unordered_set<int> hash;

    for (int i{0}; i < 100; ++i){
        int randomValue = distribution(engine);
        hash.insert(randomValue);
    }
    for (const auto& e : hash) std::cout << e << " ";
    std::cout << "\n";

    std::cout << "==========================\n\n";

    std::cout << "hash.max_load_factor(): " << hash.max_load_factor() << "\n";
    getInfo(hash);

    std::cout << "==========================\n\n";

    hash.insert(500);
    std::cout << "hash.bucket(500): " << hash.bucket(500) << "\n";
    getInfo(hash);

    std::cout << "==========================\n\n";

    hash.rehash(500);
    std::cout << "hash.bucket(500): " << hash.bucket(500) << "\n";
    getInfo(hash);

    return 0;
}