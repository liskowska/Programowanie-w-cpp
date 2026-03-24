#include <iostream>
#include <zawiera.hpp>

using namespace std;

const int MAX_SIZE = 100;

void suma(int size_A, int A[], int size_B, int B[], int wynik[], int& size_wynik){
    size_wynik = 0;
    for (int i = 0; i < size_A; i++){;
        wynik[size_wynik] = A[i];
        size_wynik++;
    }

    for(int i = 0; i < size_B; i++){
        if(!zawiera(wynik, size_wynik, B[i])){
            if(size_wynik >= MAX_SIZE){
                cerr << " [WARNING] Przepełnienie tablicy wynikowej. Tablica sumy może nie być pełna! " << endl;
                break;
            }
            wynik[size_wynik] = B[i];
            size_wynik++;
        }
    }
}