/*
 * Functions Inherited from C
 * C++ inherited many numeric functions from C. They need the header <cmath>.
 * Additionally, C++ inherits further mathematical functions from C. They are defined in the header <cstdlib>. Once
 * more, the names of mathematical functions in <cstdlib>
 */
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    std::cout << "cmath\n";

    std::cout << "std::pow(2, 10): " << std::pow(2, 10) << '\n';
    std::cout << "std::pow(2, 0.5): " << std::pow(2, 0.5) << '\n';
    std::cout << "std::exp(1): " << std::exp(1) << '\n';
    std::cout << "std::ceil(5.5): " << std::ceil(5.5) << '\n';
    std::cout << "std::floor(1): " << std::floor(1) << '\n';
    std::cout << "std::fmod(5.5, 2): " << std::fmod(5.5, 2) << '\n';

    double intPart;
    auto fracPart = std::modf(5.7, &intPart);
    std::cout << "std::modf(5.7, &intPart): " << intPart << " + " << fracPart << '\n';

    std::cout << "\ncstdlib:\n";

    std::div_t diveresult = std::div(14, 5);
    std::cout << "std::div(14, 5): " << diveresult.quot << ", " << diveresult.rem << '\n';

    // seed
    std::srand(time(nullptr));
    for (int i{0}; i <= 10; ++i) {
        std::cout << "Dice: " << (rand() % 6 + 1) << '\n';
    }

    return 0;
}