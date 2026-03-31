#include <iostream>
#include <regex>
#include <string>

#define M 20

using namespace std;

int cmd_i(string input[], int n, string ans[], string pattern_str) {
    regex pattern(pattern_str, regex_constants::icase);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (regex_search(input[i], pattern)) {
            ans[count] = input[i];
            count++;
        }
    }
    return count;
}

int cmd_w(string input[], int n, string ans[], string pattern_str){
    int count = 0;
    string final_pattern = "\\b" + pattern_str + "\\b";
    regex pattern(final_pattern);
    for (int i = 0; i < n; i++) {
        if (regex_search(input[i], pattern)) {
            ans[count] = input[i];
            count++;
        }
    }
    return count;
}

int cmd_n(string input[], int n, string ans[], string pattern_str, int parsed_args[]){
    int count = 0;
    
    // bitowy OR (|), aby połączyć flagi
    auto flags = regex_constants::ECMAScript;
    if (parsed_args[0] == 1) { // flaga -i 
        flags |= regex_constants::icase;
    }

    string final_pattern = pattern_str;
    if (parsed_args[1] == 1) { // flaga -w
        final_pattern = "\\b" + pattern_str + "\\b";
    }

    regex pattern(final_pattern, flags);

    for (int i = 0; i < n; i++) {
        if (regex_search(input[i], pattern)) {
            ans[count] = to_string(i + 1) + ":" + input[i];
            count++;
        }
    }

    return count;
}

void cmd_grep(string args[], int n){
    string input[M];
    string ans[M];
    string line;

    int line_number = 0;

    while (getline(cin, line)) {
        if (line_number < M) {
            input[line_number] = line;
            line_number++;
        } else {
            cerr << "[WARNING] Limit liczby linii przekroczony!" << endl;
            break;
        }
    }

    string pattern;
    int parsed_args[4] = {0}; // 0:i, 1:w, 2:n, 3:c
    // tablica parsed_args = [0, 1, 1, 0] znaczy ze wykonujemy operacje -w i -n
    for (int i = 1; i < n; i++){
        if (args[i] == "-i"){
            parsed_args[0] = 1;
        }
        else if(args[i] == "-w"){
            parsed_args[1] = 1;
        }
        else if (args[i] == "-n"){
            parsed_args[2] = 1;
        }
        else if(args[i] == "-c"){
            parsed_args[3] = 1;
        }
        else if(i == n - 1){ // szukane slowo
            pattern = args[i];
        }
        else{
            cerr << "[UWAGA] Komenda nieznana!" << endl;
        }
    }

    int current_cnt = 0;

    // -n (robi wszystko)
    if (parsed_args[2] == 1) {
        current_cnt = cmd_n(input, line_number, ans, pattern, parsed_args);
    } 
    // Jeśli nie ma -n, ale jest -i lub -w
    else if(parsed_args[0] == 1 || parsed_args[1] == 1) {
        string ans_i[M];
        string ans_w[M];

        if (parsed_args[0] == 1) {
            current_cnt = cmd_i(input, line_number, ans_i, pattern);
            
            if (parsed_args[1] == 1) {
                current_cnt = cmd_w(ans_i, current_cnt, ans_w, pattern);
                for (int i = 0; i < current_cnt; i++) ans[i] = ans_w[i];
            } else {
                for (int i = 0; i < current_cnt; i++) ans[i] = ans_i[i];
            }
        }

        else if (parsed_args[1] == 1) {
            current_cnt = cmd_w(input, line_number, ans_w, pattern);
            for (int i = 0; i < current_cnt; i++) ans[i] = ans_w[i];
        }

    }
    else{ // zwykły grep
        regex re(pattern);
        for (int i = 0; i < line_number; i++) {
            if (regex_search(input[i], re)) {
                ans[current_cnt] = input[i];
                current_cnt++;
            }
        }
    }
    
    cout << endl << endl;
    if (parsed_args[3] == 1) { // -c => liczba
        cout << current_cnt << endl;
    } else {
        for (int i = 0; i < current_cnt; i++) {
            cout << ans[i] << endl;
        }
    }
}