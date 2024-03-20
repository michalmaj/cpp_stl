/*
 * Regular Expression Objects
 * Objects of type regular expression are instances of the class template parametrized by their character type and
 * traits class. The trait class defines the interpretation of the properties of the regular grammar.
 *
 * We can further customize the object of type regular expression. Therefore, we can specify the used grammar or adapt
 * the syntax. As said before, C++ supports the basic, extended, awk, grep and egrep grammars. A regular expression
 * qualified by the std::regex_constants::icase flag is case-insensitive. If we want to adopt the syntax, we have to
 * specify the grammar explicitly.
 */
#include <iostream>
#include <regex>
#include <string>

int main() {

    std::string theQuestion="C++ or c++, that's the question.";

    // Regular expression for c++
    std::string regExprStr(R"(c\+\+)");

    // regular expression object
    std::regex rgx(regExprStr);

    // search result holder
    std::smatch smatch;

    std::cout << theQuestion << '\n';

    // looking for a partial match (case-sensitive)
    if (std::regex_search(theQuestion, smatch, rgx)) {
        std::cout << "The answer in case sensitive: " << smatch[0] << '\n';
    }

    // regular expression object (case insensitive)
    std::regex rgxIn(regExprStr, std::regex_constants::ECMAScript | std::regex_constants::icase);

    // looking for a partial match
    if (std::regex_search(theQuestion, smatch, rgxIn)) {
        std::cout << "The answer in case sensitive: " << smatch[0] << '\n';
    }

    return 0;
}