#include <iostream>
#include <zawiera.hpp>

using namespace std;

const int MAX_SIZE = 100;

void iloczyn(int size_A, int A[], int size_B, int B[], int wynik[], int& size_wynik){
    size_wynik = 0;
    for (int i = 0; i < size_A; i++){
        if(zawiera(B, size_B, A[i])){
            wynik[size_wynik] = A[i];
            size_wynik++;
        }
    }
}