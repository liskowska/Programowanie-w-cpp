/*
Działanie algorytmu heapsort O(nlogn):
1. Tablica heap jest drzewem, tzn. wartość z indeksu 0 jest podsatwą drzewa. Dzieci wierzchołka znajdują się na indeksach
    2i+1 oraz 2i+2.
2. Budowanie max heap. Max heap to drzewo w którym podstawa ma największą wartość w drzewie oraz każdy rodzic jest zawsze 
    większy od każdego ze swoich dzieci. Proces ten wykonuje funkcja heapify()
*/

#include <iostream>
#include <random>
#include <cstring>

#define N 10

using namespace std;

void wypiszKrok(int krok, int heap[], int sorted[], int aktualny_rozmiar) {
    cout << "Krok " << krok << "\t | Heap: ";
    for (int i = 0; i < aktualny_rozmiar; i++) cout << heap[i] << " ";
    for (int i = aktualny_rozmiar; i < N; i++) cout << "  "; 
    
    cout << "\t\t| Sorted: ";
    for (int i = 0; i < N; i++) {
        if (i < aktualny_rozmiar) cout << "  ";
        else cout << sorted[i] << " ";
    }
    cout << endl;
}

void heapify(int heap[], int sorted[], int n, int i){
    int largest = i;
    // sprawdzamy lewy wierzcholek
    if(2*i+1 < n && heap[2*i+1] > heap[largest])
        largest = 2*i + 1;

    // sprawdzamy prawy wierzcholek
    if(2*i+2 < n && heap[2*i+2] > heap[largest])
        largest = 2*i + 2;

    // jeżeli coś się zmieniło
    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(heap, sorted, n, largest);
    }
}

void heapSort(int heap[], int sorted[], bool track){
    for(int i = N/2 - 1; i >= 0; i--){
        heapify(heap, sorted, N, i);
    }

    for(int i = N-1; i >= 0; i--){
        if (track) wypiszKrok(N - i, heap, sorted, i + 1);

        sorted[i] = heap[0];
        heap[0] = heap[i];

        heap[i] = 0;

        heapify(heap, sorted, i, 0);
    }
}

int main(int argc, char* argv[]){
    int heap[N];
    int sorted[N] = {0};

    bool track = false;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "--track") == 0) track = true;
    }

    mt19937 gen{random_device{}()};
    uniform_int_distribution randint{-10, 9};

    for(int i = 0; i <  N; i++){
        heap[i] = randint(gen);
    }

    cout << "TABLICA WEJSCIOWA: ";
    for (int i = 0; i < N; i++) cout << heap[i] << " ";
    cout << endl;

    heapSort(heap, sorted, track);

    cout << "\nWYNIK KONCOWY: ";
    for (int i = 0; i < N; i++) cout << sorted[i] << " ";
    cout << endl;

    return 0;
}