#include <iostream>
#include <string>

using namespace std;

bool hasLength(string * password){
    string str_password = *password;
    if (str_password.length() >= 8) return true;
    return false;
}