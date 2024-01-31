/*
 * for_each
 * As the name suggests, this method picks up each value in our container and performs the desired action.
 * std::for_each applies a unary callable element of its range. The range is given by the input iterators.
 * std::for_each when used without an explicit execution policy is a special algorithm because it returns its callable
 * argument. If we invoke std::for_each with a function object, we can store the result of the function call directly
 * in the function object.
 * std::for_each_n is new with C++17 and applies a unary callable to the first n elements of its range. The range is
 * given by an input iterator and size.
 */
#include <array>
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class ContainerInfo {
public:
    void operator()(T t){
        num++;
        sum += t;
    }

    T getSum() const { return sum; }
    int getNum() const { return num; }
    double getMean() const {
        return static_cast<double>(sum) / static_cast<double>(num);
    }

private:
    T sum{0};
    int num{0};
};

template <typename Cont>
void print(const Cont& c){
    for (const auto& e : c)
        std::cout << e << " ";
    std::cout << "\n";
}

int main(){
    std::vector<double> myVec {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    std::cout << "myVec contains: ";
    print(myVec);

    auto vecInfo = std::for_each(myVec.begin(), myVec.end(), ContainerInfo<double>{});
    std::cout << "vecInfo.getSum(): " << vecInfo.getSum() << "\n";
    std::cout << "vecInfo.getNum(): " << vecInfo.getNum() << "\n";
    std::cout << "vecInfo.getMean(): " << vecInfo.getMean() << "\n";

    std::cout << "======================================\n\n";

    std::array<int, 100> myArr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto arrInfo= std::for_each(myArr.begin(), myArr.end(), ContainerInfo<int>());
    std::cout << "arrInfo.getSum(): " << arrInfo.getSum() << std::endl;
    std::cout << "arrInfo.getNum(): " << arrInfo.getNum() << std::endl;
    std::cout << "arrInfo.getMean(): " << arrInfo.getMean() << std::endl;

    return 0;
}