/*
 * Deques
 * std::deque, which consists of a sequence of arrays, is quite similar to std::vector. std::deque need the header
 * <deque>. The std::deque has three additional methods deq.push_front(elem), deq.pop_front() and
 * deq.emplace_front(args...) to add or remove elements at its beginning.
 */
#include <deque>
#include <iostream>

class MyInt{
    friend std::ostream& operator<<(std::ostream& out, const MyInt& m){
        out << m.myInt;
        return out;
    }
public:
    MyInt(int i): myInt(i) {}
private:
    int myInt;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& d){
    for (const auto& e : d)
        out << e << " ";
    return out;
}

int main(){
    std::deque<MyInt> myIntDeq;

    myIntDeq.push_back(MyInt(5));
    myIntDeq.emplace_back(1);
    std::cout << myIntDeq.size() << std::endl;
    std::cout << myIntDeq << "\n";

    std::cout << "=================================\n\n";

    std::deque<MyInt> intDeq;
    intDeq.assign({1, 2, 3});
    std::cout << intDeq << "\n";

    intDeq.insert(intDeq.begin(), 0);
    std::cout << intDeq << "\n";

    intDeq.insert(intDeq.begin() + 4, 4);
    std::cout << intDeq << "\n";

    intDeq.insert(intDeq.end(), {5, 6, 7, 8, 9, 10, 11});
    std::cout << intDeq << "\n";

    for (auto it{intDeq.rbegin()}; it != intDeq.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    intDeq.pop_back();
    std::cout << intDeq << "\n";

    intDeq.push_front(-1);
    std::cout << intDeq << "\n";




    return 0;
}