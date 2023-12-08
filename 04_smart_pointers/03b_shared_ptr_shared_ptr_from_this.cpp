/*
 * std::shared_ptr from this
 * With the class std::enable_shared_from_this, we can create objects which return a std::shared_ptr in itself. For that
 * we have to derive the class public from std::enable_shared_from_this. So the class supports the method
 * shared_from_this to return std::shared_ptr to this.
 */
#include <iostream>
#include <memory>

class ShareMe: public std::enable_shared_from_this<ShareMe> {
public:
    std::shared_ptr<ShareMe> getShared(){
        return shared_from_this();
    }
};

int main(){
    std::shared_ptr<ShareMe> shareMe(new ShareMe);
    std::shared_ptr<ShareMe> shareMe1 = shareMe->getShared();
    std::cout << (void*)shareMe.get() << "\n";
    std::cout << (void*)shareMe1.get() << "\n";
    std::cout << shareMe.use_count() << "\n";

    return 0;
}