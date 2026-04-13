#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "encryptXOR.hpp"
#include "vulnerability.hpp"

using namespace std;

// Rozmiar bufora do przetwarzania partiami
const int BUFFER_SIZE = 1024;
const char XOR_KEY = 0x42; // Przykładowy klucz szyfrowania

// Definicja typu dla wskaźnika na funkcję szyfrującą
typedef void (*EncryptionFunc)(const string&, const string&);

int main(int argc, char* argv[]) {
    string inFile, outFile;
    bool vulnerabilityEnabled = false;

    // Parsowanie argumentów linii komend
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg.find("--input=") == 0) inFile = arg.substr(8);
        else if (arg.find("--output=") == 0) outFile = arg.substr(9);
        else if (arg == "--vulnerability") vulnerabilityEnabled = true;
    }

    if (inFile.empty() || outFile.empty()) {
        cout << "Uzycie: " << argv[0] << " --input=plik --output=wynik [--vulnerability]" << endl;
        return 1;
    }

    EncryptionFunc currentTask = encryptXOR;

    if (vulnerabilityEnabled) {
        vulnerability(&currentTask);
    }

    currentTask(inFile, outFile);

    return 0;
}