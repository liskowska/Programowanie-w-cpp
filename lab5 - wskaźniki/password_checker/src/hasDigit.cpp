#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool hasDigit(string * password){
    if (password == nullptr) return false;

    regex digit_pattern("\\d");

    return regex_search(*password, digit_pattern);
}