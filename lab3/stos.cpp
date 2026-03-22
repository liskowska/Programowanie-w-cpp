#include <iostream>

#define N 5

using namespace std;

// Umieszcza liczbę number na szczycie stosu stack. 
// Jeżeli stos jest pełny, to zwraca wartość -1; w przeciwnym razie zwraca 0
int Stack__push(int stack[], int number){
    if(stack[N-1] != 0){
        cerr << "[WARNING] Stos pełny!" << endl;
        return -1;
    }

    int i = N-1;
    while (stack[i] == 0){
        if(stack[i-1] != 0 || i == 0){
            stack[i] = number;
            return 0;
        }
        i--;
    }
    return -1;
}

// Zdejmuje element (liczbę) ze szczytu stosu stack i zwraca go.
// Jeżeli stos jest pusty, to zwraca -2
int Stack__pop(int stack[]){
    if (stack[0] == 0) {
        cerr << "[WARNING] Stos jest pusty!" << endl;
        return -2;
    }
    
    int i = N-1;
    int popped = 0;
    while (i >= 0){
        if(i == 0 && stack[i] == 0) return -2;
        if(stack[i] != 0) {
            popped = stack[i];
            stack[i] = 0;
            return popped;
        }
        i--;
    }
    return -2;
}

// Wypisuje zawartość stosu stack
void Stack__print(int stack[]){
    for (int i = 0; i < N; i++) {
        if (stack[i] == 0) break;
        cout << stack[i] << ((i == N - 1 || stack[i+1] == 0) ? "" : ", ");
    }
    cout << endl;
}

int main(){
    int stack[N] = {0};

    int i = 2;
    while(true){
        if(Stack__push(stack, i) == -1) break;
        else Stack__print(stack);
        i+=2;
    }

    int popped;
    while (true){
        popped = Stack__pop(stack);
        cout << popped << "\t";
        Stack__print(stack);
        if(popped == -2) break;
    }
    return 0;
}