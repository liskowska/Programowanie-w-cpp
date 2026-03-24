#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

bool zawiera(int tab[], int tab_size, int element) {
    for (int i = 0; i < tab_size; i++) {
        if (tab[i] == element) return true;
    }
    return false;
}
