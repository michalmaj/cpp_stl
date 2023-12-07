/*
 * std::unique_ptr has a specialisation for arrays
 */
#include <iostream>
#include <memory>

class MyStruct{
public:
    MyStruct(): val(count) {
        std::cout << static_cast<void*>(this) << " Hello: " << val << std::endl;
        count++;
    }

    ~MyStruct(){
        std::cout << static_cast<void*>(this) << " Goodbye: " << val << std::endl;
        count--;
    }

private:
    int val;
    inline static int count{0};
};

int main(){
    // Generates a myUniqueArray with the 'MyStructs'
    std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[3]};


    return 0;
}