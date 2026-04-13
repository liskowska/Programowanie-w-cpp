#include <iostream>
#include <string>

using namespace std;

char * my_strcpy(char * dest, const char * src){
    char *start = dest;

    do{
        *dest = *src;
        dest++;
        src++;
    } while(*src != '\0');

    return start;
}

void login_system(const char* userInput) {
    int isAdmin = 0; 
    char username[8];

    cout << "Adres username: " << (void*)username << endl;
    cout << "Adres isAdmin:  " << (void*)&isAdmin << endl;

    my_strcpy(username, userInput);

    cout << "Username: " << username << endl;
    cout << "Wartosc isAdmin: " << isAdmin << endl;

    if (isAdmin != 0) {
        cout << "Konto w trybie administratora" << endl;
    } else {
        cout << "Konto w trybie zwykłego użytkownika :(" << endl;
    }
}

int main(){
    // char zrodlo[] = "Dokumentacja silnika krokowego.\n";
    // char przeznaczenie[ 40 ];
   
    // my_strcpy( przeznaczenie, zrodlo );
   
    // printf( "przeznaczenie: %s", przeznaczenie );

    login_system("admin\x01\x01\x01\x01");
    return 0;
}