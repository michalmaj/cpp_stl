/*
 * The Hash function
 * The reason for the constant access time of the unordered associative container is the hash function. The hash
 * function maps the key to its value the so-called has value. A has function is good if it produces as few collisions
 * as possible and equally distributes the keys onto the buckets. Because the execution of the hash function takes a
 * constant amount of time, the access of the elements is in base case also constant.
 *
 * The has function:
 *  - is already defined for the built-in types like boolean, natural numbers and floating point numbers,
 *  - is available for std::string and std::wstring,
 *  - generates for a C-string const char a hash value of the pointer address,
 *  - can be defined for user-defined data types.
 *
 * For user-defined types which are used as a key for an unordered associative container, we have to keep two
 * requirements to keep in mind. They need a hash function and have to be comparable to equal.
 */
#include <iostream>
#include <unordered_map>

struct MyInt {
    MyInt(int v): val(v) {}
    bool operator== (const MyInt& other) const {
        return val == other.val;
    }
    int val;
};

struct MyHash {
    std::size_t operator()(MyInt m) const {
        std::hash<int> hashVal;
        return hashVal(m.val);
    }
};

std::ostream& operator<<(std::ostream& out, const MyInt& myInt){
    out << myInt.val;
    return out;
}

int main(){
    typedef std::unordered_map<MyInt, int, MyHash> MyIntHash;
    MyIntHash  myMap{
            {MyInt(-2), -2},
            {MyInt(-1), -1},
            {MyInt(0), 0},
            {MyInt(1), 1},
    };

    for (const auto& m : myMap) std::cout << "{" << m.first << ": " << m.second << "} ";
    std::cout << "\n";

    std::cout << "====================================\n";

    std::cout << myMap[-2] << "\n";

    return 0;
}