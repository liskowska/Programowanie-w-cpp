#include <gtest/gtest.h>
#include <string>
#include "../include/tail.hpp"

using namespace std;

// Dane testowe wspólne
string tail_input[] = {
    "Linia 1", // len 7 (+1 = 8)
    "Linia 2", // len 7 (+1 = 8)
    "Linia 3", // len 7 (+1 = 8)
    "Linia 4", // len 7 (+1 = 8)
    "Linia 5"  // len 7 (+1 = 8)
};
int tn = 5;

// --- TESTY DLA CMD_N (Linie) ---

TEST(TailTest, LastNLines) {
    string ans[20];
    // p = -2 powinno zwrócić ostatnie 2 linie (4 i 5)
    int count = cmd_n(tail_input, tn, ans, -2);
    
    EXPECT_EQ(count, 2);
    EXPECT_EQ(ans[0], "Linia 4");
    EXPECT_EQ(ans[1], "Linia 5");
}

TEST(TailTest, FromNLineToEnd) {
    string ans[20];
    // p = 4 (czyli +4) powinno zwrócić od 4. linii do końca
    int count = cmd_n(tail_input, tn, ans, 4);
    
    EXPECT_EQ(count, 2);
    EXPECT_EQ(ans[0], "Linia 4");
    EXPECT_EQ(ans[1], "Linia 5");
}

// --- TESTY DLA CMD_C (Bajty/Znaki) ---

TEST(TailTest, LastCBytes) {
    string ans[20];
    string c_input[] = {"aa", "bb", "cc"}; // len 2, 2, 2. Z \n to 3, 3, 3.
    // tail -c 3 powinno zwrócić ostatnie 3 znaki 
    // W Twojej logice p = -3
    int count = cmd_c(c_input, 3, ans, -3);
    
    // Sprawdzamy czy w ogóle coś zwrócił
    EXPECT_GT(count, 0);
    // W przykładzie "aa\nbb\ncc\n", ostatnie 3 bajty to "cc" + \n. 
    // Skoro getline ucina \n, to ans[0] powinno być "cc"
    EXPECT_EQ(ans[count-1], "cc");
}

// TEST(TailTest, FromCByteToEnd) {
//     string ans[20];
//     string c_input[] = {"abc", "def"}; // total 4 + 4 = 8 bajtów
//     // tail -c +5 powinno zacząć od 5. bajtu (czyli od 'd' w "def")
//     int count = cmd_c(c_input, 2, ans, 5);
    
//     EXPECT_EQ(count, 1);
//     EXPECT_EQ(ans[0], "def");
// }

// --- TESTY BRZEGOWE ---

TEST(TailTest, OverflowTest) {
    string ans[20];
    // więcej linii niż jest w pliku
    int count = cmd_n(tail_input, tn, ans, -100);
    
    // Powinno zwrócić wszystko co ma
    EXPECT_EQ(count, 5);
    EXPECT_EQ(ans[0], "Linia 1");
}