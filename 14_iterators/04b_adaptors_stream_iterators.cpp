/*
 * Stream Iterators
 * Stream iterator adaptors can use streams as a data source or data sink. C++ offers two functions to create istream
 * iterators and two to create ostream iterators. The created istream iterators behave like input iterators, the
 * ostream iterators like insert iterators.
 *  - std::istream_iterator<T> - Creates an end-of-stream iterator.
 *  - std::istream_iterator<T>(istream) - Creates an istream iterator of istream.
 *  - std::ostream_iterator<T>(ostream) - Creates an ostream iterator for ostream.
 *  - std::ostream_iterator<T>(ostream, delim) - Creates an ostream iterator for ostream with the delimiter delim.
 *
 * The four stream iterators
 * Thanks to the stream iterator adaptors we can directly read from or write to a stream.
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <vector>

int main(){
    std::vector<int> myIntVec;
    std::istream_iterator<int> myIntStreamReader(std::cin);
    std::istream_iterator<int> myEndIterator;

    while (myIntStreamReader != myEndIterator){
        myIntVec.push_back(*myIntStreamReader);
        ++myIntStreamReader;
    }

    std::copy(myIntVec.begin(), myIntVec.end(), std::ostream_iterator<int>(std::cout, ":"));

    return 0;
}