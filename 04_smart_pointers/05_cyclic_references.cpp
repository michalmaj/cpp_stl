/*
 * Cyclic References
 * We get cyclic references of std::shared_ptr if the refer to each other. So, the resource counter never becomes 0,
 * and the resource is not automatically released. We can break this cycle if we embed a std::weak_ptr in the cycle.
 * std::weak_ptr does not modify the reference counter.
 *
 * The result of the below code is that the daughter is automatically released, but neither the son nor the mother is.
 * The mother refers to her son via a std::shared_ptr and to her daughter via a std::weak_ptr.
 */
#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother{
    ~Mother() {std::cout << "Mother gone\n";}
    void setSon(const std::shared_ptr<Son>& s){mySon = s;}
    void setDaughter(const std::shared_ptr<Daughter> d){myDaughter = d;}
    std::shared_ptr<const Son> mySon;
    std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
    Son(std::shared_ptr<Mother>& m): myMother(m) {}
    ~Son() {std::cout << "Son gone\n";}
    std::shared_ptr<const Mother> myMother;
};

struct Daughter{
    Daughter(std::shared_ptr<Mother>& m): myMother(m) {}
    ~Daughter() {std::cout << "Daughter gone\n";}
    std::shared_ptr<const Mother> myMother;
};

int main(){
    std::shared_ptr<Mother> mother = std::shared_ptr<Mother>(new Mother);
    std::shared_ptr<Son> son = std::shared_ptr<Son>(new Son(mother));
    std::shared_ptr<Daughter> daughter = std::shared_ptr<Daughter>(new Daughter(mother));

    mother->setSon(son);
    mother->setDaughter(daughter);

    return 0;
}