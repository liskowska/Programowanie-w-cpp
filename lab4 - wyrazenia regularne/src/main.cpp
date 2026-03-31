#include "grep.hpp"
#include "tail.hpp"
#include "sort.hpp"

#include <iostream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

const int MAX_ARGS = 20;

int main() {
    string line;

    while (true) {
        cout << "Podaj komendę lub wpisz CTRL + d aby zakończyć działanie programu: " << endl;
        
        if (!getline(cin, line)) {
            cout << "\nProgram zakończył działanie" << endl;
            break;
        }

        if (line.empty()) continue;

        string args[MAX_ARGS];
        int arg_count = 0;

        stringstream ss(line);
        string word;

        while (ss >> word && arg_count < MAX_ARGS) {
            args[arg_count] = word;
            arg_count++;
        }

        if (arg_count == 0) continue;

        string cmd = args[0]; // komenda

        if (cmd == "grep") {
            cmd_grep(args, arg_count);
        } 
        else if (cmd == "sort") {
            cmd_sort(args, arg_count);
        } 
        else if (cmd == "tail") {
            cmd_tail(args, arg_count);
        } 
        else {
            cout << "Nieznana komenda: " << cmd << endl;
        }

        // czyszczenie flagi po Ctrl+D z wnętrza funkcji
// --- TO MUSI TU BYĆ ---
        if (cin.eof()) {
            cin.clear(); // Czyści flagi błędów i EOF
            // Na niektórych systemach (szczególnie Linux/Unix) to wystarczy.
            // Jeśli dalej przeskakuje, musimy "puknąć" w stdin:
            clearerr(stdin); 
        }    }

    return 0;
}