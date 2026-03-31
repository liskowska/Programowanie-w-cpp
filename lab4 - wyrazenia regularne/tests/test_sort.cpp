#include <gtest/gtest.h>
#include <string>
#include "sort.hpp"

using namespace std;

// --- TESTY GET_COLUMN ---
TEST(SortTest, GetColumnTest) {
    string line = "100 Ala ma kota";
    EXPECT_EQ(get_column(line, 1), "100");
    EXPECT_EQ(get_column(line, 2), "Ala");
    EXPECT_EQ(get_column(line, 4), "kota");
    EXPECT_EQ(get_column(line, 5), ""); // Poza zakresem
}

// --- TEST SORTOWANIA ALFABETYCZNEGO ---
TEST(SortTest, AlphabeticalSort) {
    string input[] = {"Cezary", "Adam", "Beata"};
    string ans[3];
    sort_logic(input, 3, ans, false, 0); // false = nie liczbowo, 0 = cała linia
    
    EXPECT_EQ(ans[0], "Adam");
    EXPECT_EQ(ans[1], "Beata");
    EXPECT_EQ(ans[2], "Cezary");
}

// --- TEST SORTOWANIA LICZBOWEGO (-n) ---
TEST(SortTest, NumericSort) {
    string input[] = {"10", "2", "20", "1"};
    string ans[4];
    sort_logic(input, 4, ans, true, 0); // true = liczbowo
    
    EXPECT_EQ(ans[0], "1");
    EXPECT_EQ(ans[1], "2");
    EXPECT_EQ(ans[2], "10");
    EXPECT_EQ(ans[3], "20");
}

// --- TEST SORTOWANIA PO KOLUMNIE (-k) ---
TEST(SortTest, ColumnSort) {
    string input[] = {
        "2 Banan",
        "1 Cytryna",
        "3 Arbuz"
    };
    string ans[3];
    
    // Sortuj po 2. kolumnie (alfabetycznie)
    sort_logic(input, 3, ans, false, 2); 
    
    EXPECT_EQ(ans[0], "3 Arbuz");
    EXPECT_EQ(ans[1], "2 Banan");
    EXPECT_EQ(ans[2], "1 Cytryna");
}

// --- TEST KOMBINACJI -n -k ---
TEST(SortTest, NumericColumnSort) {
    string input[] = {
        "Wiersz 10",
        "Wiersz 2",
        "Wiersz 1"
    };
    string ans[3];
    
    // Sortuj po 2. kolumnie liczbowo
    sort_logic(input, 3, ans, true, 2);
    
    EXPECT_EQ(ans[0], "Wiersz 1");
    EXPECT_EQ(ans[1], "Wiersz 2");
    EXPECT_EQ(ans[2], "Wiersz 10");
}