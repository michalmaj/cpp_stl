/*
 * Partition
 * This algorithm allows us to divide or split ranges into separate sets.
 *
 * What is a partition?
 * A partition of a set is a decomposition of a set in subsets so that each element of the set is precisely in one
 * subset. The subsets are defined in C++ by a unary predicate so that the members of the first subset fulfill the
 * predicate. The remaining elements are in the second subset.
 *
 * C++ offers a few functions for dealing with partitions. All of them need a unary predicate pre. std::partition and
 * std::stable_partition partition a range and return the partition point. With std::partition_point we can get the
 * partition point of a partition. Afterward, we can check the partition with std::is_partitioned or copy it with
 * std::partition_copy.
 *
 * A std::stable_partition guarantees, in contrary to a std::partition, that the elements preserve their relative order.
 * The returned iterator FwdIt and BiIt point to the initial position in the second subset of the partition. The pair
 * std::pair<OutIt, OutIt> of the algorithm std::partition_copy contains the end iterator of the subsets result_true and
 * result_false. The behavior of std::partition_point is undefined if the range is not partitioned.
 */
#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <ranges>
#include <string>
#include <vector>

bool isOdd(int i) { return i % 2; }

template <typename Cont>
void printCont(const Cont& c) {
    for (const auto& e : c)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> vec{1, 4, 3, 4, 5, 6, 7, 3, 4, 5, 6, 0, 4, 8, 4, 6, 6, 5, 8, 8, 3, 9, 3, 7, 6, 4, 8};
    std::cout << "vec contains: ";
    printCont(vec);

    auto parPoint = std::ranges::partition(vec, isOdd);

    std::cout << "vec after partition contains: ";
    printCont(vec);

    std::cout << "First sub-range of vec contains: ";
    for (auto v = vec.begin(); v != parPoint.begin(); ++v) {
        std::cout << *v << " ";
    }
    std::cout << "\n";

    std::cout << "Second sub-range of vec contains: ";
    for (auto v = parPoint.begin(); v != vec.end(); ++v) {
        std::cout << *v << " ";
    }
    std::cout << "\n";

    std::cout << "std::is_partitioned: " << std::is_partitioned(vec.begin(), vec.end(), isOdd) << "\n";
    std::cout << "std::partition_point: "
              << (std::partition_point(vec.begin(), vec.end(), isOdd) == parPoint.begin()) << "\n";

    std::cout << "\n====================================\n\n";

    std::list<int> li;
    std::list<int> de;
    std::partition_copy(vec.begin(), vec.end(), std::back_inserter(li),
                        std::back_inserter(de), [](int i){
        return i < 5;
    });

    std::cout << "List li contains: ";
    printCont(li);
    std::cout << "List de contains: ";
    printCont(de);
    

    return 0;
}