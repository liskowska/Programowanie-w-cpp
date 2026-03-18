#include <iostream>
#include <zawiera.hpp>

using namespace std;

const int MAX_SIZE = 100;

bool czyRowne(int size_A, int A[], int size_B, int B[]){
    if(size_A != size_B) return false;
    for(int i = 0; i < size_A; i++){
        if(!zawiera(B, size_B, A[i])) return false;
    }
    return true;
}