#include <string>
#include <iostream>

#define M 20

using namespace std;

int cmd_n(string input[], int n, string ans[], int p){
    int j = 0;
    if (p > 0){
        for(int i = p - 1; i < n && i < M; i++){
            ans[j] = input[i];
            j++;
        }
    }
    else{
        int start = n + p;
        if (start < 0) start = 0;

        for(int i = start; i < n; i++){
            ans[j] = input[i];
            j++;
        }
    }
    return j;
}

int cmd_c(string input[], int n, string ans[], int p){
    int bites_cnt = 0;
    int j = 0;
    if (p >= 0){
        bool flag = false;
        bites_cnt  = p + 1;

        for (int i = 0; i < n; i++){
            if(flag == true){
                ans[j] = input[i];
                j++;
            }
            else {
                int len = input[i].length() + 1;
                if ( bites_cnt < len ){
                    flag = true;
                    ans[j] = input[i].substr(bites_cnt);
                    j++;
                }
                else bites_cnt -= len; 
            }
        }
    }
    else {
        int total_chars = 0;
        for (int i = 0; i < n; i++) {
            total_chars += input[i].length() + 1;
        }

        int p_start = total_chars + p;

        if (p_start < 1) p_start = 0;

        return cmd_c(input, n, ans, p_start - 3);
    }
    return j;
}

void cmd_tail(string args[], int n) {
    string input[M];
    string ans[M];
    string line;
    int line_count = 0;

    while (getline(cin, line)) {
        if (line_count < M) {
            input[line_count] = line;
            line_count++;
        } else {
            cerr << "[WARNING] Limit liczby linii przekroczony!" << endl;
            break;
        }
    }

    int p = -10; // domyślnie ostatnie 10 linii
    bool is_char_mode = false;

    for (int i = 1; i < n; i++) {
        string arg = args[i];

        if (arg == "-c") {
            is_char_mode = true;
            if (i + 1 < n) {
                string next_arg = args[++i];
                p = stoi(next_arg); 
                if (next_arg[0] != '+' && p > 0) p = -p;
            }
        } 
        else if (arg == "-n") {
            is_char_mode = false;
            if (i + 1 < n) {
                string next_arg = args[++i];
                p = stoi(next_arg);
                if (next_arg[0] != '+' && p > 0) p = -p;
            }
        } 
        else if (arg[0] == '-' || arg[0] == '+') {
            if (arg.size() > 1 && isdigit(arg[1])) {
                p = stoi(arg);
                if (arg[0] == '-' && p > 0) p = -p; 
            }
        }
    }

    int final_cnt = 0;
    if (is_char_mode) {
        final_cnt = cmd_c(input, line_count, ans, p);
    } else {
        final_cnt = cmd_n(input, line_count, ans, p);
    }

    cout << endl;
    for (int i = 0; i < final_cnt; i++) {
        cout << ans[i] << endl;
    }
}