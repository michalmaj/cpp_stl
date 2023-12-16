/*
 * Time Duration
 * The time duration is a measure of how many ticks have passed since a certain time point.
 *
 * Time duration is the difference between the two time-points. Time duration is measured in the number of ticks.
 *  template <class Rep, class Period=ratio<1>> class duration;
 * If reps is a floating-point number, the time duration supports fractions of ticks. The most important time durations
 * are predefined in the chrono library:
 *  typedef duration<signed int, nano> nanoseconds;
 *  typedef duration<signed int, micro> microseconds;
 *  typedef duration<signed int, milli> milliseconds;
 *  typedef duration<signed int> seconds;
 *  typedef duration<signed int, ratio< 60>> minutes;
 *  typedef duration<signed int, ratio<3600>> hours;
 * How long can a time duration be? The C++ standard guarantees that the predefined time durations can store +-292
 * years. We can easily define our own time duration like in German school hour:
 *  typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick
 * Time durations in natural numbers have to be explicitly converted to time durations in floating point numbers.
 *
 * std::ratio
 * std::ration supports arithmetic at compile time with rational numbers.  rational number has two template arguments.
 * One is the nominator, the other the denominator. C++11 predefines lots of rational numbers:
 *  typedef ratio <1, 1000000000000000000> atto;
 *  typedef ratio <1, 1000000000000000> femto;
 *  typedef ratio <1, 1000000000000> pico;
 *  typedef ratio <1, 1000000000> nano;
 *  typedef ratio <1, 1000000> micro;
 *  typedef ratio <1, 1000> milli;
 *  typedef ratio <1, 100> centi;
 *  typedef ratio <1, 10> deci;
 *  typedef ratio < 10, 1> deca;
 *  typedef ratio < 100, 1> hecto;
 *  typedef ratio < 1000, 1> kilo;
 *  typedef ratio < 1000000, 1> mega;
 *  typedef ratio < 1000000000, 1> giga;
 *  typedef ratio < 1000000000000, 1> tera;
 *  typedef ratio < 1000000000000000, 1> peta;
 *  typedef ratio < 1000000000000000000, 1> exa;
 *
 * C++14 has built-in literals for the most used time durations.
 *  std::chrono::hours - h
 *  std::chrono::minutes - min
 *  std::chrono::seconds - s
 *  std::chrono::milliseconds - ms
 *  std::chrono::microseconds - us
 *  std::chrono::nanoseconds - ns
 */
#include <chrono>
#include <iostream>
#include <ratio>

template <typename Rap, typename Period = std::ratio<1>> class duration;

int main(){
    using MySecondTick = std::chrono::duration<long long, std::ratio<1>>;
    MySecondTick  aSecond(1);

    std::chrono::milliseconds milli(aSecond);
    std::cout << milli.count() << " ms\n";

    std::chrono::seconds seconds(aSecond);
    std::cout << seconds.count() << " s\n";

    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(aSecond);
    std::cout << minutes.count()  << " min\n";

    using MyLessonTick = std::chrono::duration<double, std::ratio<2700>>;
    MyLessonTick myLesson(aSecond);
    std::cout << myLesson.count() << " less\n";

    return 0;
}