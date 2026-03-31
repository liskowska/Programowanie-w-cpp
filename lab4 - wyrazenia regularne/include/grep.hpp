#include <string>
extern void cmd_grep(std::string args[], int n);
extern int cmd_i(std::string input[], int n, std::string ans[], std::string pattern_str);
extern int cmd_w(std::string input[], int n, std::string ans[], std::string pattern_str);
extern int cmd_n(std::string input[], int n, std::string ans[], std::string pattern_str, int parsed_args[]);