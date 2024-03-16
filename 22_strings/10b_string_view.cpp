/*
 * No memory allocation with a string view
 * If we create a string view or copy a string view, there is no memory allocation necessary. This is in contrast to a
 * string; creating a string or copying a string requires memory allocation
 */
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t count) {
    std::cout << " " << count << " bytes" << '\n';
    return malloc(count);
}

void getString(const std::string& str) {}
void getStringView(std::string_view strView) {}

int main() {

    std::cout << std::endl;

    std::cout << "std::string" << std::endl;

    std::string large = "0123456789-123456789-123456789-123456789";
    std::string substr = large.substr(10);

    std::cout << std::endl;

    std::cout << "std::string_view" << std::endl;

    std::string_view largeStringView{large.c_str(), large.size()};
    largeStringView.remove_prefix(10);

    assert(substr == largeStringView);

    std::cout << std::endl;

    std::cout << "getString" << std::endl;

    getString(large);
    getString("0123456789-123456789-123456789-123456789");
    const char message []= "0123456789-123456789-123456789-123456789";
    getString(message);

    std::cout << std::endl;

    std::cout << "getStringView" << std::endl;

    getStringView(large);
    getStringView("0123456789-123456789-123456789-123456789");
    getStringView(message);

    return 0;
}