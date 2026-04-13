#include <iostream>
#include <string>
#include "hasDigit.hpp"
#include "hasLength.hpp"
#include "hasSpecialChar.hpp"

using namespace std;

// typ "wskaźnik na funkcję, która zwraca bool i bierze string*"
typedef bool (*Validator)(string*);

int main(){
    string password;
    string *w_password = &password;
    int k = 8;
    cout << "Wpisz hasło które chcesz poddać weryfikacji" << endl;
    cin >> *w_password;

    Validator checks[] = {hasDigit, hasLength, hasSpecialChar};
    bool password_correct = true;

    for (int i = 0; i < 3; i++){
        if(!checks[i](w_password)) password_correct = false;
    }

    if(password_correct) cout << "Hasło poprawne!" << endl;
    else cout << "Hasło niepoprawne!"<< endl;

    return 0;
}