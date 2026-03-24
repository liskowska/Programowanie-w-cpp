#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

// Funkcje pomocnicze
bool zawiera(int tab[], int tab_size, int element) {
    for (int i = 0; i < tab_size; i++) {
        if (tab[i] == element) return true;
    }
    return false;
}

void wypiszZbior(const string msg, int tab_size, int tab[]) {
    cout << msg << "{ ";
    for (int i = 0; i < tab_size; i++) {
        cout << tab[i] << (i == tab_size - 1 ? "" : ", ");
    }
    cout << " }" << endl;
}

// Operacje na zbiorach
void suma(int size_A, int A[], int size_B, int B[], int wynik[], int& size_wynik){
    size_wynik = 0;
    for (int i = 0; i < size_A; i++){;
        wynik[size_wynik] = A[i];
        size_wynik++;
    }

    for(int i = 0; i < size_B; i++){
        if(!zawiera(wynik, size_wynik, B[i])){
            if(size_wynik >= MAX_SIZE){
                cerr << "[WARNING] Przepełnienie tablicy wynikowej. Tablica sumy może nie być pełna!" << endl;
                break;
            }
            wynik[size_wynik] = B[i];
            size_wynik++;
        }
    }
}

void iloczyn(int size_A, int A[], int size_B, int B[], int wynik[], int& size_wynik){
    size_wynik = 0;
    for (int i = 0; i < size_A; i++){
        if(zawiera(B, size_B, A[i])){
            wynik[size_wynik] = A[i];
            size_wynik++;
        }
    }
}

void roznica(int size_A, int A[], int size_B, int B[], int wynik[], int& size_wynik){
    size_wynik = 0;
    for(int i = 0; i < size_A; i++){
        if (!zawiera(B, size_B, A[i])){
            wynik[size_wynik] = A[i];
            size_wynik++;
        }
    }
}

void roznicaSymetryczna(int size_A, int A[], int size_B, int B[], int wynik[], int& size_wynik){
    size_wynik = 0;
    for(int i = 0; i < size_A; i++){
        if (!zawiera(B, size_B, A[i])){
            wynik[size_wynik] = A[i];
            size_wynik++;
        }
    }

    for(int i = 0; i < size_B; i++){
        if (!zawiera(A, size_A, B[i])){
            wynik[size_wynik] = B[i];
            size_wynik++;
        }
    }
}

bool czyRowne(int size_A, int A[], int size_B, int B[]){
    if(size_A != size_B) return false;
    for(int i = 0; i < size_A; i++){
        if(!zawiera(B, size_B, A[i])) return false;
    }
    return true;
}

bool czyZawiera(int size_A, int A[], int size_B, int B[]){ // czy A zawiera B? (A musi być większy)
    if (size_A < size_B) return false;
    for (int i = 0; i < size_B; i++){
        if(!zawiera(A, size_A, B[i])) return false;
    }
    return true;
}

int main() {
    int nA, nB, temp;
    int kolejkaOperacji[10]; 
    int liczbaZadan = 0;

    cout << "Podaj liczbe elementow mniejszą od 100 zbioru A: ";
    while (!(cin >> nA)) { 
        cout << "Podana dana nie jest liczbą lub jest liczbą mniejszą od 100. Podaj jeszcze raz: "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    int A[nA];
    for (int i = 0; i < nA; i++) {
        cin >> temp;
        A[i] = temp;
    }

    cout << "Podaj liczbe elementow mniejszą od 100 zbioru B: ";
    while (!(cin >> nB)) { 
        cout << "Podana dana nie jest liczbą lub jest liczbą mniejszą od 100. Podaj jeszcze raz: "<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    int B[nB];
    for (int i = 0; i < nB; i++) {
        cin >> temp;
        B[i] = temp;
    }

    cout << "Podaj numery operacji (1-6), wykonaj przez Ctrl+D: " << endl;
    
    int op;
    while (cin >> op) {
        if (liczbaZadan < 10) {
            kolejkaOperacji[liczbaZadan] = op;
            liczbaZadan++;
        } else {
            cerr << "[WARNING] Limit operacji przekroczony!" << endl;
            break;
        }
    }

    cout << "\n WYNIKI \n" << endl;
    wypiszZbior("A: ", nA, A);
    wypiszZbior("B: ", nB, B);
    cout << endl;

    int wynik[MAX_SIZE];
    int nW;

    for (int i = 0; i < liczbaZadan; i++) {
        int aktualnaOp = kolejkaOperacji[i];
        nW = MAX_SIZE;

        cout << "Zadanie " << i + 1 << " (Operacja " << aktualnaOp << "): ";

        switch (aktualnaOp) {
            case 1: 
                suma(nA, A, nB, B, wynik, nW);
                wypiszZbior("Suma: ", nW, wynik);
                break;
            case 2:
                iloczyn(nA, A, nB, B, wynik, nW);
                wypiszZbior("Iloczyn: ", nW, wynik);
                break;
            case 3:
                roznica(nA, A, nB, B, wynik, nW);
                wypiszZbior("Roznica A\\B: ", nW, wynik);
                break;
            case 4:
                roznicaSymetryczna(nA, A, nB, B, wynik, nW);
                wypiszZbior("Roznica symetryczna: ", nW, wynik);
                break;
            case 5:
                cout << "A == B? " << (czyRowne(nA, A, nB, B) ? "Tak" : "Nie") << endl;
                break;
            case 6: 
                cout << "A subset B: " << (czyZawiera(nA, A, nB, B) ? "Tak" : "Nie") << ", ";
                cout << "B subset A: " << (czyZawiera(nB, B, nA, A) ? "Tak" : "Nie") << endl;
                break;
            default: 
                cerr << "[WARNING] Nieznany numer operacji: " << aktualnaOp << endl;
        }
    }
    return 0;
}