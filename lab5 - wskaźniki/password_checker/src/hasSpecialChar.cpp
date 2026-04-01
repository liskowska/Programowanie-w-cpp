#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool hasSpecialChar(string * password){
    regex specialCharPattern("[\\$\\!@#%^&*()_+=-\\[\\]\\{\\}\\|;':,.<>\\/?`~\\-_]");
    return regex_search(*password, specialCharPattern);
}