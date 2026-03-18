#include <iostream>
#include <random>

using namespace std;

int main(){
    /*
    model na prostokącie o wierzchołkach:
    A = (-0.5, 0.5)
    B = (0.5, 0.5)
    C = (0.5 -0.3)
    D = (-0.5, -0.3)
    */

    // Generator liczb losowych
    mt19937 gen{random_device{}()};
    // Rozklad na prostokacie
    uniform_real_distribution<double> losujx{-0.5, 0.5};
    uniform_real_distribution<double> losujy{-0.3, 0.5};

    double n;
    int k = 0;

    cout << "Wprowadź n: " << endl;
    cin >> n;

    double x, y;
    for(int i = 0; i < n; i++){
        x = losujx(gen);
        y = losujy(gen);

        if((y <= sqrt(0.25 - x*x) && x <=0 && y >=0) ||         // IV ćw
            (y <= -sqrt(-x*x+x)+0.5 && x > 0 && y >= 0) ||      // I ćw
            (y >= 1.2*x*x - 0.3 && x>0 && y < 0) ||             // II ćw
            (y >= -sqrt((1-x*x/0.25)*0.09) && x <0 && y <0)){   // IV ćw
                k++;
            }
    }

    double wynik = (1*0.8) * (k/n);
    cout << "Pole figury z zadania to " << wynik << endl;

    return 0;
}