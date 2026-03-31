#include <string>

extern void cmd_sort(std::string args[], int n);
extern void sort_logic(std::string input[], int line_count, std::string ans[], bool sort_numeric, int k_col);
extern std::string get_column(std::string line, int k);