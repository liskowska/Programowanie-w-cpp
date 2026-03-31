#include <gtest/gtest.h>
#include <string>
#include "grep.hpp"

using namespace std;

string test_input[] = {
    "Ala ma kota",
    "ALA MA PSA",
    "Kot ma Ale",
    "Sloń i krowa",
    "kota"
};
int n = 5;

// --- TESTY DLA CMD_I (-i) ---
TEST(GrepTest, IgnoreCaseTest) {
    string ans[20];
    int count = cmd_i(test_input, n, ans, "ala");
    
    // Powinno znaleźć "Ala ma kota" i "ALA MA PSA"
    EXPECT_EQ(count, 2) << "Funkcja cmd_i powinna znalezc 2 dopasowania dla 'ala'";
    EXPECT_EQ(ans[0], "Ala ma kota");
    EXPECT_EQ(ans[1], "ALA MA PSA");
}

// --- TESTY DLA CMD_W (-w) ---
TEST(GrepTest, WholeWordTest) {
    string ans[20];
    int count = cmd_w(test_input, n, ans, "Kot");
    
    EXPECT_EQ(count, 1) << "Funkcja cmd_w powinna znalezc tylko 'Kot ma Ale'";
    EXPECT_EQ(ans[0], "Kot ma Ale");
}

// --- TESTY DLA CMD_N (-n) ---
TEST(GrepTest, LineNumbersTest) {
    string ans[20];
    int flags[] = {0, 0, 1, 0}; // Tylko flaga -n
    int count = cmd_n(test_input, n, ans, "kota", flags);
    
    EXPECT_EQ(count, 2);
    // Linia 1: Ala ma kota -> "1:Ala ma kota"
    // Linia 5: kota -> "5:kota"
    EXPECT_EQ(ans[0], "1:Ala ma kota");
    EXPECT_EQ(ans[1], "5:kota");
}

// --- TESTY KOMBINOWANE (-i oraz -w) ---
TEST(GrepTest, CombinedFlagsTest) {
    string ans[20];
    int flags[] = {1, 1, 1, 0}; // -i, -w, -n
    int count = cmd_n(test_input, n, ans, "ala", flags);
    
    EXPECT_EQ(count, 2);
    EXPECT_EQ(ans[0], "1:Ala ma kota");
    EXPECT_EQ(ans[1], "2:ALA MA PSA");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}