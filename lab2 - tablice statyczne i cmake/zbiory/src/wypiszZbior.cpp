#include <iostream>

using namespace std;

const int MAX_SIZE = 100;


void wypiszZbior(const string msg, int tab_size, int tab[]) {
    cout << msg << "{ ";
    for (int i = 0; i < tab_size; i++) {
        cout << tab[i] << (i == tab_size - 1 ? "" : ", ");
    }
    cout << " }" << endl;
}