#include <iostream>

#define N 5

using namespace std;


// Umieszcza liczbę number na końcu kolejki queue. Jeżeli kolejka jest pełna, to zwraca wartość -1; w przeciwnym razie zwraca 0
int Queue__push(int queue[], int number){
    if(queue[N-1] != 0){
        cerr << "[WARNING] Kolejka jest pełna!" << endl;
        return -1;
    }

    int i = 0;
    while (true){
        if(i == N || queue[i] == 0){
            queue[i] = number;
            return 0;
        }
        i++;
    }
    return -1;
}

// Pobiera pierwszy element (liczbę) z kolejki queue i zwraca go. Jeżeli kolejka jest pusta, to zwraca wartość -2
int Queue__pop(int queue[]){
    if (queue[0] == 0){
        cerr << "[WARNING] Kolejka jest pusta!"<< endl;
        return -2;
    }

    int popped = queue[0];
    queue[0] = 0;
    for(int i=0; i<N-1; i++){
        swap(queue[i], queue[i+1]);
    }
    return popped;
}

// Wypisuje zawartość kolejki queue
void Queue__print(int queue[]){
    for (int i = 0; i < N; i++) {
        if (queue[i] == 0) break;
        cout << queue[i] << ((i == N - 1 || queue[i+1] == 0) ? "" : ", ");
    }
    cout << endl;
}

int main(){
    int queue[N] = {0};

    int i = 2;
    while(true){
        if (Queue__push(queue, i) != -1) Queue__print(queue);
        else break;
        i = i+2;
    }

    int popped;
    while (true){
        popped = Queue__pop(queue);
        cout << popped << "\t";
        Queue__print(queue);
        if(popped == -2) break;
    }

    return 0;
}