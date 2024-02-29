/*
 * Random Numbers
 * There's a whole library dedicated to the generation and usage of random numbers.
 *
 * C++ inherits the numeric functions from C and has a random number library.
 * Random numbers are necessary for many domains, e.g., to test software, to generate cryptographic keys or for computer
 * games. The radom number facility of C++ consists of two components. There is the generation of the random numbers,
 * and there is the distribution of these random numbers. Both components need the header <random>.
 *
 * Random number generator
 * The random number generator generates a random number stream between a minimum and maximum value. This stream is
 * initialized by a "so-called" seed, guaranteeing difference sequence of random numbers.
 *  #include <random>
 *  ...
 *  std::random_device seed;
 *  std::mt19937 generator(seed(();
 * A random number generate gen of type Generator supports four different requests:
 *  1. Generator::result_type: data type of the generated random number.
 *  2. gen(): returns a random number.
 *  3. gen.min(): Returns the minimum random number that can be returned by gen().
 *  4. gen.max(): Returns the maximum random number that can be returned by gen().
 *
 * The random number library supports several random number generators. The best known is the Mersenne Twister, the
 * std::default_random_engine that is chosen by the implementation and std::random_device. std::random_device is the
 * only true random number generator, but not all platforms offer it.
 *
 * Random number distribution
 * The random number distribution maps the random numbers with the help of the random number generator gen to the
 * selected distribution.
 * C++ has several discrete and continuous random number distributions. The discrete random number distribution
 * generates integers, the continuous random number distribution generates floating point numbers.
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <random>

static const int NUM = 1'000'000;

void writeToFile(const char* fileName, const std::map<int, int>& data) {
    std::ofstream file(fileName);

    if(!file) {
        std::cerr << "Could not open the file: " << fileName << "!\n";
        exit(EXIT_FAILURE);
    }

    // Print the datapoint to the file
    for (auto mapIt : data) file << mapIt.first << " " << mapIt.second << '\n';
}

int main() {
    std::random_device seed;

    // default generator
    std::mt19937 engine(seed());

    // Distributions

    // min=0; max=20;
    std::uniform_int_distribution<> uniformDist(0,20);

    // mean=50; sigma=8;
    std::normal_distribution<> normDist(50, 8);

    // mean=6;
    std::poisson_distribution<> poiDist(6);

    // alpha=1;
    std::gamma_distribution<> gammaDist;

    std::map<int, int> uniformFrequency;
    std::map<int, int> normFrequency;
    std::map<int, int> poiFrequency;
    std::map<int, int> gammaFrequency;

    for (int i{0}; i <= NUM; ++i) {
        ++uniformFrequency[uniformDist(engine)];
        ++normFrequency[round(normDist(engine))];
        ++poiFrequency[poiDist(engine)];
        ++gammaFrequency[round(gammaDist(engine))];
    }

    writeToFile("uniform_int_distribution.txt", uniformFrequency);
    writeToFile("normal_distribution.txt", normFrequency);
    writeToFile("poisson_distribution.txt", poiFrequency);
    writeToFile("gamma_distribution.txt", gammaFrequency);

    return 0;
}