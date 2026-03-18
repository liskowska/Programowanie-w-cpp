/*
Aby proces kompilacji kończył się sukcesem:
- Odkomentuj dyrektywy '#include' znajdujące się w liniach 7-9.
- Zastąp każde wystąpienie 'plikNagłówkowyNr{N}' nazwą konkretnego, wymaganego pliku nagłówkowego.
*/

#include <complex>
#include <iostream>
#include <format>

using namespace std;
using namespace complex_literals;
int main(void)
{
    // Zmodyfikowany przykład ze strony 'https://valgrind.org/docs/manual/quick-start.html'
    int *x = new int[10];
    x[10] = 0;

    delete[] x;

    // Komentarz
    bool zywy = true;
    cout << format("\e[31mZmienna 'zywy' ma wartość:\e[0m {}", zywy) << endl;
    int n = rand();
    cout << format("\e[31mWylosowano liczbę:\e[0m {}", n) << endl;
    n = n % 10;
    cout << format("\e[31mWylosowana liczba modulo 10 =\e[0m {}", n) << endl;
    switch (n)
    {
    case 1 ... 5:
        cout << "\e[31mOtrzymana wartość należy do przedziału od 1 do 5\e[0m" << endl;
        break;
    case 9:
        cout << "\e[31mOtrzymano wartość 9\e[0m" << endl;
        break;
    default:
        cout << "\e[31mOtrzymana wartość nie należy do przedziału od 1 do 5 oraz jest różna od 9\e[0m" << endl;
    }
    int iloczyn = 1;
    for (int i = n; i > 0; i--)
    {
        iloczyn = iloczyn * i;
        cout << format("\e[31m{} \e[0m", i) << endl;
    }
    cout << "\e[31mStart\n\e[0m";
    cout << format("\e[31mWartość iloczynu:\e[0m {}", iloczyn) << endl;
    cout << "\e[31mKoniec\e[0m" << endl;
    double a, b, c, d;
    cout << "\e[31mObliczanie (a+bi)+(c-di)\e[0m" << endl;
    cout << "\e[31mPodaj wartość współczynnika a:\e[0m ";
    cin >> a;
    cout << "\e[31mPodaj wartość współczynnika b:\e[0m ";
    cin >> b;
    cout << "\e[31mPodaj wartość współczynnika c:\e[0m ";
    cin >> c;
    cout << "\e[31mPodaj wartość współczynnika d:\e[0m ";
    cin >> d;
    complex<double> z1 = a + b * 1i;
    complex<double> z2 = c - d * 1i;
    complex<double> suma = z1 + z2;
    cout << format("\e[31m({:.1f}+{:.1f}i) + ({:.1f}{:+.1f}i)  =\e[0m {:.1f}{:+.1f}i", a, b, c, d, suma.real(), suma.imag()) << endl;
    return 0;
}