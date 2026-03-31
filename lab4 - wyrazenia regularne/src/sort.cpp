#include <string>
#include <iostream>
#include <sstream>

#define M 20
using namespace std;

string get_column(string line, int k) {
    if (k <= 0) return line; // Jeśli nie ma -k, bierzemy całą linię
    
    stringstream ss(line);
    string word;
    int current_col = 1;
    
    while (ss >> word) {
        if (current_col == k) return word;
        current_col++;
    }
    return ""; // Jeśli kolumna k nie istnieje w tej linii
}

void cmd_sort(string args[], int n) {
    string input[M];
    string ans[M];
    string line;
    int line_count = 0;

    while (line_count < M && getline(cin, line)) {
        input[line_count++] = line;
    }

    bool sort_numeric = false;
    int k_col = 0;

    for (int i = 1; i < n; i++) {
        string arg = args[i];
        if (arg == "-n") {
            sort_numeric = true;
        } else if (arg.substr(0, 2) == "-k") {
            if (arg.length() > 2) {
                k_col = stoi(arg.substr(2)); // dla -k2
            } else if (i + 1 < n) {
                k_col = stoi(args[++i]); // dla -k 2
            }
        }
    }

    for (int i = 0; i < line_count; i++) ans[i] = input[i];

    //bubble sort
    for (int i = 0; i < line_count - 1; i++) {
        for (int j = 0; j < line_count - i - 1; j++) {
            bool swap_needed = false;

            string val1 = get_column(ans[j], k_col);
            string val2 = get_column(ans[j + 1], k_col);

            if (sort_numeric) {
                // Sortowanie liczbowe (-n)
                try {
                    // Zamieniamy na inty, jeśli się da
                    int num1 = (val1 != "") ? stoi(val1) : 0;
                    int num2 = (val2 != "") ? stoi(val2) : 0;
                    if (num1 > num2) swap_needed = true;
                } catch (...) {
                    // Jeśli to nie liczba, sortujemy alfabetycznie jako fallback
                    if (val1 > val2) swap_needed = true;
                }
            } else {
                // Sortowanie alfabetyczne (domyślne)
                if (val1 > val2) swap_needed = true;
            }

            if (swap_needed) {
                string temp = ans[j];
                ans[j] = ans[j + 1];
                ans[j + 1] = temp;
            }
        }
    }

    cout << endl;
    for (int i = 0; i < line_count; i++) {
        cout << ans[i] << endl;
    }
}