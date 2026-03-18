#include <iostream>
#include <zawiera.hpp>
#include <wypiszZbior.hpp>
#include <czyRowne.hpp>
#include <czyZawiera.hpp>
#include <iloczyn.hpp>
#include <roznica.hpp>
#include <roznicaSymetryczna.hpp>
#include <suma.hpp>

using namespace std;

const int MAX_SIZE = 100;

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

    cout << "Podaj numery operacji (1-6), wykonaj przez Ctrl+D: " << endl <<
        "1. Suma" << endl <<
        "2. Iloczyn" << endl <<
        "3. Roznica" << endl <<
        "4. Roznica symetryczna" << endl <<
        "5. Porownanie" << endl <<
        "6. Czy A zawiera sie w B lub B zawiera sie w A" << endl;
    
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