#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 1024;
const char XOR_KEY = 0x42; // klucz szyfrowania

void encryptXOR(const string& inputPath, const string& outputPath) {
    ifstream inFile(inputPath, ios::binary);
    ofstream outFile(outputPath, ios::binary);

    if (!inFile || !outFile) {
        cerr << "[WARNING] Blad otwarcia plikow." << endl;
        return;
    }

    // Dynamiczna alokacja bufora
    char* buffer = new char[BUFFER_SIZE];

    if (!inFile.is_open()) {
    cerr << "[WARNING] Bład otwarcia pliku wejsciowego: " << inputPath << endl;
    return;
    }

    cout << "Szyfrowanie pliku algorytmem XOR." << endl;

    while (inFile) {
        inFile.read(buffer, BUFFER_SIZE);
        streamsize bytesRead = inFile.gcount();

        for (int i = 0; i < bytesRead; ++i) {
            // Prosta operacja XOR na każdym bajcie
            *(buffer + i) ^= XOR_KEY; 
        }

        outFile.write(buffer, bytesRead);
    }

    delete[] buffer;

    inFile.close();
    outFile.close();

    cout << "Plik został zapisany w: " << outputPath << endl;
}
