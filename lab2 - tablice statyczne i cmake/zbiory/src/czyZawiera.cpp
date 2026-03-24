#include <iostream>
#include <zawiera.hpp>

using namespace std;

const int MAX_SIZE = 100;

bool czyZawiera(int size_A, int A[], int size_B, int B[]){ // czy A zawiera B? (A musi być większy)
    if (size_A < size_B) return false;
    for (int i = 0; i < size_B; i++){
        if(!zawiera(A, size_A, B[i])) return false;
    }
    return true;
}